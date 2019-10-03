public class Paper {
    private int maxSymbols;
    private int symbols;
    private StringBuffer content;
    
    public Paper(int maxSymbols) {
        this.maxSymbols = maxSymbols;
        this.symbols = 0;
        this.content = new StringBuffer();
    }
    
    public Paper() {
        this(4096);
    }
    
    public int getMaxSymbols() {
        return maxSymbols;
    }
    
    public int getSymbols() {
        return symbols;
    }
    
    public void addContent(String message) throws OutOfSpaceException {
        int spaceLeft = this.maxSymbols - this.symbols;
        String textToAdd = message.substring(0, spaceLeft);
        
        if ( spaceLeft == 0 ) {
            throw new OutOfSpaceException();
        }
        this.content.append(textToAdd);
        this.symbols += textToAdd.length();
        
    }
    
    public void show() {
        System.out.println(content);
    }
}
