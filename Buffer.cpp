#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Buffer.h"

using namespace std;

void Buffer::load_data(con_strr file_name) {
	Player entry;
	players.clear();
	ifstream in(file_name);
	in >> current_year_;
	in.ignore();
	while (in >> entry) {
		in.ignore(); //ignores the following \n
		players[entry.nameFirst() + " " + entry.nameLast()] = entry;
	};
}

void Buffer::save_data(con_strr file_name) {
	ofstream out(file_name);
	out << current_year_ << endl;
	for (std::pair<std::string, Player> x : players) {
		out << x.second;
	}
}

bool Buffer::print_data(con_strr file_name, std::vector<Player*>& results) {
	ofstream out(file_name);
	if (out << "Current Year: " << current_year_ << endl) return false;
	out << "Search Results: " << endl;
	for (const auto x : results) {
		out << *x;
	}
	return true;
}

bool Buffer::print_data(con_strr file_name) {
	ofstream out(file_name);
	if (out << "Current Year: " << current_year_ << endl) return false;
	for (int i = 6; i < 18; i += 2) {
		if (i == 16) i++;
		out << "U" << i << ":" << endl;
		for (std::pair<std::string, Player> x : players) {
			if (x.second.category() == i) out << x.second;
		}
	}
	return true;
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

bool Buffer::search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, con_strr keyword, const int& birth_year, const int& category, const bool& status) {
	results.clear();
	for (pair<const string, Player>& x : players) {
		bool match = true; //the entry is assumed to match then checked if it doesn't match
		if ((first_name != "") && (x.second.nameFirst() != first_name)) match = false;
		if ((last_name != "") && (x.second.nameLast() != last_name)) match = false;
		if ((keyword != "") && (x.first.find(keyword) == string::npos)) match = false;
		if ((birth_year != 0) && (x.second.year() != birth_year)) match = false;
		if ((category != 0) && (x.second.category() != category)) match = false;
		if ((x.second.registery() != status)) match = false;
		if (match) results.push_back(&(x.second));
	}
	if (results.size() > 0) return true;
	return false;
}

bool Buffer::search(std::vector<Player*>& results, con_strr first_name, con_strr last_name, con_strr keyword, const int& birth_year, const int& category) {
	results.clear();
	for (pair<const string, Player>& x : players) {
		bool match = true; //the entry is assumed to match then checked if it doesn't match
		if ((first_name != "") && (x.second.nameFirst() != first_name)) match = false;
		if ((last_name != "") && (x.second.nameLast() != last_name)) match = false;
		if ((keyword != "") && (x.first.find(keyword) == string::npos)) match = false;
		if ((birth_year != 0) && (x.second.year() != birth_year)) match = false;
		if ((category != 0) && (x.second.category() != category)) match = false;
		if (match) results.push_back(&(x.second));
	}
	if (results.size() > 0) return true;
	return false;
}

void Buffer::test_cout() {
	cout << "Map: \n";
	for (pair<const string, Player>& x : players)
	{
		cout << "entry:" << x.first << endl << x.second << endl;
	}
}

void Buffer::statistics(int* stats) {
	for (const pair<const string, Player>& x : players)
	{
		stats[0]++;
		switch (x.second.category()) {
		case 6:
			if (x.second.registery()) {
				stats[1]++;
				stats[2]++;
			}
			break;
		case 8:
			if (x.second.registery()) {
				stats[1]++;
				stats[3]++;
			}
			break;
		case 10:
			if (x.second.registery()) {
				stats[1]++;
				stats[4]++;
			}
			break;
		case 12:
			if (x.second.registery()) {
				stats[1]++;
				stats[5]++;
			}
			break;
		case 14:
			if (x.second.registery()) {
				stats[1]++;
				stats[6]++;
			}
			break;
		case 17:
			if (x.second.registery()) {
				stats[1]++;
				stats[7]++;
			}
			break;
		}
	}
}

void Buffer::new_session(int new_year) {
	current_year_ = new_year;
	players.clear();
}
