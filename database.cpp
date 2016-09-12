#include "database.h"
#include <iostream>

Database::Database(vector<Game *> _games_list, vector<Player *> _player_list)
{
	games_list = _games_list;
	player_list = _player_list;
}

void Database::AddPlayer(int _id, string _name)
{
	Player * new_player = new Player(_id, _name);
	player_list.push_back(new_player);
}

void Database::AddGame(int _id, string _name)
{
	Game * new_game = new Game(_id, _name);
	games_list.push_back(new_game);
}

void Database::AddVictory(int g_id, int v_id, string v_name, int vpoints)
{
	Victory * victory = new Victory(v_id, v_name, vpoints);
	for (int i=0; i<games_list.size(); i++)
	{
		if (g_id == games_list[i]->id)
			games_list[i]->victory_list.push_back(victory);
	}
}

void Database::Plays(int p_id, int g_id, string p_ign)
{
	int playerIndex = 0;
	for(int i=0; i<player_list.size(); i++)
	{
		if(p_id == player_list[i]->id)
			playerIndex = i;
	}
	
	Alias * alias = new Alias(p_id, p_ign, player_list[playerIndex]->name);
	for(int i=0; i<games_list.size(); i++)
	{
		if (g_id == games_list[i]->id)
			games_list[i]->player_list.push_back(alias);
	}
}

void Database::AddFriends(int id1, int id2)
{
	int temp1 = 0;
	int temp2 = 0;
	for(int i=0; i<player_list.size(); i++)
	{
		if(id1 == player_list[i]->id)
			temp1 = i;
		if(id2 == player_list[i]->id)
			temp2 = i;
	}
	player_list[temp1]->friends_list.push_back(player_list[temp2]);
	player_list[temp2]->friends_list.push_back(player_list[temp1]);
}

void Database::WinVictory(int p_id, int g_id, int v_id)
{
	int gameIndex = 0;
	int aliasIndex = 0;
	int victoryIndex = 0;
	for(int i=0; i<games_list.size(); i++)
	{
		if(g_id == games_list[i]->id)
			gameIndex = i;
	}
	for(int j=0; j<games_list[gameIndex]->player_list.size(); j++)
	{
		if(p_id == games_list[gameIndex]->player_list[j]->id)
			aliasIndex = j;
	}
	for(int k=0; k<games_list[gameIndex]->victory_list.size(); k++)
	{
		if(v_id == games_list[gameIndex]->victory_list[k]->id)
			victoryIndex = k;
	}
	games_list[gameIndex]->victory_list[victoryIndex]->achievers_list.push_back(games_list[gameIndex]->player_list[aliasIndex]);
	games_list[gameIndex]->player_list[aliasIndex]->score += games_list[gameIndex]->victory_list[victoryIndex]->points;
}

void Database::FriendsWhoPlay(int p_id, int g_id)
{
	int playerIndex = 0;
	int gameIndex = 0;
	vector<string> friendsWhoPlay;
	for(int i=0; i<player_list.size(); i++)
	{
		if(p_id == player_list[i]->id)
			playerIndex = i;
	}
	for(int j=0; j<games_list.size(); j++)
	{
		if(g_id == games_list[j]->id)
			gameIndex = j;
	}
	for(int k=0; k<player_list[playerIndex]->friends_list.size(); k++)
	{
		for(int l=0; l<games_list[gameIndex]->player_list.size(); l++)
		{
				if(player_list[playerIndex]->friends_list[k]->id == games_list[gameIndex]->player_list[l]->id)
					friendsWhoPlay.push_back(player_list[playerIndex]->friends_list[k]->name);
		}
	}
	cout << "Friends of " << player_list[playerIndex]->name << " who play " << games_list[gameIndex]->name << ":" << '\n';
	for(int m=0; m<friendsWhoPlay.size(); m++)
	{
		cout << friendsWhoPlay[m] << '\n';
	}
}

void Database::ComparePlayers(int p1_id, int p2_id, int g_id)
{
	int gameIndex = 0;
	int a1Index = 0;
	int a2Index = 0;
	int p1Index = 0;
	int p2Index = 0;
	int p1check = 0;
	int p2check = 0;
	vector<char> p1vec;
	vector<char> p2vec;
	for(int i=0; i<games_list.size(); i++)
	{
		if(g_id == games_list[i]->id)
			gameIndex = i;
	}
	for(int j=0; j<games_list[gameIndex]->player_list.size(); j++)
	{
		if(p1_id == games_list[gameIndex]->player_list[j]->id)
			a1Index = j;
		if(p2_id == games_list[gameIndex]->player_list[j]->id)
			a2Index = j;
	}
	for(int k=0; k<player_list.size(); k++)
	{
		if(p1_id == player_list[k]->id)
			p1Index = k;
		if(p2_id == player_list[k]->id)
			p2Index = k;
	}
	cout << "Comparison between " << player_list[p1Index]->name << " and " << player_list[p2Index]->name << '\n';
	cout << "Victory" << "		" << player_list[p1Index]->name << "		" << player_list[p2Index]->name << '\n';
	for(int l=0; l<games_list[gameIndex]->victory_list.size(); l++)
	{ 
		for(int m=0; m<games_list[gameIndex]->victory_list[l]->achievers_list.size(); m++)
		{
			if(p1_id == games_list[gameIndex]->victory_list[l]->achievers_list[m]->id)
				++ p1check;
			if(p2_id == games_list[gameIndex]->victory_list[l]->achievers_list[m]->id)
				++ p2check;
		}
		if(p1check > 0)
			p1vec.push_back('y');
		else
			p1vec.push_back('n');
		if(p2check > 0)
			p2vec.push_back('y');
		else
			p2vec.push_back('n');
		p1check = 0;
		p2check = 0;
	}
	for(int n=0; n<p1vec.size(); n++)
	{
		cout << games_list[gameIndex]->victory_list[n]->name << "		" << p1vec[n] << "		" << p2vec[n] << '\n';
	}
	cout << "Gamer point totals:	 " << player_list[p1Index]->name << " = " << games_list[gameIndex]->player_list[a1Index]->score << "	" << player_list[p2Index]->name << " = " << games_list[gameIndex]->player_list[a2Index]->score << '\n';
}

