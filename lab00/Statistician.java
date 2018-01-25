// File: Statistician.java
// This is an assignment for students to complete after reading Chapter 2 of
// "Data Structures and Other Objects Using Java" by Michael Main.


/******************************************************************************
* This class is a homework assignment;									       
* A <CODE>Statistician</CODE> keeps track of statistics about a sequence of
* double numbers.<br>
*
* <b>Note:</b><br>
*   This file contains only blank implementations ("stubs") for many of
*   the methods because this is a Programming Project for students in Prof. Haiduk's
*   CS 3305 class
*
* @version
*   Jan 23, 2018
******************************************************************************/
public class Statistician {   

   //  Here we define the "instance" variables that hold
   //  the "state" information for objects of this class.
   //  What should they be given that we are obligated to 
   //  report to a user such "statistics" as mean, sum,
   //  maximum, minimum and length AND we are NOT going to
   //  save all the values
   //
   //  Class invariant:  the attributes/instance variables count,
   //  total, tinyest, and largest are used to derive the statistics
   //  and define the state of a statistician object

    // private int    count;   // How many numbers in the sequence
    // private double total;   // The sum of all the numbers in the sequence
    // private double tinyest; // The smallest number in the sequence
    // private double largest; // The largest number in the sequence
     int    count;   // How many numbers in the sequence
     double total;   // The sum of all the numbers in the sequence
     double tinyest; // The smallest number in the sequence
     double largest; // The largest number in the sequence



   /**
   * Initialize a new Statistician <br>
   * <b>Postcondition:</b><br>
   *   This Statistician is newly initialized and has not yet been given any 
   *   numbers.
   **/   
   public Statistician( ) {
      this.count    = 0;
      this.total    = 0.0;
      this.tinyest  = +Double.MAX_VALUE;
      this.largest  = -Double.MAX_VALUE;
   } 

   /**
   * Initialize a new Statistician as a copy of another Statistician <br>
   * @param other
   *     other is a non-null reference to another Statistician
   * <b>Precondition:</b><br>
   *   Other is not null.  If it is, then throw NullPointerException
   * <b>Postcondition:</b><br>
   *   This Statistician is newly initialized and has been given attributes
   *   equal to those of other
   **/   
   public Statistician( Statistician other ) {
      // Student implementation.      
   }  


   /**
   * Compare this <CODE>Statistician</CODE> to another object for equality.
   * @param obj
   *   an object with which this <CODE>Statistician</CODE> will be compared
   * @return
   *   A return value of <CODE>true</CODE> indicates that 
   *   <CODE>obj</CODE> refers to a 
   *   <CODE>Statistican</CODE> object with the same length, sum,
   *   minimum and maximum as this 
   *   <CODE>Statistician</CODE>. Otherwise the return value is 
   *   <CODE>false</CODE>.<br>
   * <b>Note:</b><br>
   *   If <CODE>obj</CODE> is null or does not refer to a 
   *   <CODE>Statistician</CODE> object, then the answer is 
   *   <CODE>false</CODE>.
   **/  
   @Override
   public boolean equals(Object obj) {

      boolean answer = false;

      if ( obj == null ) return false;
      if ( !(obj instanceof Statistician) ) return false;

      Statistician other = (Statistician) obj;
      if ( this == other ) return true; //Are we comparing with ourself
      if ( this.length( ) == 0 &&  other.length( ) == 0 ) return true;

      // The student's code will replace this return statement:
      if(this.count == other.count && this.total == other.total
              && this.tinyest == other.tinyest && this.largest == other.largest) return true;
      return false;
   } 
   
   
   /**
   * Determine how many numbers have been given to this Statistician.
   * @return
   *   the count of how many numbers have been given to this Statistician
   *   since it was initialized or reinitialized <br>
   * <b>Note:</b><br>
   *   Giving a Statistician more than
   *   <CODE>Integer.MAX_VALUE</CODE> numbers, will
   *   cause failure with an arithmetic overflow.
   **/ 
   public int length( ) {
      return count;
   }

   /**
   * Determine the largest number that has been given 
   * to this Statistician.
   * @return
   *   the largest number that has been given to this 
   *   Statistician since it was initialized or reinitialized<br>
   * <b>Note:</b><br>
   *   If <CODE>length()</CODE> is zero, then the answer from this method
   *   is <CODE>Double.NaN</CODE>.
   **/ 
   public double maximum( ) {
      // The student's code will replace this return statement:
      return 0.0;
   }

