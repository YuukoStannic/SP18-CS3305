import java.util.Iterator;
import java.util.NoSuchElementException;
import java.util.Arrays;
import java.util.Objects;

public class LongArraySequence implements Cloneable, Iterable<Long> {

    // ***************************************************
    // ATTRIBUTES/PROPERTIES
    // ***************************************************

    private int used;
    private int cursor;
    private long[] data;

    // ***************************************************
    //                  CONSTRUCTORS
    // ***************************************************

    /* default constructor */
    public LongArraySequence() {
        this.used = 0;
        this.cursor = 0;
        this.data = new long[1];
    }

    /* parameterized constructor */
    public LongArraySequence(int initialCapacity) {
        if (initialCapacity < 1)
            throw new IllegalArgumentException("initialCapacity must be > 0");
        this.used = 0;
        this.cursor = 0;
        try {
            this.data = new long[initialCapacity];
        } catch (OutOfMemoryError err) {
            throw new OutOfMemoryError("Could not accommodate capacity request");
        }
    }

    /* copy constructor */
    public LongArraySequence(LongArraySequence other) {
        if (other == null) {
            throw new NullPointerException("other must not be null");
        }

        this.data = new long[other.used];
        this.cursor = other.cursor;
        this.used = other.used;
        for (int index = 0; index < this.used; index++) {
            this.data[index] = other.data[index];
        }
        /* or use below
        System.arraycopy(other.data, 0, this.data, 0, other.used);
        */
    }

    @Override
    public LongArraySequence clone() {
        LongArraySequence result;

        try {
            result = (LongArraySequence) super.clone();
            result.data = this.data.clone();
            return result;
        } catch (CloneNotSupportedException e) {
            throw new RuntimeException("This class does not implement Cloneable");
        }
    }

    // ***************************************************
    //                  ACCESSORS
    // ***************************************************

    @Override
    public boolean equals(Object other) {
        if (!(other instanceof LongArraySequence)) return false;
        LongArraySequence candidate = (LongArraySequence) other;

        if (candidate == null) return false;
        if (this == candidate) return true;

        boolean isEqual = true; //assume equal until proven otherwise
        //
        //STUDENT WORK HERE
        //
        return isEqual;
    }

    @Override
    public int hashCode() {

        int hashValue = Objects.hash(this.used) +
                Objects.hash(this.cursor);

        for (int index = 0; index < this.used; ++index) {
            hashValue += Objects.hash(this.data[index]);
        }
        return hashValue;
    }

    @Override
    public String toString() {
        StringBuffer sb = new StringBuffer();
        sb.append("LongArraySequence: ");
        sb.append(this.used);
        sb.append(" items");
        sb.append("-->[ ");
        if (this.used > 0) {
            if (this.cursor == 0)
                sb.append("^");
            sb.append(this.data[0]);
            for (int index = 1; index < this.used; index++) {
                sb.append(", ");
                if (index == this.cursor)
                    sb.append("^");
                sb.append(this.data[index]);
            }
        }
        sb.append(" ]");
        sb.append(" Capacity: ");
        sb.append(this.data.length);

        return sb.toString();
    }

    public int size() {
        return this.used;
    }

    public int getCapacity() {
        return this.data.length;
    }

    public boolean isCurrent() {
        return this.cursor < this.used && this.cursor >= 0;
    }

    public long getCurrent() {
        if (!this.isCurrent()) {
            throw new IllegalStateException("There is no current element");
        }
        return this.data[this.cursor];
    }

    // ***************************************************
    //                  MUTATORS
    // ***************************************************

    public void ensureCapacity(int minimumCapacity) {
        if (minimumCapacity < 1)
            throw new IllegalArgumentException("minimumCapacity must be >= 1");

        if (this.data.length < minimumCapacity) {
            try {
                long[] biggerArray = new long[minimumCapacity];
                for (int index = 0; index < this.used; index++)
                    biggerArray[index] = this.data[index];
                this.data = biggerArray;
            } catch (OutOfMemoryError err) {
                throw new OutOfMemoryError("Could not expand capacity --" +
                        "capacity remains the same");
            }
        }
    }

