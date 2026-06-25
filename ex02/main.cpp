#include <iostream>
#include "Base.hpp"




// ─────────────────────────────────────────
// MAIN
// ─────────────────────────────────────────
int main()
{
    std::srand(time(NULL)); // random seed

    // ── Test 1: generate random w identify ──
    std::cout << "=== Test 1: random generate x5 ===" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        Base *obj = generate();
        std::cout << "object " << i + 1 << ":" << std::endl;
        identify(obj);
        identify(*obj);
        delete obj;
    }

    // ── Test 2: A direct ──
    std::cout << "\n=== Test 2: A direct ===" << std::endl;
    {
        Base *a = new A();
        identify(a);
        identify(*a);
        delete a;
    }

    // ── Test 3: B direct ──
    std::cout << "\n=== Test 3: B direct ===" << std::endl;
    {
        Base *b = new B();
        identify(b);
        identify(*b);
        delete b;
    }

    // ── Test 4: C direct ──
    std::cout << "\n=== Test 4: C direct ===" << std::endl;
    {
        Base *c = new C();
        identify(c);
        identify(*c);
        delete c;
    }

    // ── Test 5: NULL pointer ──
    std::cout << "\n=== Test 5: NULL pointer ===" << std::endl;
    {
        Base *null = NULL;
        identify(null);
        // mkandrch ndiro identifyReference(null) — undefined behavior
        std::cout << "  [reference] skipped — NULL ref is UB" << std::endl;
    }

    return 0;
}