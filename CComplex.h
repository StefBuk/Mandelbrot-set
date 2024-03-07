#include <iostream>
#include <complex>

class Complex {
public:
    double R;
    double I;

    Complex() : R( 0.0 ), I( 0.0 ){};
    Complex( double R, double I ) : R( R ), I( I ) {};

    ~Complex(){};

    friend Complex operator* ( const Complex& Z );
    friend Complex operator+ ( const Complex& Z );

    double magnitude() const;
    void set( double real, double imag );
};


Complex operator* ( const Complex& Z1, const Complex& Z2 ) {

  double real = Z1.R * Z2.R - Z1.I * Z2.I;
  double imag = Z1.R * Z2.I + Z1.I * Z2.R;

  return Complex( real, imag );
}

Complex operator+ ( const Complex& Z1, const Complex& Z2 ) {

  double real = Z1.R + Z2.R;
  double imag = Z1.I + Z2.I;

  return Complex( real, imag );
}

double Complex :: magnitude() const {

  return std::sqrt( this->R * this->R + this->I * this->I );
}

void Complex :: set( double real, double imag ) {
  this->R = real;
  this->I = imag;
}
