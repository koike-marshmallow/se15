#include <ncurses.h>
#include <string.h>
#include "matrix.h"
#include "drawScreen.h"

void rs_initscr(void);
void rs_endwin(void);
void drawString(int pos_x, int pos_y, char *str, int format);
void drawMatrix(int pos_x, int pos_y, MATRIX *matrix);
void drawBox(int pos_x, int pos_y, int width, int height);

void rs_initscr(void){
	
	/* 画面の初期化処理 */
	initscr();
	start_color();
	
	/* カラーペアの初期化 */
	init_pair(COLOR_WHITE, COLOR_BLACK, COLOR_WHITE);
	
	/* 入力処理の初期化設定 */
	keypad(stdscr, TRUE);
	crmode();
	noecho();
	curs_set(0);
	
	return;
}


void rs_endwin(void){
	
	/* 画面の終了処理 */
	endwin();
	
	return;
}


void drawString(int pos_y, int pos_x, char *str, int format){
	int x, len;
	
	len = strlen(str);
	
	switch( format ){
		case FORMAT_LEFT:
			x = pos_x;
			break;
		case FORMAT_RIGHT:
			x = pos_x - len;
			break;
		case FORMAT_CENTER:
			x = pos_x - (len / 2);
			break;
		default:
			return;
	}
	
	mvprintw(pos_y, x, str);
	
	return;
}


void drawMatrix(int pos_y, int pos_x, MATRIX *matrix){
	int *dp;
	int i, j;
	int max_y, max_x;
	
	getmaxyx(stdscr, max_y, max_x);
	if( pos_y + (matrix->size_y-1) >= max_y ){
		return;
	}
	if( pos_x + (matrix->size_x-1) >= max_x ){
		return;
	}
	
	dp = matrix->dots;
	
	for( i=pos_y; i < (pos_y + matrix->size_y); i++){
		for( j=pos_x; j < (pos_x + matrix->size_x); j++){
			if( *dp != MC_NONE ){
				mvaddch(i, j, *dp);
			}
			dp++;
		}
	}
	
	return;
}


void drawBox(int pos_y, int pos_x, int height, int width){
	int i;
	
	mvaddch(pos_y           , pos_x          , ACS_ULCORNER);
	mvaddch(pos_y           , pos_x + width-1, ACS_URCORNER);
	mvaddch(pos_y + height-1, pos_x          , ACS_LLCORNER);
	mvaddch(pos_y + height-1, pos_x + width-1, ACS_LRCORNER);
	
	for( i=pos_x + 1; i < pos_x+width-1; i++){
		mvaddch(pos_y, i, ACS_HLINE);
		mvaddch(pos_y + height-1, i, ACS_HLINE);
	}
	for( i=pos_y + 1; i < pos_y+height-1; i++){
		mvaddch(i, pos_x, ACS_VLINE);
		mvaddch(i, pos_x + width-1, ACS_VLINE);
	}
	
	return;
}


void drawGround(int y, int x, int width){
	int i;
	
	for( i=x; i < (x+width); i++){
		mvaddch(y, i, '-');
	}
	
	return;
}

