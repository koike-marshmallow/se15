#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "gameScreen.h"
#include "highScore.h"


int main(void){
	int tmp;
	srand((unsigned)time(NULL));
	
	loadHighScore("score");
	while( 1 ){
		tmp = gameScreen(LEVEL_HARD, 0);
		printf("RET = %d\n", tmp);
	
		if( tmp == COMMAND_RETRY ){
			continue;
		}else if( tmp == COMMAND_MENU ){
			break;
		}else if( tmp == COMMAND_QUIT ){
			break;
		}
	}
	
	resetHighScore();
	saveHighScore("score");
	return 0;
}
