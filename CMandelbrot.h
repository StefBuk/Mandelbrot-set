#include <iostream>
#include <fstream>
#include <string>

#include "CComplex.h"

#include "settings.h"
#include "fun.h"

class Mandelbrot {
public:
  static const int MAX_ITERATIONS = 1000;

  int calc_mandelbrot( const Complex &C );
  void output_result( const char *name );

};

int Mandelbrot :: calc_mandelbrot( const Complex &C )
{
  Complex Z( 0, 0 );
  int iterations = 0;

  while( Z.magnitude() < 2.0 && iterations < MAX_ITERATIONS ) {

    Z = Z * Z + C;  //formula
    iterations++;
  }

  return iterations;
}

void Mandelbrot :: output_result( const char *name )
{
  double real, imag;

  Mandelbrot M;
  Complex C;

  //File opener
  const char *extension = ".ppm";
  std::string string_name = std::string( name ) + extension;
  const char *full_name = string_name.c_str();

  std::fstream output = file_opener( full_name, 1 );
  output << "P3\n" << WIDTH << " " << HEIGHT << "\n255\n";

  for( int y = 0; y < HEIGHT; y++ )
  {
    for( int x = 0; x < WIDTH; x++ )
    {
      real = MIN_REAL + ( MAX_REAL - MIN_REAL ) * x / ( WIDTH - 1 );
      imag = MIN_IMAG + ( MAX_IMAG - MIN_IMAG ) * y / ( HEIGHT - 1 );

      C.set( real, imag );

      int iterations = M.calc_mandelbrot( C );

      // Map the number of iterations to a color
      int red = iterations % 256;
      int green = ( iterations * 2 ) % 256;
      int blue = ( iterations * 3 ) % 256;

      output << red << " " << green << " " << blue << " ";
    }
    output << "\n";
  }

  output.close();
}
