#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include "drawScreen.h"
#include "gameScreen.h"


int main(void){
	int tmp;
	srand((unsigned)time(NULL));
	
	tmp = gameScreen(SPD_INIT, SCR_INIT);
	printf("spd = %d, scr = %d, RET = %d\n", 
		SPD_INIT, SCR_INIT, tmp);
	return 0;
}
