#include "matrix.h"
#include "gameScreen.h"
#include "game_jumping.h"

int JUMP_FLAG;
int JUMP_WAIT;

void initJumpFlag(void){
	JUMP_FLAG = 0;
	JUMP_WAIT = 0;
}

void setJumpFlag(void){
	if( JUMP_FLAG == 0 ){
		JUMP_FLAG = 1;
	}
}


void jumpPlayer(void){
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
