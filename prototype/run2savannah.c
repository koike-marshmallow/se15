#include <stdio.h>
#include "matrix.h"
#include "menuScreen.h"
#include "gameScreen.h"
#include "highScore.h"

#define MLIST_SIZE 2

MLIST mlist[MLIST_SIZE] = {
	{1, "START", MSTATE_ENABLE, MVISIB_VISIBLE},
	{2, "QUIT", MSTATE_ENABLE, MVISIB_VISIBLE},
};

int gameLoop(int lev){
	int tmp;
	
	while( 1 ){
		tmp = gameScreen(lev, 0);
		
		if( tmp == COMMAND_RETRY ){
			continue;
		}else if( tmp == COMMAND_MENU ){
			return COMMAND_MENU;
		}else{
			break;
		}
	}
	
	return COMMAND_QUIT;
}
	

int main(void){
	int com, level;
	
	loadHighScore("score");
	level = LEVEL_NORMAL;
	
	while( 1 ){
		com = menuScreen(mlist, MLIST_SIZE);
		
		if( com == 1 ){
			com = gameLoop(level);
			if( com == COMMAND_QUIT ){
				break;
			}
		}else if( com == 2 ){
			break;
		}
	}
	
	return 0;
}
	
