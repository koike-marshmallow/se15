#include "matrix.h"
#include "gameScreen.h"
#include "game_jumping.h"

#define DEFAULT_JUMP_HEIGHT 6
#define DEFAULT_JUMP_INT 1

int JUMP_HEIGHT;
int JUMP_INT;

/* externされていない変数 */
int JUMP_FLAG;
int JUMP_WAIT;


void gjump_initFlag(void){
	JUMP_HEIGHT = DEFAULT_JUMP_HEIGHT;
	JUMP_INT = DEFAULT_JUMP_INT;
	JUMP_FLAG = 0;
	JUMP_WAIT = 0;
}


void gjump_flagSet(void){
	if( JUMP_FLAG == 0 ){
		JUMP_FLAG = 1;
	}
}


void gjump_jumpPlayer(void){
	if( JUMP_WAIT > 0 ){
		JUMP_WAIT--;
		return;
	}
	
	if( JUMP_FLAG == 1 ){
		PLAYER_JHEIGHT++;
		JUMP_WAIT = JUMP_INT;
		if( PLAYER_JHEIGHT >= JUMP_HEIGHT ){
			JUMP_FLAG = -1;
		}
	}else if( JUMP_FLAG == -1 ){
		PLAYER_JHEIGHT--;
		JUMP_WAIT = JUMP_INT;
		if( PLAYER_JHEIGHT <= 0 ){
			JUMP_FLAG = 0;
		}
	}
}
