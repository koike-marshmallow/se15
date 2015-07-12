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
#include "getCommand.h"

#define MAX_LEVEL 6
#define COMMAND_NUM 3

LEVEL_P LEVEL_TABLE[MAX_LEVEL] = {
	{15,  200, 1},
	{20,  500, 2},
	{25,  800, 2},
	{30, 1000, 3},
	{35, 1500, 3},
	{40, 2000, 3}
};

CLIST COMMAND_LIST[COMMAND_NUM] = {
	{'r', "retry"},
	{'m', "menu"},
	{'q', "quit"}
};

int SCORE;
int SCORE_HIGH;
int LEVEL;
int PLAYER_JHEIGHT;
int DELAY;
MATRIX *PLAYER_MATRIX;

MATRIX *PLAYER_MATRIX_LOSE;


void initGame(int lv0, int sc0){
	gfield_init();
	gobstacle_init();
	gjump_initFlag();
	
	SCORE = sc0;
	LEVEL = lv0;
	
	PLAYER_JHEIGHT = 0;
	PLAYER_MATRIX = loadMatrix("player.mat");
	PLAYER_MATRIX_LOSE = loadMatrix("player_lose.mat");
	SCORE_HIGH = getHighScore();
	
}


void setDelay(int fps){
	DELAY = 1000000 / fps;
}


int checkLevelUp(void){
	if( (LEVEL + 1) >= MAX_LEVEL ){
		return 0;
	}
	if( SCORE >= LEVEL_TABLE[LEVEL].next_score ){
		return 1;
	}else{
		return 0;
	}
}


void setLevel(int level){
	setDelay(LEVEL_TABLE[level].speed_fps);
	OBSTACLE_RANGE = LEVEL_TABLE[level].obs_range;
}


int gameScreen(int lv0, int sc0){
	int i, inp;
	
	initGame(lv0, sc0);
	gdscr_initscr();
	
	gdscr_refresh();
	drawString(6, 40, "Press space key to start", FORMAT_CENTER);
	while( (inp = getch()) != ' ' );
	
	timeout(0);
	setLevel(LEVEL);
	while( !gbump_check() ){
	
		/*sleep処理*/
		usleep(DELAY);
	
		/*入力受付処理*/
		inp = getch();
		if( inp == 'q' ) break;
		if( inp == ' ' ) gjump_flagSet();
		
		/*レベルアップ処理*/
		if( checkLevelUp() ){
			LEVEL++;
			setLevel(LEVEL);
		}
		
		/*画面更新処理*/
		gfield_shiftl();
		gobstacle_put(&FIELD[FIELD_WIDTH - 1]);
		gjump_jumpPlayer();
		SCORE++;
		gdscr_refresh();
	}
	
	/*終了処理*/
	setHighScore(SCORE);
	SCORE_HIGH = getHighScore();
	timeout(-1);
	freeMatrix(PLAYER_MATRIX);
	PLAYER_MATRIX = PLAYER_MATRIX_LOSE;
	
	/*終了画面描画*/
	gdscr_draw();
	drawString(5, 5, "GAME OVER.", FORMAT_LEFT);
	printCommand(22, 76, FORMAT_RIGHT, COMMAND_LIST, COMMAND_NUM);
	refresh();
	
	/*コマンド取得*/
	inp = getCommand(COMMAND_LIST, COMMAND_NUM);
	
	/*開放*/
	freeMatrix(PLAYER_MATRIX_LOSE);
	gobstacle_memFree();
	gdscr_endwin();
	
	/*メッセージ返却*/
	switch( inp ){
		case 'r':
			return COMMAND_RETRY;
		case 'm':
			return COMMAND_MENU;
		case 'q':
			return COMMAND_QUIT;
		default:
			return 9999;
	}
}
