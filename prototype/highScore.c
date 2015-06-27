#include <stdio.h>
#include "highScore.h"

int SCORE = 0;

int loadHighScore(char *fname){
	FILE *fp;
	int tmp;
	
	if( (fp = fopen(fname, "r")) == NULL ){
		return 1;
	}
	
	fscanf(fp, "%d", &tmp);
	SCORE = tmp;
	
	fclose(fp);
	return 0;
}


int saveHighScore(char *fname){
	FILE *fp;
	
	if( (fp = fopen(fname, "w")) == NULL ){
		return 1;
	}
	
	fprintf(fp, "%d", SCORE);
	
	fclose(fp);
	return 0;
}


void setHighScore(int s0){
	if( SCORE < s0 ){
		SCORE = s0;
	}
}


int getHighScore(){
	return SCORE;
}


void resetHighScore(){
	SCORE = 0;
}
