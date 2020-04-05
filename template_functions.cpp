//
// Created by ryan on 22.03.20.
//

#include "object.hpp"
#include "templates.h"

int Object_types::Object::objectCount{0};

int main(){
    Object_types::Point myPoint{0,10};
    Object_types::Point myPoint2{10,10};
    Object_types::Point c =  ryan_stl::my_max(myPoint,myPoint2);
    Object_types::Point d = ryan_stl::my_max2(myPoint, myPoint2);
    Object_types::Point e = std::max(myPoint, myPoint2);


    Object_types::Object my_object1{};
    Object_types::Object my_object2{};
    ryan_stl::my_max(my_object1,my_object2);
}