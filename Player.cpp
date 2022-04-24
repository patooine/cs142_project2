#include "Player.h"
using namespace std;

void Player::set_category(const int& new_category) {
	switch (new_category) {
	case 6:
		u = u6;
	case 8:
		u = u8;
	case 10:
		u = u10;
	case 12:
		u = u12;
	case 14:
		u = u14;
	case 17:
		u = u17;
	}
}


int Player::category() {
	switch (u) {
	case u6: 
		return '6';
	case u8:
		return '8';
	case u10:
		return '10';
	case u12:
		return '12';
	case u14:
		return '14';
	case u17:
		return '17';
	}
}

istream& operator>>(istream& in, Player& p) {
	getline(in, p.nameFirst_);
	getline(in, p.nameLast_);
	in >> p.year_;
	in.ignore();
	int stopGap;
	in >> stopGap;
	p.set_category(stopGap);
	in >> p.register_;
	return in;
}

ostream& operator<<(ostream& out, Player& p) {
	out << p.nameFirst_;
	out << p.nameLast_;
	out << p.year_;
	out << p.category();
	out << p.register_;


	return out;
}