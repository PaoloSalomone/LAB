#pragma once
#include <iostream>
#include <string>

class vector
{
    // constructors
    vector();
    vector(double x, double y, double z, const char type= *"cart" );
    vector(const vector& vector);


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
    double scalar (const vector& vector) const;
    vector vectorial (const vector& vector) const;

private:
    double x_, y_, z_;
};

