#include <string>

class Pidentifier {
public:
    std::string val;
    Pidentifier(std::string name) : val(name) {};
};

class Num{
public:
    std::string val;
    Num(int value) : val(std::to_string(value)) {};
};

class Identifier{
public:
    std::string val;
    Identifier(Pidentifier* pid){ val = pid->val;}
};

class Value{
public:
    std::string val;
    Value(Num* num) { val = num->val;}
    Value(Identifier* i) { val = i->val;}
};

class Command {
public:
    std::string val;
    Command(Value* v) {val = v->val;};
};