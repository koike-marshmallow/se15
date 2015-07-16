#include <stdio.h>
#include <unistd.h>
#include "highScore.h"

char *SCORE_FILE_NAME = "score";

int main(int argc, char *argv[]){
	int opt;
	int score, flag;
	char *file_name;
	
	flag = 0;
	file_name = SCORE_FILE_NAME;
	while( (opt = getopt(argc, argv, "rs:f:")) != -1 ){
		
		if( flag != 0 && (opt == 's' || opt == 'r') ){
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
			case 'f':
				file_name = optarg;
				break;
		}
	}
	
	if( flag == 0 ){
		fprintf(stderr, "オプション[-s, -r]を指定してください\n");
		return 0;
	}
	
	setHighScore(score);
	if( saveHighScore(file_name) != 0 ){
		fprintf(stderr, "書き込みが正常に完了しませんでした\n");
	}
	
	return 0;
}		
