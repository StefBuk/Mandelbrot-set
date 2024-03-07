#include <iostream>
#include <fstream>

std::fstream file_opener( const char *name, int nop )
{
  std::fstream str;

  if( nop == 1 )   str.open( name, std::ofstream::in | std::fstream::out | std::fstream::trunc );
  if( nop == 2 )   str.open( name, std::ofstream::app );

  if( !str.is_open() )
  {
    std::cout << "Greska pri otvaranju fajla!";
    exit( EXIT_FAILURE );
  }

  return str;
}
