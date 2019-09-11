#include <iostream>
#include "Car.h"
#include "Point.h"

int main() {
    Car car;
    
    std::cout << car << std::endl;
    
    std::cout << "Your max travel distance: " << Point(0, 0).distance(Point(50, 86.6025403784)) * car.getFuelConsumption() << "km." << std::endl;

    try {
        car.drive(50, 86.6025403785);
    } catch (OutOfFuel e) {
        std::cout << "Size of fuel tank is too small for your journey." << std::endl;
    }

    try {
        car.refill(61);
    } catch (ToMuchFuel e) {
        std::cout << "You can't fuel more of tank capacity." << std::endl;
    }
    
    car.drive(Point(5, 11));

    std::cout << car << std::endl;
    
    return 0;
}
