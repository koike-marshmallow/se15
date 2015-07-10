extern int PUT_PROB;
extern int PUT_WAIT_SPAN;
extern int OBSTACLE_RANGE;

void gobstacle_init(void);
int gobstacle_put(MATRIX **field_ads);
void gobstacle_memFree(void);
