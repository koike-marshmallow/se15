#include <stdio.h>
#include "highScore.h"


int main(int argc, char *argv[]){
	int tmp, reset = 0;
	
	if( argc < 2 ){
		fprintf(stderr, "引数エラー\n");
		return 0;
	}
	
	if( argc > 2 && strcmp(argv[2], "reset") == 0 ){
		reset = 1;
	}
	
	tmp = loadHighScore(argv[1]);
	printf("loadHighScore >> RETURN : %d\n", tmp);
	if( tmp == 0 ){
		printf("loadHighScore >> load succeeded\n");
	}else{
		printf("loadHighScore >> load failed\n");
		return 1;
	}
	
	if( reset ) {
		printf("SCORE RESET\n");
		resetHighScore();
	}else{
	
		tmp = getHighScore();
		printf("SCORE = %d\n", tmp);
	
		printf("new score : ");
		scanf("%d", &tmp);
		setHighScore(tmp);
	
		tmp = getHighScore();
		printf("SCORE = %d\n", tmp);
	
	}
	
	tmp = saveHighScore(argv[1]);
	printf("saveHighScore >> RETURN : %d\n", tmp);
	if( tmp == 0 ){
		printf("saveHighScore >> save succeeded\n");
	}else{
		printf("saveHighScore >> save failed\n");
		return 1;
	}
	
	return 0;
}
