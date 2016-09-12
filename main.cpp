#include "player.h"
#include "game.h"
#include "alias.h"
#include "database.h"
#include "victory.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
	vector<Game *> games;
	vector<Player *> players;
	Database * dbTest = new Database(games, players);
	dbTest->AddPlayer(200, "steve");
	dbTest->AddPlayer(300, "chris");
	dbTest->AddPlayer(400, "jacob");
	dbTest->AddPlayer(500, "michael");
	dbTest->AddPlayer(600, "orlando");
	dbTest->AddFriends(200, 300);
	dbTest->AddFriends(200, 400);
	dbTest->AddFriends(200, 500);
	dbTest->AddFriends(200, 600);
	dbTest->AddGame(2000, "CoD");
	dbTest->AddGame(3000, "DOTA 2");
	dbTest->AddGame(4000, "SSBM");
	dbTest->AddVictory(2000, 1, "nuke", 1000);
	dbTest->AddVictory(2000, 2, "ac130", 500);
	dbTest->AddVictory(2000, 3, "chopper", 500);
	dbTest->AddVictory(2000, 4, "n00b", 100);
	dbTest->AddVictory(2000, 5, "troll", 50);
	dbTest->AddVictory(3000, 1, "a", 50);
	dbTest->AddVictory(3000, 2, "b", 100);
	dbTest->AddVictory(3000, 3, "c", 150);
	dbTest->AddVictory(3000, 4, "d", 200);
	dbTest->AddVictory(4000, 1, "a", 50);
	dbTest->AddVictory(4000, 2, "b", 100);
	dbTest->AddVictory(4000, 3, "c", 150);
	dbTest->Plays(200, 2000, "squeeze03");
	dbTest->Plays(300, 2000, "its_chrisx");
	dbTest->Plays(400, 2000, "prisonmike");
	dbTest->Plays(500, 2000, "mikehugedeck");
	dbTest->Plays(600, 2000, "odelta");
	dbTest->Plays(200, 3000, "cohnjena");
	dbTest->Plays(200, 4000, "modeg");
	dbTest->WinVictory(200, 2000, 1);
	dbTest->WinVictory(200, 2000, 2);
	dbTest->WinVictory(200, 2000, 4);
	dbTest->WinVictory(200, 2000, 5);
	dbTest->WinVictory(300, 2000, 1);
	dbTest->WinVictory(300, 2000, 2);
	dbTest->WinVictory(300, 2000, 3);
	dbTest->WinVictory(200, 3000, 1);
	dbTest->WinVictory(200, 3000, 3);
	dbTest->WinVictory(200, 4000, 2);
	dbTest->WinVictory(200, 4000, 3);
	dbTest->WinVictory(400, 2000, 1);
	dbTest->FriendsWhoPlay(300, 2000);
	dbTest->ComparePlayers(200, 300, 2000);
	dbTest->SummarizePlayer(200);
	dbTest->SummarizeGame(2000);
	dbTest->SummarizeVictory(2000, 1);
	dbTest->VictoryRanking();
}