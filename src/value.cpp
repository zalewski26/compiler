#include "../inc/types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

void idValue::load(){
    Declaration* d = declarations->context_check(ident->name);
    if (d != 0){
        adjAddress(d->pos);
        output->load(registers->addr);
    }
}

void numValue::load(){
    output->reset(registers->acc);

    registers->accVal = 0;
    if (value > 0) {
        for (int i = 0; i < value; i++) {
            output->inc(registers->acc);
            registers->accVal++;
        }
    } 
    else {
        for (int i = value; i < 0; i++) {
            output->dec(registers->acc);
            registers->accVal--;
        }
    }
}