
#ifndef _Player_h_
#define _player_h_

#include<string>
class Player {
	friend istream& operator >> (istream& in, Player p);
public:
	inline int year() { return year_; }
	inline string nameFirst() { return nameFirst_;}
	inline string nameLast() { return nameLast_; }
	inline string catagory()  { return catagory_; }
	inline bool registery() { return register; }
	inline void set_year(const int& new_year) { if (new_year != NULL) { year_ = new_year; } }
	inline void set_nameFirst(const std::string& new_name) { if (new_name != "") { nameFirst_ = new_name; } }
	inline void set_nameLast(const std::string& new_name) { if (new_name != "") { nameLast_ = new_name; } }
	inline void set_register(const bool& new_registery) {  register_ = new_registery;  }
	void set_catagory(const int& new_catagory);

private:
	int year_;
	string nameFirst_, nameLast_;
	enum catagory_
	{
		u6, u8, u10, u12, u14, u17 
	};
	bool register_;


}
#endif 