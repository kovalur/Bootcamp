public class Main {
    public static void main(String[] args) throws ZeroLenException, OutOfMemoryException {
    List listEvenNumbers = new List(10);
    List listOddNumbers = new List(10);
    List list = new List(11);
    List list2 = new List(11);
    List list3 = new List();
    
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
    list2.insert(2, list2.size()-1);
    
    System.out.println("Printing list with even numbers:");
    System.out.println(listEvenNumbers);
    System.out.println("Printing list with odd numbers:");
    System.out.println(listOddNumbers);
    
    System.out.println("Capacity of even numbers list: " + listEvenNumbers.max_size());
    System.out.println("Current size of even numbers list: " + listEvenNumbers.size());
    System.out.println("Capacity of odd numbers list: " + listOddNumbers.max_size());
    System.out.println("Current size of odd numbers list: " + listOddNumbers.size());
    
    listEvenNumbers.push_back(listEvenNumbers.find(listEvenNumbers.size()-1)+2);
    
    System.out.println("Printing list with even numbers:");
    System.out.println(listEvenNumbers);
    
    System.out.println("Capacity of even numbers list: " + listEvenNumbers.max_size());
    System.out.println("Current size of even numbers list: " + listEvenNumbers.size());
    
    try {
        for ( int i = listOddNumbers.size(), j = listOddNumbers.find(i-1) + 2; i < 18; i++, j+=2 ) {
            listOddNumbers.insert(j, i);
        }
    } 
    catch (OutOfMemoryException e) {
        System.out.println("Heap is full.");
    }
    
    System.out.println("Printing list with odd numbers:");
    System.out.println(listOddNumbers);
    
    System.out.println("Capacity of odd numbers list: " + listOddNumbers.max_size());
    System.out.println("Current size of odd numbers list: " + listOddNumbers.size());
    
    if ( !list.equals(list2) ) {
        System.out.println("Lists aren't equal.");
    } else {
        System.out.println("Lists are equal.");
    }
    
    System.out.println("First item of even list: " + listEvenNumbers.find(0));
    System.out.println("Last item of odd list: " + listOddNumbers.find(listOddNumbers.size()-1));
    
    listEvenNumbers.erase(0);
    listOddNumbers.pop_back();
    
    System.out.println("Printing list with even numbers:");
    System.out.println(listEvenNumbers);
    System.out.println("Printing list with odd numbers:");
    System.out.println(listOddNumbers);
    
    try {
        list3.pop_back();
    } catch (ZeroLenException e) {
        System.out.println("List is empty.");
    }
    
    try {
        list3.erase(0);
    } catch (ZeroLenException e) {
        System.out.println("List is empty.");
    }
    
    System.out.println("Printing unsorted list");
    System.out.println(list2);
    list2.sort();
    System.out.println("Printing sorted list");
    System.out.println(list2);
    
    System.out.println(list);
    }
}
