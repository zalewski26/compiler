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


/********** PROGRAM ***************/
class Program {
private:
    std::vector<Declaration*> declarations;
    // std::vector<Command*> commands;

    Declaration* getDeclaration(std::string name);
    void addDeclaration(std::string name);
public:
    void install(std::string name);
    int context_check(std::string name);
    // void addCommand(Command* c);

    void printAll();
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
typedef std::vector<Command*> CommandSet;

class Command{

};

class AssignCommand : public Command{
public:
    AssignCommand(Identifier*, Expression*){}
};

class IfElseCommand : public Command{
public:
    IfElseCommand(Condition*, CommandSet*, CommandSet*){}
};

class IfCommand : public Command{
public:
    IfCommand(Condition*, CommandSet*){}
};

class WhileCommand : public Command{
public:
    WhileCommand(Condition*, CommandSet*) {}
};

class RepeatCommand : public Command{
public:
    RepeatCommand(CommandSet*, Condition*){}
};

class ForToCommand : public Command{
public:
    ForToCommand(std::string, Value*, Value*, CommandSet*){}
};

class ForDownToCommand : public Command{
public:
    ForDownToCommand(std::string, Value*, Value*, CommandSet*){}
};

class ReadCommand : public Command{
public:
    ReadCommand(Identifier*) {}
};

class WriteCommand : public Command{
public:
    WriteCommand(Value*) {}
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
    Identifier(){}
};

class Pidentifier : public Identifier {
public:
    Pidentifier(std::string name){}
};


#endif
