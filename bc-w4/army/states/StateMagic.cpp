#include "StateMagic.h"

StateMagic::StateMagic(int mana) {
    this->mana = mana;
    this->manaLimit = mana;
    std::cout << "StateMagic object constructed" << std::endl;
}

StateMagic::~StateMagic() {
    std::cout << "StateMagic object destroyed" << std::endl;
}

int StateMagic::getMana() const {
    return this->mana;
}

int StateMagic::getManaLimit() const {
    return this->manaLimit;
}
