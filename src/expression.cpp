#include "../inc/types.hpp"

void SingleExpression::load(){
    val->load();
}

void BinaryExpression::load(){
    numValue* num1 = dynamic_cast<numValue*>(val1);
    numValue* num2 = dynamic_cast<numValue*>(val2);
    if (num1){
        if (num2){
            switch (type){
            case Operations::ADD:
                num1->setValue(num1->getValue() + num2->getValue());
                break;
            case Operations::SUBTRACT:
                num1->setValue(num1->getValue() - num2->getValue());
                break;
            case Operations::MULTIPLY:
                num1->setValue(num1->getValue() * num2->getValue());
                break;
            case Operations::DIVIDE:
                num1->setValue(num1->getValue() / num2->getValue());
                break;
            case Operations::MOD:
                num1->setValue(num1->getValue() % num2->getValue());
                break;
            default:
                break;
            }
            num1->load();
        }
        else {
            
        }
    }
    else {
        if (num2){
        
        }
        else {
            
        }
    }
    
}