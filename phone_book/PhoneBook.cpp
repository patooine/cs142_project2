// PhoneBook.cpp

#include "PhoneBook.h"

using namespace std;

void PhoneBook::run()
{
    entry_list_.read_file(cs_file_name);
    bool done = false;
    while (!done) {
        display_entry_and_menu();
        cout << "choice: ";
        char command;
        cin >> command;
        cin.get(); // new line char
        execute(command, done);
        cout << endl;
    }
}

void PhoneBook::display_entry_and_menu() const {
    string long_separator(50, '-');
    string short_separator(8, '-');

    system(clear_command);

    entry_list_.display_current_entry();

    cout << long_separator << endl
         << "  next      search  edit    quit\n"
         << "  previous  add     delete\n"
         << short_separator << endl;
}

void PhoneBook::execute(char command, bool & done)
{
    switch (command) {
        case 'n': {
            entry_list_.move_to_next();
            break;
        }
        case 'p': {
            // Not yet implemented
            break;
        }
        case 'e': {
            if (entry_list_.empty())
                return;
            PhoneBookEntry new_data;
            cout << "(leave blank if no change needed)\n";
            cout << "new name: ";
            getline(cin, new_data.name);
            cout << "phone number: ";
            getline(cin, new_data.number);
            entry_list_.update_current_entry(new_data);
            break;
        }
        case 's': {
            cout << "name: ";
            string name;
            getline(cin, name);
            entry_list_.find(name);
            break;
        }
        case 'a': {
            PhoneBookEntry e;
            cout << "new name: ";
            getline(cin, e.name);
            cout << "phone number: ";
            getline(cin, e.number);
            entry_list_.add(e);
            break;
        }
        case 'd': {
            // Not yet implemented
            break;
        }
        case 'q': {
            entry_list_.write_file(cs_file_name);
            done = true;
            break;
        }
    }
}

