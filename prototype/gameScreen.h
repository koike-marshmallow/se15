#define PLAYER_POS_X 6

#define LEVEL_EASY 0
#define LEVEL_NORMAL 1
#define LEVEL_HARD 2

struct level_profile{
	int speed_fps;
	int next_score;
};
typedef struct level_profile LEVEL_P;

extern int SCORE;
extern int SCORE_HIGH;
extern int LEVEL;
extern int PLAYER_JHEIGHT;
extern MATRIX *PLAYER_MATRIX;

void initGame(int lv0, int sc0);
void setTimeout(int fps);
int checkLevelUp(void);
int gameScreen(int lv0, int sc0);
