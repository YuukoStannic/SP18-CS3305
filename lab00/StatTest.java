/*
 * StatTest.java
 * Copyright (C) 2018 Jecsan Blanco <jblancolicano1@buffs.wtamu.edu>
 *
 * Distributed under terms of the MIT license.
 *
 *   @author Jecsan Blanco
 *   @version 1.0
 *   @since  01/25/2018
 */

public class StatTest
{
    public static void main(String[] args){
        Statistician foo = new Statistician();
        Statistician bar = new Statistician();
        Object foobar = new Object();

        System.out.printf("Test 0.1: equals (null) \n \t Testing foo: %s \n",foo);
        System.out.printf("\t Expected False and got it %b\n",!foo.equals(foobar));

        System.out.printf("Test 0.1: equals (self) \n \t Testing foo: %s \n",foo);

        foo.count = 3;
        foo.total = 3;
        foo.tinyest = 3;
        foo.largest = 3;

        bar.count = 3;
        bar.total = 3;
        bar.tinyest = 3;
        bar.largest = 3;


        System.out.printf("\t Expected True and got it %b\n",foo.equals(foo));

        System.out.printf("Test 0.2: equals \n \t Testing foo: %s \n \t with bar: %s \n",foo,bar);
        System.out.printf("\t Expected True and got it %b\n",bar.equals(foo) && foo.equals(bar));

        bar.count = 4;
        bar.total = 3;
        bar.tinyest = 3;
        bar.largest = 3;


        System.out.printf("Test 0.3: equals \n \t Testing foo: %s \n \t with bar: %s \n",foo,bar);
        System.out.printf("\t Expected False  and got it %b\n",!(bar.equals(foo) && foo.equals(bar)));

        
        



        
	}
}