    public void trimToSize() {
        if (this.used == 0) {
            this.data = new long[1];
            this.cursor = 1;
            return;
        }
        if (this.used < this.data.length) {
            try {
                long[] trimmedArray = new long[this.used];
                for (int index = 0; index < this.used; index++)
                    trimmedArray[index] = this.data[index];
                this.data = trimmedArray;
            } catch (OutOfMemoryError err) {
                throw new OutOfMemoryError("Not enough dynamic memory available to trim --" +
                        " capacity not changed");
            }
        }
    }

    public LongArraySequence concatenation(LongArraySequence other) {
        if (other == null) {
            throw new NullPointerException("other must be non-null");
        }
        int newCapacity = this.used + other.used;
        LongArraySequence newSequence = new LongArraySequence(newCapacity);
        newSequence.cursor = 0;
        newSequence.used = newCapacity;

        int toIndex, fromIndex;
        toIndex = fromIndex = 0;

        while (fromIndex < this.used) {
            newSequence.data[toIndex] = this.data[fromIndex];
            toIndex++;
            fromIndex++;
        }

        fromIndex = 0;
        while (fromIndex < other.used) {
            newSequence.data[toIndex] = other.data[fromIndex];
            toIndex++;
            fromIndex++;
        }

        return newSequence;
    }


    public void start() {
        this.cursor = 0;
    }

    public void advance() {
        if (this.cursor == this.used)
            throw new IllegalStateException("Attempting to advance cursor beyond end of sequence");
        else
            this.cursor++;
    }

    public void addBefore(long newEntry) {
        /**
         adds newEntry to the LongArraySequence if capacity available;
         otherwise, capacity is expanded to accommodate addition -- newEntry
         placed in position immediately before the cursor's position
         or at beginning of sequence if there is no valid current position
         of cursor

         Precondition:
         newEntry must be an integer; otherwise,
         method raises a TypeError exception.

         Postcondition:
         If isCurrent() is True then newEntry is placed
         in sequence just before the entry at the cursor's
         position.  If not isCurrent(), then newEntry is
         placed at the beginning of the sequence. The
         internal cursor remains at same relative position
         and, thus, is "pointing" to the newEntry.

         @parm newEntry (int)

         @throws OutOfMemoryError
         MemoryError if not enough dynamic memory
         available to accommodate expansion
         **/
        if (this.data.length == this.used)
            this.ensureCapacity(this.used * 2);
        if (isCurrent() && (this.cursor != 0)) {
            this.cursor--;
            this.addAfter(newEntry);
        } else {
            System.arraycopy(this.data, 0, this.data, 1, this.used);
            this.start();
            this.data[0] = newEntry;
            this.used++;
        }

    }

    public void addAfter(long newEntry) {
        /**
         Adds newEntry to the LongArraySequence if capacity available;
         otherwise, capacity is expanded to accommodate addition -- newEntry
         placed in position immediately after the cursor's position
         or at end of sequence if there is no valid current position of cursor

         Precondition:
         newEntry must be an integer or long

         Postcondition:
         If isCurrent() is True then newEntry is placed
         in sequence just after the entry at the cursor's
         position.  If not isCurrent(), then newEntry is
         placed at the end of the sequence.  The internal
         cursor "points" to this newEntry.  Otherwise, relative
         ordering of elements remains unchanged except for the
         newElement being inserted into the sequence.

         @args newEntry (int)

         @throws OutOfMemoryError
         if not enough dynamic memory
         available to accommodate expansion
         **/

        if (this.data.length == this.used)
            this.ensureCapacity(this.used * 2);
        if (isCurrent() && (this.cursor != this.used - 1)) {
            //there is a cursor and it is not at the end
            //                 from        start           to           from               how many
            System.arraycopy(this.data, this.cursor + 1, this.data, this.cursor + 2, this.used - this.cursor);
            this.advance();
            this.data[this.cursor] = newEntry;
        } else {
            this.data[this.used] = newEntry;
            this.cursor = this.used;
        }
        this.used++;
    }

