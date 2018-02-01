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
    this->count = 0;
    this->total = 0;
    this->tinyest =  3.4E+38;
    this->largest = -3.4E+38;
}

statistician::statistician(const statistician& other) {
    if(&other == NULL)
        std::invalid_argument("other is NULL");        
    this->count   = other.count;
    this->total   = other.total;
    this->tinyest = other.tinyest;
    this->largest = other.largest;
}

void statistician::next(double number) {
    this->count++;
    this->total += number;
    // Students complete here
    this->largest = (number >= this->largest) ? number : this->largest;
    this->tinyest = (number <= this->tinyest) ? number : this->tinyest;
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
    if(&other == NULL)
        std::invalid_argument("other is NULL");        
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

    // Students complete this
    //
    return temp;
}

statistician operator +(const statistician s1, const statistician s2) {
    statistician temp;

    // Students write the code to define temp to be the union
    // of s1 and s2


    return temp;
}

bool operator ==(const statistician& s1, const statistician& s2) {
    if(&s1 == NULL || &s2 == NULL)
        std::invalid_argument("s1 or s2 is NULL");        
    if (s1.length( ) == 0 && s2.length( ) == 0) return true;

    // Students must now evaluate whether all attributes of s1
    // are equal, one by one, to the attributes of s2
    // replace the bogus return with your implementation
    return ((s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum())
            && (s1.maximum() == s2.maximum()) && (s1.mean() == s2.mean()));
}


std::ostream& operator <<(std::ostream& outs, const statistician& s1) {
    outs << s1.toString();
    return outs;
}

