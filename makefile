all: main

player.o: player.h player.cpp
	g++ -std=c++11 -c -g player.cpp

game.o: game.h game.cpp
	g++ -std=c++11 -c -g game.cpp
	
alias.o: alias.h alias.cpp
	g++ -std=c++11 -c -g alias.cpp

victory.o: victory.h victory.cpp
	g++ -std=c++11 -c -g victory.cpp
	
database.o: database.h database.cpp
	g++ -std=c++11 -c -g database.cpp
	
main: main.cpp player.o game.o alias.o victory.o database.o 
	g++ -std=c++11 main.cpp player.o game.o alias.o victory.o database.o
