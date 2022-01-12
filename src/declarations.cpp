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

void Declarations::install(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        declarations.push_back(new Declaration(name,memoryCounter));
        memoryCounter++;
    }
    else{
        yyerror(std::string(name) + " is already defined");
    }
}

void Declarations::install(std::string name, int start, int end){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        int length = end - start + 1;
        int baseDiff = start - memoryCounter;
        declarations.push_back(new Declaration(name,memoryCounter, length, baseDiff));
        memoryCounter += length;
    }
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

void Declarations::print(){
    for (auto i : declarations){
        std::cout << i->name << ": pos = " << i->pos << " length = " << i->length << " baseDiff = " << i->baseDiff << "\n"; 
    }
}