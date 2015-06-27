#include <ncurses.h>
#include "matrix.h"
#include "drawScreen.h"
#include "gameScreen.h"
#include "game_field.h"
#include "game_drawScreen.h"

#define BUF_SIZE 128

char STRING_BUF[BUF_SIZE];

void game_refreshScreen(void){
	clear();
	game_drawScreen();
	refresh();
}


void game_drawScreen(void){
	int i;
	
	/*画面枠*/
	drawBox(0, 0, SCRSIZE_Y, SCRSIZE_X);
	/*地面*/
	drawGround(FIELD_ORIGIN_Y, FIELD_ORIGIN_X, FIELD_WIDTH);
	/*障害物*/
	for( i=0; i < FIELD_WIDTH; i++){
		if( FIELD[i] != NULL ){
			drawMatrix(FIELD_ORIGIN_Y - FIELD[i]->size_y, i, FIELD[i]);
		}
	}
	/*プレイヤー*/
	drawMatrix(
		FIELD_ORIGIN_Y - PLAYER_MATRIX->size_y - PLAYER_JHEIGHT,
		PLAYER_POS_X, PLAYER_MATRIX
	);
	/*スコア*/
	sprintf(STRING_BUF, "SCORE: %6d (%6d)", SCORE, SCORE_HIGH);
	drawString(2, 76, STRING_BUF, FORMAT_RIGHT);
	
	return;
}


void draw2array(int y, int x, int *ary, int i_max, int j_max){
	int i, j;
	
	for( i=i_max-1; i>=0; i--){
		for( j=0; j<j_max; j++){
			mvprintw(y+i, x+j, "%d", *ary);
			ary++;
		}
	}
}
