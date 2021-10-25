// Vector3D.h

#include <iostream>
using namespace std;

class Vector3D {
  public:
    // constructors  (seconda prova di modifica sul ramo)
    Vector3D();
    Vector3D(double x,double y,double z);
    Vector3D(const Vector3D& Vector3D);


    //setters
    void setX (double x); 
    void setY (double y); 
    void setZ (double z);

    //getters magnitude(), theta(), phi(),
    double x();
    double y();
    double z(); 
    double magnitude();
    double theta();
    double phi();


    // Operators ??
    /*Vector3D operator+ (const Vector3D& rhs) const;
    Vector3D operator- (const Vector3D& rhs) const;
    Vector3D operator* (const Vector3D& rhs) const;
    Vector3D operator/ (const Vector3D& rhs) const;
    Vector3D operator= (const Vector3D& rhs) const;
    Vector3D operator+= (const Vector3D& rhs) const;
    Vector3D operator-= (const Vector3D& rhs) const;
    Vector3D operator*= (const Vector3D& rhs) const;
    Vector3D operator/= (const Vector3D& rhs) const;   ******** li ho commentati per fare una prova con i rami *********/  
  
    // operators of assigment

    //const Vector3D& operator+=(const Vector3D& rhs);
    const Vector3D& operator-=(const Vector3D& rhs);
    const Vector3D& operator*=(const Vector3D& rhs);
    const Vector3D& operator/=(const Vector3D& rhs);

    void operator+=(const Vector3D& rhs);

    //moltiplication by a scalar

    // moltiplication only of the form Vector3D*double
    Vector3D operator* (const double& rhs) const;

    //moltiplication of form double*Vector3D
    friend Vector3D operator*(const double& lhs, const Vector3D& rhs);
  
    void reset();
    void print();
  private:
    double x_,y_,z_;
};
  
