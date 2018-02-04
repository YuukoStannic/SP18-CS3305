#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <limits>

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
    //from climits 
    this->tinyest = std::numeric_limits<int>::max();
    this->largest = std::numeric_limits<int>::min();
}

statistician::statistician(const statistician& other) {
    this->count   = other.count;
    this->total   = other.total;
    this->tinyest = other.tinyest;
    this->largest = other.largest;
}

void statistician::next(double number) {
    this->count++;
    this->total += number;
    // Students complete here
    if(count == 1){
        this->largest = this->tinyest = number;
    }else{
        this->largest = (number >= this->largest) ? number : this->largest;
        this->tinyest = (number <= this->tinyest) ? number : this->tinyest;
    }
}

void statistician::reset( ) {
    count = 0;
    total = 0;
    this->tinyest = std::numeric_limits<int>::max();
    this->largest = std::numeric_limits<int>::min();
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

    // Students complete this
    //
    temp.total   *= scale;
    temp.tinyest *= scale; 
    temp.largest *= scale; 

    if(scale <  0){
        double t = temp.tinyest;
        temp.tinyest = temp.largest;
        temp.largest = t;
    }

    return temp;
}

statistician operator +(const statistician s1, const statistician s2) {
    statistician temp;
    // Students write the code to define temp to be the union
    // of s1 and s2
    if(s1.length() && s2.length()){
        temp.count  = (s1.length() + s2.length());
        temp.total  = (s1.sum() + s2.sum());
        temp.largest = (s1.maximum() >= s2.maximum()) ? s1.maximum() : s2.maximum();
        temp.tinyest = (s1.minimum() <= s2.minimum()) ? s1.minimum() : s2.minimum();
    }else{
        temp  = (s1.length()) ? s1 : s2;
    }

    return temp;
}

bool operator ==(const statistician& s1, const statistician& s2) {

    // Students must now evaluate whether all attributes of s1
    // are equal, one by one, to the attributes of s2
    // replace the bogus return with your implementation
    if ( &s1 == &s2 ) return true;
    return ((s1.length() == s2.length()) && (s1.sum() == s2.sum()) && (s1.minimum() == s2.minimum())
            && (s1.maximum() == s2.maximum()));
}


std::ostream& operator <<(std::ostream& outs, const statistician& s1) {
    outs << s1.toString();
    return outs;
}

