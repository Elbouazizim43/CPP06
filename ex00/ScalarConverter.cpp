#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <climits>
#include <cmath>

// ─────────────────────────────────────────
// STEP 1: detect what type is the literal
// ─────────────────────────────────────────

// wash hiya char? ex: 'a'
static bool isChar(const std::string &s)
{
    return (s.length() == 3 && s[0] == '\'' && s[2] == '\'');
}

// wash kol characters digits? (optionally starts with + or -)
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

// wash katsa3da b 'f' w fiha dot? ex: 3.14f
static bool isFloat(const std::string &s)
{
    if (s == "nanf" || s == "+inff" || s == "-inff" || s == "inff")
        return true;
    // lazm katsa3da b 'f'
    if (s[s.size() - 1] != 'f')
        return false;
    // nchayko bla f — wash hiya double valid?
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
    return hasDot; // lazm kayn dot: 3f invalid, 3.0f valid
}

// wash fiha dot w bla 'f' f l-akhir? ex: 3.14
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

// ─────────────────────────────────────────
// STEP 2: print the 4 types from a double
// ─────────────────────────────────────────

static void printChar(double d)
{
    // nan/inf → impossible
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    // ASCII range: 0 → 127
    else if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    // printable = li kaydhr (space, a-z, 0-9, !, @...)
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

// ─────────────────────────────────────────
// STEP 3: detect → convert → print
// ─────────────────────────────────────────

void ScalarConverter::convert(const std::string &literal)
{
    double d = 0.0;

    if (isChar(literal))
    {
        // 'a' → nakhdo l character f l-milieu (index 1)
        d = static_cast<double>(literal[1]);
    }
    else if (isInt(literal))
    {
        // string → long → double
        d = static_cast<double>(std::atol(literal.c_str()));
    }
    else if (isFloat(literal))
    {
        // string → float → double
        d = static_cast<double>(std::atof(literal.c_str()));
    }
    else if (isDouble(literal))
    {
        // string → double direct
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