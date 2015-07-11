#include <stdio.h>
#include <unistd.h>
#include "highScore.h"

#define SCORE_FILE_NAME "score"

int main(int argc, char argv[]){
	int opt;
	int score, flag;
	
	
	flag = 0;
	while( (opt = getopt(argc, argv, "rs:")) != -1 ){
		
		if( flag != 0 ){
			fprintf(stderr, "オプション[-s, -r]は同時に指定することができません\n");
			return 0;
		}
			
		switch( opt ) {
			case 'r':
				flag = 1;
				score = 0;
				break;
			case 's':
				flag = 1;
				score = atoi(optarg);
				break;
		}
	}
	
	if( flag == 0 ){
		fprintf(stderr, "オプション[-s, -r]を指定してください\n");
		return 0;
	}
	
	setHighScore(score);
	saveHighScore(SCORE_FILE_NAME);
	
	return 0;
}		
