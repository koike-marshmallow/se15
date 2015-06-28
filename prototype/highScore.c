#include <stdio.h>
#include "highScore.h"

int HSCORE = 0;

int loadHighScore(char *fname){
	FILE *fp;
	int tmp;
	
	if( (fp = fopen(fname, "r")) == NULL ){
		return 1;
	}
	
	fscanf(fp, "%d", &tmp);
	HSCORE = tmp;
	
	fclose(fp);
	return 0;
}


int saveHighScore(char *fname){
	FILE *fp;
	
	if( (fp = fopen(fname, "w")) == NULL ){
		return 1;
	}
	
	fprintf(fp, "%d", HSCORE);
	
	fclose(fp);
	return 0;
}


void setHighScore(int s0){
	if( HSCORE < s0 ){
		HSCORE = s0;
	}
}


int getHighScore(){
	return HSCORE;
}


void resetHighScore(){
	HSCORE = 0;
}
