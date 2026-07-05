#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &src)
{
    *this = src;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
    (void)src;
    return *this;
}

ScalarConverter::~ScalarConverter() {}


static bool isChar(const std::string &s)
{
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

static bool isInt(const std::string &s)
{
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.size())
        return false;
    while (i < s.size())
    {
        if (s[i] < '0' || s[i] > '9')
            return false;
        i++;
    }
    return true;
}

static bool isFloat(const std::string &s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
        return true;
    if (s[s.size() - 1] != 'f')
        return false;
    std::string withoutF = s.substr(0, s.size() - 1);
    size_t i = 0;
    bool hasDot = false;
    if (withoutF[i] == '+' || withoutF[i] == '-')
        i++;
    if (i == withoutF.size())
        return false;
    while (i < withoutF.size())
    {
        if (withoutF[i] == '.' && !hasDot)
            hasDot = true;
        else if (withoutF[i] < '0' || withoutF[i] > '9')
            return false;
        i++;
    }
    return hasDot; 
}

static bool isDouble(const std::string &s)
{
    if (s == "nan" || s == "+inf" || s == "-inf" || s == "inf")
        return true;
    size_t i = 0;
    bool hasDot = false;
    if (s[i] == '+' || s[i] == '-')
        i++;
    if (i == s.size())
        return false;
    while (i < s.size())
    {
        if (s[i] == '.' && !hasDot)
            hasDot = true;
        else if (s[i] < '0' || s[i] > '9')
            return false;
        i++;
    }
    return hasDot;
}


static void printChar(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (d < 32 || d == 127)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
}

static void printInt(double d)
{
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
}

static void printFloat(double d)
{
     float f = static_cast<float>(d);
    if (std::isnan(f))
        std::cout << "float: nanf" << std::endl;
    else if (std::isinf(f))
        std::cout << "float: " << (f > 0 ? "+" : "-") << "inff" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << "float: " << f << "f" << std::endl;
}

static void printDouble(double d)
{
    if (std::isnan(d))
        std::cout << "double: nan" << std::endl;
    else if (std::isinf(d))
        std::cout << "double: " << (d > 0 ? "+" : "-") << "inf" << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1)
                  << "double: " << d << std::endl;
}

void ScalarConverter::convert(const std::string &literal)
{
    double d = 0.0;

    if (isChar(literal))
    {
        d = static_cast<double>(literal[1]);
    }
    else if (isInt(literal))
    {
        d = static_cast<double>(std::atol(literal.c_str()));
    }
    else if (isFloat(literal))
    {
        d = static_cast<double>(std::atof(literal.c_str()));
    }
    else if (isDouble(literal))
    {
        d = std::atof(literal.c_str());
    }
    else
    {
        std::cout << "Error: unrecognized literal" << std::endl;
        return;
    }

    printChar(d);
    printInt(d);
    printFloat(d);
    printDouble(d);
}