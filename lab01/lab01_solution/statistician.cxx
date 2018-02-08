#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>

#include "statistician.h"

std::string statistician::toString( ) const {
    //Library facilities used:  sstream, string
    std::stringstream outs;
    outs << "Statistician: \n";
    outs << "\tcount = " << this->count  << "\n";
    outs << "\ttotal = " << this->total  << "\n";
    if ( this->count == 0 ) {
       outs << "\tmean  = NOT DEFINED\n";
       outs << "\tmin   = NOT DEFINED\n";
       outs << "\tmax   = NOT DEFINED\n";
    }
    else {
        outs << "\tmean  = " << this->mean()  << "\n";
        outs << "\tmin   = " << this->tinyest << "\n";
        outs << "\tmax   = " << this->largest << "\n";
    }
    return outs.str();
}

statistician::statistician( ) {
    count = 0;
    total = 0;
    tinyest =  3.4E+38;
    largest = -3.4E+38;
}

statistician::statistician(const statistician& other) {
    this->count   = other.count;
    this->total   = other.total;
    this->tinyest = other.tinyest;
    this->largest = other.largest;
}

void statistician::next(double r) {
    this->count++;
    this->total += r;
    if ( count == 1) {
        this->tinyest = this->largest = r;
    } 
    else if ( r < this->tinyest ) 
        this->tinyest = r;
    else if ( r > this->largest )
        this->largest = r;
}

void statistician::reset( ) {
    count = 0;
    total = 0;
    tinyest =  3.4E+38;
    largest = -3.4E+38;;
}

statistician& statistician::operator =(const statistician& other) {
    //Check for possible self-assignment
    if (this == &other) return *this;

    this->count   = other.count;
    this->total   = other.total;
    this->tinyest = other.tinyest;
    this->largest = other.largest;

    return *this;
}

int statistician::length( ) const {
    return count;
}

double statistician::sum( ) const {
    return total;
}

double statistician::mean( ) const {
    if ( this->length( ) == 0 )
        throw std::domain_error("Mean not defined as there is no data");
    return total / count;
}

double statistician::minimum( ) const {
    if ( this->length( ) == 0 )
        throw std::domain_error("Minimum not defined as there is no data");
    return tinyest;
}

double statistician::maximum( ) const {
    if ( this->length( ) == 0 )
        throw std::domain_error("Maximum not defined as there is no data");
    return largest;
}

statistician  operator *(double scale, statistician& s) {
    statistician temp(s);

    temp.total   *= scale;
    temp.tinyest *= scale;
    temp.largest *= scale;

    if ( scale < 0 ) std::swap(temp.tinyest, temp.largest);

    return temp;
}

statistician operator +(const statistician s1, const statistician s2) {
    statistician temp;

    temp.count = s1.count + s2.count;
    temp.total = s1.total + s2.total;
    if ( s1.tinyest < s2.tinyest )
        temp.tinyest = s1.tinyest;
    else temp.tinyest = s2.tinyest;
    if ( s1.largest > s2.largest ) 
        temp.largest = s1.largest;
    else temp.largest = s2.largest;

    return temp;
}

bool operator ==(const statistician& s1, const statistician& s2) {
    if (s1.length( ) == 0 && s2.length( ) == 0) return true;

    return ( s1.length( )  == s2.length( )  ) &&
           ( s1.sum( )     == s2.sum( )     ) &&
           ( s1.minimum( ) == s2.minimum( ) ) &&
           ( s1.maximum( ) == s2.maximum( ) );
}

std::ostream& operator <<(std::ostream& outs, const statistician& s1) {
    outs << s1.toString();
    return outs;
}

