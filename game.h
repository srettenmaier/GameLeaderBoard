#include "alias.h"
#include "victory.h"
#include <vector>
#include <string>

#ifndef _game_H_                   
#define _game_H_

using namespace std;

class Game{
public:
int id;
string name;
Game(int _id, string _name);
//Game();
vector<Alias *> player_list;
vector<Victory *> victory_list;
friend class Database;
//~Game();
};
#endif