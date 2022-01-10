struct symrec {
    char *name; /* name of symbol */
    // int offset; /* data offset */
    int pos;
    bool inRegister;
    struct symrec *next; /* link field */
};

typedef struct symrec symrec;
symrec *sym_table = (symrec *)0;

// int registers[8];
int memoryCounter = 0;

symrec* putsym (char *sym_name){
    symrec* ptr;
    ptr = (symrec *) malloc (sizeof(symrec));
    ptr->name = (char *) malloc (strlen(sym_name)+1);
    strcpy (ptr->name, sym_name);
    // ptr->offset = data_location();
    ptr->next = (struct symrec *)sym_table;
    sym_table = ptr;
    ptr->pos = memoryCounter;
    ptr->inRegister = false;
    memoryCounter++;
    return ptr;
}

symrec * getsym (char *sym_name){
    symrec *ptr;
    for ( ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next ){
        if (strcmp (ptr->name,sym_name) == 0)
            return ptr;
    }
    return 0;
}

void printSym(){
    symrec *ptr;
    printf("------------------\n");
    for ( ptr = sym_table; ptr != (symrec *) 0; ptr = (symrec *)ptr->next ){
        printf("name = %s, pos = %d, inRegister = %d\n", ptr->name, ptr->pos, ptr->inRegister);
    }
}

