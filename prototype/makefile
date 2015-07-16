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
test_gameScreen : test_gameScreen.o matrix.o drawScreen.o highScore.o gameScreen.o game_bump.o game_drawScreen.o game_field.o game_jumping.o game_obstacle.o getCommand.o
	cc -o test_gameScreen test_gameScreen.o matrix.o drawScreen.o highScore.o gameScreen.o game_bump.o game_drawScreen.o game_field.o game_jumping.o game_obstacle.o getCommand.o -lncurses
test_gameScreen.o : test_gameScreen.c drawScreen.h gameScreen.h matrix.h
	cc -c test_gameScreen.c
#
test_matrix : test_matrix.o matrix.o drawScreen.o 
	cc -o test_matrix test_matrix.o matrix.o drawScreen.o -lncurses
test_matrix.o : test_matrix.c matrix.h drawScreen.h
	cc -c test_matrix.c
#
test_menuScreen : test_menuScreen.o menuScreen.o
	cc -o test_menuScreen test_menuScreen.o menuScreen.o drawScreen.o matrix.o -lncurses
test_menuScreen.o : test_menuScreen.c menuScreen.h
	cc -c test_menuScreen.c
#
#main
run_savannah : run_savannah.o drawScreen.o highScore.o menuScreen.o matrix.o gameScreen.o game_bump.o game_field.o game_drawScreen.o game_obstacle.o game_jumping.o getCommand.o
	cc -o run_savannah run_savannah.o drawScreen.o highScore.o menuScreen.o matrix.o gameScreen.o game_bump.o game_field.o game_drawScreen.o game_obstacle.o game_jumping.o getCommand.o -lncurses
run_savannah.o : run_savannah.c matrix.h menuScreen.h gameScreen.h highScore.h
	cc -c run_savannah.c
#
#modules
drawScreen.o : drawScreen.c drawScreen.h
	cc -c drawScreen.c
highScore.o : highScore.c highScore.h
	cc -c highScore.c
gameScreen.o : gameScreen.c matrix.h gameScreen.h drawScreen.h game_field.h game_drawScreen.h game_obstacle.h game_jumping.h game_bump.h highScore.h getCommand.h
	cc -c gameScreen.c
game_drawScreen.o : game_drawScreen.c matrix.h drawScreen.h gameScreen.h game_field.h game_drawScreen.h
	cc -c game_drawScreen.c
game_field.o : game_field.c game_field.h matrix.h
	cc -c game_field.c
game_obstacle.o : game_obstacle.c game_obstacle.h matrix.h
	cc -c game_obstacle.c
game_jumping.o : game_jumping.c gameScreen.h game_jumping.h
	cc -c game_jumping.c
game_bump.o : game_bump.c matrix.h gameScreen.h game_field.h game_jumping.h
	cc -c game_bump.c
matrix.o : matrix.c matrix.h
	cc -c matrix.c
getCommand.o : getCommand.c getCommand.h drawScreen.h matrix.h
	cc -c getCommand.c
menuScreen.o : menuScreen.c matrix.h drawScreen.h menuScreen.h
	cc -c menuScreen.c
#
#tools
resetScore : resetScore.o highScore.o
	cc -o resetScore resetScore.o highScore.o
resetScore.o : resetScore.c highScore.h
	cc -c resetScore.c
#
#release
release_dir = ../release
release : run_savannah.o drawScreen.o highScore.o menuScreen.o matrix.o gameScreen.o game_bump.o game_field.o game_drawScreen.o game_obstacle.o game_jumping.o getCommand.o title.mat player.mat player_lose.mat obs1.mat obs2.mat obs3.mat score
#	フォルダ作成
	if [ -d $(release_dir) ]; then rm -rf $(release_dir); fi
	mkdir $(release_dir)
#	ファイル作成
	cc -o $(release_dir)/run_savannah run_savannah.o drawScreen.o highScore.o menuScreen.o matrix.o gameScreen.o game_bump.o game_field.o game_drawScreen.o game_obstacle.o game_jumping.o getCommand.o -lncurses
	cp title.mat $(release_dir)/title.mat
	cp player.mat $(release_dir)/player.mat
	cp player_lose.mat $(release_dir)/player_lose.mat
	cp obs1.mat $(release_dir)/obs1.mat
	cp obs2.mat $(release_dir)/obs2.mat
	cp obs3.mat $(release_dir)/obs3.mat

