
#include "vect2.hpp"






vect2::vect2() : x(0), y(0) {


}


vect2::~vect2() {


}


vect2::vect2(int a, int b) : x(a), y(b) {


}


vect2::vect2(const vect2& other) {

    x = other.x;
    y = other.y;

}




vect2& vect2::operator=(const vect2& other) {

    if (this != &other)
    {

        x = other.x;
        y = other.y;

    }


    return (*this);

}




int&       vect2::operator[] (int pos)       {

    if (pos == 0)
        return (x);
    
    
    return (y);

}


const int& vect2::operator[] (int pos) const {

    if (pos == 0)
        return (x);
    
    
    return (y);

}




vect2  vect2::operator++ (int)  {

    vect2 temp(*this);
    
    x++;
    y++;
    
    
    return (temp);

}


vect2& vect2::operator++ (void) {

    x++;
    y++;


    return (*this);

}


vect2  vect2::operator-- (int)  {

    vect2 temp(*this);
    
    x--;
    y--;
    
    
    return (temp);

}


vect2& vect2::operator-- (void) {

    x--;
    y--;


    return (*this);

}




vect2& vect2::operator+= (const vect2& other) {

    x += other.x;
    y += other.y;


    return (*this);

}


vect2& vect2::operator-= (const vect2& other) {

    x -= other.x;
    y -= other.y;


    return (*this);

}


vect2& vect2::operator*= (int scalar)         {

    x *= scalar;
    y *= scalar;


    return (*this);

}




vect2 vect2::operator+ (const vect2& other) const {

    return (
        vect2(
            (x + other.x), (y + other.y)
        )
    );

}


vect2 vect2::operator- (const vect2& other) const {

    return (
        vect2(
            (x - other.x), (y - other.y)
        )
    );

}

vect2 vect2::operator* (int scalar)         const {

    return (
        vect2(
            (x * scalar), (y * scalar)
        )
    );

}




vect2 vect2::operator- (void) const {

    return (
        vect2(
            (-(x)), (-(y))
        )
    );

}




bool vect2::operator== (const vect2& other) const {

    return (
        (x == other.x)
         && 
        (y == other.y)
    );

}


bool vect2::operator!= (const vect2& other) const {

    return (!(*this == other));

}




int vect2::get_x (void) const {

    return (x);

}


int vect2::get_y (void) const {

    return (y);

}





vect2 operator* (int scalar, const vect2& vector) {

    return ((vector * scalar));

}




std::ostream& operator<< (std::ostream& output, const vect2& vector) {

    output << "{" << vector.get_x() << ", " << vector.get_y() << "}";


    return (output);

}






// vect2.cpp
