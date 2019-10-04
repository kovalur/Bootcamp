#include <iostream>
#include <cstdlib>
#include "List.h"

List::List(int capacity, double multiplier)
    : capacity(capacity), multiplier(multiplier), current(0) {
        this->array = (int*)malloc(sizeof(int)*capacity);
        if ( this->array == NULL ) {
            throw OutOfMemoryException();
        }
}

List::~List() {
    free(array);
}

int List::size() const {
    return current;
}

int List::max_size() const {
    return capacity;
}

void List::erase(int index) {
    int last = this->current - 1;
    
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    for ( int i = index; i < last; i++ ) {
        array[i] = array[i+1];
    }
    this->current -= 1;
}

void List::insert(int value, int index) {
    int newCurrent = this->current + 1;
    
    if ( newCurrent > this->capacity ) {
        int newCapacity = this->capacity * this->multiplier;
        int* newArray;
        
        if ( newCapacity == this->capacity ) {
            newCapacity += 5;
        }
        
        newArray = (int*)realloc(this->array, sizeof(int)*newCapacity);
        
        if ( newArray == NULL ) {
            throw OutOfMemoryException();
        }
        this->capacity = newCapacity;
        this->array = newArray;
    }
    
    for ( int i = newCurrent - 1; i > index; i-- ) {
        this->array[i] = this->array[i-1];
    }
    this->array[index] = value;
    this->current = newCurrent;
}

int List::find(int index) const {
    return this->array[index];
}

void List::push_back(int value) {
    this->insert(value, this->current);
}

int List::pop_back() {
    if ( this->current == 0 ) {
        throw ZeroLenException();
    }
    this->current -= 1;
    
    return this->array[this->current];
}

void List::sort() {
    int stack[this->current];
    int top = -1;
    
    if ( this->current < 2 ) {
        return;
    }
    
    top += 1;
    stack[top] = 0;
    top += 1;
    stack[top] = this->current - 1;
    
    while ( top >= 0 ) {
        int hi = stack[top--];
        int lo = stack[top--];
        int temp = this->array[hi];
        int i = lo - 1;
        int pivot;
        
        for ( int j = lo; j < hi; j++ ) {
            if ( this->array[j] <= temp ) {
                int buf = this->array[j];
                
                this->array[j] = this->array[++i];
                this->array[i] = buf;
            }
        }
        pivot = i + 1;
        this->array[hi] = this->array[pivot];
        this->array[pivot] = temp;
        
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

int List::operator[](int index) const {
    return this->array[index];
}

bool List::operator==(const List& other) const {
    bool isEqual = true;
    int thisLast = this->current - 1;
    
    for ( int i = 0; i < other.current && isEqual; i++ ) {
        int otherValue = other.array[i];
        
        for ( int j = 0; j < this->current; j++ ) {
            if ( this->array[j] == otherValue ) {
                break;
            }
            if ( j == thisLast ) {
                isEqual = false;
            }
        }
    }
    
    return isEqual;
}

bool List::operator!=(const List& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const List& list) {
    int last = list.size() - 1;
    
    if ( last < 0 ) {
        return out;
    }
    
    for ( int i = 0; i < last; i++ ) {
        out << list[i] << ' ';
    }
    return out << list[last];
}
