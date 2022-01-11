#include "types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

void AssignCommand::run(){
    Declaration* d = declarations->context_check(ident->name);
    if (d != 0){
        // printf("LOAD EXPRESSION TO A:\n");
        exp->load();
        adjAddress(d->pos);
        printf("STORE %c\n", registers->addr);
    }
}

void IfElseCommand::run(){

}

void IfCommand::run(){

}

void WhileCommand::run(){

}

void RepeatCommand::run(){

}

void ForToCommand::run(){

}

void ForDownToCommand::run(){

}

void ReadCommand::run(){
    Declaration* d = declarations->context_check(ident->name);
    if (d != 0){
        printf("GET\n");
        adjAddress(d->pos);
        printf("STORE %c\n", registers->addr);
    }
}

void WriteCommand::run(){
    val->load();
    printf("PUT\n");
}



void adjAddress(int pos){
    extern Registers* registers;
    if (registers->addrVal < pos){
        while (registers->addrVal < pos){
            printf("INC %c\n", registers->addr);
            registers->addrVal++;
        }
    }
    else if (registers->addrVal > pos){
        if ((registers->addrVal - pos) < pos){
            while (registers->addrVal > pos){
                printf("DEC %c\n", registers->addr);
                registers->addrVal--;
            }
        }
        else {
            printf("RESET %c\n", registers->addr);
            registers->addrVal = 0;
            while (registers->addrVal < pos){
                printf("INC %c\n", registers->addr);
                registers->addrVal++;
            }
        }
    }
}