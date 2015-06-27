#include <stdio.h>
#include "matrix.h"
#include "drawScreen.h"

int main(int argc, char *argv[]){
	MATRIX *mat;
	
	if( argc < 2 ){
		mat = loadMatrix("test.mat");
	}else{
		mat = loadMatrix(argv[1]);
	}
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
