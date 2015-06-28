#include <stdio.h>
#include "game_levels.h"
#define LEVEL_NUM 3

LEVEL_P LEVELS[LEVEL_NUM] = {
	{0, 5},
	{0, 10},
	{500, 12}
};

LEVEL_P getLevelParameter(int level){
	LEVEL_P tmp;
	
	switch( level ){
		case LEVEL_EASY:
			return LEVELS[0];
		case LEVEL_NORMAL:
			return LEVELS[1];
		case LEVEL_HARD:
			return LEVELS[2];
	}
	
	return LEVELS[0];
}
