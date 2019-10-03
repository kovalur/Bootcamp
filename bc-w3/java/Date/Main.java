public class Main {
    public static void main(String[] args) throws InvalidDateException {
        try {
            Date date = new Date(29, 02, 2000);
            
            System.out.println(date);
        } catch (InvalidDateException e) {
            System.out.println(e.text);
        }
    }
}
