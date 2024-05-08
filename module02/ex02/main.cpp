#include "./Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

a = Fixed(5.05f) * Fixed(2);
std::cout << "a : is "<< a << std::endl;
std::cout << "++a :" <<  ++a << std::endl;
std::cout << "then a = " << a << std::endl;
std::cout << "a++" << a++ << std::endl;
std::cout << "and a = " << a << std::endl;
std::cout << "b is : " << b << std::endl;
std::cout << Fixed::max( a, b ) << std::endl;
return 0;
}
