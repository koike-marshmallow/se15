struct command_list {
	char ch;
	char *str;
};
typedef struct command_list CLIST;


void printCommand(int y, int x, int format, CLIST list[], int list_len);
int getCommand(CLIST list[], int list_len);
