#include "../inc/types.hpp"
extern Output* output;

void Condition::load(){
    numValue* num1 = dynamic_cast<numValue*>(val1);
    numValue* num2 = dynamic_cast<numValue*>(val2);
    if (num1){
        if (num2){
            switch (type){
            case Conditions::NEQ:
                num1->setValue
                num1->load();
                output->placeholder("JZERO");
                break;
            default:
                break;
            }
        }

    }
}