// Lab_1a.cc
#include "lab_1a.h"

#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

// Constructors

Complex::Complex() {
  x_=0;
  y_=0;
}

Complex::Complex(double x, double y) {
  x_ = x;
  y_ = y;
}

// Setters

void Complex::setRe( double re) { x_ = re; }
void Complex::setIm( double im) { y_ = im; }

// Getters

double Complex::re() {
  return x_;
}

double Complex::im() {
  return y_;
}

double Complex::mag() {
  return sqrt(x_*x_+y_*y_);
}

double Complex::phase() {
  if(x_>0){
    
    return atan(x_/y_);}
  
  if(x_<0){

    return atan(y_/x_)+3.1416;}
}

//Operators

Complex Complex::operator+( const Complex& rhs) const {

  double re = x_ + rhs.x_;
  double im = y_ + rhs.y_;

  return Complex(re,im);
}

Complex Complex::operator-( const Complex& rhs) const {

  double re = x_ - rhs.x_;
  double im = y_ - rhs.y_;

  return Complex(re,im);
}

Complex Complex::operator*( const Complex& rhs) const {

  double re = x_ * rhs.x_;
  double im = y_ * rhs.y_;

  return Complex(re,im);
}

Complex Complex::operator/( const Complex& rhs) const {

  double re = x_ / rhs.x_;
  double im = y_ / rhs.y_;

  return Complex(re,im);
}

void Complex::reset(){
  x_=0;
  y_=0;
}

void Complex::print(){
  cout << "Complex Number: "<< x_ <<"+"<< y_ << "i" << endl;
}
  
