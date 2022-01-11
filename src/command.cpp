#include "../inc/types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

void AssignCommand::run(){
    Declaration* d = declarations->context_check(ident->name);
    if (d != 0){
        exp->load();
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->store(registers->addr);
    }
}

void IfElseCommand::run(){
    int result = cond->loadIf();
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
    int result = cond->loadIf();
    for (const auto &command : *this->cSet) {
        command->run();
    }
    output->updateCondJump(result);
}

void WhileCommand::run(){
    output->repeatPlaceholder();
    int result = cond->loadIf();
    for (const auto &command : *this->cSet) {
        command->run();
    }
    output->updateWhile();
}

void RepeatCommand::run(){
    output->repeatPlaceholder();
    for (const auto &command : *this->cSet) {
        command->run();
    }
    int result = cond->loadRepeat();
    output->updateRepeat(result);
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
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->store(registers->addr);
    }
}

void WriteCommand::run(){
    val->load();
    output->put();
}

