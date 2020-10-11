//
// Created by ryan on 22.03.20.
//

#include <iostream>
#include <set>
int main() {
  std::set<int> coll{1, 2, 3, 5, 7, 9, 11, 13, 17};
  // list with numbers
  //    coll.push_back(42);  //error, push_back not supported for set container,
  //    no position
  coll.insert(42); // insert one element (if not in yet)
  coll.insert(99); // insert one element (if not in yet)
  coll.insert(99); // does not insert (no duplicates allowed)

  for (int elem : coll) {
    std::cout << elem << '\n';
  } // print all elements with range-based for loop
  // coll.insert(coll.begin(), {0, 8, 15});
  coll.insert({0, 8, 15}); // ERROR: positions not supported
                           // OK: inserts multiple elements (if not in yet)
  for (auto pos = coll.begin(); pos != coll.end(); ++pos) {
    std::cout << *pos << '\n';
  }
  auto pos = coll.find(9);
  if (pos != coll.end()) {
    coll.erase(9);
  }
  if (coll.end() == coll.begin()) {
    std::cout << "im empty bro" << std::endl;
  } else {
    std::cout << "size =" << coll.size() << std::endl;
  }
}
