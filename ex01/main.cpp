#include <iostream>
#include "Serializer.hpp"

int main()
{
    Data d;
    d.x = 42;

    Data* ptr = &d;

    uintptr_t raw = Serializer::serialize(ptr);
    Data* newPtr = Serializer::deserialize(raw);

    std::cout << "Original ptr: " << ptr << std::endl;
    std::cout << "Raw value: " << raw << std::endl;
    std::cout << "New ptr: " << newPtr << std::endl;

    // if (ptr == newPtr)
        std::cout << "Value: " << newPtr->x << std::endl;

    return 0;
}