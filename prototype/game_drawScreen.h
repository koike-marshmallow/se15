#define SCRSIZE_X 80
#define SCRSIZE_Y 24

#define FIELD_ORIGIN_X 1
#define FIELD_ORIGIN_Y 20

void gdscr_refresh(void);
void gdscr_draw(void);
void gdscr_draw2array(int y, int x, int *ary, int i_max, int j_max);
