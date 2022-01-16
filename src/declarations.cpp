#include "../inc/types.hpp"
#include <iostream>
extern void yyerror(std::string, int correction=0);

Declaration* Declarations::getDeclaration(std::string name){
    for (auto i : declarations){
        if (i->name == name)
            return i;
    }
    return 0;
}

void Declarations::install(std::string name, bool isIterator){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        declarations.push_back(new Declaration(name,memoryCounter, isIterator));
        memoryCounter++;
    }
    else{
        yyerror(std::string(name) + " is already defined", 0);
    }
}

void Declarations::install(std::string name, long long start, long long end){
    if (end < start)
        yyerror(std::string(name) + " has incorrect boundaries", 0);
    Declaration* d = getDeclaration(name);
    if (d == 0){
        long long length = end - start + 1;
        long long baseDiff = start - memoryCounter;
        declarations.push_back(new Declaration(name,memoryCounter, length, baseDiff));
        memoryCounter += length;
    }
    else{
        yyerror(std::string(name) + " is already defined", 0);
    }
}

void Declarations::markAsInitialized(Identifier* ident){
    for (auto i : declarations){
        if (i->name == ident->getName())
            i->isInitialized = true;
    }
}

Declaration* Declarations::context_check(std::string name){
    Declaration* d = getDeclaration(name);
    if (d == 0){
        yyerror((std::string(name) + " is an undeclared identifier"), 0);
        return 0;
    }
    return d;
}

void Declarations::remove(std::string name){
    declarations.erase(declarations.begin() + declarations.size() - 1);
    memoryCounter--;
}

void Declarations::throwErr(std::string err, int correction){
    yyerror(err, correction);           // zależy od liczby linijek w wyrażeniu
}

void Declarations::print(){
    for (auto i : declarations){
        std::cout << i->name << ": pos = " << i->pos << " length = " << i->length << " baseDiff = " << i->baseDiff << "\n"; 
    }
}