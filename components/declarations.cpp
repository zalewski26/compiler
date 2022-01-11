#include "types.hpp"
#include <iostream>

Declaration* Declarations::getDeclaration(std::string name){
    for (auto i : declarations){
        if (i->name == name)
            return i;
    }
    return 0;
}

void Declarations::addDeclaration(std::string name){
    declarations.push_back(new Declaration(name, declarations.size(), false));
}

void Declarations::install (std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0)
        addDeclaration(name);
    else
        std::cout << "\033[1;31merror: " << name << " is already defined\033[0m\n";
}

Declaration* Declarations::context_check(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        std::cout << "\033[1;31merror: " << name << " is an undeclared identifier\033[0m\n";
        return 0;
    }
    return d;
}