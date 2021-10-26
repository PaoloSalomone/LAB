// Complex.cc
#include "Complex.h"

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

//operators of assigment

//const Complex& Complex::operator+=(const Complex& rhs) {
void Complex::operator+=(const Complex& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    //retun *this; ho notato che si può fare anche così, non so cosa cambia al caso con *this
}

const Complex& Complex::operator-=(const Complex& rhs) {
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}

const Complex& Complex::operator*=(const Complex& rhs) {
    x_ *= rhs.x_;
    y_ *= rhs.y_;
    return *this;
}

const Complex& Complex::operator/=(const Complex& rhs) {
    x_ /= rhs.x_;
    y_ /= rhs.y_;
    return *this;
}

//molitplication by a scalar

//moltiplication of form Complex*double
Complex Complex::operator*(const double& rhs) const {
    return Complex(rhs * x_, rhs * y_);
}

//Moltiplication of form double*Complex
Complex operator*(const double& lhs, const Complex& rhs) {
    return Complex(lhs * rhs.x_, lhs * rhs.y_);
}


void Complex::reset(){
  x_=0;
  y_=0;
}

void Complex::print(){
  cout << "Complex Number: "<< x_ <<"+"<< y_ << "i" << endl;
}
  
