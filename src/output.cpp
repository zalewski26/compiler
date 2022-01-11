#include "../inc/types.hpp"
#include <iostream>

void Output::printCode(){
    for (int i = 0; i < programCode.size(); i++){
        std::cout << "\033[1;34m " << i << "\033[0m " << programCode[i] << "\n";
        std::cerr << programCode[i] << "\n";
    }
}

void Output::modify(int result){
    for (int j = 0; j < result; j++){
        int temp = counter - counters.top();
        counters.pop();
        for (int i = programCode.size() - 1; i >= 0; i--){
            if (programCode[i] == std::string("JZERO") || programCode[i] == std::string("JPOS") || programCode[i] == std::string("JNEG")){
                programCode[i] = programCode[i] + " "  + std::to_string(temp);
                break;
            }
        }
    }
}

void Output::get(){programCode.push_back("GET"); counter++;}
void Output::put(){programCode.push_back("PUT"); counter++;}
void Output::load(char c){programCode.push_back(std::string("LOAD ") + c); counter++;}  
void Output::store(char c){programCode.push_back(std::string("STORE ") + c); counter++;}  
void Output::add(char c){programCode.push_back(std::string("ADD ") + c); counter++;}  
void Output::sub(char c){programCode.push_back(std::string("SUB ") + c); counter++;}  
void Output::shift(char c){programCode.push_back(std::string("SHIFT ") + c); counter++;}  
void Output::swap(char c){programCode.push_back(std::string("SWAP ") + c); counter++;}  
void Output::reset(char c){programCode.push_back(std::string("RESET ") + c); counter++;}  
void Output::inc(char c){programCode.push_back(std::string("INC ") + c); counter++;}  
void Output::dec(char c){programCode.push_back(std::string("DEC ") + c); counter++;}  
void Output::jump(int a){programCode.push_back(std::string("JUMP ") + std::to_string(a)); counter++;}  
void Output::jpos(int a){programCode.push_back(std::string("JPOS ") + std::to_string(a)); counter++;}  
void Output::jzero(int a){programCode.push_back(std::string("JZERO ") + std::to_string(a)); counter++;}  
void Output::jneg(int a){programCode.push_back(std::string("JNEG ") + std::to_string(a)); counter++;}  
void Output::halt(){
    programCode.push_back("HALT");
    printCode();
}  

void Output::placeholder(std::string name){
    programCode.push_back(name);
    counters.push(counter);
    counter++;
}