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

vector::vector(double x, double y, double z, const char type) {

    if (type == *"polar") {
        std::cout << "vector constructor called for r=" << x << "\t theta=" << z << "\t phi=" << y << std::endl;
        x_ = x * sin(z) * cos(y);
        y_ = x * sin(z) * sin(y);
        z_ = x * cos(z);
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

vector::~vector() { std::cout << "vector canceled" << std::endl; }

// Setters

void vector::setx(double x) { x_ = x; }
void vector::sety(double y) { y_ = y; }
void vector::setz(double z) { z_ = z; }


// Getters

double vector::x() { return x_; }
double vector::y() { return y_; }
double vector::z() { return z_; }
double vector::mag() { return sqrt(x_ * x_ + y_ * y_ + z_ * z_); }
double vector::theta() { return atan(sqrt(x_ * x_ + y_ * y_) / z_); }
double vector::phi() { return atan(y_ / x_); }


void vector::print() {
    std::cout << "vector: x=" << x_ << "\t y=" << y_ << "\t z=" << z_ << std::endl;
}

void vector::reset() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}


//operator
vector vector::operator+ (const vector& Vector) const { return vector(x_ + Vector.x_, y_ + Vector.y_, z_ + Vector.z_); }
vector vector::operator- (const vector& Vector) const { return vector(x_ - Vector.x_, y_ - Vector.y_, z_ - Vector.z_); }
double vector::scalar(const vector& Vector) const { return Vector.x_ * x_ + Vector.y_ * y_ + Vector.z_ * z_; }
vector vector::vectorial(const vector& Vector) const { return vector(y_ * Vector.z_ - Vector.y_ * z_, z_ * Vector.x_ - Vector.z_ * x_, x_ * Vector.y_ - Vector.y_ * x_); }


//operator of assigment
vector& vector::operator+=(const vector& rhs) {
    x_ += rhs.x_;
    y_ += rhs.y_;
    return *this;
}
vector& vector::operator-=(const vector& rhs) {
    x_ -= rhs.x_;
    y_ -= rhs.y_;
    return *this;
}


//molitplication by a scalar
//moltiplication of form vector*double
vector vector::operator*(const double& rhs) const { return vector(rhs * x_, rhs * y_, rhs * z_); }
//Moltiplication of form double*vector
vector operator*(const double& lhs, const vector& Vector) { return vector(lhs * Vector.x_, lhs * Vector.y_, lhs * Vector.z_); }


//division by a scalar
//division of form vector/double
vector vector::operator/(const double& rhs) const { return vector(x_ / rhs, y_ / rhs, z_ / rhs); }


//angle
double angle(vector vector1, vector vector2) { return acos(vector1.scalar(vector2) / (vector1.mag() * vector2.mag())); }
