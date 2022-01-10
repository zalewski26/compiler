#include <iostream>
#include <vector>
#include <string>
#include "declaration.cpp"

class Program {
private:
    std::vector<Declaration*> declarations;
    Declaration* getDeclaration(std::string name);
    void addDeclaration(std::string name);
public:
    void install(std::string name);
    void context_check(std::string name);
};

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

void Program::context_check(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0)
        std::cout << "error: " << name << " is an undeclared identifier\n";
}