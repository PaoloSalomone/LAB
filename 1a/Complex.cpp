// Complex.cpp

#include "Complex.h"

int main() {

  Complex z1 (1,1);
  Complex z2 (2,2);
  
  z1.print();
  z2.print();
  
  Complex z3 = z1.operator+(z2);
  Complex z4 = z1.operator-(z2);
  Complex z5 = z1.operator*(z2);
  Complex z6 = z1.operator/(z2);
    
  z3.print();
  z4.print();
  z5.print();
  z6.print();
  
  //z.setRe(2);
  // z.setIm(2);
  //z.print();

  return 0;
}

