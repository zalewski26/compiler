#include "../inc/types.hpp"
extern Output* output;

void SingleExpression::load(){
    val->load();
}

void BinaryExpression::load(){
    val2->load();
    output->swap('c');
    val1->load();
    switch (type){
        case Operations::ADD:
            output->add('c');
            break;
        case Operations::SUBTRACT:
            output->sub('c');
            break;
        case Operations::MULTIPLY:

            break;
        case Operations::DIVIDE:

            break;
        case Operations::MOD:

            break;
        default:
            break;
    }
    
}