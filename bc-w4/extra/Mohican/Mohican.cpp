#include "Mohican.h"

Mohican::Mohican(std::string name) : name(name) {
    mohicans.push_back(this);
}

Mohican::~Mohican() {
    for ( auto it = mohicans.begin(); it != mohicans.end(); ++it ) {
     if ( *it == this ) {
       mohicans.erase(it);
       return;
     }
   }
}

const std::string& Mohican::getName() const {
  return this->name;
}

const Mohican& Mohican::getLastOfMohicans() {
    return *(mohicans.back());
}

std::vector<Mohican*> Mohican::mohicans;

std::ostream& operator<<(std::ostream& out, const Mohican& mohican) {
  out << mohican.getName();
}
