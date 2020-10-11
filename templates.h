//
// Created by ryan on 07.03.20.
//
#include <algorithm>

#ifndef PLAYGROUND_TEMPLATES_H
#define PLAYGROUND_TEMPLATES_H
namespace ryan_stl {
    template<typename T>
    T my_max(T a, T b) {
        return b < a ? a : b;
    }

    template<typename T>
    T my_max2(T a, T b) {
        return std::max(a,b);
    }
    template<typename T>
    const T& my_max4(const T& a, const T& b,const T& c, const T& d)  {
        const T& first = std::max(a,b);
        const T& second = std::max(c,d);
        return std::max(first,second);
    }
}
#endif //PLAYGROUND_TEMPLATES_H