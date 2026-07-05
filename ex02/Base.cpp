#include <iostream>
#include <cstdlib>
#include "Base.hpp"

Base::Base() {}
Base::Base(const Base &src)
{
    *this = src;
}

Base &Base::operator=(const Base &src)
{
    (void)src;
    return *this;
}

Base::~Base() {}


A::A() {}
A::A(const A &src) { *this = src; }
A &A::operator=(const A &src) { (void)src; return *this; }
A::~A() {}

B::B() {}
B::B(const B &src) { *this = src; }
B &B::operator=(const B &src) { (void)src; return *this; }
B::~B() {}

C::C() {}
C::C(const C &src) { *this = src; }
C &C::operator=(const C &src) { (void)src; return *this; }
C::~C() {}
Base* generate(void)
{
    int r = rand() % 3;

    if (r == 0)
        return new A();
    else if (r == 1)
        return new B();
    return new C();
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B\n";
        return;
    } catch (...) {}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C\n";
        return;
    } catch (...) {}
}