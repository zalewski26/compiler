#include <iostream>
#include "types.hpp"

Declaration* Program::getDeclaration(std::string name){
    for (auto i : declarations){
        if (i->name == name)
            return i;
    }
    return 0;
}

void Program::addDeclaration(std::string name){
    declarations.push_back(new Declaration(name, declarations.size(), false));
}

void Program::install (std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0)
        addDeclaration(name);
    else
        std::cout << "error: " << name << " is already defined\n";
}

int Program::context_check(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        std::cout << "error: " << name << " is an undeclared identifier\n";
        return 0;
    }
    return 1;
}

void Program::printAll(){
    std::cout << "Declarations:\n";
    for (auto i : declarations){
        std::cout << "name: " << i->name << " position: " << i->pos << " inRegister: " << i->inRegister << "\n";
    }
    // std::cout << "Commands:\n";
    // for (auto i : commands){
    //     std::cout << i->val << "\n";
    // }
}