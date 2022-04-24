// PhonebookList.h

#include <iostream>
#include <map>
#include <string>

#include "PhoneBookEntry.h"

class PhoneBookList
{
public:
    PhoneBookList() : itr_current_entry_(m_entries_.end()) {}

    void add(const PhoneBookEntry & e);
    void display_current_entry() const;
    void move_to_next();
    void update_current_entry(const PhoneBookEntry & new_data);
    void find(const std::string & name);
    bool empty() const { return m_entries_.empty(); }
    void read_file(const std::string & file_name);
    void write_file(const std::string & file_name) const;

private:
    std::map<std::string, PhoneBookEntry> m_entries_;
    std::map<std::string, PhoneBookEntry>::iterator
        itr_current_entry_;
};

inline void PhoneBookList::add(const PhoneBookEntry & e)
{
// Simple but requires two searches:
//    m_entries_[e.name] = e;
//    itr_current_entry_ = m_entries_.find(e.name);

    auto result = m_entries_.insert({e.name, e});
    itr_current_entry_ = result.first;

// More verbose insertion:
//        m_entries_.insert(
//            std::pair<std::string, PhoneBookEntry>(e.name, e)));
}

inline void PhoneBookList::display_current_entry() const
{
    if (m_entries_.empty())
        return;
    std::cout << itr_current_entry_->second;
}

inline void PhoneBookList::move_to_next()
{
    if (m_entries_.empty())
        return;
    ++itr_current_entry_;
    if (itr_current_entry_ == m_entries_.end())
        itr_current_entry_ = m_entries_.begin();
}

inline void PhoneBookList::find(const std::string & name)
{
    auto itr = m_entries_.find(name);
    if (itr != m_entries_.end())
        itr_current_entry_ = itr;
}
