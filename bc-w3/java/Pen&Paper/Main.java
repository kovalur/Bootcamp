public class Main {
    public static void main(String[] args) throws OutOfInkException, OutOfSpaceException {
        Paper paper = new Paper(12);
        Pen pen = new Pen(12);
        
        pen.write(paper, "Hello, world!");
        
        System.out.println("Paper max symbols: " + paper.getMaxSymbols());
        System.out.println("Paper symbols: " + paper.getSymbols());
        System.out.println("Pen ink amount: " + pen.getInkAmount());
        System.out.println("Pen ink capacity: " + pen.getInkCapacity());
        
        try {
            pen.write(paper, "!");
        } catch (OutOfInkException e) {
            System.out.println("Out of ink.");
        }
        
        paper.show();
        
        System.out.println("Pen ink amount: " + pen.getInkAmount());
        System.out.println("Pen ink capacity: " + pen.getInkCapacity());
        
        pen.refill();
        System.out.println("Pen ink amount: " + pen.getInkAmount());
        
        try {
            pen.write(paper, "!");
        } catch (OutOfSpaceException e) {
            System.out.println("Out of space.");
        }
        
        paper.show();
    }
}
