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
		players[entry.nameFirst() + " " + entry.nameLast()] = entry;
	};
}

void Buffer::print_data(con_strr file_name) {
	ofstream out(file_name);
	for (std::pair<std::string, Player> x : players) {
		out << x.second;
	}
}

bool Buffer::add_entry(con_strr first_name, con_strr last_name, const int& birth_year, const bool& status) {
	int category;
	int age = birth_year - current_year_;
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
	results.clear();
	for (pair<const string, Player>& x : players) {
		bool match = true; //the entry is assumed to match then checked if it doesn't match
		if ((first_name != "") && (x.second.nameFirst() != first_name)) match = false;
		if ((last_name != "") && (x.second.nameLast() != last_name)) match = false;
		if ((birth_year != 0) && (x.second.year() != birth_year)) match = false;
		if ((category != 0) && (x.second.category() != category)) match = false;
		if ((x.second.registery() != status)) match = false;
		if (match) results.push_back(&(x.second));
	}
}

void Buffer::search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, const int& birth_year, const int& category) {
	results.clear();
	for (pair<const string, Player>& x : players) {
		bool match = true; //the entry is assumed to match then checked if it doesn't match
		if ((first_name != "") && (x.second.nameFirst() != first_name)) match = false;
		if ((last_name != "") && (x.second.nameLast() != last_name)) match = false;
		if ((birth_year != 0) && (x.second.year() != birth_year)) match = false;
		if ((category != 0) && (x.second.category() != category)) match = false;
		if (match) results.push_back(&(x.second));
	}
}

void Buffer::test_cout() {
	for (pair<const string, Player>& x : players)
	{
		cout << "entry:" << x.first << endl << x.second << endl;
	}
}