#include <stdio.h>
#include "matrix.h"
#include "gameScreen.h"
#include "game_field.h"
#include "game_jumping.h"

#define CHECK_AREA_WIDTH 20
#define CHECK_AREA_HEIGHT 12

#define ADD 4701
#define PUT 4702

int MASK[CHECK_AREA_HEIGHT][CHECK_AREA_WIDTH];


void gbump_initMask(void){
	int i, j;
	
	for( i=0; i<CHECK_AREA_HEIGHT; i++){
		for( j=0; j<CHECK_AREA_WIDTH; j++){
			MASK[i][j] = 0;
		}
	}
}

void gbump_putMask(int y, int x, MATRIX *matrix, int mode){
	int i, j, cnt = 0;
	int *dp;
	
	if( x + matrix->size_x > CHECK_AREA_WIDTH ){
		return;
	}
	if( y + matrix->size_y > CHECK_AREA_HEIGHT ){
		return;
	}
	
	dp = matrix->dots;
	for( i=y + matrix->size_y - 1; i>=y; i--){
		for( j=x; j<x + matrix->size_x; j++){
			if( *dp != MC_NONE ){
				if( mode == ADD ){
					MASK[i][j]++;
				}else if( mode == PUT ){
					MASK[i][j] = 1;
				}
			}
			else{
				cnt++;
			}
			dp++;
		}
	}
	
	return;
}

int gbump_checkMask(void){
	int i, j;

	for( i=0; i<CHECK_AREA_HEIGHT; i++){
		for( j=0; j<CHECK_AREA_WIDTH; j++){
			if( MASK[i][j] >= 2 ) return 1;
		}
	}
	return 0;
}

int gbump_check(void){
	int i;
	
	gbump_initMask();
	
	for( i=0; i<CHECK_AREA_WIDTH; i++){
		if( FIELD[i] != NULL ){
			gbump_putMask(0, i, FIELD[i], PUT);
		}
	}
	gbump_putMask(PLAYER_JHEIGHT, PLAYER_POS_X, PLAYER_MATRIX, ADD);
	
	return gbump_checkMask();
}
