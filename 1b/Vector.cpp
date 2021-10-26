// Lab_1b_main.cpp

#include "Vector.h"

int main() {

//Vector definition
vector v1 (2,3,4,*"cart");
vector v2 (1,1,1,*"cart");

//Vector attributes
std::cout << "v1 module is =" << v1.mag()<< std::endl;

//Operations with vectors
vector v3 = v1.operator+(v2);
v1.operator+=(v2);
//v1.print();
v1.operator*(3);

std::cout << "Angle between v1 & v2 is =" << angle(v1,v2) <<"rad"<< std::endl;

  return 0;
}

