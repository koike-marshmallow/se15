#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include "gameScreen.h"
#include "drawScreen.h"

#define TIMEOUT 20

#define SCRSIZE_X 80
#define SCRSIZE_Y 24

#define FIELD_WIDTH 78
#define FIELD_ORIGIN_X 1
#define FIELD_ORIGIN_Y 20

#define PLAYER_POS_X 6
#define PLAYER_JUMP_HIGHT 8
#define PLAYER_JUMP_POWER 1

#define OBSTACLE_COUNT 1

#define PUT_PROB 10
#define PUT_WAIT_SPAN 24
#define OCCUPYED 3101


int SCORE;
int HIGH_SCORE;
int FLAMES;
int FLAME_REF;
int JUMP_FLAG;
int PUT_WAIT;
MATRIX *FIELD[FIELD_WIDTH];

int PLAYER_JHIGHT;

int PLAYER_MATRIX_PATTERN[] = {
	NDRW, NDRW, NDRW, NDRW, SP_W, 
	SP_W, '`' | COLOR_PAIR(COLOR_WHITE), SP_W,
	SP_W, SP_W, SP_W, SP_W, SP_W, SP_W, SP_W, '~' | COLOR_PAIR(COLOR_WHITE), 
	NDRW, SP_W, SP_W, SP_W, SP_W, NDRW, NDRW, NDRW,
	NDRW, SP_W, NDRW, NDRW, SP_W, NDRW, NDRW, NDRW
};
MATRIX PLAYER_MATRIX = {
	PLAYER_MATRIX_PATTERN, 4, 8
};

int OBSTACLE_PATTERN1[] = {
	NDRW, SP_W, NDRW,
	SP_W, SP_W, SP_W,
	NDRW, SP_W, NDRW
};
MATRIX OBSTACLES[OBSTACLE_COUNT] = {
	{OBSTACLE_PATTERN1, 3, 3}
};

void initGame(int sp0, int sc0){
	int i;	

	/*フィールドの生成*/
	for( i=0; i<FIELD_WIDTH; i++){
		FIELD[i] = NULL;
	}
	FIELD[PLAYER_POS_X] = &PLAYER_MATRIX;
	
	PLAYER_JHIGHT = 0;
	FLAMES = 0;
	JUMP_FLAG = 0;
	PUT_WAIT = 0;
	SCORE = 0;
	HIGH_SCORE = 0;
	
}



int gameScreen(int sp0, int sc0){
	int i, inp;

	rs_initscr();
	initGame(sp0, sc0);

	FIELD[20] = &OBSTACLES[0];
	FLAME_REF = 1;
	JUMP_FLAG = 1;

	timeout(TIMEOUT);
	for( i=0; i<1000; i++){
		inp = getch();
		if( inp == ' ' && JUMP_FLAG == 0 ){
			JUMP_FLAG = 1;
		}
		FLAMES++;
		if( isRefTime() ){
			renewField();
			clear();
			game_drawScreen();
			FLAMES = 0;
		}
		mvprintw(1, 2, "FLAMES = %4d, FLAME_REF = %4d, PUT_WAIT = %4d", FLAMES, FLAME_REF, PUT_WAIT);
	}

	sleep(3);
	rs_endwin();

	return 0;
}


void game_drawScreen(void){
	int i;
	
	/*画面枠*/
	drawBox(0, 0, SCRSIZE_Y, SCRSIZE_X);
	/*地面*/
	drawGround(FIELD_ORIGIN_Y, FIELD_ORIGIN_X, FIELD_WIDTH);
	/*障害物*/
	for( i=PLAYER_POS_X + 1; i < FIELD_WIDTH; i++){
		if( FIELD[i] != NULL ){
			drawMatrix(FIELD_ORIGIN_Y - FIELD[i]->size_y, i, FIELD[i]);
		}
	}
	/*プレイヤー*/
	drawMatrix(
		FIELD_ORIGIN_Y - PLAYER_MATRIX.size_y - PLAYER_JHIGHT,
		PLAYER_POS_X, FIELD[PLAYER_POS_X]
	);
	/*スコア*/
	mvprintw(2, 40, "SCORE : %6d (%6d)", SCORE, HIGH_SCORE);
	
	
	refresh();
	return;
}


void renewField(void){
	int i;
	
	/*フィールドシフト*/
	for( i=PLAYER_POS_X + 1; i < FIELD_WIDTH - 1; i++){
		FIELD[i] = FIELD[i + 1];
	}
	FIELD[FIELD_WIDTH - 1] = NULL;
	/*障害物配置*/
	putObstacle();
	/*プレイヤージャンプ*/
	jumpPlayer();
	
	return;
}
		

int isRefTime(void){
	return FLAMES >= FLAME_REF;
}


void jumpPlayer(void){
	
	if( JUMP_FLAG == 1 ){
		PLAYER_JHIGHT++;
		if( PLAYER_JHIGHT >= PLAYER_JUMP_HIGHT ){
			JUMP_FLAG = -1;
		}
	}else if( JUMP_FLAG == -1 ){
		PLAYER_JHIGHT--;
		if( PLAYER_JHIGHT <= 0 ){
			JUMP_FLAG = 0;
		}
	}
	
	return;
}


void putObstacle(void){
	if( PUT_WAIT > 0 ){
		PUT_WAIT--;
		return;
	}
	
	if( (rand() % PUT_PROB) == 0 ){
		FIELD[FIELD_WIDTH - 1] = &OBSTACLES[rand() % OBSTACLE_COUNT];
		PUT_WAIT = PUT_WAIT_SPAN;
	}
	
	return;
}
	
	
	
	
