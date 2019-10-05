import java.util.Arrays;

public class List {
    private int capacity;
    private double multiplier;
    private int current;
    private Integer[] array;
    
    public List(int capacity, double multiplier) throws OutOfMemoryException {
        this.capacity = capacity;
        this.multiplier = multiplier;
        this.current = 0;
        try {
            this.array = new Integer[capacity];   
        } catch (OutOfMemoryError e) {
            throw new OutOfMemoryException();
        }
    }
    
    public List(int capacity) throws OutOfMemoryException {
        this(capacity, 1.05);
    }
    
    public List() throws OutOfMemoryException {
        this(100, 1.05);
    }
    
    public int size() {
        return current;
    }
    
    public int max_size() {
        return capacity;
    }
    
    public void erase(int index) throws ZeroLenException, OutOfMemoryException {
        int numMoved = this.current - 1 - index;
        
        if ( this.current == 0 ) {
            throw new ZeroLenException();
        }
        
        if ( numMoved > 0 ) {
            try {
                System.arraycopy(this.array, index+1, this.array, index, numMoved);   
            } catch (OutOfMemoryError e) {
                throw new OutOfMemoryException();
            }
        }
        this.current -= 1;
        array[this.current] = null;
    }
    
    public void insert(int value, int index) throws OutOfMemoryException {
        int newCurrent = this.current + 1;
        
        try {
            if ( newCurrent > this.capacity ) {
                int newCapacity = (int) (this.capacity * this.multiplier);
                
                if ( newCapacity == this.capacity ) {
                    newCapacity += 5;
                }
                this.array = Arrays.copyOf(this.array, newCapacity);
                this.capacity = newCapacity;
            }
            System.arraycopy(this.array, index, this.array, index+1, this.current-index);
        } catch (OutOfMemoryError e) {
            throw new OutOfMemoryException();
        }
        this.array[index] = value;
        this.current += 1;
    }
    
    public int find(int index) {
        return this.array[index];
    }
    
    public void push_back(int value) throws OutOfMemoryException {
        this.insert(value, this.current);
    }
    
    public int pop_back() throws ZeroLenException {
        int eraseValue;
        
        if ( this.current == 0 ) {
            throw new ZeroLenException();
        }
        this.current -= 1;
        eraseValue = this.array[this.current];
        this.array[this.current] = null;
        
        return eraseValue;
    }
    
    public void sort() throws OutOfMemoryException {
        int[] stack;
        int top = -1;
        
        if ( this.current < 2 ) {
            return;
        }
        
        try {
            stack = new int[this.current];
        } catch (OutOfMemoryError e) {
            throw new OutOfMemoryException();
        }
        
        top += 1;
        stack[top] = 0;
        top += 1;
        stack[top] = this.current - 1;
        
        while ( top >= 0 ) {
            int hi = stack[top--];
            int lo = stack[top--];
            int temp = this.array[hi];
            int i = lo - 1;
            int pivot;
            
            for ( int j = lo; j < hi; j++ ) {
                if ( this.array[j] <= temp ) {
                    int buf = this.array[j];
                    
                    this.array[j] = this.array[++i];
                    this.array[i] = buf;
                }
            }
            pivot = i + 1;
            this.array[hi] = this.array[pivot];
            this.array[pivot] = temp;
            
            if ( pivot - 1 > lo ) {
                top += 1;
                stack[top] = lo;
                top += 1;
                stack[top] = pivot - 1;
            }
            
            if ( pivot + 1 < hi ) {
                top += 1;
                stack[top] = pivot + 1;
                top += 1;
                stack[top] = hi;
            }
        }
    }
    
    public boolean equals(List other) throws ZeroLenException, OutOfMemoryException {
        boolean isEqual = true;
        int thisLast = this.current - 1;
        Integer[] thisArrayCopy;
        
        if ( this.current != other.current ) {
            return false;
        }
        
        try {
            thisArrayCopy = this.array.clone();
        } catch (OutOfMemoryError e) {
            throw new OutOfMemoryException();
        }
        
        for ( int i = 0; i < other.current && isEqual; i++ ) {
            int otherValue = other.array[i];
            
            for ( int j = 0; j < this.current; j++ ) {
                if ( thisArrayCopy[j] != null && thisArrayCopy[j] == otherValue ) {
                    thisArrayCopy[j] = null;
                    break;
                } else if ( j == thisLast ) {
                    isEqual = false;
                }
            }
        }
        
        return isEqual;
    }
    
    public String toString() {
        int last = this.current - 1;
        StringBuffer out = new StringBuffer();
        
        if ( last < 0 ) {
            return "";
        }
        
        for ( int i = 0; i < last; i++ ) {
            out.append(this.array[i] + " ");
        }
        out.append(this.array[last]);
        
        return out.toString();
    }
}
