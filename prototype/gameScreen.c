#include <ncurses.h>
#include <unistd.h>
#include "matrix.h"
#include "gameScreen.h"
#include "drawScreen.h"
#include "game_field.h"
#include "game_drawScreen.h"
#include "game_obstacle.h"
#include "game_jumping.h"
#include "game_bump.h"
#include "game_levels.h"
#include "highScore.h"


#define TIMEOUT 10



int SCORE = 0;
int SCORE_HIGH = 20;

int FLAMES;
int FLAME_REF;

int PLAYER_JHEIGHT;
MATRIX *PLAYER_MATRIX;

void initGame(int fps, int sc0){

	initField();
	initObstacleSet();
	initJumpFlag();
	
	PLAYER_JHEIGHT = 0;
	PLAYER_MATRIX = loadMatrix("player.mat");
	FLAMES = 0;
	setSpeed(fps);
	SCORE = sc0;
	SCORE_HIGH = getHighScore();
	
}

int gameScreen(int level){
	int i, inp;
	LEVEL_P lvp;
	
	lvp = getLevelParameter(level);
	initGame(lvp.fps, lvp.score);
	
	rs_initscr();
	
	timeout(TIMEOUT);
	while( !checkBump() ){
		inp = getch();
		if( inp == 'q' ) break;
		if( inp == ' ' ) setJumpFlag();
		
		FLAMES++;	
		if( isRefTime() ){
			shiftField();
			putObstacle(FIELD_WIDTH - 1);
			jumpPlayer();
			SCORE++;
			
			if( SCORE % 200 == 0 ){
				FLAME_REF--;
			}
		
			game_refreshScreen();
			FLAMES = 0;
		}
		
		
		mvprintw(1, 2, "FLAMES=%4d, FLAME_REF=%4d\n", FLAMES, FLAME_REF);
	}
	
	setHighScore(SCORE);
	SCORE_HIGH = getHighScore();
	game_refreshScreen();
	drawString(5, 5, "GAME OVER.", FORMAT_LEFT);
	refresh();
	sleep(2);
	
	freeObstacleSet();
	rs_endwin();
	return 0;
}


int isRefTime(void){
	return FLAMES >= FLAME_REF;
}


void setSpeed(int fps){
	FLAME_REF = (1000/TIMEOUT) / fps;
}
