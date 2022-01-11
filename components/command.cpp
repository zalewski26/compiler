#include "types.hpp"

void AssignCommand::run(Program* p){
    Declaration* d = p->context_check(ident->name);
    if (d != 0){
        // printf("LOAD EXPRESSION TO A:\n");
        exp->load();

        if (p->addrVal < d->pos){
            while (p->addrVal < d->pos){
                printf("INC %c\n", p->addr);
                p->addrVal++;
            }
        }
        else if (p->addrVal > d->pos){
            if ((p->addrVal - d->pos) < d->pos){
                while (p->addrVal > d->pos){
                    printf("DEC %c\n", p->addr);
                    p->addrVal--;
                }
            }
            else {
                printf("RESET %c\n", p->addr);
                p->addrVal = 0;
                while (p->addrVal < d->pos){
                    printf("INC %c\n", p->addr);
                    p->addrVal++;
                }
            }
        }
        printf("STORE %c\n", p->addr);
    }
}

void IfElseCommand::run(Program* p){

}

void IfCommand::run(Program* p){

}

void WhileCommand::run(Program* p){

}

void RepeatCommand::run(Program* p){

}

void ForToCommand::run(Program* p){

}

void ForDownToCommand::run(Program* p){

}

void ReadCommand::run(Program* p){

}

void WriteCommand::run(Program* p){
    
}