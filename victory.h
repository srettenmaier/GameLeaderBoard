#include "alias.h"
#include <vector>
#include <string>

#ifndef _victory_H_                   
#define _victory_H_

using namespace std;

class Victory{
public:
int id;
string name;
int points;
Victory(int _id, string _name, int _points);
vector<Alias *> achievers_list;
//~Victory();
};

#endif