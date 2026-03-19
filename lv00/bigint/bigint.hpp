
#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <sstream>
#include <iostream>

class bigint {
private:
    std::string digits;
    explicit bigint(const std::string& str) : digits(str) {}
    static void normalize(std::string& digits);

public:
    bigint();
    ~bigint();
    bigint(unsigned long long num);
    bigint(const bigint& other);
    bigint& operator=(const bigint& other);

    bigint  operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);
    bigint& operator++();
    bigint  operator++(int);

    bigint  operator<<(unsigned int num) const;
    bigint& operator<<=(unsigned int num);
    bigint& operator>>=(const bigint& other);

    bool operator>(const bigint& other)  const;
    bool operator>=(const bigint& other) const;
    bool operator<(const bigint& other)  const;
    bool operator<=(const bigint& other) const;
    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    std::string getValue() const;
};

std::ostream& operator<<(std::ostream& output, const bigint& print);

#endif
