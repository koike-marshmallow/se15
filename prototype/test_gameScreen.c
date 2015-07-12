#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "gameScreen.h"
#include "highScore.h"


int main(void){
	int tmp, levels;
	srand((unsigned)time(NULL));
	
	loadHighScore("score");
	levels = 7;
	while( 1 ){
		tmp = gameScreen(levels, 0);
		printf("RET = %d\n", tmp);
	
		if( tmp == COMMAND_RETRY ){
			continue;
		}else if( tmp == COMMAND_MENU ){
			printf("input level: ");
			fflush(stdout);
			scanf("%d", &levels);
			continue;
		}else if( tmp == COMMAND_QUIT ){
			break;
		}
	}
	
	resetHighScore();
	saveHighScore("score");
	return 0;
}
