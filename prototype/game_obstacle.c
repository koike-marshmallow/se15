#include <stdlib.h>
#include "matrix.h"
#include "game_obstacle.h"

#define OBSTACLE_NUM 4

#define PUT_PROB_INIT 10
#define PUT_WAIT_SPAN_INIT 24

/* externされた変数 */
int PUT_PROB;
int PUT_WAIT_SPAN;
int OBSTACLE_RANGE;


MATRIX *OBSTACLES[OBSTACLE_NUM];
int PUT_WAIT;


void gobstacle_init(void){
	PUT_WAIT = 0;
	PUT_PROB = PUT_PROB_INIT;
	PUT_WAIT_SPAN = PUT_WAIT_SPAN_INIT;
	OBSTACLES[0] = loadMatrix("obs1.mat");
	OBSTACLES[1] = loadMatrix("obs2.mat");
	OBSTACLES[2] = loadMatrix("obs3.mat");
	OBSTACLES[3] = loadMatrix("obs4.mat");
	OBSTACLE_RANGE = OBSTACLE_NUM;
}


int gobstacle_put(MATRIX **field_ads){
	if( PUT_WAIT > 0 ){
		PUT_WAIT--;
		return 0;
	}else{
		if( (rand() % PUT_PROB) == 0 ){
			*field_ads = OBSTACLES[rand() % OBSTACLE_RANGE];
			PUT_WAIT = PUT_WAIT_SPAN;
		}
		return 1;
	}
}


void gobstacle_memFree(void){
	int i;
	
	for( i=0; i<OBSTACLE_NUM; i++){
		freeMatrix(OBSTACLES[i]);
	}
}
