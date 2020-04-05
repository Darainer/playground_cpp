//
// Created by ryan on 07.03.20.
//

#include <utility>
#include <iostream>
#ifndef PLAYGROUND_RAII_H
#define PLAYGROUND_RAII_H

#endif //PLAYGROUND_RAII_H

namespace stringmaker{

class String
{
    std::basic_string<char> str;
public:
    explicit String (std::string n = "im NULL")
            : str{n} {}
    //String(){}
    //String(char* s){
     //   str = s;}
    String& operator=(const String& s)
    {
        String temp(s); // Copy-constructor -- RAII
        temp.swap(*this); // Non-throwing swap

        return *this;
    }// Old resources released when destructor of temp is called.
    void swap(String & s) throw() // Also see the non-throwing swap idiom
    {
        std::swap(this->str, s.str);
    }
    friend std::ostream& operator<< (std::ostream& strm, const String& p) {
        return strm << p.str;
    }

    friend bool operator== (const String& lhs,
                            const String& rhs) {
        return lhs.str== rhs.str;
    }

};
}