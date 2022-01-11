#include "../inc/types.hpp"
#include <iostream>
extern void yyerror(std::string);

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
    else{
        yyerror(std::string(name) + " is already defined");
    }
}

Declaration* Declarations::context_check(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        yyerror(std::string(name) + " is an undeclared identifier");
        return 0;
    }
    return d;
}