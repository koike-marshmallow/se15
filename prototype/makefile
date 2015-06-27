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
test_gameScreen : test_gameScreen.o gameScreen.o drawScreen.o game_drawScreen.o game_field.o matrix.o
	cc -o test_gameScreen test_gameScreen.o gameScreen.o drawScreen.o game_drawScreen.o game_field.o matrix.o -lncurses
test_gameScreen.o : test_gameScreen.c drawScreen.h gameScreen.h
	cc -c test_gameScreen.c
#
test_matrix : test_matrix.o matrix.o drawScreen.o 
	cc -o test_matrix test_matrix.o matrix.o drawScreen.o -lncurses
test_matrix.o : test_matrix.c matrix.h drawScreen.h
	cc -c test_matrix.c
#
#modules
drawScreen.o : drawScreen.c drawScreen.h
	cc -c drawScreen.c
highScore.o : highScore.c highScore.h
	cc -c highScore.c
gameScreen.o : gameScreen.c gameScreen.h drawScreen.h game_drawScreen.h game_field.h
	cc -c gameScreen.c
game_drawScreen.o : game_drawScreen.c game_field.h drawScreen.h game_drawScreen.h gameScreen.h
	cc -c game_drawScreen.c
game_field.o : game_field.c game_field.h matrix.h
	cc -c game_field.c
matrix.o : matrix.c matrix.h
	cc -c matrix.c
