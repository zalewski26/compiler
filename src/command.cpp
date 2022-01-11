#include "../inc/types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

void AssignCommand::run(){
    Declaration* d = declarations->context_check(ident->name);
    if (d != 0){
        exp->load();
        adjAddress(d->pos);
        output->store(registers->addr);
    }
}

void IfElseCommand::run(){
    int result = cond->load();
    for (const auto &command : *this->cSet1) {
        command->run();
    }
    output->jumpPlaceholder();
    output->updateCondJump(result);
    for (const auto &command : *this->cSet2) {
        command->run();
    }
    output->updateJump();
}

void IfCommand::run(){
    int result = cond->load();
    for (const auto &command : *this->cSet) {
        command->run();
    }
    output->updateCondJump(result);
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
        // printf("GET\n");
        output->get();
        adjAddress(d->pos);
        // printf("STORE %c\n", registers->addr);
        output->store(registers->addr);
    }
}

void WriteCommand::run(){
    val->load();
    // printf("PUT\n");
    output->put();
}


void adjAddress(int pos){
    extern Registers* registers;
    if (registers->addrVal < pos){
        while (registers->addrVal < pos){
            // printf("INC %c\n", registers->addr);
            output->inc(registers->addr);
            registers->addrVal++;
        }
    }
    else if (registers->addrVal > pos){
        if ((registers->addrVal - pos) < pos){
            while (registers->addrVal > pos){
                // printf("DEC %c\n", registers->addr);
                output->dec(registers->addr);
                registers->addrVal--;
            }
        }
        else {
            // printf("RESET %c\n", registers->addr);
            output->reset(registers->addr);
            registers->addrVal = 0;
            while (registers->addrVal < pos){
                // printf("INC %c\n", registers->addr);
                output->inc(registers->addr);
                registers->addrVal++;
            }
        }
    }
}