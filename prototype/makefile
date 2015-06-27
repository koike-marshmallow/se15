#testers
test_drawScreen : test_drawScreen.o drawScreen.o
	cc -o test_drawScreen test_drawScreen.o drawScreen.o -lncurses
test_drawScreen.o : test_drawScreen.c drawScreen.h
	cc -c test_drawScreen.c
#
test_highScore : test_highScore.o highScore.o
	cc -o test_highScore test_highScore.o highScore.o
test_highScore.o : test_highScore.c highScore.h
	cc -c test_highScore.c
#
test_gameScreen : test_gameScreen.o gameScreen.o drawScreen.o
	cc -o test_gameScreen test_gameScreen.o gameScreen.o drawScreen.o -lncurses
test_gameScreen.o : test_gameScreen.c drawScreen.h gameScreen.h
	cc -c test_gameScreen.c
#
#modules
drawScreen.o : drawScreen.c drawScreen.h
	cc -c drawScreen.c
highScore.o : highScore.c highScore.h
	cc -c highScore.c
gameScreen.o : gameScreen.c gameScreen.h drawScreen.h
	cc -c gameScreen.c
