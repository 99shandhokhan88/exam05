
#include "bigint.hpp"






bigint::bigint() : digits("0") {


}


bigint::~bigint() {


}


bigint::bigint(unsigned long long num) {

    std::ostringstream in_string;
    in_string << num;
    digits = in_string.str();

}


bigint::bigint(const bigint& other) : digits(other.digits) {


}


bigint& bigint::operator=(const bigint& other) {

    if (this != &other)
        digits = other.digits;
    
    
    return (*this);

}




bigint bigint::operator+(const bigint& other) const {

    std::string a = digits;
    std::string b = other.digits;

    while (a.length() < b.length())
        a = ("0" + a);
    while (b.length() < a.length())
        b = ("0" + b);
    
    std::string num = "";
    int carry = 0;

    for (int i = a.length() - 1; i >= 0; i--)
    {

        int sum = ((a[i] - '0') + (b[i] - '0') + carry);
        num = (char((sum % 10) + '0') + num);
        carry = (sum / 10);

    }

    if (carry > 0)
        num = ("1" + num);
    
    bigint res;
    res.digits = num;


    return (res);

}




bigint& bigint::operator+=(const bigint& other) {

    *this = (*this + other);


    return (*this);

}




bigint& bigint::operator++(void)    {

    *this = (*this + bigint(1));


    return (*this);

}


bigint  bigint::operator++(int num) {

    bigint temp(*this);

    *this = (*this + bigint(1));


    return (temp);

}




bigint  bigint::operator<<(unsigned int num) const {

    bigint res(*this);

    for (unsigned long long i = 0; i < num; i++)
        res.digits = (res.digits + "0");

    normalize(res.digits);
    
    
    return (res);

}


bigint& bigint::operator<<=(unsigned int num)      {

    for (unsigned long long i = 0; i < num; i++)
        digits = (digits + "0");
    
    normalize(digits);
    
    
    return (*this);

}


bigint& bigint::operator>>=(const bigint& other)   {

    int in_num = 0;

    std::istringstream(other.digits) >> in_num;

    if (in_num >= static_cast<int>(digits.length()))
        digits = "0";
    else
        digits = digits.substr(0, (digits.length() - in_num));
    
    normalize(digits);


    return (*this);

}




bool bigint::operator>(const bigint& other)  const {

    if (digits.length() != other.digits.length())
        return (digits.length() > other.digits.length());


    return (digits > other.digits);

}


bool bigint::operator>=(const bigint& other) const {

    return ((*this > other) || (*this == other));

}


bool bigint::operator<(const bigint& other)  const {

    if (digits.length() != other.digits.length())
        return (digits.length() < other.digits.length());
    
    
    return (digits < other.digits);

}


bool bigint::operator<=(const bigint& other) const {

    return ((*this < other) || (*this == other));

}


bool bigint::operator==(const bigint& other) const {

    return (digits == other.digits);

}


bool bigint::operator!=(const bigint& other) const {

    return (!(*this == other));

}




void bigint::normalize(std::string& digits) {

    size_t pos = digits.find_first_not_of("0");

    if (pos == std::string::npos)
        digits = "0";
    else
        digits = digits.erase(0, pos);

}




std::string bigint::getValue(void) const {

    return (digits);

}




std::ostream& operator<<(std::ostream& output, const bigint& print) {

    output << print.getValue();


    return (output);

}






// bigint.cpp
