#include <stdio.h>
#include "matrix.h"
#include "menuScreen.h"
#include "gameScreen.h"
#include "highScore.h"

#define MLIST_SIZE 5

#define SEL_GEASY 201
#define SEL_GNORMAL 202
#define SEL_GHARD 203
#define SEL_QUIT 211

MLIST mlist[MLIST_SIZE] = {
	{SEL_GEASY, "EASY", MSTATE_ENABLE, MVISIB_VISIBLE},
	{SEL_GNORMAL, "NORMAL", MSTATE_DISABLE, MVISIB_INVISIBLE},
	{SEL_GHARD, "HARD", MSTATE_DISABLE, MVISIB_INVISIBLE},
	{SEL_QUIT, "", MSTATE_DISABLE, MVISIB_INVISIBLE},
	{SEL_QUIT, "QUIT", MSTATE_ENABLE, MVISIB_VISIBLE}
};

int gameLoop(int lev, int score){
	int tmp;
	
	while( 1 ){
		tmp = gameScreen(lev, score);
		
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


void levelUnlock(void){
	if( getHighScore() > 200 ){
		mlist[1].state = MSTATE_ENABLE;
		mlist[1].visible = MVISIB_VISIBLE;
	}
	if( getHighScore() > 1000 ){
		mlist[2].state = MSTATE_ENABLE;
		mlist[2].visible = MVISIB_VISIBLE;
	}
}


int main(void){
	int com;
	
	loadHighScore("score");
		
	while( 1 ){
		levelUnlock();
		com = menuScreen(mlist, MLIST_SIZE);
		
		if( com == SEL_GEASY ){
			com = gameLoop(LEVEL_EASY, 0);
		}
		else if( com == SEL_GNORMAL ){
			com = gameLoop(LEVEL_NORMAL, 0);
		}
		else if( com == SEL_GHARD ){
			com = gameLoop(LEVEL_HARD, 1000);
		}
		else if( com == SEL_QUIT ){
			break;
		}
		
		if( com == COMMAND_QUIT ){
			 break;
		}
	}
	
	saveHighScore("score");
	return 0;
}
	
