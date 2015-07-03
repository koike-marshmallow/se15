#include <stdio.h>
#include "menuScreen.h"

#define LIST_SIZE 5

MLIST mlist[LIST_SIZE] = {
	{1, "menu1", MSTATE_ENABLE, MVISIB_VISIBLE},
	{2, "menu3", MSTATE_ENABLE, MVISIB_VISIBLE},
	{3, "menu5", MSTATE_ENABLE, MVISIB_VISIBLE},
	{4, "menu7", MSTATE_ENABLE, MVISIB_VISIBLE},
	{5, "menu9", MSTATE_ENABLE, MVISIB_VISIBLE}
};


int main(void){
	int tmp;
	
	tmp = menuScreen(mlist, LIST_SIZE);
	printf("return = %d\n", tmp);
	
	return 0;
}
