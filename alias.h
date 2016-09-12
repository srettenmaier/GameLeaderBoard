#include <vector>
#include <string>

#ifndef _alias_H_                   
#define _alias_H_

using namespace std;

class Alias{
public:
string player_name;
int id;
string ign;
Alias(int _id, string _ign, string _player_name);
int score = 0;
//~Alias();
};

#endif