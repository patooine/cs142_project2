#include "Player.h"

using namespace std;

void set_catagory(const int& new_catagory) {
	switch (new_catagory) {
	case 6:
		catagory_ = u6;
	}
}

istream& operator >> (istream& in, Player &p) {
	in >> p.nameFirst_;
	in >> p.nameLast_;
	return in;
}

