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
	int quit, select, gret;
	
	if( loadHighScore("score") != 0 ){
		fprintf(stderr, "スコアファイルを読み込めませんでした\n");
		return 0;
	}
	
	quit = 0;
	gret = 0;
	while( !quit ){
		levelUnlock();
		
		if( gret != COMMAND_RETRY ){
			select = menuScreen(mlist, MLIST_SIZE);
		}
		
		switch( select ){
			case SEL_GEASY:
				gret = gameScreen(LEVEL_EASY, 0);
				break;
			case SEL_GNORMAL:
				gret = gameScreen(LEVEL_NORMAL, 0);
				break;
			case SEL_GHARD:
				gret = gameScreen(LEVEL_HARD, 1000);
				break;
			
			case SEL_QUIT:
				quit = 1;
				break;
		}
		
		if( gret == COMMAND_QUIT ){
			quit = 1;
		}	
	}
	
	saveHighScore("score");
	
	return 0;
}
