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
        std::cout << "\033[1;31merror: " << name << " is already defined\033[0m\n";
}

Declaration* Program::context_check(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        std::cout << "\033[1;31merror: " << name << " is an undeclared identifier\033[0m\n";
        return 0;
    }
    return d;
}

Program::Program(IdentifiersSet* ids, CommandSet* commands) : commands(commands) {
    for (auto i : *ids){
        install(i->name);
    }
}

void Program::compile(){
    printf("RESET %c\n", acc);
    printf("RESET %c\n", addr);
    accVal = 0;
    addrVal = 0;
    for (const auto &command : *this->commands) {
        command->run(this);
    }
}

void Program::printAll(){
    std::cout << "Declarations:\n";
    for (auto i : declarations){
        std::cout << "name: " << i->name << " position: " << i->pos << " inRegister: " << i->inRegister << "\n";
    }
    std::cout << "Commands:\n";
    for (auto &i : *commands){
        std::cout << i << "\n";
    }
}

