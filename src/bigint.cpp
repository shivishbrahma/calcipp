/**
 * @file bigint.cpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief Header file for BigInt
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "bigint.hpp"

// Private functions
std::string bigint::__to_nibble_string(char n, bool is_start = false)
{
    std::string s = "";
    u_char c;
    for (size_t i = 0; i < sizeof(n) * 2; i++)
    {
        c = (n >> (i * NIBBLE_SIZE)) & NIBBLE_MASK;
        s += (c == 0 && is_start) ? "" : std::to_string(c);
    }
    return s;
}

std::vector<u_char> bigint::__to_nibble(std::string s)
{
    std::vector<u_char> nibble;
    u_char c;
    if (s.size() % 2 == 1)
    {
        c = (s.front() - '0') * (NIBBLE_MASK + 1);
        s.erase(0, 1);
        nibble.insert(nibble.begin(), 1, c);
    }
    for (size_t i = 0; i < s.size(); i++)
        if (i % 2 == 0)
            c = (s[i] - '0');
        else
            nibble.insert(nibble.begin(), 1, ((s[i] - '0') * (NIBBLE_MASK + 1) + c));

    return nibble;
}

// Public functions

u_char &bigint::operator[](size_t i)
{
    return __big_int[i];
}

size_t bigint::size()
{
    return __big_int.size();
}

bigint::bigint(std::string s)
{
    if (s.front() == '-')
    {
        this->__is_negative = true;
        s.erase(0, 1);
    }
    this->__big_int = this->__to_nibble(s);
}

bigint::bigint(std::vector<u_char> v, bool is_neg = false) : __big_int(v), __is_negative(is_neg) {}

bigint::~bigint()
{
    __big_int.clear();
}

void bigint::print()
{
    for (int i = this->size() - 1; i >= 0; i--)
        std::cout << __to_nibble_string(this->__big_int[i], i == this->size() - 1);
    std::cout << std::endl;
}

std::string bigint::to_string()
{
    std::string s = "";
    s += (this->__is_negative) ? "-" : "";
    for (int i = this->size() - 1; i >= 0; i--)
        s += __to_nibble_string(this->__big_int[i], i == this->size() - 1);
    return s;
}

bigint bigint::add(bigint bi)
{
    std::vector<u_char> res;
    u_char carry = 0, sum = 0, s = 0;
    for (size_t i = 0; i < std::max(this->size(), bi.size()) * 2; i++)
    {
        u_char c1 = (i / 2 < size()) ? __big_int[i / 2] : 0,
               c2 = (i / 2 < bi.size()) ? bi[i / 2] : 0;
        if (i % 2 == 0)
            s = (c1 >> NIBBLE_SIZE) + (c2 >> NIBBLE_SIZE) + carry;
        else
        {
            s = s << NIBBLE_SIZE;
            sum = (c1 & NIBBLE_MASK) + (c2 & NIBBLE_MASK) + carry;
            s += sum % 10;
            res.push_back(s);
            s = sum;
        }
        carry = s / 10;
        s = s % 10;
    }

    if (carry)
        res.push_back(carry << NIBBLE_SIZE);
    return bigint(res);
}

bigint bigint::sub(bigint bi)
{
    std::vector<u_char> res;
    u_char carry = 0, sum = 0, s = 0;
    for (size_t i = 0; i < std::max(this->size(), bi.size()) * 2; i++)
    {
        u_char c1 = (i / 2 < size()) ? __big_int[i / 2] : 0,
               c2 = (i / 2 < bi.size()) ? bi[i / 2] : 0;
        if (i % 2 == 0)
            s = (c1 >> NIBBLE_SIZE) - (c2 >> NIBBLE_SIZE) - carry;
        else
        {
            s = s << NIBBLE_SIZE;
            sum = (c1 & NIBBLE_MASK) - (c2 & NIBBLE_MASK) - carry;
            s += sum % 10;
            res.push_back(s);
            s = sum;
        }
        carry = s / 10;
        s = s % 10;
    }

    if (carry)
        res.push_back(carry << NIBBLE_SIZE);
    return bigint(res);
}