
#ifndef VECT2_HPP
#define VECT2_HPP




#include <iostream>



class vect2 {

            private:

                    int x;
                    int y;

            public:

                    vect2() ;
                    ~vect2() ;
                    vect2(int a, int b) ;
                    vect2(const vect2& other) ;

                    vect2& operator=(const vect2& other) ;

                    int&       operator[] (int pos)       ;
                    const int& operator[] (int pos) const ;

                    vect2  operator++ (int)  ;
                    vect2& operator++ (void) ;
                    vect2  operator-- (int)  ;
                    vect2& operator-- (void) ;

                    vect2& operator+= (const vect2& other) ;
                    vect2& operator-= (const vect2& other) ;
                    vect2& operator*= (int scalar)         ;
                    
                    vect2 operator+ (const vect2& other) const ;
                    vect2 operator- (const vect2& other) const ;
                    vect2 operator* (int scalar)         const ;

                    vect2 operator- (void) const ;

                    bool operator== (const vect2& other) const ;
                    bool operator!= (const vect2& other) const ;

                    int get_x (void) const ;
                    int get_y (void) const ;

};


vect2 operator* (int scalar, const vect2& vector) ;


std::ostream& operator<< (std::ostream& output, const vect2& vector) ;




#endif

// vect2.hpp
