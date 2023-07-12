#include <iostream>

void foo(int&& arg) {
	arg=arg+1;
    std::cout << "Argument is " << arg << std::endl;
}

int main() {
    foo(42); // rvalue passed as argument
    int x = 42;
    foo(std::move(x)); // explicitly cast to rvalue reference
    
    std::cout<<x;

    return 0;
}
