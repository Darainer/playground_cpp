//
// Created by ryan on 28.02.20.
//
#ifndef PLAYGROUND_PERSON_HPP
#define PLAYGROUND_PERSON_HPP


#include <string>

class Person
{
private:
    static int nextID() {
        static int maxID{0};
        return ++maxID;
    }
    std::string name{""};
    int value{0};
    int id{nextID()};
public:
    Person(const std::string& n, int v = 0)
            : name{n}, value{v} {
    }
    // Copy constructor
    Person(const Person& p)
            : name{p.name}, value{p.value} {
    }
    std::string getName() const {
        return name;
    }
    int getValue() const {
        return value;
    }
    long getID() const {
        return id;
    }
};

#endif //PLAYGROUND_PERSON_HPP