#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
#include <stack>
#include "../inc/enums.hpp"

class Identifier;
class Value;
class Condition;
class Expression;
class Command;
class Declaration;
typedef std::vector<Command*> CommandSet;

void adjAddress(int pos);

/********** PROGRAM ***************/
class Program {
private:
    CommandSet* commands;
public:
    Program(CommandSet* commands) : commands(commands){};
    void compile();
};

/********** REGISTERS *****************/
class Registers{
private:
public:
    const char acc = 'a';
    const char addr = 'b';
    int accVal, addrVal;
    char registers[6] = {'c','d','e','f','g','h'};
    int registersVal[6];
};

/*********** OUTPUT *******************/
class Output{
private:
    std::vector<std::string> programCode;
    void printCode();
    int counter = 0;
    std::stack<int> counters;
public:
    void get();
    void put();
    void load(char);
    void store(char);
    void add(char);
    void sub(char);
    void shift(char);
    void swap(char);
    void reset(char);
    void inc(char);
    void dec(char);
    void jump(int);
    void jpos(int);
    void jzero(int);
    void jneg(int);
    void halt(); 

    void placeholder(std::string);
    void modify(int);
};

/********** DECLARATIONS **************/
class Declarations{
private:
    std::vector<Declaration*> declarations;

    Declaration* getDeclaration(std::string name);
    void addDeclaration(std::string name);
public:
    void install(std::string name);
    Declaration* context_check(std::string name);
};

/********** DECLARATION ***************/
class Declaration {
public:
    std::string name;
    int pos;
    bool inRegister;

    Declaration(std::string name, int pos, bool inRegister) 
            : name(name), pos(pos), inRegister(inRegister){}
};

/********** COMMAND ***************/
class Command{
public:
    virtual void run() {};
};

class AssignCommand : public Command{
private:
    Identifier* ident;
    Expression* exp;
public:
    AssignCommand(Identifier* ident, Expression* exp) : ident(ident), exp(exp){}
    void run() override;
};

class IfElseCommand : public Command{
public:
    IfElseCommand(Condition*, CommandSet*, CommandSet*){}
    void run() override;
};

class IfCommand : public Command{
    Condition* cond;
    CommandSet* cSet;
public:
    IfCommand(Condition* cond, CommandSet* cSet) : cond(cond), cSet(cSet) {}
    void run() override;
};

class WhileCommand : public Command{
public:
    WhileCommand(Condition*, CommandSet*) {}
    void run() override;
};

class RepeatCommand : public Command{
public:
    RepeatCommand(CommandSet*, Condition*){}
    void run() override;
};

class ForToCommand : public Command{
public:
    ForToCommand(std::string, Value*, Value*, CommandSet*){}
    void run() override;
};

class ForDownToCommand : public Command{
public:
    ForDownToCommand(std::string, Value*, Value*, CommandSet*){}
    void run() override;
};

class ReadCommand : public Command{
private:
    Identifier* ident;
public:
    ReadCommand(Identifier* i) : ident(i) {}
    void run() override;
};

class WriteCommand : public Command{
    Value* val;
public:
    WriteCommand(Value* val) : val(val) {}
    void run() override;
};


/********** EXPRESSION ***************/
class Expression{
public:
    virtual void load(){};
};

class SingleExpression : public Expression{
private:
    Value* val;
public:	
    SingleExpression(Value* v) : val(v) {}
    void load() override;
};

class BinaryExpression : public Expression{
private:
    Value* val1;
    Value* val2;
    Operations type;
public:
    BinaryExpression(Value* v1, Value* v2, Operations type) : val1(v1), val2(v2), type(type) {}
    void load() override;
};


/********** CONDITION ***************/
class Condition{
private:
    Value* val1;
    Value* val2;
    Conditions type;
public:
    Condition(Value* a, Value* b, Conditions type) : val1(a), val2(b), type(type){};
    int load();
};


/********** VALUE ***************/
class Value{
public:
    virtual void load(){};
};

class idValue : public Value{
private:
    Identifier* ident;
public:
    idValue(Identifier* ident) : ident(ident) {};
    void load() override;
};

class numValue : public Value{
private:
    int value;
public:
    numValue(int num) : value(num) {};
    int getValue() {return value;}
    void setValue(int value) {this->value = value;}
    void load() override;
};


/********** IDENTIFIER ***************/
class Identifier{
public:
    std::string name;
    Identifier(){}
};

class Pidentifier : public Identifier {
public:
    Pidentifier(std::string n){
        name = n;
    }
};

#endif
