//Used to test both the Buffer and Player class, has some example code for how to interact with functions!


#include <iostream>

#include "Buffer.h"
#include "Player.h"


using namespace std;
int main() {
	Buffer buffer;
	buffer.load_data("save_data.txt");
	cout << buffer.current_year() << endl;
	buffer.current_year_set(2000);
	//buffer.test_cout();
	buffer.add_entry("bob", "jefferson", 2010, false);
	//buffer.print_data("save_data.txt");

	vector<Player*> results;

	cout << "Search A:" << endl;
	buffer.search(results, "", "", "", 0, 12, false);
	for (auto x : results)
	{
		cout << *x;
	}
	cout << "Search B:" << endl;
	buffer.search(results, "", "", "a", 0, 0);
	for (auto x : results)
	{
		cout << *x;
	}
	int stats[8]{};
	buffer.statistics(stats);
	cout << "total: " << stats[0] << endl;
	cout << "paid for: " << stats[1] << endl;
	cout << "paid for u6: " << stats[2] << endl;
	cout << "paid for u8: " << stats[3] << endl;
	cout << "paid for u10: " << stats[4] << endl;
	cout << "paid for u12: " << stats[5] << endl;
	cout << "paid for u14: " << stats[6] << endl;
	cout << "paid for u17: " << stats[7] << endl;

	buffer.new_session(2000);
	buffer.test_cout();

	return 0;
 }