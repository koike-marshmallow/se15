#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "gameScreen.h"
#include "highScore.h"


int main(void){
	int tmp;
	srand((unsigned)time(NULL));
	
	loadHighScore("score");
	tmp = gameScreen(LEVEL_EASY, 0);
	printf("RET = %d\n", tmp);
	saveHighScore("score");
	return 0;
}
