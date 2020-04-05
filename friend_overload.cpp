//
// Created by ryan on 07.03.20.
//
#include "friend_overload.h"
#include <iostream>


int main(){
    Coord coordinate(3, 12);
    Coord coordinate2(12, 24);
    Coord intersection = coordinate + coordinate2;
    std::cout << intersection;
    return 0;
}