#include "../inc/types.hpp"
extern Output* output;

int Condition::load(){
    int result;
    val2->load();
    output->swap('c');
    val1->load();
    output->sub('c');
    switch (type){
        case Conditions::EQ:
            output->placeholder("JNEG");
            output->placeholder("JPOS");
            result = 2;
            break;
        case Conditions::NEQ:
            output->placeholder("JZERO");
            result = 1;
            break;
        case Conditions::LE:
            output->placeholder("JZERO");
            output->placeholder("JPOS");
            result = 2;
            break;
        case Conditions::GE:
            output->placeholder("JZERO");
            output->placeholder("JNEG");
            result = 2;
            break;
        case Conditions::LEQ:
            output->placeholder("JPOS");
            result = 1;
            break;
        case Conditions::GEQ:
            output->placeholder("JNEG");
            result = 1;
            break;
        default:
            break;
    }
    return result;
}