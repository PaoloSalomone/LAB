#pragma once
#ifndef Datum_h
#define Datum_h

class Datum
{
public:

	//constructor
	Datum();
	Datum(const double value, const double error);
	Datum(const Datum& datum);
	//destructor
	~Datum();

	//getters
	double GetValue() const;
	double GetError() const;

	//setters
	void SetValue(double value);
	void SetError(double erorr);

	//print
	void print();

private:

	double value_;
	double error_;

};
#endif // !Datum
