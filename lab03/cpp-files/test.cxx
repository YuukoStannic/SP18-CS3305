/*
 * test.cpp
 * Copyright (C) 2018 Jecsan Blanco <jblancolicano1@buffs.wtamu.edu>
 *
 * Distributed under terms of the MIT license.
 */

#include  <iostream>
#include "bag2.h"

using namespace std;


int main(int argc, char* argv[]){

    bag  bag1(5);
    bag  bag2(5);

    bag1.insert(1);
    bag1.insert(2);
    bag1.insert(3);
    bag1.insert(4);
    bag1.insert(5);
   cout << "Bag 1: " << bag1.toString() << endl;

   bag2.insert(5);
   bag2.insert(4);
   bag2.insert(3);
   bag2.insert(2);
   bag2.insert(1);

   cout << "Bag 2: " << bag2.toString() << endl;

   bag1 += bag2;

   cout << "Bag 1: " << bag1.toString() << endl;


}


