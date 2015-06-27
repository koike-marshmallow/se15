#define MC_NONE 6001

struct matrix {
	int *dots;
	int size_y;
	int size_x;
};
typedef struct matrix MATRIX;


MATRIX *loadMatrix(char *fname);
void freeMatrix(MATRIX *matrix);
