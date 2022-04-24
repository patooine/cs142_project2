#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Buffer.h"

using namespace std;

void Buffer::load_data(con_strr file_name) {
	Player entry;
    players.empty();
	ifstream in(file_name);
	while (in >> entry) {
		in.ignore(); //ignores the following \n
		players[entry.first_name() + " " + entry.last_name()] = entry;
	};
}

void Buffer::print_data(con_strr file_name) {
	ofstream out(file_name);
	for (std::pair<std::string, Player> x : players) {
		out << x.second << endl;
	}
}

bool Buffer::add_entry(con_strr first_name, con_strr last_name, const int& birth_year, const bool& status) {
	int category;
	int age = current_year_ - birth_year;
	if (age > 16) return false;
	else if (age > 13) category = 17;
	else if (age > 11) category = 14;
	else if (age > 9) category = 12;
	else if (age > 7) category = 10;
	else if (age > 5) category = 8;
	else if (age > 3) category = 6;
	else return false;
	players[(first_name + " " + last_name)] = Player{first_name, last_name, birth_year, category, status};
	return true;
}

void Buffer::search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, const int& birth_year, const int& category, const bool& status) {
	for (pair<const string, Player>& x : players) {
		results.clear();
		bool match = true; //the entry is assumed to match then checked if it doesn't
		if ((first_name != "") && (x.second.first_name() != first_name)) match = false;
		if ((last_name != "") && (x.second.last_name() != last_name)) match = false;
		if ((birth_year != 0) && (x.second.birth_year() != birth_year)) match = false;
		if ((category != 0) && (x.second.category() != category)) match = false;
		if ((x.second.status() != status)) match = false;
		if (match) results.push_back(&(x.second));
	}
}

void Buffer::search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, const int& birth_year, const int& category) {
	for (pair<const string, Player>& x : players) {
		results.clear();
		bool match = true; //the entry is assumed to match then checked if it doesn't
		if ((first_name != "") && (x.second.first_name() != first_name)) match = false;
		if ((last_name != "") && (x.second.last_name() != last_name)) match = false;
		if ((birth_year != 0) && (x.second.birth_year() != birth_year)) match = false;
		if ((category != 0) && (x.second.category() != category)) match = false;
		if (match) results.push_back(&(x.second));
	}
}