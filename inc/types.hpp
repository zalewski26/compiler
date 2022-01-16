#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>
#include <stack>
#include "../inc/enums.hpp"

class Pidentifier;
class Identifier;
class Value;
class Condition;
class Expression;
class Command;
class Declaration;
typedef std::vector<Command*> CommandSet;


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
    long long accVal, addrVal;
    char registers[6] = {'c','d','e','f','g','h'};
    int registersVal[6];
};

/*********** OUTPUT *******************/
class Output{
private:
    std::vector<std::string> programCode;
    void printCode();
    int counter = 0;
    std::stack<long long> condJumpCount;
    std::stack<long long> jumpCount;
    std::stack<long long> repeatCount;
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
    void jump(long long);
    void jpos(long long);
    void jzero(long long);
    void jneg(long long);
    void halt(); 

    void condJumpPlaceholder(std::string);
    void updateCondJump(int);
    void jumpPlaceholder();
    void updateJump();
    void repeatPlaceholder();
    void updateRepeat(int);
    void updateWhile();
};

/********** DECLARATIONS **************/
class Declarations{
private:
    std::vector<Declaration*> declarations;
    long long memoryCounter = 0;

    Declaration* getDeclaration(std::string name);
public:
    void install(std::string name, bool isIterator=false);
    void install(std::string name, long long start, long long end);
    Declaration* context_check(std::string name);
    void markAsInitialized(Identifier*);
    void remove(std::string name);
    void throwErr(std::string, int correction=0);
    void print();
};

/********** DECLARATION ***************/
class Declaration {
public:
    std::string name;
    long long pos;
    long long length;
    long long baseDiff;
    bool isArray;
    bool isIterator;
    bool isInitialized;

    Declaration(std::string name, long long pos, bool isIterator) 
            : name(name), pos(pos), isIterator(isIterator) { 
                length = 1; baseDiff = 0; isArray = false; isInitialized = false;
            }
    Declaration(std::string name, long long pos, long long length, long long baseDiff) 
            : name(name), pos(pos), length(length), baseDiff(baseDiff) {
                isArray = true; isInitialized = false;
            }
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
    AssignCommand(Identifier* ident, Expression* exp);
    void run() override;
};

class IfElseCommand : public Command{
private:
    Condition* cond;
    CommandSet* cSet1;
    CommandSet* cSet2;
public:
    IfElseCommand(Condition* cond, CommandSet* cSet1, CommandSet* cSet2)
             : cond(cond), cSet1(cSet1), cSet2(cSet2) {}
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
private:
    Condition* cond;
    CommandSet* cSet;
public:
    WhileCommand(Condition* cond, CommandSet* cSet) : cond(cond), cSet(cSet) {}
    void run() override;
};

class RepeatCommand : public Command{
private:
    CommandSet* cSet;
    Condition* cond;
public:
    RepeatCommand(CommandSet* cSet, Condition* cond) : cSet(cSet), cond(cond){}
    void run() override;
};

class ForCommand : public Command{
private:
    Pidentifier* pident;
    Pidentifier* limit;
    Value* val1;
    Value* val2;
    CommandSet* cSet;
    bool downTo;

public:
    ForCommand(Pidentifier* pident, Pidentifier* limit, Value* v1, Value* v2, CommandSet* cSet, bool downTo)
        : pident(pident), limit(limit), val1(v1), val2(v2), cSet(cSet), downTo(downTo){}
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
    int loadIf();
    int loadRepeat();
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
    long long value;
public:
    numValue(long long num) : value(num) {};
    long long getValue() {return value;}
    void setValue(long long value) {this->value = value;}
    void load() override;
};


/********** IDENTIFIER ***************/
class Identifier{
public:
    bool isIterator;
    Identifier(){}
    virtual void loadAddr(){};

    virtual std::string getName(){
        return "base";
    };
};

class Pidentifier : public Identifier {
private:
    std::string name;
    long long pos;
public:
    Pidentifier(std::string);
    void loadAddr();
    std::string getName(){
        return name;
    };
};

class arrIdentifier : public Identifier {
private:
    std::string name;
    numValue* baseDiff;
    Value* index;
public:
    arrIdentifier(std::string, long long);
    arrIdentifier(std::string, std::string);
    void loadAddr();
    std::string getName(){
        return name;
    };
};

#endif
