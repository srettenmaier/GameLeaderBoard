#include <vector>
#include <string>

#ifndef _player_H_                   
#define _player_H_

using namespace std;

class Player{
public:
int score;
int id;
string name;
Player(int _id, string _name);
vector<Player *> friends_list;
//~Player();
};

#endif