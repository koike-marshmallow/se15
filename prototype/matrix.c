#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "matrix.h"

#define CONVERT_TABLE_SIZE 2

char CONVERT_TABLE_INPUT[CONVERT_TABLE_SIZE] = {
	'0', '1'
};
int CONVERT_TABLE_CHAR[CONVERT_TABLE_SIZE] = {
	MC_NONE,
	' ' | COLOR_PAIR(COLOR_WHITE)
};

int searchConvertTable(char c){
	int i;
	
	for( i=0; i<CONVERT_TABLE_SIZE; i++){
		if( c == CONVERT_TABLE_INPUT[i] ){
			return i;
		}
	}
	
	return -1;
}


MATRIX *loadMatrix(char *fname){
	FILE *in;
	MATRIX *matrix;
	int length;
	int tmp;
	int i, conv;
	
	if( (in = fopen(fname, "r")) == NULL ){
		fprintf(stderr, "loadMatrix: cannot open file\n");
		return NULL;
	}
	
	if( (matrix = malloc(sizeof(MATRIX))) == NULL ){
		fprintf(stderr, "loadMatrix: cannot allocate memory (0)\n");
		return NULL;
	}
	
	fscanf(in, "%d", &matrix->size_y);
	fscanf(in, "%d", &matrix->size_x);
	length = matrix->size_y * matrix->size_x;
	
	if( (matrix->dots = malloc(sizeof(int) * length)) == NULL ){
		fprintf(stderr, "loadMatrix: cannot allocate memory (1)\n");
		return NULL;
	}
	
	i = 0;
	while( (tmp = fgetc(in)) != EOF ){
		if( tmp == '\n' ) continue;

		if( i >= length ){
			fprintf(stderr, "loadMatrix: memory space out of bounds(len:%d)\n", length);
			break;
		}
		
		if( (conv = searchConvertTable((char)tmp)) >= 0 ){
			matrix->dots[i] = CONVERT_TABLE_CHAR[conv];
		}else{
			matrix->dots[i] = tmp;
		}
		
		i++;
	}
	
	fclose(in);
	
	return matrix;
}


void freeMatrix(MATRIX *matrix){
	free(matrix->dots);
	free(matrix);
}
		
		
			
