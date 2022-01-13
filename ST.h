struct symrec {
    char *name; /* name of symbol */
    int pos;
    bool inRegister;
};
typedef struct symrec symrec;

int registers[8];
int registerCounter = 2;

symrec* putsym (char *sym_name){
    symrec* ptr;
    ptr = (symrec *) malloc (sizeof(symrec));
    ptr->name = (char *) malloc (strlen(sym_name)+1);
    strcpy (ptr->name, sym_name);
    ptr->pos = registerCounter;
    ptr->inRegister = true;
    registers[registerCounter++] = ptr;
    return ptr;
}

symrec * getsym (char *sym_name){
    symrec *ptr;
    for (int i = 2; i < std::min(registerCounter, 8); i++){
        if (strcmp(registers[i]->name, sym_name) == 0)
            return registers[i];
    }
    return 0;
}

void printRegs(){
    for (int i = 0; i < std::min(registerCounter, 8); i++){
        printf("register[%d]: name = %s, pos = %d, inRegister = %d\n", i, registers[i]->name, registers[i]->pos, registers[i]->inRegister);
    }
}