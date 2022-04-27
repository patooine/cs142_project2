#ifndef _Buffer_h_
#define _Buffer_h_

#include <map>
#include <vector>

#include "Player.h"

using con_strr = const std::string&;

class Buffer
{
public:
	void load_data(con_strr file_name); //saves data from a file to the map
	void save_data(con_strr file_name); //saves data from the map to a save file (no format)
	void print_data(con_strr file_name, std::vector<Player*>& results); //saves the search data to a file
	void print_data(con_strr file_name);
	bool add_entry(con_strr first_name, con_strr last_name, const int& birth_year, const bool& status); //adds an entry to the map
	void test_cout(); //outputs the entire map to cout for testing
	void statistics(int* stats); //fills the given array with the total paid for for each category, overall, and total players
	//both search functions fill the results vector with pointers to players who matched the results
	bool search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, con_strr keyword, const int& birth_year, const int& category, const bool& status);
	bool search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, con_strr keyword, const int& birth_year, const int& category);

	void new_session(int new_year);

	//setters & getters
	const int current_year() const { return current_year_; }
	void current_year_set(int year) { current_year_ = year; }

private:
	std::map<std::string, Player> players;
	int current_year_;
};

#endif