void Database::SummarizePlayer(int p_id)
{
	int playerIndex = 0;
	int gameplayCheck = 0;
	for(int i=0; i<player_list.size(); i++)
	{
		if(p_id == player_list[i]->id)
			playerIndex = i;
	}
	cout << "Friends:" << '\n';
	for(int j=0; j<player_list[playerIndex]->friends_list.size(); j++)
	{
		cout << player_list[playerIndex]->friends_list[j]->name << '\n';
	}
	cout << "Games Played:" << "	" << "Gamer Tag" << "	" << "Gamer Score" << '\n';
	for(int k=0; k<games_list.size(); k++)
	{
		int aliasIndex = 0;
		for(int l=0; l<games_list[k]->player_list.size(); l++)
		{
			if(p_id == games_list[k]->player_list[l]->id)
			{
				
				gameplayCheck ++;
			}
		}
		if(gameplayCheck > 0)
			cout << games_list[k]->name << "		" << games_list[k]->player_list[aliasIndex]->ign << "	" << games_list[k]->player_list[aliasIndex]->score << '\n';
	}
}

void Database::SummarizeGame(int g_id)
{
	int gameIndex = 0;
	for(int i=0; i<games_list.size(); i++)
	{
		if(g_id == games_list[i]->id)
			gameIndex = i;
	}
	cout << "Players who play " << games_list[gameIndex]->name << '\n';
	for(int j=0; j<games_list[gameIndex]->player_list.size(); j++)
	{
		cout << games_list[gameIndex]->player_list[j]->player_name << '\n';
	}
	cout << "Victory		 	Number of Victories" << '\n';
	for(int k=0; k<games_list[gameIndex]->victory_list.size(); k++)
	{
		cout << games_list[gameIndex]->victory_list[k]->name << "			" << games_list[gameIndex]->victory_list[k]->achievers_list.size() << '\n';
	}
}

void Database::SummarizeVictory(int g_id, int v_id)
{
	int gameIndex = 0;
	int vicIndex = 0;
	for(int i=0; i<games_list.size(); i++)
	{
		if(g_id == games_list[i]->id)
			gameIndex = i;
	}
	for(int j=0; j<games_list[gameIndex]->victory_list.size(); j++)
	{
		if(v_id == games_list[gameIndex]->victory_list[j]->id)
			vicIndex = j;
	}
	cout << "Players who have achieved the " << games_list[gameIndex]->victory_list[vicIndex]->name << " achievement" << '\n';
	for(int k=0; k<games_list[gameIndex]->victory_list[vicIndex]->achievers_list.size(); k++)
	{
		cout << games_list[gameIndex]->victory_list[vicIndex]->achievers_list[k]->player_name << '\n';
	}
	cout << "Percentage of players who have achieved the " << games_list[gameIndex]->victory_list[vicIndex]->name << " achievement" << '\n';
	cout << games_list[gameIndex]->victory_list[vicIndex]->achievers_list.size() << " out of " << games_list[gameIndex]->player_list.size() << '\n';
}

int Database::get_player_score(int p_id)
{
	int score = 0;
	for(int i=0; i<games_list.size(); i++)
	{
		for(int j=0; j<games_list[i]->player_list.size(); j++)
		{
			if(p_id == games_list[i]->player_list[j]->id)
				score += games_list[i]->player_list[j]->score;
		}
	}
	return score;
}

void Database::VictoryRanking()
{
	vector<Player *> sorted_players;
	for(int i=0; i<player_list.size(); i++)
	{
		player_list[i]->score = get_player_score(player_list[i]->id);
		sorted_players.push_back(player_list[i]);
	}
	for (int j = 0; j < sorted_players.size(); ++j)
	{
		for (int k = 0; k < sorted_players.size() - j - 1; ++k)
		{
			if (sorted_players[k]->score < sorted_players[k + 1]->score)

			{

				Player * temp = sorted_players[k];

				sorted_players[k] = sorted_players[k + 1];

				sorted_players[k + 1] = temp;

			}

		}
	}
	cout << "Players Sorted by Gamer Points:" << '\n';
	for(int l=0; l<sorted_players.size(); l++)
	{
		cout << sorted_players[l]->name << "	" << sorted_players[l]->score << '\n';
	}
}
//Database::~Database(){}