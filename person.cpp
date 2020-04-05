//
// Created by ryan on 28.02.20.
//
#include "person.hpp"
#include <iostream>
void print(const Person& p)
{
    std::cout << p.getID() << ": "
              << p.getName() << ": "
              << p.getValue() << '\n';
}
int main()
{
    Person p1{"Sarah"};
    Person p2{"Tim", 33};
    print(p1);
    print(p2);

    Person p3 = p1;
    Person p4{p1};
    p1 = p2;


    print(p3);
    print(p4);
}