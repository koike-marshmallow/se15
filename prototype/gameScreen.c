#include <ncurses.h>
#include <unistd.h>
#include "matrix.h"
#include "gameScreen.h"
#include "drawScreen.h"
#include "game_field.h"
#include "game_drawScreen.h"


#define TIMEOUT 20



int SCORE = 0;
int SCORE_HIGH = 20;

int PLAYER_JHEIGHT;
MATRIX *PLAYER_MATRIX;

void initGame(int sp0, int sc0){
	
	initField();
	
	PLAYER_JHEIGHT = 0;
	PLAYER_MATRIX = loadMatrix("player.mat");
	
}

int gameScreen(int sp0, int sc0){

	initGame(sp0, sc0);
	rs_initscr();
	
	game_refreshScreen();
	
	sleep(5);
	
	rs_endwin();
	return 0;
}

