#ifndef _Buffer_h_
#define _Buffer_h_

#include <map>
#include <vector>

#include "Player.h"

using con_strr = const std::string&;

class Buffer
{
public:
	void load_data(con_strr file_name);
	void print_data(con_strr file_name);
	bool add_entry(con_strr first_name, con_strr last_name, const int& birth_year, const bool& status);

	void search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, const int& birth_year, const int& category, const bool& status);
	void search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, const int& birth_year, const int& category);

	//setters & getters
	int current_year() { return current_year_; }
	void current_year_set(int year) { current_year_ = year; }

private:
	std::map<std::string, Player> players;
	int current_year_;
};

#endif