#include <iostream>
#include "good_utility.h" // contains void print_message();

void say_hello();  // from logic.cpp

int main() {
    std::cout << "Start program." << std::endl;
    say_hello();      // from logic.cpp
    print_message();  // from good_utility.cpp, actual code is implemented
    return 0;
}
