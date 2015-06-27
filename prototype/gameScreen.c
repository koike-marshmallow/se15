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


#define TIMEOUT 20


int SCORE = 0;
int SCORE_HIGH = 20;

int FLAMES;
int FLAME_REF;

int PLAYER_JHEIGHT;
MATRIX *PLAYER_MATRIX;

void initGame(int sp0, int sc0){

	initField();
	initObstacleSet();
	initJumpFlag();
	
	PLAYER_JHEIGHT = 0;
	PLAYER_MATRIX = loadMatrix("player.mat");
	FLAMES = 0;
	FLAME_REF = 5;
	
}

int gameScreen(int sp0, int sc0){
	int i, inp;

	initGame(sp0, sc0);
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
		
			game_refreshScreen();
			FLAMES = 0;
		}
		
		
		mvprintw(1, 2, "FLAMES=%4d, FLAME_REF=%4d\n", FLAMES, FLAME_REF);
	}
	
	mvprintw(3, 2, "[[END]]");
	refresh();
	sleep(2);
	
	freeObstacleSet();
	rs_endwin();
	return 0;
}


int isRefTime(void){
	return FLAMES >= FLAME_REF;
}

