#include "../inc/types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

Pidentifier::Pidentifier(std::string name){
    Declaration* d = declarations->context_check(name);
    if (d->isArray){
        declarations->throwErr(name + " is an array");
    }
    this->name = name;
    this->pos = d->pos;
    this->isIterator = d->isIterator;
}

arrIdentifier::arrIdentifier(std::string name, long long num){
    Declaration* d = declarations->context_check(name);
    if (!d->isArray){
        declarations->throwErr(name + " is not an array");
    }
    if (num < d->pos + d->baseDiff || num > d->pos + d->baseDiff + d->length - 1){
        declarations->throwErr("index " + std::to_string(num) + " out of bounds of " + name);
    }
    this->name = name;
    this->baseDiff = new numValue(d->baseDiff);
    this->index = new numValue(num);
    this->isIterator = false;
}

arrIdentifier::arrIdentifier(std::string name, std::string ident){
    Declaration* d = declarations->context_check(name);
    if (!d->isArray){
        declarations->throwErr(name + " is not an array");
    }
    this->name = name;
    this->baseDiff = new numValue(d->baseDiff);
    this->index = new idValue(new Pidentifier(ident));
}

void Pidentifier::loadAddr(){
    output->reset('b');
    registers->addrVal = 0;
    printf("%lld\n", pos);
    numValue* temp = new numValue(pos);
    temp->load();
    output->swap('b');
    delete temp;
}

void arrIdentifier::loadAddr(){
    this->baseDiff->load();
    output->reset('e');
    output->swap('e');
    index->load();
    output->sub('e');
    output->swap('b');
}