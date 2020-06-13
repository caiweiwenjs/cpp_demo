#include <iostream>
#include <functional>
#include <utility>



void fn(int &a) {
  std::cout << a << std::endl;  
}

void fn2(int &&a) {
  std::cout << a << std::endl;  
}

void overloaded( int const &arg ) { std::cout << "by lvalue\n"; }
void overloaded( int && arg ) { std::cout << "by rvalue\n"; }
//void overloaded( int arg ) { std::cout << "by rvalue\n"; }

template< typename t >
/* "t &&" with "t" being template param is special, and  adjusts "t" to be
   (for example) "int &" or non-ref "int" so std::forward knows what to do. */
void forwarding( t && arg ) {
    std::cout << "via std::forward: ";
    overloaded( std::forward< t >( arg ) );
    std::cout << "via std::move: ";
    overloaded( std::move( arg ) ); // conceptually this would invalidate arg
    std::cout << "by simple passing: ";
    overloaded( arg );
}

int main() {
    std::cout << "initial caller passes rvalue:\n";
    forwarding( 5 );
    std::cout << "initial caller passes lvalue:\n";
    int x = 5;
    forwarding( x );
}

int main2() {
  //fn(std::forward<int>(10));
  int a;
  int &&b = 10;
  fn(a);
  fn(b);
  // fn(std::forward<int>(b)); // error
  //fn(10); // error
  fn2(10);
  fn2(std::forward<int>(b));
  //fn2(b); // error
  //fn2(a); //error
  fn2(std::forward<int>(a));
  fn2(std::move(a));
  return 0;  
}
