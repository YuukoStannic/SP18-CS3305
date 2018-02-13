// FILE: bag2.h
// CLASS PROVIDED: bag 
//
// TYPEDEF and MEMBER CONSTANTS for the bag class:
//   typedef ____ value_type
//     bag::value_type is the data type of the items in the bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   typedef ____ size_type
//     bag::size_type is the data type of any variable that keeps track of how many items
//     are in a bag.
//
// CONSTRUCTOR for the bag class:
//   bag( )
//     Postcondition: The bag has been initialized as an empty bag.
//     May throw std::bad_alloc if not enough memory available
//
//   bag( const bag& source )
//     Postcondition:  The new bag has been initialized as bag with
//     all the elements in source and with capacity to equal that
//     number of elements.
//     May throw std::bad_alloc if not enough memory available
//
// MODIFICATION MEMBER FUNCTIONS for the bag class:
//   void ensureCapacity( size_type newCapacity )
//     Precondition:  newCapacity must be > 0
//     Postcondition: bag's capacity is at least newCapacity
//     May throw std::bad_alloc if not enough memory available
//
//   void trimToSize( )
//     Postcondition:  bag's capacity is reduced to number of
//     elements actually in the bag.  However, capacity can never
//     be reduced to be < 1.
//     May throw std::bad_alloc if not enough memory available
//
//   size_type erase(const value_type& target)
//     Postcondition: All copies of target have been removed from the bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the bag, then one copy has been removed;
//     otherwise the bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been added to the bag.
//
//   bag& operator =(const bag& source)
//     Precondition:  source is not this bag
//     Postcondition: This bag's values are destroyed and replaced
//     with values from source.
//
//   void operator +=(const bag& addend)
//     Precondition:  size( ) + addend.size( ) <= CAPACITY.
//     Postcondition: Each item in addend has been added to this bag.
//
// CONSTANT MEMBER FUNCTIONS for the bag class:
//   size_type getCapacity( ) const
//     Postcondition:  The return value is the total capacity of this bag1
//   size_type size( ) const
//     Postcondition: The return value is the total number of items in the bag.
//
//   size_type occurrences(const value_type& target) const
//     Postcondition: The return value is number of times target is in the bag.
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//     Precondition:  b1.size( ) + b2.size( ) <= bag::CAPACITY.
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//    Assignments and the copy constructor may be used with bag objects.

#ifndef BAG1_H
#define BAG1_H
#include <cstdlib>  // Provides size_t
#include <string>   // Provides string
#include <iostream> // Provides ostream

class bag { 
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef std::size_t size_type;

        // CONSTRUCTORS
        bag(size_type initialCapacity = 1);
        bag(const bag& other);

        // DESTRUCTOR
        ~bag();

        // MODIFICATION MEMBER FUNCTIONS
        void ensureCapacity(const size_type newCapacity);
        size_type erase(const value_type& target);
        bool erase_one(const value_type& target);
        void insert(const value_type& entry);
        void trimToSize( );
        bag& operator =(const bag& source);
        void operator +=(const bag& addend);

        // CONSTANT MEMBER FUNCTIONS
        size_type getCapacity( ) const;
        bool operator ==(const bag& comparand) const;
        bool operator !=(const bag& comparand) const;
        size_type occurrences(const value_type& target) const;
        size_type size( ) const { return used; }
        std::string toString( ) const;

    private:
        value_type* data;   // The array to store items
        size_type used;     // How much of array is used
        size_type capacity; // How big is array holding data
};

    // NONMEMBER FUNCTIONS for the bag class
    bag operator +(const bag& b1, const bag& b2);
    std::ostream& operator <<(std::ostream& outs, const bag& b1);
#endif
