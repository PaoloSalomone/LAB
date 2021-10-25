#pragma once
#include <iostream>
#include <string>

class vector
{
public:
    // constructors
    vector();
    vector(double x, double y, double z, const char type = *"cart");
    vector(const vector& vector);
    ~vector();


    //setters
    void setx(double x);
    void sety(double y);
    void setz(double z);


    //getters
    double x();
    double y();
    double z();
    double mag();
    double theta();
    double phi();


    //
    void reset();
    void print();


    //operator
    vector operator+ (const vector& vector) const;
    vector operator- (const vector& vector) const;
    double scalar(const vector& vector) const;
    vector vectorial(const vector& vector) const;


    //operator of assigment
    vector& operator+=(const vector& rhs);
    vector& operator-=(const vector& rhs);


    //moltiplication by a scalar
    // moltiplication only of the form vector*double
    vector operator* (const double& rhs) const;
    //moltiplication of form vector*Complex
    friend vector operator*(const double& lhs, const vector& rhs);

    //division by a scalar
    // division only of the form vector/double
    vector operator/ (const double& rhs) const;

    //angle
    friend double angle(vector vector1, vector vector2);

private:
    double x_, y_, z_;
};