    public void removeCurrent() {
        if (!this.isCurrent())
            throw new IllegalStateException("No current item defined");

        //
        // STUDENT WORK HERE
        //

    }

    public Iterator<Long> iterator() {
        return new SequenceIterator();
    }

    // ***************************************************
    //                 ITERATOR 
    // ***************************************************

    private class SequenceIterator implements Iterator<Long> {

        private int seqCursor;

        public SequenceIterator() {
            seqCursor = 0;
        }

        public boolean hasNext() {
            return (seqCursor < LongArraySequence.this.used);
        }

        public Long next() throws NoSuchElementException {
            if (!hasNext())
                throw new NoSuchElementException();

            Long retValue = LongArraySequence.this.data[seqCursor++];

            return retValue;
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }

    }//end class SequenceIterator

    public static void main(String[] args) {
        LongArraySequence ages = new LongArraySequence(20);

        System.out.printf("%s\n %s %s\n\n", "Afterconstructor with request for default capacity: ", ages,
                "and capacity should be 10");
        LongArraySequence stuff = new LongArraySequence(1);
        System.out.printf("%s\n %s %s\n\n", "After constructor with request for capacity of 1: ", stuff,
                "and capacity should be 1");
        stuff = new LongArraySequence(500);
        System.out.printf("%s\n %s %s\n\n", "After constructor with request for capacity of 500: ", stuff,
                "and capacity should be 500");

        stuff.addBefore(11);
        System.out.printf("%s\n%s\n", "stuff.addBefore(11) cursor should be on 11 at end of sequence", stuff);

        stuff.trimToSize();
        System.out.printf("%s\n%s %s\n\n",
                "after stuff.trimToSize() cursor should be on 11 at end of sequence", stuff, "and capacity should be 1");

        ages = new LongArraySequence(2);
        ages.addAfter(47);
        System.out.printf("%s\n%s\n\n", "ages.addAfter(47) cursor should be on 47 at end of sequence", ages);
        ages.addAfter(33);
        System.out.printf("%s\n%s\n\n", "ages.addAfter(33) cursor should be on 33 at end of sequence", ages);
        ages.addAfter(17);
        System.out.printf("%s\n%s\n\n", "ages.addAfter(17) cursor should be on 17 at end of sequence", ages);
        ages.addAfter(77);
        System.out.printf("%s\n%s\n\n", "ages.addAfter(77) cursor should be on 77 at end of sequence", ages);
        ages.addAfter(3);
        System.out.printf("%s\n%s\n\n", "ages.addAfter(3) should be on 3 at end of sequence", ages);
        ages.addAfter(1);
        System.out.printf("%s\n%s\n\n", "ages.addAfter(1) cursor should be on 1 at end of sequence", ages);

        ages.addBefore(99);
        System.out.printf("%s\n%s\n\n", "After ages.addBefore(99) cursor should be on 99 and the 99 before the 1", ages);
        ages.removeCurrent();
        System.out.printf("%s\n%s\n\n", "After attempting removeCurrent() and the 99 should be removed and cursor on the 1", ages);
        ages.removeCurrent();
        System.out.printf("%s\n%s\n\n", "After attempting removeCurrent() and the 1 should be removed with no cursor", ages);

        try {
            System.out.printf("%s", "Attempting ages.removeCurrent() with no current item -->");
            ages.removeCurrent();
        } catch (IllegalStateException except) {
            System.out.printf("\n%s %s\n\n", "Should have failed and did:", except.getMessage());
        }

        ages.start();
        ages.removeCurrent();
        System.out.printf("%s\n%s\n\n",
                "ages after attempting start() and then removeCurrent() cursor should be at 33", ages);


        LongArraySequence a = new LongArraySequence(ages);
        System.out.printf("%s\n%s\n\n", "a after being copied from ages", a);
        System.out.printf("%s %s\n", " a.equals( ages )should be true ", a.equals(ages));
        System.out.printf("%s %s\n\n", " a  != ages should be true", a != ages);
        a.advance();
        System.out.printf("%s\n%s\n\n", "a after a.advance cursor should be at 17", a);

        LongArraySequence negatives = new LongArraySequence(1);
        for (int index = -10; index < 0; index++)
            negatives.addAfter(index);
        System.out.printf("%s\n%s\n\n",
                "negatives with ten negatives from -10 to -1, cursor should be on -1, capacity should be 16", negatives);

        LongArraySequence b = a.concatenation(negatives);
        System.out.printf("%s\n%s\n\n",
                "b after b = ages.concatenation( a ) cursor should be at 33 and capacity 14", b);
        b.addBefore(99);
        System.out.printf("%s\n%s\n\n",
                "b after b.addBefore(99) -- cursor should be at 99 and 99 first element in sequence and capacity 28", b);

        b.start();
        while (b.isCurrent())
            b.removeCurrent();
        System.out.printf("%s \n%s\n\n",
                "b after b.start() and then repeatedly removing current item -- should have 0 items, capacity remains at 28", b);

        b.trimToSize();
        System.out.printf("%s\n%s\n\n",
                "b after b.trimToSize() -- should have 0 items. capacity should be the minimum of 1", b);
        b.addBefore(7);
        System.out.printf("%s\n %s\n\n", "b after b.addBefore(7)", b);
        b.removeCurrent();
        b.addAfter(7);
        System.out.printf("%s\n %s\n\n", "b after b.removeCurrent() and b.addAfter(7)", b);

        b.removeCurrent();
        System.out.printf("%s %s\n\n",
                "b after b.removeCurrent().  b.isCurrent() should be False and it is?", b.isCurrent());

        negatives.start();
        int index = 0;
        System.out.printf("%s\n%s\n\n", "After negatives.start() and before any advances", negatives);
        System.out.printf("Iterating over the elements of negatives using class methods\n");
        negatives.start();
        boolean ok = true;
        while (ok && negatives.isCurrent()) {
            System.out.printf("%d ", negatives.getCurrent());
            try {
                negatives.advance();
            } catch (IllegalStateException except) {
                System.out.printf("\n %s\n\n",
                        "Should have printed all ten negatives and advanced beyond end of sequence");
                ok = false;
            }
        }
        System.out.printf("\n\n");

        System.out.printf("The next several examples ALL rely on the class implementing\n" +
                "the Iterable<T> interface\n\n");

        System.out.printf("Now using the formal iterator to visit all elements of negatives\n" +
                "This time iteration is under full control of programmer -- " +
                "thus the iterator is active or external.\n");
        Iterator<Long> it = negatives.iterator();
        while (it.hasNext()) {
            System.out.printf("%d ", it.next());
        }
        System.out.printf("\n\n");

        System.out.printf("Now using the formal iterator to visit all elements of negatives\n" +
                "This is using the enhanced for loop introduced in Java 5, and \n" +
                "is still known as an active or external iterator\n");
        for (Long number : negatives) {
            System.out.printf("%d ", number);
        }
        System.out.printf("\n\n");

        System.out.printf("Now using the new (as of Java 8) internal iterator.\n" +
                "This also known as a passive, call back, or implicit\n" +
                "iterator -- programmer focuses only on the \"what\" not the \"how\"\n");
        negatives.forEach(number -> System.out.printf("%d ", number));
        System.out.println();
    }


}//end class LongArraySequence
