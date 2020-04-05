//
// Created by ryan on 07.03.20.
//

#ifndef PLAYGROUND_COORDINATE_H
#define PLAYGROUND_COORDINATE_H

#endif //PLAYGROUND_COORDINATE_H

#include <iostream>

class Coord {
private:
    int x;
    int y;
public:
    Coord() : x{0}, y{0} {
    }

    Coord(int new_x, int new_y) : x{new_x}, y{new_y} {
    }

    friend Coord operator+(Coord c1, Coord c2) {
        return Coord{c1.x + c2.x, c1.y + c2.y};
    }

    friend Coord operator-(Coord c1, Coord c2) {
        return Coord{c1.x - c2.x, c1.y - c2.y};
    }

    Coord operator-() const {
        return Coord{-x, -y};
    }

    void operator+=(Coord c) {
        *this = *this + c;
    }

    friend std::ostream &operator<<(std::ostream &strm,
                                    Coord c) {
        return strm << '(' << c.x << ',' << c.y << ')';
    }
};