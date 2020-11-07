//
// Created by ryan on 29.02.20.
//

#include "object.hpp"
#include <array>
#include <iostream>
#include <vector>

using namespace Object_types;

int Object::objectCount{0}; // initialize to zero on program startup

int d{0};

static int ns_var{0};

Object fixture() {
  BoundingBox b = BoundingBox(Point(1.0, 0.0), Point(1.0, 1.0), Point(0.0, 0.0),
                              Point(0.0, 1.0));
  ObjectType my_type = ObjectType::Vehicle;
  Object s = Object(b, my_type);
  return s;
}

Object return_object() {
  Object myobj = fixture();
  Object obj2 = fixture();
  std::cout << Object::getCount() << std::endl;
  return obj2;
} // myobj goes out of scope when return_object() returns obj2, calls destructor

void static_test(){
  // std::array<Object,200>  ObjectList{};
  std::vector<Object> Objectvec;
  // want to initialize with 200 default "safe objects"
  Object ret_obj = return_object();
  std::cout << Object::getCount() << std::endl;
  Objectvec.emplace_back(ret_obj);
  std::cout << Object::getCount() << std::endl;
  Object test = fixture();
  std::cout << Object::getCount() << std::endl;
  Object test2 = fixture();
  std::cout << Object::getCount() << std::endl;
  Object test3 = fixture();

  std::cout << Object::getCount()
            << std::endl; // static variable can be accessed from any object,
}

void ObjectList_test(){
  ObjectList mylist{};
};


int main() {
//static_test();
ObjectList_test();

}
