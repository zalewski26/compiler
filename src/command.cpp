#include "../inc/types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

void AssignCommand::run(){
    exp->load();
    output->reset('e');
    output->swap('e');
    ident->loadAddr();
    output->swap('e');
    output->store(registers->addr);
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
    output->updateCondJump(result);
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
    Declaration* d = declarations->context_check(name);
    if (d != 0){
        val1->load();
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->store(registers->addr);
        output->reset('f');
        output->swap('f');
        output->repeatPlaceholder();

        val2->load();
        output->swap('c');
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->load(registers->addr);
        output->sub('c');
        output->condJumpPlaceholder("JPOS");
        for (const auto &command : *this->cSet) {
            command->run();
        }
        output->inc('f');
        output->reset('a');
        output->add('f');
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->store(registers->addr);
        output->updateWhile();
        output->updateCondJump(1);
    }
}

void ForDownToCommand::run(){
    Declaration* d = declarations->context_check(name);
    if (d != 0){
        val1->load();
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->store(registers->addr);
        output->reset('f');
        output->swap('f');
        output->repeatPlaceholder();

        val2->load();
        output->swap('c');
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->load(registers->addr);
        output->sub('c');
        output->condJumpPlaceholder("JNEG");
        for (const auto &command : *this->cSet) {
            command->run();
        }
        output->dec('f');
        output->reset('a');
        output->add('f');
        output->reset(registers->addr);
        registers->addrVal = 0;
        while (registers->addrVal < d->pos){
            output->inc(registers->addr);
            registers->addrVal++;
        }
        output->store(registers->addr);
        output->updateWhile();
        output->updateCondJump(1);
    }
}

void ReadCommand::run(){
    output->get();
    ident->loadAddr();
    output->store(registers->addr);
}

void WriteCommand::run(){
    val->load();
    output->put();
}

