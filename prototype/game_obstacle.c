#include <stdlib.h>
#include "matrix.h"
#include "game_field.h"
#include "game_obstacle.h"

#define OBSTACLE_NUM 2


MATRIX *OBSTACLES[OBSTACLE_NUM];
int PUT_WAIT;

int PUT_PROB;
int PUT_WAIT_SPAN;


void initObstacleSet(void){
	PUT_WAIT = 0;
	PUT_PROB = PUT_PROB_INIT;
	PUT_WAIT_SPAN = PUT_WAIT_SPAN_INIT;
	OBSTACLES[0] = loadMatrix("obs1.mat");
	OBSTACLES[1] = loadMatrix("obs2.mat");
	FIELD[60] = OBSTACLES[0];
}


int putObstacle(int pos){
	if( PUT_WAIT > 0 ){
		PUT_WAIT--;
		return 0;
	}else{
		if( (rand() % PUT_PROB) == 0 ){
			FIELD[pos] = OBSTACLES[rand() % OBSTACLE_NUM];
			PUT_WAIT = PUT_WAIT_SPAN;
		}
		return 1;
	}
}


void freeObstacleSet(void){
	int i;
	
	for( i=0; i<OBSTACLE_NUM; i++){
		freeMatrix(OBSTACLES[i]);
	}
}
