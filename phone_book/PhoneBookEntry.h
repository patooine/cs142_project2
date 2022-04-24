// PhoneBookEntry.h

#ifndef _PhoneBookEntry_h_
#define _PhoneBookEntry_h_

#include <fstream>
#include <string>

class PhoneBookEntry
{
public:
    PhoneBookEntry() : name("no name"), number("no number") {}

    PhoneBookEntry(const std::string & name0,
                   const std::string & number0) :
        name(name0), number(number0) {}

    void update(const PhoneBookEntry & new_data);

    std::string name;
    std::string number;
};

inline void PhoneBookEntry::update(const PhoneBookEntry & new_data)
{
    if (!new_data.name.empty())
        name = new_data.name;
    if (!new_data.number.empty())
        number = new_data.number;
}

inline std::istream & operator>>(std::istream & in,
                                 PhoneBookEntry & e)
{
    getline(in, e.name);
    getline(in, e.number);
    return in;
}

inline std::ostream & operator<<(std::ostream & out,
                                 const PhoneBookEntry & e)
{
    out << e.name << std::endl
        << e.number << std::endl;
    return out;
}

#endif
