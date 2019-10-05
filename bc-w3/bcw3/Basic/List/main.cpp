#include <iostream>
#include <cstdlib>
#include "List.h"

int main() {
    List listEvenNumbers(10);
    List listOddNumbers(10);
    List list(11);
    List list2(11);
    List list3;
    
    for ( int i = 0, j = 0; i < listEvenNumbers.max_size(); i++, j+=2 ) {
        listEvenNumbers.insert(j, i);
    }
    
    for ( int i = 0, j = 1; i < listOddNumbers.max_size(); i++, j+=2 ) {
        listOddNumbers.insert(j, i);
    }
    
    for ( int i = 0, j = 11; i < list.max_size(); i++, j-- ) {
        list.insert(j, i);
    }
    
    for (int i = 0, j = 11; i < list.max_size(); i++, j--) {
        list2.insert(j, i);
    }
    
    list2.pop_back();
    list2.insert(2, list2.size() - 1);
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    std::cout << "Capacity of even numbers list: " << listEvenNumbers.max_size() << std::endl;
    std::cout << "Current size of even numbers list: " << listEvenNumbers.size() << std::endl;
    std::cout << "Capacity of odd numbers list: " << listOddNumbers.max_size() << std::endl;
    std::cout << "Current size of odd numbers list: " << listOddNumbers.size() << std::endl;
    
    listEvenNumbers.push_back(listEvenNumbers.find(listEvenNumbers.size()-1)+2);
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    
    std::cout << "Capacity of even numbers list: " << listEvenNumbers.max_size() << std::endl;
    std::cout << "Current size of even numbers list: " << listEvenNumbers.size() << std::endl;
    
    try {
        for ( int i = listOddNumbers.size(), j = listOddNumbers[i-1] + 2; i < 18; i++, j+=2 ) {
            listOddNumbers.insert(j, i);
        }
    } catch (OutOfMemoryException e) {
        std::cout << "Heap is full." << std::endl;
    }
    
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    std::cout << "Capacity of odd numbers list: " << listOddNumbers.max_size() << std::endl;
    std::cout << "Current size of odd numbers list: " << listOddNumbers.size() << std::endl;
    
    if (list != list2) {
        std::cout << "Lists aren't equal." << std::endl;
    } else {
        std::cout << "Lists are equal." << std::endl;
    }
    
    std::cout << "First item of even list: " << listEvenNumbers[0] << std::endl;
    std::cout << "Last item of odd list: " << listOddNumbers[listOddNumbers.size()-1] << std::endl;
    
    listEvenNumbers.erase(0);
    listOddNumbers.pop_back();
    
    std::cout << "Printing list with even numbers:" << std::endl;
    std::cout << listEvenNumbers << std::endl;
    std::cout << "Printing list with odd numbers:" << std::endl;
    std::cout << listOddNumbers << std::endl;
    
    try {
        list3.pop_back();
    } catch (ZeroLenException e) {
        std::cout << "List is empty." << std::endl;
    }
    
    try {
        list3.erase(0);
    } catch (ZeroLenException e) {
        std::cout << "List is empty." << std::endl;
    }
    
    std::cout << "Printing unsorted list" << std::endl;
    std::cout << list2 << std::endl;
    list2.sort();
    std::cout << "Printing sorted list" << std::endl;
    std::cout << list2 << std::endl;
    
    std::cout << list << std::endl;
    
    return 0;
}
