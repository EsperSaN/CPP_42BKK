#include "./Fixed.hpp"

int main( void ) {
Fixed a;
Fixed z;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer " << a.toFloat() << " as float " << a.getRawBits() << " raw bits " << std::endl;
std::cout << "b is " << b.toInt() << " as integer " << b.toFloat() << " as float " << b.getRawBits() << " raw bits " << std::endl;
std::cout << "c is " << c.toInt() << " as integer " << c.toFloat() << " as float " << c.getRawBits() << " raw bits " << std::endl;
std::cout << "d is " << d.toInt() << " as integer " << d.toFloat() << " as float " << d.getRawBits() << " raw bits " << std::endl;
return 0;
}
