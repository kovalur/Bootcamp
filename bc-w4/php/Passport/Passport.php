<?php 
    require_once(dirname(__FILE__) . '\exceptions.php');
    
    define("PS_L", 'A');
    define("PS_H", 'Z');
    define("PN_L", 1);
    define("PN_H", 999999);
    
    class Passport {
        private $firstName;
        private $lastName;
        private $dateOfBirth;
        private $dateOfBirthParams = array();
        private static $passportSeries = array(0 => PS_L, 1 => PS_L);
        private static $passportNumber = PN_L;
        private $passportId;
        
        private function validate($value) {
            if ( is_int($value) && $value > 0 ) {
                return $value;
            }
            throw new Exception("Invalid param");
        }
        
        private function validateDate($day, $month, $year) {
            $daysInMonth = array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
            $message = sprintf("%s/%s/%s", $day, $month, $year) . " is invalid date.";
            
            if ( $month > 0 && $month <= 12 && $year > 0 && $day > 0 ) {
                if ( !($year % 400 || $year % 4) && $month == 2 ) {
                    if ( $day <= 29 ) {
                        return;
                    }
                }
                if ( $day <= $daysInMonth[$month-1] ) {
                    return;
                }
            }
            throw new InvalidDate($message);
        }
        
        public function __construct($firstName, $lastName, $yearOfBirth, $monthOfBirth, $dayOfBirth) {
            $this->firstName = $firstName;
            $this->lastName = $lastName;
            $this->validateDate($this->validate($dayOfBirth), $this->validate($monthOfBirth), $this->validate($yearOfBirth));
            $this->dateOfBirthParams = array("year" => $yearOfBirth,
                                            "month" => $monthOfBirth,
                                            "day" => $dayOfBirth);
            $this->setDateOfBirth();
            $this->setPassportId();
        }
        
        public function __get($name) {
            if ( property_exists($this, $name) ) {
                return $this->$name;
            }
            throw new Exception("Attribute error: attribute $name not found");
        }
        
        public function __set($name, $value) {
            throw new Exception("Action error: attribute change not allowed");
        }
        
        private function setPassportId() {
            if ( self::$passportNumber > PN_H ) {
                $this->adjustIdParams();
            }
            $buffer = strval(self::$passportNumber);
            $this->passportId = sprintf("%s%s", self::$passportSeries[0], self::$passportSeries[1])
                                . str_repeat('0', 6-count(str_split($buffer))) . $buffer;
            self::$passportNumber += 1;
        }
        
        private function setDateOfBirth() {
            $year = strval($this->dateOfBirthParams["year"]);
            $month = strval($this->dateOfBirthParams["month"]);
            $day = strval($this->dateOfBirthParams["day"]);
            $this->dateOfBirth = $month . '/' . $day . '/' . $year;
        }
        
        private function adjustIdParams() {
            if ( self::$passportSeries[0] == PS_H && self::$passportSeries[1] == PS_H ) {
                self::$passportNumber = PN_H;
                throw new PassportIdLimit("State error: passport id limit reached");
            }
            if ( self::$passportSeries[1] < PS_H ) {
                self::$passportSeries[1] = chr(ord(self::$passportSeries[1]) + 1);
                self::$passportNumber = PN_L;
                return;
            }
            if ( self::$passportSeries[0] < PS_H ) {
                self::$passportSeries[0] = chr(ord(self::$passportSeries[0]) + 1);
                self::$passportSeries[1] = 'A';
                self::$passportNumber = PN_L;
            }
        }
        
        public static function currentPassportSeries() {
            return sprintf("%s%s", self::$passportSeries[0], self::$passportSeries[1]);
        }
        
        public static function currentPassportNumber() {
            return self::$passportNumber == PN_H + 1 ? self::$passportNumber - 1 : self::$passportNumber;
        }
        
        public static function changePassportSeries($series) {
            if ( is_string($series) ) {
                $series = str_split($series); 
            }
            if ( !is_array($series) || count($series) != 2 ) {
                throw new InvalidPassportSeries("Value error: not valid passport series");
            }
            
            $a = $series[0];
            $b = $series[1];
            if ( $a < PS_L || $a > PS_H || $b < PS_L || $b > PS_H ) {
                throw new InvalidPassportSeries("Value error: not valid passport series");
            }
            self::$passportSeries[0] = $a;
            self::$passportSeries[1] = $b;
            self::$passportNumber = PN_L;
        }
        
        public static function changePassportNumber($number) {
            if ( !is_int($number) || $number > PN_H || $number <= 0) {
                throw new InvalidPassportNumber("Value error: not valid passport number");
            }
            self::$passportNumber = $number;
        }
        
        public function __toString() {
            $out = "";
            
            $out .= sprintf("%s %s", $this->firstName, $this->lastName) . PHP_EOL;
            $out .= $this->dateOfBirth . PHP_EOL;
            $out .= $this->passportId;
            
            return $out;
        }
    }
    
    try {
        $p1 = new Passport("Bruno", "Jorge", 1994, 2, 7);
        
        echo "##########################" . PHP_EOL;
        echo $p1 . PHP_EOL;
        
        Passport::changePassportSeries("ZZ");
        Passport::changePassportNumber(999999);
        
        echo "##########################" . PHP_EOL;
        $p2 = new Passport("Felicia", "Lagrange", 1955, 1, 2);
        echo $p2 . PHP_EOL;
        
        echo "##########################" . PHP_EOL;
        $p3 = new Passport("John", "Walenso", 1945, 1, 2);
        echo $p3 . PHP_EOL;
    } catch (Exception $e) {
        echo $e->getMessage() . PHP_EOL;
    }
    
    echo Passport::currentPassportSeries() . PHP_EOL;
    echo Passport::currentPassportNumber() . PHP_EOL;
?>
