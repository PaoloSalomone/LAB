#include <iostream>
#include "Datum.h"

//constructor
Datum::Datum() { value_ = 0; error_ = 0; }
Datum::Datum(const double value, const double error) { value_ = value; error_ = error; }
Datum::Datum(const Datum& datum) { value_ = datum.value_; error_ = datum.error_; }
//destructor
Datum::~Datum(){}

//getters
double Datum::GetValue() const { return value_; }
double Datum::GetError() const { return error_; }

//setters
void Datum::SetValue(double value) { value_ = value; }
void Datum::SetError(double error) { error_ = error; }

//print
void Datum::print() { std::cout << "Datum: value" << value_ << "+/-" << error_ << std::endl; }