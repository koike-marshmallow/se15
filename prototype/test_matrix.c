#include <stdio.h>
#include "matrix.h"
#include "drawScreen.h"

int main(void){
	MATRIX *mat;
	
	mat = loadMatrix("test.mat");
	if( mat == NULL ){
		fprintf(stderr, "test_matrix: return NULL\n");
		return 1;
	}
	rs_initscr();
	drawMatrix(0, 0, mat);
	refresh();
	sleep(3);
	freeMatrix(mat);
	rs_endwin();
	return 0;
}
