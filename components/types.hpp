#ifndef TYPES_H
#define TYPES_H

#include <vector>
#include <string>

class Identifier;
class Value;
class Condition;
class Expression;
class Command;
class Declaration;
typedef std::vector<Command*> CommandSet;
typedef std::vector<Identifier*> IdentifiersSet;


/********** PROGRAM ***************/
class Program {
private:
    std::vector<Declaration*> declarations;
    CommandSet* commands;
    Declaration* getDeclaration(std::string name);
    void addDeclaration(std::string name);
public:
    char acc = 'a', addr = 'b';
    int accVal, addrVal;
    char registers[6] = {'c','d','e','f','g','h'};
    int registersVal[6];

    void install(std::string name);
    Declaration* context_check(std::string name);
    void printAll();

    Program(CommandSet* commands) : commands(commands){};
    Program(IdentifiersSet* ids, CommandSet* commands);
    void compile();
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
    virtual void run(Program*) {};
};

class AssignCommand : public Command{
private:
    Identifier* ident;
    Expression* exp;
public:
    AssignCommand(Identifier* ident, Expression* exp) : ident(ident), exp(exp){}
    void run(Program*) override;
};

class IfElseCommand : public Command{
public:
    IfElseCommand(Condition*, CommandSet*, CommandSet*){}
    void run(Program*) override;
};

class IfCommand : public Command{
public:
    IfCommand(Condition*, CommandSet*){}
    void run(Program*) override;
};

class WhileCommand : public Command{
public:
    WhileCommand(Condition*, CommandSet*) {}
    void run(Program*) override;
};

class RepeatCommand : public Command{
public:
    RepeatCommand(CommandSet*, Condition*){}
    void run(Program*) override;
};

class ForToCommand : public Command{
public:
    ForToCommand(std::string, Value*, Value*, CommandSet*){}
    void run(Program*) override;
};

class ForDownToCommand : public Command{
public:
    ForDownToCommand(std::string, Value*, Value*, CommandSet*){}
    void run(Program*) override;
};

class ReadCommand : public Command{
public:
    ReadCommand(Identifier*) {}
    void run(Program*) override;
};

class WriteCommand : public Command{
public:
    WriteCommand(Value*) {}
    void run(Program*) override;
};


/********** EXPRESSION ***************/
class Expression{

};

class SingleExpression : public Expression{
public:	
    SingleExpression(Value* v) {}
};

class BinaryExpression : public Expression{
public:
    BinaryExpression(Value* v1, Value* v2, int type) {}
};


/********** CONDITION ***************/
class Condition{
public:
    Condition(Value* a, Value* b, int type){};
};


/********** VALUE ***************/
class Value{

};

class idValue : public Value{
public:
    idValue(Identifier* i) {};
};

class numValue : public Value{
public:
    numValue(int num) {};
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
