import java.util.Scanner;

public class IsPali {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in); // create a scanner object
        String input = in.nextLine(); // read a string
        StringBuffer reversed = new StringBuffer(input); // create a copy of the string
        
        reversed.reverse(); // reverse the string
        
        // compare and output the result
        if ( input.equals(reversed.toString()) ) {
            System.out.println("yes");
        } else {
            System.out.println("no");
        }
        
        in.close();
    }
}
