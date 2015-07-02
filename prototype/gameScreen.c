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
#include "highScore.h"

int SCORE = 0;
int SCORE_HIGH = 20;

int PLAYER_JHEIGHT;
MATRIX *PLAYER_MATRIX;
MATRIX *PLAYER_MATRIX_LOSE;

void initGame(){
	gfield_init();
	gobstacle_init();
	gjump_initFlag();
	
	PLAYER_JHEIGHT = 0;
	PLAYER_MATRIX = loadMatrix("player.mat");
	PLAYER_MATRIX_LOSE = loadMatrix("player_lose.mat");
	SCORE_HIGH = getHighScore();
	
}


void setTimeout(int fps){
	if( fps == 0 ){
		timeout(0);
	}else{
		timeout( 1000 / fps );
	}
}


int gameScreen(int level){
	int i, inp;
	
	initGame();
	SCORE = 0;
	gdscr_initscr();
	
	setTimeout(10);
	while( !gbump_check() ){
	
		/*入力受付処理*/
		inp = getch();
		if( inp == 'q' ) break;
		if( inp == ' ' ) gjump_flagSet();
		
		
		/*画面更新処理*/
		gfield_shiftl();
		gobstacle_put(&FIELD[FIELD_WIDTH - 1]);
		gjump_jumpPlayer();
		SCORE++;
		gdscr_refresh();
	}
	
	setHighScore(SCORE);
	SCORE_HIGH = getHighScore();
	freeMatrix(PLAYER_MATRIX);
	PLAYER_MATRIX = PLAYER_MATRIX_LOSE;
	/*終了画面描画*/
	gdscr_draw();
	drawString(5, 5, "GAME OVER.", FORMAT_LEFT);
	refresh();
	sleep(2);
	
	freeMatrix(PLAYER_MATRIX_LOSE);
	gobstacle_memFree();
	gdscr_endwin();
	return 0;
}
