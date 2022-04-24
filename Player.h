
#ifndef _Player_h_
#define _Player_h_

#include<iostream>
#include<string>
class Player {
public:
	Player(std::string firstName, std::string lastName, int year, int catagory, bool registry) : nameFirst_(firstName), nameLast_(lastName), year_(year), register_(registry) { set_category(catagory); }
	Player() :nameFirst_(""), nameLast_(""), year_(-1), register_(false) { set_category(6); };
	friend std::istream& operator >> (std::istream& in, Player& p);
	friend std::ostream& operator<<(std::ostream& out, Player& p);
	//friend enum category_ parse_category(const int& new_catagory);

	inline int year() { return year_; }
	inline std::string nameFirst() { return nameFirst_; }
	inline std::string nameLast() { return nameLast_; }
	int category();
	inline bool registery() { return register_; }
	inline void set_year(const int& new_year) { if (new_year != NULL) { year_ = new_year; } }
	inline void set_nameFirst(const std::string& new_name) { if (new_name != "") { nameFirst_ = new_name; } }
	inline void set_nameLast(const std::string& new_name) { if (new_name != "") { nameLast_ = new_name; } }
	inline void set_register(const bool& new_registery) { register_ = new_registery; }
	void set_category(const int& new_catagory);

private:
	enum category_
	{
		u6, u8, u10, u12, u14, u17
	};
	int year_;
	std::string nameFirst_, nameLast_;
	category_ u;
	bool register_;
};
#endif