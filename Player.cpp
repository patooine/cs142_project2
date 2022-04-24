#include "Player.h"
using namespace std;

void Player::set_category(const int& new_category) {
	switch (new_category) {
	case 6:
		u = u6;
		break;
	case 8:
		u = u8;
		break;
	case 10:
		u = u10;
		break;
	case 12:
		u = u12;
		break;
	case 14:
		u = u14;
		break;
	case 17:
		u = u17;
		break;
	}
}


const int Player::category() const {
	switch (u) {
	case u6:
		return 6;
	case u8:
		return 8;
	case u10:
		return 10;
	case u12:
		return 12;
	case u14:
		return 14;
	case u17:
		return 17;
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
	out << p.nameFirst_ << endl;
	out << p.nameLast_ << endl;
	out << p.year_ << endl;
	out << p.category() << endl;
	out << p.register_ << endl;


	return out;
}