   /**
   * Determine the arithmetic average of all the numbers that have been given 
   * to this Statistician.
   * @return
   *   the arithmetic mean of all the number that have been given to this 
   *   Statistician
   *   since it was initialized or reinitializeda<br>
   * <b>Note:</b><br>
   *   If this Statistician has been given more than
   *   <CODE>Integer.MAX_VALUE</CODE> numbers, then this method fails
   *   because of arithmetic overflow.
   *   If <CODE>length()</CODE> is zero, then the answer from this method
   *   is <CODE>Double.NaN</CODE>.
   *   If <CODE>sum()</CODE> exceeds the bounds of double numbers, then the 
   *   answer from this method may be 
   *   <CODE>Double.POSITIVE_INFINITY</CODE> or
   *   <CODE>Double.NEGATIVE_INFINITY</CODE>.
   **/ 
   public double mean( ) {
      // The student's code will replace this return statement:
      return 0.0;
   }


   /**
   * Determine the smallest number that has been given 
   * to this Statistician.
   * @return
   *   the smallest number that has been given to this 
   *   Statistician since it was initialized or reinitialized<br>
   * <b>Note:</b><br>
   *   If <CODE>length()</CODE> is zero, then the answer from this method
   *   is <CODE>Double.NaN</CODE>.
   **/ 
   public double minimum( ) {
      // The student's code will replace this return statement:
      return 0.0;
   }


   /**
   * Give a new number to this Statistician. 
   * @param number
   *   the new number that is being given to this Statisticiana<br>
   * <b>Postcondition:</b><br>
   *   The specified number has been given to this Statistician and
   *   it will be included in any subsequent statistics
   **/
   public void nextNumber(double number) {
      // Student implementation -- this must update all the
      // instance variables
   }

   
   /**
   * Reset this Statistician to state with no numbers
   * in the sequence. <br>
   *
   * <b>Postcondition:</b><br>
   *   This Statistician is reinitialized as if it has never been given any 
   *   numbers
   **/
   public void reset( ) {
      // Student implementation.
   }

   /**
    * Create a new Statistician whose state is scaled by parameter scale--
    * such that "statistics" other than length() are multiplied by scale.
    * <b>Postcondition:</b><br>
    *   The returned Statistician is a scaled copy of parameter s which 
    *   is not modified.
    * @param scale
    *   a double scale factor
    * @param s
    *   a reference to a Statistician
    * @return
    *   a reference to a new Statiscian that is a scaled copy of parameter s
    **/
   public static Statistician scale(double scale, Statistician s) {
       Statistician temp = new Statistician(s);

       //Student implementation here

       return temp;
   }

   /**
   * Create a string representation of this Statistician.
   * <b>Postcondition:</b><br>
   *   State of the Statistician remains unaltered by this method
   * @return String
   *   a human readable representation of the Statistician's internal
   *   state
   **/
   @Override
   public String toString( ) {
       StringBuffer sb = new StringBuffer();
       sb.append("Statistician: \n");
       sb.append("\tcount = " + this.count + "\n");
       sb.append("\ttotal = " + this.total + "\n");
       if ( this.count == 0 ) {
           sb.append("\tmean  = NOT DEFINED\n");
           sb.append("\tmin   = NOT DEFINED\n");
           sb.append("\tmax   = NOT DEFINED\n");
       }
       else {
           sb.append("\tmean  = " + this.mean()  + "\n");
           sb.append("\tmin   = " + this.tinyest + "\n");
           sb.append("\tmax   = " + this.largest + "\n");
       }

       return sb.toString();
   }

   /**
   * Determine the sum of all the numbers that have been given to this 
   * Statistician.
   * @return
   *   the sum of all the number that have been given to this 
   *   Statistician since it was initialized or reinitialized <br>
   * <b>Note:</b><br>
   *   If the sum exceeds the bounds of double numbers, then the answer
   *   from this method may be 
   *   <CODE>Double.POSITIVE_INFINITY</CODE> or
   *   <CODE>Double.NEGATIVE_INFINITY</CODE>.
   **/ 
   public double sum( ) {
      return this.total;
   }

   /**
   * Create a new Statistician that behaves as if it was given all the
   * numbers from two other statisticians.
   * @param  s1
   *   the first of two Statisticians
   * @param s2
   *   the second of two Statisticians <br>
   * <b>Precondition:</b><br>
   *   Neither s1 nor s2 is null.
   * @return
   *   a new Statistician that acts as if it was given all the numbers from
   *   s1 and s2.
   * @throws NullPointerException
   *   Indicates that one or the other or both of the arguments are null.
   **/   
   public static Statistician union(Statistician s1, Statistician s2) {
      if ( s1 == null || s2 == null )
          throw new NullPointerException("One or both arguments are null");

      Statistician temp = new Statistician();

      // The student's code will replace this return statement:

      return null;
   }
      
}
           
