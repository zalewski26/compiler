#include <iostream>
#include "../inc/types.hpp"
extern Registers* registers;
extern Output* output;

void Program::compile(){
    output->reset(registers->addr);
    registers->addrVal = 0;

    for (const auto &command : *this->commands) {
        command->run();
    }
    output->halt();
}

