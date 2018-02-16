// FILE: bag1.cxx
// CLASS IMPLEMENTED: bag (see bag1.h for documentation)
// INVARIANT for the bag class:
//   1. The number of items in the bag is in the member variable used;
//   2. The bag's capacity is maintained in the member variable capacity;
//   3. For an empty bag, we do not care what is stored in any of data; for a
//      non-empty bag the items in the bag are stored in data[0] through
//      data[used-1], and we don't care what's in the rest of data.

#include <algorithm> // Provides copy function
#include <cassert>   // Provides assert function
#include <sstream>   // Provides ostream
#include <string>    // Provides string
#include <stdexcept> // Provides exceptions
#include "bag2.h"

using namespace std;

typedef bag::size_type size_type;  //render typedef visible at outer scope

bag::bag(size_type initialCapacity) {
    this->used = 0;
    if ( initialCapacity < 1 )
        throw std::invalid_argument("initialCapacity must be > 0");
    this->data = new value_type[initialCapacity];
    this->capacity = initialCapacity;
}

bag::bag(const bag& other) {
    this->used = other.used;
    this->data = new value_type[other.used];
    this->capacity = other.used;
    copy(other.data, other.data + other.used, this->data);
}

bag::~bag() {
    //cout << "In destructor deleting data with " << this->capacity << " element array\n";
    delete [] this->data;
    this->data = NULL;
}

void bag::ensureCapacity(size_type newCapacity) {
    if ( newCapacity < 1 )
        throw std::invalid_argument("newCapacity must be > 0");
    //cout << "this bag at entry to ensureCapacity " << *this << endl;
    if ( this->capacity < newCapacity ) {
        // Now we must allocate the bigger array, copy items from this->data
        // into bigger array, deallocate this->data, assign to this->data 
        // the bigger array, etc,
        // STUDENT WORK GOES HERE

    	temp = new value_type(newCapcity);
    	copy(this->data,temp + other.used, this->data);
    	swap(this->data,temp);
    	delete temp;
    }
    //cout << "this bag at exit from ensureCapacity " << *this << endl;
}
    
bag::size_type bag::erase(const value_type& target) {
    size_type index = 0;
    size_type number_removed = 0;

    while (index < this->used) {
        if (this->data[index] == target) {
            --this->used;
            this->data[index] = this->data[this->used];
            ++number_removed;
        }
        else
            ++index;
    }

    return number_removed;
}

bool bag::erase_one(const value_type& target) {
    size_type index; // The location of target in the data array    

    // First, set index to the location of target in the data array,
    // which could be as small as 0 or as large as used-1. If target is not
    // in the array, then index will be set equal to used.
    index = 0; 
    while ((index < this->used) && (this->data[index] != target))
        ++index;

    if (index == this->used)
        return false; // target isn't in the bag, so no work to do.

    // When execution reaches here, target is in the bag at data[index].
    // So, reduce used by 1 and copy the last item onto data[index].
    --this->used;
    this->data[index] = this->data[this->used];    
    return true;
}

size_type bag::getCapacity() const {
    return this->capacity;
}

void bag::insert(const value_type& entry) {
// Library facilities used: stdexcept
    if (this->size( ) == this->capacity)
        this->ensureCapacity( this->capacity * 2 );

    this->data[this->used++] = entry;
}

bag& bag::operator =(const bag& other) {
// Library facilities used:  algorithm
    //Check for possible self-assignment
    if (this == &other) return *this;

    this->used = other.used;
    value_type* newData = new value_type[other.used];

    copy(other.data, other.data + other.used, newData);
    delete [] this->data; this->data = NULL;

    this->data = newData;
    newData = NULL;

    return *this;
}

void bag::operator +=(const bag& addend) {
// Library facilities used: algorithm, stdexcept
    // Guarantee that we have enough room to hald all the items
    // from addend and then copy them into this bag
    // STUDENT WORK GOES HERE
    bag::ensureCapacity(this->used + addend.used);

    used += addend.used;
}

bool bag::operator ==(const bag& comparand) const {
    //check if comparing with self
    if (this == &comparand) return true;

    if (this->size() != comparand.size()) return false;
    bool isEqual = true;
    int index = 0;
    while ( isEqual && index < this->used ) {
        if ( this->data[index] != comparand.data[index] )
            isEqual = false;
        else
            ++index;
    }
    return isEqual;
}

bool bag::operator !=(const bag& comparand) const {
    return !(*this == comparand);
}


bag::size_type bag::occurrences(const value_type& target) const {
    size_type answer;
    size_type i;

    answer = 0;
    for (i = 0; i < this->used; ++i) {
        if (target == this->data[i]) ++answer;
    }
    return answer;
}

string bag::toString( ) const {
//Library facilities used:  sstream, string
    std::stringstream outs;
    outs << "bag with " << this->size() << " elements: [";
    if ( this->size() > 0 ) {
        for (int i=0; i < this->size()-1; ++i) {
            outs << " " << this->data[i];
            outs << ",";
        }
        outs << " " << this->data[this->size()-1];
    }
    outs << " ]";
    outs << " Capacity " << this->capacity;
    return outs.str();
}

void bag::trimToSize() {
    if ( this->used < this->capacity ) {
        int newCapacity;
        if ( this->used <= 1 ) 
            newCapacity = 1;
        else
            newCapacity = this->used;

        // We must allocate a new smaller array, copy the elements 
        // from this->data into the smaller array, deallocate this->data,
        // and then assign to this->data the smaller array
        // STUDENT WORK GOES HERE
    }
}

bag operator +(const bag& b1, const bag& b2) {
    // We must guarantee that the new bag has exactly the 
    // capacity needed to hold all items from both b1 and b2
    // and then copy the items from b1 and then b2 into the new
    // bag
    // STUDENT WORK GOES HERE
    //bag newBag(???));

    return newBag;
}

std::ostream& operator <<(std::ostream& outs, const bag& b1) {
    outs << b1.toString();
    return outs;
}
