#include <iostream>
#include <cstdlib>
#include "List.h"

int main() {
    List listEvenNumbers;
    List listOddNumbers(10);
    List list(11);

    for ( int i = 0, j = 0; i < listEvenNumbers.max_size(); i++, j+=2 ) {
        listEvenNumbers.insert(j, i);
    }
    for ( int i = 0, j = 1; i < listOddNumbers.max_size(); i++, j+=2 ) {
        listOddNumbers.insert(j, i);
    }

    for ( int i = 0, j = 11; i < list.max_size(); i++, j-- ) {
        list.insert(j, i);
    }
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    std::cout << "Capacity of even numbers list: " << listEvenNumbers.max_size() << std::endl;
    std::cout << "Current size of even numbers list: " << listEvenNumbers.size() << std::endl;
    std::cout << "Capacity of odd numbers list: " << listOddNumbers.max_size() << std::endl;
    std::cout << "Current size of odd numbers list: " << listOddNumbers.size() << std::endl;
    
    listEvenNumbers.push_back(listEvenNumbers.find(listEvenNumbers.size()-1)+2);
    listOddNumbers.push_back(listOddNumbers.find(listOddNumbers.size()-1)+2);
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    std::cout << "Capacity of even numbers list: " << listEvenNumbers.max_size() << std::endl;
    std::cout << "Current size of even numbers list: " << listEvenNumbers.size() << std::endl;
    std::cout << "Capacity of odd numbers list: " << listOddNumbers.max_size() << std::endl;
    std::cout << "Current size of odd numbers list: " << listOddNumbers.size() << std::endl;
    
    try {
        for ( int i = listEvenNumbers.size(), j = listEvenNumbers.find(i-1) + 2; i < 108; i++, j+=2 ) {
            listEvenNumbers.insert(j, i);
        }
        for ( int i = listOddNumbers.size(), j = listOddNumbers.find(i-1) + 2; i < 108; i++, j+=2 ) {
            listOddNumbers.insert(j, i);
        }
    } catch (OutOfMemoryException e) {
        std::cout << "Heap is full." << std::endl;
    }
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    std::cout << "Capacity of even numbers list: " << listEvenNumbers.max_size() << std::endl;
    std::cout << "Current size of even numbers list: " << listEvenNumbers.size() << std::endl;
    std::cout << "Capacity of odd numbers list: " << listOddNumbers.max_size() << std::endl;
    std::cout << "Current size of odd numbers list: " << listOddNumbers.size() << std::endl;
    
    if ( listEvenNumbers != listOddNumbers ) {
        std::cout << "Lists aren't equal." << std::endl;
    } else {
        std::cout << "Lists are equal." << std::endl;
    }
    
    std::cout << "First item of even list: " << listEvenNumbers[0] << std::endl;
    std::cout << "Last item of odd list: " << listOddNumbers[listOddNumbers.size()-1] << std::endl;
    
    listEvenNumbers.erase(0);
    listOddNumbers.pop_back();
    
    std::cout << "First item of even list: " << listEvenNumbers[0] << std::endl;
    std::cout << "Last item of odd list: " << listOddNumbers[listOddNumbers.size()-1] << std::endl;
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    try {
        list.pop_back();
    } catch (ZeroLenException e) {
        std::cout << "List is empty." << std::endl;
    }
    
    try {
        list.erase(0);
    } catch (ZeroLenException e) {
        std::cout << "List is empty." << std::endl;
    }
    
    list.sort();
    std::cout << "Printing sorted list" << std::endl;
    std::cout << list << std::endl;
    
    return 0;
}
