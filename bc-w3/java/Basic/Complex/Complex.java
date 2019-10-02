import java.text.DecimalFormat;

public class Complex implements Cloneable {
    private double real;
    private double imaginary;
    
    public Complex(double real, double imaginary) {
        this.real = real;
        this.imaginary = imaginary;
    }
    
    public Complex() {
        this(0, 0);
    }
    
    public double getReal() {
        return real;
    }
    
    public double getImaginary() {
        return imaginary;
    }
    
    public boolean equals(Complex other) {
        return this.real == other.real && this.imaginary == other.imaginary;
    }
    
    public void incrementedBy(Complex other) {
        this.real += other.real;
        this.imaginary += other.imaginary;
    }
    
    public void decrementedBy(Complex other) {
        this.real -= other.real;
        this.imaginary -= other.imaginary;
    }
    
    public Complex plus(Complex other) {
        Complex sumOfComplexes = new Complex();
        
        sumOfComplexes.real = this.real + other.real;
        sumOfComplexes.imaginary = this.imaginary + other.imaginary;
        return sumOfComplexes;
    }
    
    public Complex minus(Complex other) {
        Complex diffOfComplexes = new Complex();
        
        diffOfComplexes.real = this.real - other.real;
        diffOfComplexes.imaginary = this.imaginary - other.imaginary;
        return diffOfComplexes;
    }
    
    public Complex multiply(Complex other) {
        Complex multiplyOfComplexes = new Complex();
        
        multiplyOfComplexes.real = this.real * other.real - this.imaginary * other.imaginary;
        multiplyOfComplexes.imaginary = this.real * other.imaginary + this.imaginary * other.real;
        return multiplyOfComplexes;
    }
    
    public String toString() {
        StringBuffer out = new StringBuffer();
        DecimalFormat fmt = new DecimalFormat("######.######");
        
        if ( this.imaginary == 0 ) {
            return out.append(fmt.format(this.real)).toString();
        } else if ( this.real == 0 ) {
            return out.append(fmt.format(this.imaginary) + 'i').toString();
        }
        out.append(String.format("%s", fmt.format(this.real)));
        if ( this.imaginary > 0 ) {
            out.append(String.format("%c%s%c", '+', fmt.format(this.imaginary), 'i'));
        } else {
            out.append(String.format("%s%c", fmt.format(this.imaginary), 'i'));
        }
        
        return out.toString();
    }
    
    public Complex clone() throws CloneNotSupportedException {
        return (Complex) super.clone();
    }
}
