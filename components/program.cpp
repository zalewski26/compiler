#include <iostream>
#include "types.hpp"
extern Registers* registers;

void Program::compile(){
    printf("RESET %c\n", registers->addr);
    registers->addrVal = 0;

    for (const auto &command : *this->commands) {
        command->run();
    }
    printf("HALT\n");
}

// void Program::printAll(){
//     std::cout << "Declarations:\n";
//     for (auto i : declarations){
//         std::cout << "name: " << i->name << " position: " << i->pos << " inRegister: " << i->inRegister << "\n";
//     }
//     std::cout << "Commands:\n";
//     for (auto &i : *commands){
//         std::cout << i << "\n";
//     }
// }

