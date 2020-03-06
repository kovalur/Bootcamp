public class Pen {
    private int inkAmount;
    private int inkCapacity;
    
    public Pen(int inkCapacity) {
        this.inkAmount = inkCapacity;
        this.inkCapacity = inkCapacity;
    }
    
    public Pen() {
        this(4096);
    }
    
    public int getInkAmount() {
        return inkAmount;
    }
    
    public int getInkCapacity() {
        return inkCapacity;
    }
    
    public void write(Paper paper, String message) throws OutOfInkException, OutOfSpaceException {
        if ( this.inkAmount == 0 ) {
            throw new OutOfInkException();
        }
        
        int beforePaperSymbols = paper.getSymbols();
        if ( message.length() > this.inkAmount ) {
            paper.addContent(message.substring(0, this.inkAmount));
            this.inkAmount -= paper.getSymbols() - beforePaperSymbols;
            return;
        }
        paper.addContent(message);
        this.inkAmount -= paper.getSymbols() - beforePaperSymbols;
    }
    
    public void refill() {
        inkAmount = inkCapacity;
    }
}
