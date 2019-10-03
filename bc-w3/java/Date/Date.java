public class Date {
    private int day;
    private int month;
    private int year;
    
    public Date(int day, int month, int year) throws InvalidDateException {
        try {
            this.validate(day, month, year);
        } catch (InvalidDateException e) {
            throw e;
        }
        this.day = day;
        this.month = month;
        this.year = year;
    }
    
    public Date() throws InvalidDateException {
        this(1, 1, 1970);
    }
    
    public int getDay() {
        return day;
    }
    
    public int getMonth() {
        return month;
    }
    
    public int getYear() {
        return year;
    }
    
    private void validate(int day, int month, int year) throws InvalidDateException {
        int[] daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        String text = new String(day + "/" + month + "/" + year + " is invalid date.");
        
        if ( month > 0 && month <= 12 && year > 0 && day > 0 ) {
            if ( year % 400 == 0 && year % 4 == 0 && month == 2 ) {
                if ( day <= 29 ) {
                    return;
                }
            }
            if ( day <= daysInMonth[month-1] ) {
                return;
            }
        }
        throw new InvalidDateException(text);
    }
    
    public String toString() {
        return day + "/" + month + "/" + year;
    }
}
