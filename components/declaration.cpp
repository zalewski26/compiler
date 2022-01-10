#include <string>

class Declaration {
public:
    std::string name;
    int pos;
    bool inRegister;

    Declaration(std::string name, int pos, bool inRegister) 
            : name(name), pos(pos), inRegister(inRegister){}
};