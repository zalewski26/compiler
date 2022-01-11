#include "types.hpp"
extern Declarations* declarations;
extern Registers* registers;

void idValue::load(){
    Declaration* d = declarations->context_check(ident->name);
    if (d != 0){
        adjAddress(d->pos);
        printf("LOAD %c\n", registers->addr);
    }
}

void numValue::load(){
    printf("RESET %c\n", registers->acc);
    registers->accVal = 0;
    if (value > 0) {
        for (int i = 0; i < value; i++) {
            printf("INC %c\n", registers->acc);
            registers->accVal++;
        }
    } 
    else {
        for (int i = value; i < 0; i++) {
            printf("DEC %c\n", registers->acc);
            registers->accVal--;
        }
    }
}