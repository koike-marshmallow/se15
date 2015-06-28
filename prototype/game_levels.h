#define LEVEL_EASY 7001
#define LEVEL_NORMAL 7002
#define LEVEL_HARD 7003

struct level_parameter{
	int score;
	int fps;
};
typedef struct level_parameter LEVEL_P;

LEVEL_P getLevelParameter(int level);
