#define FORMAT_LEFT   4101
#define FORMAT_RIGHT  4102
#define FORMAT_CENTER 4103

void rs_initscr(void);
void rs_endwin(void);
void drawString(int pos_y, int pos_x, char *str, int format);
void drawMatrix(int pos_y, int pos_x, MATRIX *matrix);
void drawBox(int pos_y, int pos_x, int width, int height);
void drawGround(int y, int x, int width);
