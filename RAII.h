//
// Created by ryan on 07.03.20.
//

#include <iostream>
#include <utility>
#ifndef PLAYGROUND_RAII_H
#define PLAYGROUND_RAII_H

namespace stringmaker {

class String {
  std::basic_string<char> str;

public:
  explicit String(std::string n = "im NULL")
      : str{n} {} // Use explicit because we want to prevent any invocation of
                  // constructor with implicitly convertable types which would cause a
                  // compiler error see AUTOSAR A12-1-4
  // String(){}
  // String(char* s){
  //   str = s;}
  String &operator=(const String &s) {
    String temp(s);   // Copy-constructor -- RAII
    temp.swap(*this); // Non-throwing swap

    return *this;
  } // Old resources released when destructor of temp is called.
  void swap(String &s) throw() // Also see the non-throwing swap idiom
  {
    std::swap(this->str, s.str);
  }
  friend std::ostream &operator<<(std::ostream &strm, const String &p) {
    return strm << p.str;
  }

  friend bool operator==(const String &lhs, const String &rhs) {
    return lhs.str == rhs.str;
  }
};
} // namespace stringmaker

#endif // PLAYGROUND_RAII_H