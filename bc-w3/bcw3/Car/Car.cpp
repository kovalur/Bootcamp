#include <iostream>
#include <string>
#include "Car.h"
#include "Point.h"

Car::Car(double capacity, double consumption,
        const Point& location, const std::string& model) : fuelCapacity(capacity),
                                                        fuelConsumption(consumption), 
                                                        location(location), model(model) {
    this->fuelAmount = 0;
}

Car::~Car() {}

double Car::getFuelAmount() const {
    return fuelAmount;
}

double Car::getFuelCapacity() const {
    return fuelCapacity;
}

double Car::getFuelConsumption() const {
    return fuelConsumption;
}

const Point& Car::getLocation() const {
    return location;
}

const std::string& Car::getModel() const {
    return model;
}

void Car::drive(const Point& destination) {
    double fuelNeeded = this->location.distance(destination) * this->fuelConsumption;

    if ( fuelNeeded > this->fuelCapacity ) {
        throw OutOfFuel();
    }

    if ( fuelNeeded > this->fuelAmount ) {
        this->refill(fuelNeeded-this->fuelAmount);
    }
    this->location = destination;
    this->fuelAmount -= fuelNeeded;
}

void Car::drive(double x, double y) {
    double fuelNeeded = this->location.distance(Point(x, y)) * this->fuelConsumption;

    if ( fuelNeeded > this->fuelCapacity ) {
        throw OutOfFuel();
    }

    if ( fuelNeeded > this->fuelAmount ) {
        this->refill(fuelNeeded-this->fuelAmount);
    }
    this->location = Point(x, y);
    this->fuelAmount -= fuelNeeded;
}

void Car::refill(double fuel) {
    double fuelAfterRefill = this->fuelAmount + fuel;
    
    if ( fuelAfterRefill > this->fuelCapacity ) {
        throw ToMuchFuel();
    }
    this->fuelAmount = fuelAfterRefill;
}

std::ostream& operator<<(std::ostream& out, const Car& car) {
    out << "Car of model #" << car.getModel() << " is located at " << car.getLocation() << '.' << '\n';
    out << " details:" << "\n";
    out << "  * fuel capacity, l: " << car.getFuelCapacity() << ';' << '\n';
    out << "  * fuel ammount, l: " << car.getFuelAmount() << ';' << '\n';
    out << "  * fuel consumption, l/km: " << car.getFuelConsumption() << '.' << '\n';
    
    return out;
}
