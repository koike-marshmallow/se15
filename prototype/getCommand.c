#include <stdio.h>
#include <string.h>
#include <ncurses.h>
#include "matrix.h"
#include "drawScreen.h"
#include "getCommand.h"

#define GC_STRBUF_LEN 128

char GC_STRBUF1[GC_STRBUF_LEN];
char GC_STRBUF2[GC_STRBUF_LEN];

void printCommand(int y, int x, int format, CLIST list[], int list_len){
	int i;
	
	GC_STRBUF2[0] = '\0';
	
	for( i=0; i<list_len; i++){
		sprintf(GC_STRBUF1, " [%c]:%s", list[i].ch, list[i].str);
		strncat(GC_STRBUF2, GC_STRBUF1, GC_STRBUF_LEN);
	}
	
	drawString(y, x, GC_STRBUF2, format);
}


int getCommand(CLIST list[], int list_len){
	int i, inp;
	
	while( 1 ){
		inp = getch();
		
		for( i=0; i<list_len; i++){
			if( inp == list[i].ch ){
				return inp;
			}
		}
	}
	
	return -1;
}	
