#include "player.h"
#include "game.h"
#include "alias.h"
#include <vector>
#include <string>

#ifndef _database_H_                   
#define _database_H_

using namespace std;

class Database{
public:
vector<Game *> games_list;
vector<Player *> player_list;
Database(vector<Game *> _games_list, vector<Player *> _player_list);
void AddPlayer(int _id, string _name);
void AddGame(int _id, string _name);
void AddVictory(int g_id, int v_id, string vname, int vpoints);
void Plays(int p_id, int g_id, string p_ign); 
void AddFriends(int id1, int id2);
void WinVictory(int p_id, int g_id, int v_id);
void FriendsWhoPlay(int p_id, int g_id);
void ComparePlayers(int p1_id, int p2_id, int g_id);
void SummarizePlayer(int p_id);
void SummarizeGame(int g_id);
void SummarizeVictory(int g_id, int v_id);
int get_player_score(int p_id);
void VictoryRanking();
//~Database();
};

#endif