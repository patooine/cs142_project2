// PhoneBookList.cpp

#include "PhoneBookList.h"

#include <fstream>
using std::ifstream;
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
#include <map>
using std::pair;
#include <string>
using std::string;

void PhoneBookList::update_current_entry(
        const PhoneBookEntry & new_data)
{
    itr_current_entry_->second.update(new_data);

    string new_name = new_data.name;
    if (!new_name.empty()
        && new_name != itr_current_entry_->first) {
        // A new name was given and it is different from the current
        // key, so the entry must be reinserted using the new name as
        // the key.
        auto result =
            m_entries_.insert({new_name,
                              itr_current_entry_->second});
        m_entries_.erase(itr_current_entry_);
        itr_current_entry_ = result.first;
    }
}

void PhoneBookList::read_file(const std::string & file_name)
{
    ifstream ifs(file_name);
    if (!ifs) // no file -- one will be created when write_file is called
        return;

    int num_entries;
    ifs >> num_entries;
    ifs.get(); // \n
    for (int i = 0; i < num_entries; i++) {
        PhoneBookEntry new_entry;
        ifs >> new_entry;
        // m_entries[new_entry.name] = new_entry;
        m_entries_.insert(m_entries_.end(),
                          {new_entry.name, new_entry});
    }
    itr_current_entry_ = m_entries_.begin();
}

void PhoneBookList::write_file(const std::string & file_name) const
{
    cout << "Saving not yet implemented\n";
}

