//
// Created by ryan on 01.11.19.
//

#ifndef PLAYGROUND_FUNCTIONALOBJECTS_H
#define PLAYGROUND_FUNCTIONALOBJECTS_H

#include <numeric>
#include "vector"
#include "algorithm"

class gen{    // generator for integration function
public:
    gen(double start_value, double end_value, double increment_width)
    : x_start(start_value), x_end(end_value), increment(increment_width){
        int size = (x_end -x_start)/increment_width;
        fx(size);
    }
    double operator ()() { x_start += increment;
        return x_start * x_start;}
private:
    double x_start, x_end, increment,counter;
    std::vector<double> fx;
    double integrate(){
// integrate on (0,1)
        {
                    ( std::accumulate(fx.begin(),fx.end(),0.0/n));
        }

    };
};





class FunctionalObjects {

};


#endif //PLAYGROUND_FUNCTIONALOBJECTS_H
