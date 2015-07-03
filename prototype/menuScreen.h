#define MSTATE_ENABLE 9001
#define MSTATE_DISABLE 9002
#define MVISIB_VISIBLE 9003
#define MVISIB_INVISIBLE 9004

struct menu_list{
	int no;
	char *label;
	int state;
	int visible;
};
typedef struct menu_list MLIST;

int menuScreen(MLIST list[], int mlist_num);
