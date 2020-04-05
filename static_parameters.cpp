//
// Created by ryan on 29.02.20.
//

#include "object.hpp"
#include <iostream>
#include <vector>
#include <array>

using namespace Object_types;

int objectCount{ 0 };


int  d{0};

static int ns_var{0};

Object fixture(){
    BoundingBox b = BoundingBox(Point(1.0 ,0.0), Point(1.0,1.0),Point(0.0,0.0), Point(0.0,1.0));
    ObjectType my_type = ObjectType::Vehicle;
    Object s = Object(b, my_type);
    return s;
}

Object return_object(){
    Object myobj = fixture();
    Object obj2 = fixture();
    std::cout << Object::getCount()<< std::endl;
    return obj2;
}


int main(){

    //std::array<Object,200>  ObjectList{};
    std::vector<Object> Objectvec;
    //want to initialize with 200 default "safe objects"

    Object ret_obj = return_object();
    std::cout << Object::getCount()<< std::endl;
    Objectvec.push_back(ret_obj);
    std::cout << Object::getCount()<< std::endl;
    Object test = fixture();
    std::cout << Object::getCount() << std::endl;
    Object test2 = fixture();
    std::cout << Object::getCount() << std::endl;
    Object test3 = fixture();

    std::cout << Object::getCount() << std::endl;   // static variable can be accessed from any object,

    int x = 42;
    int y = x;
    y *= 2;
}

