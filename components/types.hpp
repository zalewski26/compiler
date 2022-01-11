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
    void install(std::string name);
    int context_check(std::string name);
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
    virtual void run() {};
};

class AssignCommand : public Command{
public:
    AssignCommand(Identifier*, Expression*){
        printf("ASSIGN\n");
    }
    void run() override;
};

class IfElseCommand : public Command{
public:
    IfElseCommand(Condition*, CommandSet*, CommandSet*){}
    void run() override;
};

class IfCommand : public Command{
public:
    IfCommand(Condition*, CommandSet*){}
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
public:
    ReadCommand(Identifier*) {}
    void run() override;
};

class WriteCommand : public Command{
public:
    WriteCommand(Value*) {}
    void run() override;
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
    BinaryExpression(Value* v1, Value* v2, int type) {
        printf("%d\n", type);
    }
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
