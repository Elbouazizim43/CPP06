#ifndef BASE_HPP
#define BASE_HPP

class Base
{
public:
    virtual ~Base();
};

// ===== Classes =====


class A : public Base
{
public:
    A();
    A(const A &src);
    A &operator=(const A &src);
    ~A();
};

class B : public Base
{
public:
    B();
    B(const B &src);
    B &operator=(const B &src);
    ~B();
};

class C : public Base
{
public:
    C();
    C(const C &src);
    C &operator=(const C &src);
    ~C();
};

// class A : public Base {};
// class B : public Base {};
// class C : public Base {};

// ===== Prototypes =====

Base* generate(void);

void identify(Base* p);
void identify(Base& p);

#endif