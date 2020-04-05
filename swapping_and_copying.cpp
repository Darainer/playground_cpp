//
// Created by ryan on 07.03.20.
//
#include "RAII.h"

using namespace stringmaker;

void print_me_a_string(String& its_a_STRING ){
    std::cout << its_a_STRING << std::endl;
}



int main(){
    int t = 'fd';
    std::string ts = "fd";
    std::string d = "sssdfefe";
    String my_std{d};
    String s{"d"};
    String m {"send me to the destructor"};
    print_me_a_string(m);
    if (m==s){
        print_me_a_string(s);
    };
    String d2{};
    d2.swap(s);

}