#include <iostream>
#include <string>


const std::string s = "abc ->  " 
                "followed by not a newline: "
                " which is then followed by a non-raw literal that's concatenated with"
                " an embedded non-raw newline";

int main() {

	std::cout << s << std::endl;
  return 0;  
}
