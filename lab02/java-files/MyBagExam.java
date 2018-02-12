/*
 * MyBagExam.java
 * Copyright (C) 2018 Jecsan Blanco <jblancolicano1@buffs.wtamu.edu>
 *
 * Distributed under terms of the MIT license.
 *
 *   @author Jecsan Blanco
 *   @version 1.0
 *   @since  02/11/2018
 */

public class MyBagExam
{
    public static void main(String[] args){

        DoubleArrayBag myBag = new DoubleArrayBag();
        DoubleArrayBag myBag2 = new DoubleArrayBag();

        // System.out.printf("Testing equality of empty bags: \n \t  empty myBag is equal to empty myBag2:\t" + 
        //         "Expexted true and got it: %b\n",myBag.equals(myBag2) && myBag2.equals(myBag));
        // System.out.println("Bag1:" + ( myBag.toString()));
        // System.out.println("Bag2:" + ( myBag2.toString()));

        // System.out.println();

        // myBag2.insert(20);
        // System.out.printf("Testing equality of non equal bags: \n \t empty myBag is not equal to non-empty myBag2:\t" +
        //         "Expected false and got it: %b\n",!myBag.equals(myBag2));

        // myBag = new DoubleArrayBag(myBag2);
        // System.out.println();
        // System.out.printf("Testing copy constructor: \n \t myBag is equal to non-empty myBag2:\t" +
        //         "Expected true  and got it: %b\n",myBag.equals(myBag2));

        // System.out.println("Bag1:" + ( myBag.toString()));
        // System.out.println();

        // System.out.println("Bag2:" + ( myBag2.toString()));

        // myBag = myBag2.clone();
        // System.out.printf("Testing equality of cloned bags: \n \t myBag is equal myBag2:\t" +
        //         "Expected true  and got it: %b\n",myBag.equals(myBag2));
        // System.out.println("Bag1:" + ( myBag.toString()));
        // System.out.println("Bag2:" + ( myBag2.toString()));

        // System.out.println();

        // myBag.insert(21);
        // System.out.printf("Testing equality of bags: \n \t myBag is not  equal myBag2:\t" +
        //         "Expected false  and got it: %b\n",!myBag.equals(myBag2));

        // System.out.println("Bag1:" + ( myBag.toString()));
        // System.out.println("Bag2:" + ( myBag2.toString()));

        // System.out.printf("Testing occurrences  of 21 in bag1: \n \t 21 accurs 1 time:\t" +
        //         "Expected 1  and got it: %b\n",myBag.occurrences(21) == 1);

        // myBag.insert(21);
        // myBag.insert(21);
        // myBag.insert(21);
        // myBag.insert(21);

        // System.out.println("Bag1:" + ( myBag.toString()));
        // System.out.printf("Testing occurrences  of 21 in bag1: \n \t 21 accurs 5 time:\t" +
        //         "Expected 5  and got it: %b\n",myBag.occurrences(21) == 5);


        // System.out.println("Before Bag1:" + ( myBag.toString()));
        // System.out.printf("Testing clear  21 in bag1: \n \t 21 accurs 5 time:\t" +
        //         "Expected 5  and got it: %b\n",myBag.erase(21) == 5);
        // System.out.println("After Bag1:" + ( myBag.toString()));

        DoubleArrayBag test = new DoubleArrayBag();            
        System.out.printf("Inserting these: 8 6 10 1 7 10 15 3 13 2 5 11 14 4 12\n");
        test.insert( 8);
        test.insert( 6);
        test.insert(10);
        test.insert( 1);
        test.insert( 7);
        test.insert(10);
        test.insert(15);
        test.insert( 3);
        test.insert(13);
        test.insert( 2);
        test.insert( 5);
        test.insert(11);
        test.insert(14);
        test.insert( 4);
        test.insert(12);
        System.out.println(test);

        test.erase(0);
        System.out.println(test);

        
	}

}

