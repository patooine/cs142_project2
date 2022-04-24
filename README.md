# cs142_project2

## Design Info

### Buffer:
### Functions:
#### buffer.load_data(string file_name)
When given a file name it takes in player entries and sends them to the map. (Needs player to have the >> operator, .first_name() getter, .last_name() getter)
#### buffer.print_data(string file_name)
When given a file name it prints out player entries to the file. (Needs player to have the << operator)
#### buffer.current_year()
Returns the current year value
#### buffer.current_year_set(int year)
Sets the current year value to the year value
#### search(vector<Player*> results, string first_name, string last_name, int birth_year, section category, bool status)
when provided with a vector of Player pointers it will fill the vector with Player entries that match the input info, leaving a string empty, int as 0, or section as none, with have the function not search for those. The function is overloaded to not require the status, not including the status will have the function not search for the status.
#### add_entry(string first_name, string last_name, int birth_year, bool status)
when provided with the first and last name, birth year and status it adds a player entry to the map. It calculates the category using the current year. (Needs player to have a construct which takes: first_name, last_name, birth_year, category, status)
### Data:
#### map<string, Player> players;
Holds all the player entries, the key is the full name
#### int current_year_;
Holds the current year to calculate the category
### Main:



### Player: 
