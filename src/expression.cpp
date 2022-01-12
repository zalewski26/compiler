#include "../inc/types.hpp"
extern Output* output;

void SingleExpression::load(){
    val->load();
}

void BinaryExpression::load(){
    val2->load();
    output->swap('d');
    val1->load();
    switch (type){
        case Operations::ADD:
            output->add('d');
            break;
        case Operations::SUBTRACT:
            output->sub('d');
            break;
        case Operations::MULTIPLY:
            /*  x * y:    
                    'c'= x  'd'= y  'e'= wynik  'f'= 1 (shift) 'g'= -1 (shift)
            */
            output->swap('c');
            // zerowanie e, ustawianie f i g pod shifty
            output->reset('e');
            output->reset('f');
            output->inc('f');
            output->reset('g');
            output->dec('g');
            // sprawdzamy czy y%2 == 1, jeśli tak to trzeba dodać x do wyniku
            output->reset('a');
            output->add('d');
            output->shift('g');
            output->add('a');
            output->sub('d');
            output->jzero(5);
            output->reset('a');
            output->add('c');
            output->add('e');
            output->swap('e');
            // x = x*2  y = y/2     jeśli y == 0 to kończymy, jak nie to jeszcze raz
            output->swap('d');
            output->shift('g');
            output->jzero(7);
            output->swap('d');
            output->reset('a');
            output->swap('c');
            output->shift('f');
            output->swap('c');
            output->jump(-18);
            output->swap('e');
            break;
        case Operations::DIVIDE:

            break;
        case Operations::MOD:

            break;
        default:
            break;
    }
    
}