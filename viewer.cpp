// viewer.cpp

#include "viewer.h"
using namespace std;

void Viewer::display_main() {
    const string long_separator(80, '-');
    const string short_separator(8, '-');

    system(clear_command);

    cout << long_separator << endl;
    cout << "n: Start new season  |  s: Search for player   |  l: Print list of players" << endl;
    cout << "a: Add player        |  d: Display statistics  |  q: Save and exit" << endl;
    cout << long_separator << endl;

    if (!error_message_.empty()) {
        cout << "ERROR: " + error_message_ << endl;
        cout << long_separator << endl;
        error_message_.clear();
    }
}

void Viewer::display_search() {
    const string long_separator(80, '-');
    const string short_separator(8, '-');

    system(clear_command);

    cout << long_separator << endl;
    cout << "s: New search  |  p: Previous  |  n: Next   |  x: Exit search" << endl;
    cout << "e: Edit        |  l: Print list of players  |  q: Save and exit" << endl;
    cout << long_separator << endl;

    if (!error_message_.empty()) {
        cout << "ERROR: " + error_message_ << endl;
        cout << long_separator << endl;
        error_message_.clear();
    }
}

int main() {


	return 0;
}