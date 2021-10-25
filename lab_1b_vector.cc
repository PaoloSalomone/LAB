#include "vector.h"
#include <iostream>
#include <cmath>
#include <string>


// Constructors

vector::vector() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

vector::vector(double x, double y, double z, const char type ) {
    
    if (type == *"polar") {
        std::cout << "vector constructor called for r=" << x << "\t theta=" << z << "\t phi=" << y << std::endl;
        x_ = x*sin(z)*cos(y);
        y_ = x*sin(z)*sin(y);
        z_ = x*cos(z);
    }

    else {
        std::cout << "vector constructor called for x=" << x << "\t y=" << y << "\t z=" << z << std::endl;
        x_ = x;
        y_ = y;
        z_ = z;
    }
}

vector::vector(const vector& vector) { 
    std::cout << "vector constructor called for x=" << vector.x_ << "\t y=" << vector.y_ << "\t z=" << vector.z_ << std::endl;
    x_ = vector.x_;
    y_ = vector.y_;
    z_ = vector.z_;
}


// Setters

void vector::setx(double x) { x_ = x; }
void vector::sety(double y) { y_ = y; }
void vector::setz(double z) { z_ = z; }


// Getters

double vector::x() { return x_; }
double vector::y() { return y_; }
double vector::z() { return z_; }
double vector::mag() { return sqrt(x_ * x_ + y_ * y_+ z_ * z_); }
double vector::theta() { return atan(sqrt(x_ * x_ + y_ * y_) / z_); }
double vector::phi() { return atan(y_ / x_); }


//

void vector::print() {
    std::cout << "Vector: x=" << x_ << "\t y=" << y_ << "\t z=" << z_ << std::endl;
}

void vector::reset() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}


//operator
vector vector::operator+ (const vector& Vector) const { return vector(x_ + Vector.x_, y_ + Vector.y_, z_ + Vector.z_); }
vector vector::operator- (const vector& Vector) const{ return vector(x_ - Vector.x_, y_ - Vector.y_, z_ - Vector.z_); }
double vector::scalar(const vector& Vector) const { return Vector.x_ * x_ + Vector.y_ * y_ + Vector.z_ * z_; }
vector vector::vectorial(const vector& Vector) const { return vector(y_ * Vector.z_ - Vector.y_ * z_, z_ * Vector.x_ - Vector.z_ * x_, x_ * Vector.y_ - Vector.y_ * x_); }


//operator of assignment
