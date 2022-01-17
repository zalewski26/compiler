#include "../inc/types.hpp"
extern Declarations* declarations;
extern Registers* registers;
extern Output* output;

AssignCommand::AssignCommand(Identifier* ident, Expression* exp) : ident(ident), exp(exp){
        if (ident->isIterator)
            declarations->throwErr("you cannot modify iterator inside loop");
}

void AssignCommand::run(){
    exp->load();
    output->reset('h');
    output->swap('h');
    ident->loadAddr();
    output->swap('h');
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
    int result = cond->loadIf();
    output->updateRepeat(result);
}

void ForCommand::run(){
    val1->load();
    output->swap('h');
    pident->loadAddr();
    output->swap('h');
    output->store('b');
    val2->load();
    output->swap('h');
    limit->loadAddr();
    output->swap('h');
    output->store('b');

    output->repeatPlaceholder();
    limit->loadAddr();
    output->load('b');
    output->swap('h');
    pident->loadAddr();
    output->load(registers->addr);
    output->sub('h');
    if (downTo)
        output->condJumpPlaceholder("JNEG");
    else
        output->condJumpPlaceholder("JPOS");
    for (const auto &command : *this->cSet) {
        command->run();
    }
    output->reset('a');
    pident->loadAddr();
    output->load(registers->addr);
    if (downTo)
        output->dec('a');
    else
        output->inc('a');
    output->store(registers->addr);
    output->updateWhile();
    output->updateCondJump(1);
}

void ReadCommand::run(){
    output->get();
    output->reset('h');
    output->swap('h');
    ident->loadAddr();
    output->swap('h');
    output->store(registers->addr);
}

void WriteCommand::run(){
    val->load();
    output->put();
}

