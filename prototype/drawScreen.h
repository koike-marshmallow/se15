#define FORMAT_LEFT   4101
#define FORMAT_RIGHT  4102
#define FORMAT_CENTER 4103

#define SP_B ' '|COLOR_PAIR(COLOR_BLACK)
#define SP_W ' '|COLOR_PAIR(COLOR_WHITE)
#define NDRW 4201

struct matrix {
	int *dots;
	int size_y;
	int size_x;
};
typedef struct matrix MATRIX;


void rs_initscr(void);
void rs_endwin(void);
void drawString(int pos_y, int pos_x, char *str, int format);
void drawMatrix(int pos_y, int pos_x, MATRIX *matrix);
void drawBox(int pos_y, int pos_x, int width, int height);
void drawGround(int y, int x, int width);

