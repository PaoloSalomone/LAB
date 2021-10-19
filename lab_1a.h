// Complex.h

#include <iostream>
using namespace std;

class Complex {
  public:
    // constructors
    Complex();
    Complex(double x,double y);
    Complex(const Complex& complex);


    //setters
    void setRe (double re); 
    void setIm (double im); 

    //getters
    double re();
    double im();
    double mag(); 
    double phase();

    // Operators ??
    Complex operator+ (const Complex& rhs) const;
    Complex operator- (const Complex& rhs) const;
    Complex operator* (const Complex& rhs) const;
    Complex operator/ (const Complex& rhs) const;
    Complex operator= (const Complex& rhs) const;
    Complex operator+= (const Complex& rhs) const;
    Complex operator-= (const Complex& rhs) const;
    Complex operator*= (const Complex& rhs) const;
    Complex operator/= (const Complex& rhs) const;
  
    // operators of assigment

    //const Complex& operator+=(const Complex& rhs);
    const Complex& operator-=(const Complex& rhs);
    const Complex& operator*=(const Complex& rhs);
    const Complex& operator/=(const Complex& rhs);

    void operator+=(const Complex& rhs);

    //moltiplication by a scalar

    // moltiplication only of the form Complex*double
    Complex operator* (const double& rhs) const;

    //moltiplication of form double*Complex
    friend Complex operator*(const double& lhs, const Complex& rhs);
  
    void reset();
    void print();
  private:
    double x_,y_;
};
  
