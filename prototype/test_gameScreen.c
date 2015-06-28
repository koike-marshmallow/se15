#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "matrix.h"
#include "drawScreen.h"
#include "gameScreen.h"
#include "highScore.h"
#include "game_levels.h"


int main(void){
	int tmp;
	srand((unsigned)time(NULL));
	
	loadHighScore("score");
	tmp = gameScreen(LEVEL_NORMAL);
	printf("RET = %d\n", tmp);
	saveHighScore("score");
	return 0;
}
