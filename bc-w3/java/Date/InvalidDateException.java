public class InvalidDateException extends Exception {
    public String text;
    
    public InvalidDateException(final String text) {
        this.text = text;
    }
}
