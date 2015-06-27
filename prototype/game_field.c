#include <stdio.h>
#include "matrix.h"
#include "game_field.h"

MATRIX *FIELD[FIELD_WIDTH];


void initField(void){
	int i;
	
	for( i=0; i<FIELD_WIDTH; i++){
		FIELD[i] = NULL;
	}
}

void shiftField(void){
	int i;
	
	for( i=0; i<FIELD_WIDTH - 1; i++){
		FIELD[i] = FIELD[i + 1];
	}
	FIELD[FIELD_WIDTH - 1] = NULL;
}
	
