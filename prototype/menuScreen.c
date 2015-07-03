#include <ncurses.h>
#include "matrix.h"
#include "drawScreen.h"
#include "menuScreen.h"

#define LIST_POS_X 20
#define LIST_POS_Y 15

int SELECTED;
MATRIX *TITLE;

void drawItemList(int y, int x, MLIST list[], int mlist_num){
	int i;
	clear();

	drawMatrix(5, 10,TITLE);	
	for( i=0; i<mlist_num; i++){
		if( list[i].visible == MVISIB_VISIBLE ){
			if( i == SELECTED ){
				mvprintw(y + i, x, "> %s", list[i].label);
			}else{
				mvprintw(y + i, x, "  %s", list[i].label);
			}
		}
	}
}


int menuScreen(MLIST list[], int mlist_num){
	int inp, tmp;
	
	SELECTED = 0;
	TITLE = loadMatrix("title.mat");
	rs_initscr();
	
	/*入力受付処理*/
	while( 1 ){
		mvprintw(0, 0, "SELECTED = %d\n", SELECTED);
		drawItemList(LIST_POS_Y, LIST_POS_X, list, mlist_num);
		refresh();
		
		inp = getch();
		if( inp == '\n' ){
			break;
		}
		
		if( inp == KEY_UP ){
			tmp = SELECTED - 1;
			while( 1 ){
				if( tmp < 0 ){
					break;
				}
				if( list[tmp].state == MSTATE_ENABLE ){
					SELECTED = tmp;
					break;
				}
				tmp--;
			}
		}
		
		if( inp == KEY_DOWN ){
			tmp = SELECTED + 1;
			while( 1 ){
				if( tmp >= mlist_num ){
					break;
				}
				if( list[tmp].state == MSTATE_ENABLE ){
					SELECTED = tmp;
					break;
				}
				tmp--;
			}
		}
	}
	
	rs_endwin();
	freeMatrix(TITLE);
	return list[SELECTED].no;
}	
