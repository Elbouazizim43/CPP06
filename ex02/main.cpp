#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

int main()
{
    std::srand(std::time(NULL));

    std::cout << "Test 1 : Random object" << std::endl;

    Base *obj = generate();

    std::cout << "Pointer identify : ";
    identify(obj);

    std::cout << "Reference identify : ";
    identify(*obj);

    delete obj;

    std::cout << std::endl;
    std::cout << "Test 2 : Object A" << std::endl;

    Base *a = new A();

    identify(a);
    identify(*a);

    delete a;

    std::cout << std::endl;

    std::cout << "Test 3 : Object B" << std::endl;

    Base *b = new B();

    identify(b);
    identify(*b);

    delete b;

    std::cout << std::endl;
    
    std::cout << "Test 4 : Object C" << std::endl;

    Base *c = new C();

    identify(c);
    identify(*c);

    delete c;

    return 0;
}