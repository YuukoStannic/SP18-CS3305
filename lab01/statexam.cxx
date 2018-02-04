// FILE: statexam.cxx
// This program calls five test functions to test the statisitician class.
// Maximum number of points from this program is 90.

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "statistician.h"

using namespace std;

bool close(double a, double b) {
    const double EPSILON = 1e-5;
    return (fabs(a-b) < EPSILON);
}

int test1( ) {
    // Test program for basic statistician functions.
    // Returns 51 if everything goes okay; otherwise returns 0.

    statistician s, t;
    int points = 0;

    int i;
    double r = 0;

    if (s.length( ) || t.length( )) return 0;
    points += 3;

    if (s.sum( ) || t.sum( )) return 0;
    points += 3;

    try {
        s.mean(); //should fail
        return 0;
    }
    catch (domain_error e) { 
        points += 4;
    }

    for (i = 1; i <= 10000; i++) {
	s.next(i);
	r += i;
    };

    if (t.length( ) || t.sum( )) return 0;
    points += 3;

    if (s.length( ) != 10000) return 0;
    points += 5;

    if (!close(s.sum( ), r)) return 0;
    points += 5;

    if (!close(s.mean( ), r/10000)) return 0;
    points += 5;

    
    // Reset and then retest everything
    s.reset( );
    t.reset( );
    r = 0;
    
    if (s.length( ) || t.length( )) return 0;
    points += 3;

    if (s.sum( ) || t.sum( )) return 0;
    points += 3;

    try {
        s.mean(); //should fail
        return 0;
    }
    catch (domain_error e) { 
        points += 5;
    }

    for (i = 1; i <= 10000; i++) {
	s.next(i);
	r += i;
    };

    if (t.length( ) || t.sum( )) return 0;
    points += 3;

    if (s.length( ) != 10000) return 0;
    points += 3;

    if (!close(s.sum( ), r)) return 0;
    points += 3;

    if (!close(s.mean( ), r/10000)) return 0;
    points += 3;


    cout << "points from this test " << points << endl;
    return points;
}

int test2( ) {
    // Test program for minimum/maximum statistician functions.
    // Returns 10 if everything goes okay; otherwise returns 0.

    statistician s, t, u;
    int points = 0;

    if (s.length( ) || t.length( )) return 0;
    points += 1;
    if (s.sum( ) || t.sum( )) return 0;
    points += 1;

    try {
        s.minimum(); //should fail
        return 0;
    }
    catch (domain_error e) {
        points += 1;
    }
    try {
        s.maximum(); //should fail
        return 0;
    }
    catch (domain_error e) {
        points += 1;
    }

    double r = 1.39804e-76;
    r = 1/r;
    s.next(r);
    std::cout <<"r"<<r<<std::endl;
    std::cout <<"m"<<s.maximum()<<" max:"<<s.maximum()<<std::endl;
    if ((s.minimum( ) != r) || (s.maximum( ) != r)) return 0;
    points += 2;

    r *= -1;
    t.next(r);
    if ((t.minimum( ) != r) || (t.maximum( ) != r)) return 0;
    points += 2;

    u.next(100); u.next(-1); u.next(101); u.next(3);
    if ((u.minimum( ) != -1) || (u.maximum( ) != 101)) return 0;
    points += 2;

    cout << "points from this test " << points << endl;
    return points;
}

int test3( ) {
    // Test program for + operator of the statistician
    // Returns 10 if everything goes okay; otherwise returns 0.

    statistician s, t, u, v;
    int points = 0;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;


    t.next(5);
    u.next(0); u.next(10); u.next(10); u.next(20);

    cout << "got here1" << endl;
    v = s + s;
    if (v.length( ) || v.sum( )) return 0;
    points += 2;
    cout << "got here2" << endl;

    v = s + u;
    cout <<"s = " << s << endl;
    cout <<"u = " << u << endl;
    cout <<"v = " << v << endl;
    if (!(u == v)) return 0;
    points += 2;

    cout << "got here3" << endl;
    v = t + s;
    if (!(t == v)) return 0;
    points += 2;

    cout << "got here4" << endl;
    v = t + u;
    if (v.length( ) != 5) return 0;
    if (!close(v.sum( ), 45)) return 0;
    if (v.minimum( ) != 0) return 0;
    if (v.maximum( ) != 20) return 0;
    if (!close(v.mean( ), 45.0/5)) return 0;
    points += 2;

    v = v + t;
    if (v.length( ) != 6) return 0;
    if (!close(v.sum( ), 50)) return 0;
    if (v.minimum( ) != 0) return 0;
    if (v.maximum( ) != 20) return 0;
    if (!close(v.mean( ), 50.0/6)) return 0;
    points += 2;

    cout << "points from this test " << points << endl;
    return points;
}

