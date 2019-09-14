#include <iostream>
#include "Gun.h"

Gun::Gun(const std::string& model, int capacity)
    : model(model), capacity(capacity), amount(0),
        isReady(false), totalShots(0) {}

Gun::~Gun() {}

int Gun::getAmount() const {
    return amount;
}

int Gun::getCapacity() const {
    return capacity;
}

bool Gun::ready() const {
    return isReady;
}

const std::string& Gun::getModel() const {
    return model;
}

int Gun::getTotalShots() const {
    return totalShots;
}

void Gun::prepare() {
    if ( !isReady ) {
        isReady = !isReady;
    }
}

void Gun::reload() {
    amount = capacity;
}

void Gun::shoot() {
    if ( !isReady ) {
        throw NotReady();
    }
    if ( amount == 0 ) {
        throw OutOfRounds();
    }
    amount -= 1;
    totalShots += 1;
    std::cout << "Bang!" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Gun& gun) {
    out << "Gun of model #" << gun.getModel() << '.' << '\n';
    out << " details:" << '\n';
    out << "  * magazine capacity: " << gun.getCapacity() << ';' << '\n';
    out << "  * bullets in magazine: " << gun.getAmount() << ';' << '\n';
    out << "  * is gun ready for usage: " << (gun.ready() ? "Yes" : "No") << ';' << '\n';
    out << "  * number of shots fired: " << gun.getTotalShots() << '.' << '\n';
    return out;
}
