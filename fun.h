#include <iostream>
#include <fstream>

std::fstream file_opener( const char *name, int how )
{
  std::fstream str;

  if( how == 1 )   str.open( name, std::ofstream::in | std::fstream::out | std::fstream::trunc );
  if( how == 2 )   str.open( name, std::ofstream::app );

  if( !str.is_open() )
  {
    std::cout << "File opening error!";
    exit( EXIT_FAILURE );
  }

  return str;
}
