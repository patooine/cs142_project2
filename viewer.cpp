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

void Viewer::main_execute(char command, bool& done)
{
    switch (command) {
    case 'n': {
        cout << "Enter year: ";
        int year;
        cin >> year;
        cin.get();  // '\n'
        cout << "Confirm? (y/n) ";
        char confirm;
        while (confirm != 'y' && confirm != 'n') {
            cin >> confirm;
            cin.get();  // '\n'
        }
        if (confirm == 'y')
            buffer_.new_session(year);
        break;
    }

    case 'a': {
        string fname;
        string lname;
        int byear;
        bool status;
        cout << "First name: ";
        getline(cin, fname);
        cout << "Last name: ";
        getline(cin, lname);
        cout << "Birth year: ";
        cin >> byear;
        cout << "Registration status: ";
        cin >> status;
        cin.get();  // '\n'
        buffer_.add_entry(fname, lname, byear, status);
        break;
    }

    case 's': {
        cout << "Enter search criteria (press enter to skip criterion)." << endl;
        string lname;
        string fname;
        string keyword;
        int byear;
        bool status;
        int category;
        cout << "Last name: ";
        getline(cin, lname);
        cout << "First name: ";
        getline(cin, fname);
        cout << "Keyword";
        getline(cin, keyword);
        cout << "Birth year: ";
        cin >> byear;
        cout << "Registration status: ";
        cin >> status;
        cin.get();  // '\n'
        break;
    }

    case 'd': {

        break;
    }

    case 'l': {
        cout << "file name: ";
        string file_name;
        getline(cin, file_name);
        if (!buffer_.print_data(file_name))
            error_message_ = "Could not open " + file_name;
        break;
    }

    case 'q': {
        done = true;
        break;
    }
    }
}

void Viewer::search_execute(char command, bool& done) {

}

void Viewer::run() {
    buffer_.load_data("data.txt");
    bool done = false;
    while (!done) {
        display_main();

        cout << "command: ";
        char command;
        cin >> command;
        cin.get(); // '\n'

        main_execute(command, done);

        cout << endl;
    }
}

void Viewer::run_search() {

}