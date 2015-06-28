#define PUT_PROB_INIT 10
#define PUT_WAIT_SPAN_INIT 24

extern PUT_PROB;
extern PUT_WAIT_SPAN;

void initObstacleSet(void);
int putObstacle(int pos);
void freeObstacleSet(void);
