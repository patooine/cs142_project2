# cs142_project2

## Design Info

### Buffer:
### Functions:
#### void buffer.load_data(string file_name)
When given a file name it takes in player entries and sends them to the map. (Needs player to have the >> operator, .first_name() getter, .last_name() getter)
#### void buffer.print_data(string file_name)
When given a file name it prints out player entries to the file. (Needs player to have the << operator)
#### int buffer.current_year()
Returns the current year value
#### void buffer.current_year_set(int year)
Sets the current year value to the year value
#### bool search(vector<Player*> results, string first_name, string last_name, string keyword, int birth_year, section category, bool status)
when provided with a vector of Player pointers it will fill the vector with Player entries that match the input info, leaving a string empty, int as 0, or section as none, with have the function not search for those. The function is overloaded to not require the status, not including the status will have the function not search for the status. returns false if nothing matches
#### bool add_entry(string first_name, string last_name, int birth_year, bool status)
when provided with the first and last name, birth year and status it adds a player entry to the map. It calculates the category using the current year. Returns false if the birth year puts them in outside of a category (Needs player to have a construct which takes: first_name, last_name, birth_year, category, status)
#### void test_cout()
outputs all of the map to cout, for testing purposes only!
#### void statistics(int* stats)
takes an array of int, length 8. inputs [0] as the total number of players, [1] as the total paid for, [2] as those in u6 paid for, [3] as those in u8 paid for, and so on
#### void new_session(int new_year)
sets the current year to the new year and clears the map

### Data:
#### map<string, Player> players;
Holds all the player entries, the key is the full name
#### int current_year_;
Holds the current year to calculate the category
