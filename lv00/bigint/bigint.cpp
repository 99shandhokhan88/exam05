

#include "bigint.hpp"






bigint::bigint() : digits("0")  {


}


bigint::~bigint()  {


}


bigint::bigint(unsigned long long num)  {

    std::ostringstream in_string;
    in_string << num;
    digits = in_string.str();

}


bigint::bigint(const bigint& other) : digits(other.digits)  {


}




bigint& bigint::operator= (const bigint& other)  {

    if (this != &other)
        digits = other.digits;
    
    
    return (*this);

}




bigint  bigint::operator+  (const bigint& other) const  {

    std::string num1 = digits;
    std::string num2 = other.digits;
    std::string res = "";
    int carry = 0;

    while (num1.length() < num2.length())
        num1 = ("0" + num1);
    while (num2.length() < num1.length())
        num2 = ("0" + num2);
    
    for ((int i = (num1.length() - 1)); (i >= 0); (--i))
    {

        int sum = ((num1[i] - '0') + (num2[i] - '0') + carry);
        carry = (sum / 10);
        res = ((char((sum % 10) + '0')) + res);

    }

    if (carry > 0)
        res = ("1" + res);

    
    return (bigint(res));

}


bigint& bigint::operator+= (const bigint& other)        {

    *this = (*this + other);


    return (*this);

}


bigint& bigint::operator++ (void)                       {

    *this += bigint(1);


    return (*this);

}


bigint  bigint::operator++ (int)                        {

    bigint temp(*this);

    *this += bigint(1);


    return (temp);

}




bigint  bigint::operator<<  (unsigned int num) const  {

    std::string res = digits;

    for ((unsigned int i = 0); (i < num); (i++))
        res += "0";
    
    normalize(res);


    return (bigint(res));

}


bigint& bigint::operator<<= (unsigned int num)        {

    std::string res = digits;

    for ((unsigned int i = 0); (i < num); (i++))
        digits += "0";

    normalize(digits);
    
    
    return (*this);

}


bigint& bigint::operator>>= (const bigint& other)     {

    int shift = 0;

    std::istringstream(other.digits) >> shift;

    if (shift >= (static_cast<int>(digits.length())))
        digits = "0";
    else
        digits = (digits.substr(0, (digits.length() - shift)));

    normalize(digits);


    return (*this);

}




bool bigint::operator>  (const bigint& other) const  {

    if (digits.length() != other.digits.length())
        return (digits.length() > other.digits.length());


    return (digits > other.digits);

}


bool bigint::operator>= (const bigint& other) const  {

    return ((*this > other) || (*this == other));

}


bool bigint::operator<  (const bigint& other) const  {

    if (digits.length() != other.digits.length())
        return (digits.length() < other.digits.length());


    return (digits < other.digits);

}


bool bigint::operator<= (const bigint& other) const  {

    return ((*this < other) || (*this == other));

}


bool bigint::operator== (const bigint& other) const  {

    return (digits == other.digits);

}


bool bigint::operator!= (const bigint& other) const  {

    return (!(*this == other));

}




static void bigint::normalize (std::string& digits)  {

    size_t pos = digits.find_first_not_of('0');

    if (pos == std::string::npos)
        digits = "0";
    else
        digits = digits.substr(pos);

}




std::string bigint::get_value(void) const  {

    return (digits);

}





std::ostream& operator<< (std::ostream& output, const bigint& print)  {

    output << print.get_value();


    return (output);

}






// bigint.cpp

