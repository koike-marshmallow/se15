#include "drawScreen.h"
#include <ncurses.h>
#include <unistd.h>

int TEST_MATRIX_PATTERN[] = {
	SP_B, SP_B, SP_B, SP_B, SP_W, 'o' | COLOR_PAIR(COLOR_WHITE), SP_W, SP_W,
	SP_W, SP_W, SP_W, SP_W, SP_W, SP_W, SP_W, SP_W, 
	SP_B, SP_W, SP_W, SP_W, SP_W, SP_B, SP_B, SP_B,
	SP_B, SP_W, SP_B, SP_B, SP_W, SP_B, SP_B, SP_B
};

MATRIX TEST_MATRIX = {TEST_MATRIX_PATTERN, 4, 8};
	
	
	 
	 


int main(void){
	
	rs_initscr();
	drawBox(0, 0, 24, 80);
	drawString(3, 15, "lefting", FORMAT_LEFT);
	drawString(4, 15, "righting", FORMAT_RIGHT);
	drawString(5, 15, "centering", FORMAT_CENTER);
	drawMatrix(19-TEST_MATRIX.size_y+1, 5, &TEST_MATRIX);
	drawGround(20, 1, 78);
	
	refresh();

	sleep(5);

	rs_endwin();
	
	return 0;
}