int test4( ) {
    // Test program for * operator of the statistician
    // Returns 17 if everything goes okay; otherwise returns 0.

    statistician s, t, u;
    int points = 0;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    u.next(0); u.next(10); u.next(10); u.next(20);

    s = 2*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), 80)) return 0;
    if (s.minimum( ) != 0) return 0;
    if (s.maximum( ) != 40) return 0;
    if (!close(s.mean( ), 80.0/4)) return 0;
    points += 2;

    s = -2*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), -80)) return 0;
    if (s.minimum( ) != -40) return 0;
    if (s.maximum( ) != 0) return 0;
    if (!close(s.mean( ), -80.0/4)) return 0;
    points += 11;

    s = 0*u;
    if (s.length( ) != 4) return 0;
    if (!close(s.sum( ), 0)) return 0;
    if (s.minimum( ) != 0) return 0;
    if (s.maximum( ) != 0) return 0;
    if (!close(s.mean( ), 0)) return 0;
    points += 2;

    s = 10 * t;
    if (s.length( ) != 0) return 0;
    if (s.sum( ) != 0) return 0;
    points += 2;

    cout << "points from this test " << points << endl;
    return points;
}

int test5( ) {
    // Test program for == operator of the statistician.
    // Returns 12 if everything goes okay; otherwise returns 0.

    statistician s, t, u, v, w, x;
    int points = 0;

    if (s.length( ) || t.length( )) return 0;
    if (s.sum( ) || t.sum( )) return 0;

    t.next(10);
    u.next(0); u.next(10); u.next(10); u.next(20);
    v.next(5); v.next(0); v.next(20); v.next(15);
    w.next(0);
    x.next(0); x.next(0);
    
    if (!(s == s)) return 0;
    points += 2;
    cout << "Got here" << endl;
    if (s == t) return 0;
    points += 2;
    cout << "Got here1" << endl;
    if (t == s) return 0;
    cout << "Got here2" << endl;
    if (t == s) return 0;
    cout << "Got here3" << endl;
    points += 2;
    if (u == t) return 0;
    cout << "Got here4" << endl;
    points += 2;
    if (!(u == v)) return 0;
    cout << "Got here5" << endl;
    points += 2;
    if (w == x) return 0;
    cout << "Got here6" << endl;
    points += 2;

    cout << "points from this test " << points << endl;
    return points;
}

int main( ) {
    int value = 0;
    int result;
    
    cerr << "Running statistician tests:" << endl;
 
    cerr << "TEST 1:" << endl;
    cerr << "Testing next, reset, length, sum, and mean (51 points).\n";
    result = test1( );
    value += result;
    if (result > 0) cerr << "Test 1 passed." << endl << endl;
    else cerr << "Test 1 failed." << endl << endl; 
 
    cerr << "\nTEST 2:" << endl;
    cerr << "Testing minimum and maximum member functions (10 points).\n";
    result = test2( );
    value += result;
    if (result > 0) cerr << "Test 2 passed." << endl << endl;
    else cerr << "Test 2 failed." << endl << endl; 
 
    cerr << "\nTEST 3:" << endl;
    cerr << "Testing the + operator (10 points).\n";
    result = test3( );
    value += result;
    if (result > 0) cerr << "Test 3 passed." << endl << endl;
    else cerr << "Test 3 failed." << endl << endl; 
 
    cerr << "\nTEST 4:" << endl;
    cerr << "Testing the * operator (17 points).\n";
    result = test4( );
    value += result;
    if (result > 0) cerr << "Test 4 passed." << endl << endl;
    else cerr << "Test 4 failed." << endl << endl; 

    cerr << "\nTEST 5:" << endl;
    cerr << "Testing the == operator (12 points).\n";
    result = test5( );
    value += result;
    if (result > 0) cerr << "Test 5 passed." << endl << endl;
    else cerr << "Test 5 failed." << endl << endl; 

    cerr << "If you submit the statistician to Prof. Haiduk now, this part of the\n";
    cerr << "grade will be " << value << " points out of 100.\n";
    
    return EXIT_SUCCESS;

}












