#pragma once
#ifndef MOHICAN_H
#define MOHICAN_H

#include <vector>
#include <string>

class Mohican {
    private:
        const std::string name;
        static std::vector<Mohican*> mohicans;
    public:
        Mohican(std::string name);
        virtual ~Mohican();
        
        const std::string& getName() const;
        
        static const Mohican& getLastOfMohicans();
};

std::ostream& operator<<(std::ostream& out, const Mohican& mohican);

#endif //MOHICAN_H
