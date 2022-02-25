/**
 * @file bigint.hpp
 * @author Purbayan Chowdhury (pur.cho.99@gmail.com)
 * @brief Library file for BigInt
 * @version 0.1
 * @date 2022-02-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <vector>
#include <iostream>

#define NIBBLE_SIZE 4
#define NIBBLE_MASK 0xF

class bigint
{
private:
    // Private functions
    std::vector<u_char> __to_nibble(std::string s);
    std::string __to_nibble_string(char n, bool is_start);
    // Private member variables
    std::vector<u_char> __big_int;
    bool __is_negative = false;

public:
    u_char &operator[](size_t i);
    size_t size();
    bigint(std::string s);
    bigint(std::vector<u_char> v, bool is_neg);
    ~bigint();
    void print();
    std::string to_string();
    bigint add(bigint bi);
    bigint sub(bigint bi);
};

#endif