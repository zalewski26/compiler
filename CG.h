enum code_ops { HALT, STORE, JMP_FALSE, GOTO,
    DATA, LD_INT, LD_VAR,
    READ_INT, WRITE_INT,
    LT, EQ, GT, ADD, SUB, MULT, DIV, PWR };

char *op_name[] = {"halt", "store", "jmp_false", "goto",
                "data", "ld_int", "ld_var",
                "in_int", "out_int",
                "lt", "eq", "gt", "add", "sub", "mult", "div", "pwr" };

struct instruction{
    enum code_ops op;
    int arg;
};

struct instruction code[999];
int stack[999];
int pc = 0;
struct instruction ir;
int ar = 0;
int top = 0;
char ch;

int data_offset = 0; /* Initial offset */
int data_location() /* Reserves a data location */{
    return data_offset++;
}

int code_offset = 0; /* Initial offset */
int gen_label() /* Returns current offset */{
return code_offset;
}
int reserve_loc() /* Reserves a code location */{
return code_offset++;
}
/* Generates code at current location */
void gen_code( enum code_ops operation, int arg ){ 
    code[code_offset].op = operation;
    code[code_offset++].arg = arg;
}
/* Generates code at a reserved location */
void back_patch( int addr, enum code_ops operation, int arg ){
    code[addr].op = operation;
    code[addr].arg = arg;
}

void print_code(){
    int i = 0;
    while (i < code_offset) {
    printf("%3ld: %-10s%4ld\n",i,op_name[(int) code[i].op], code[i].arg );
    i++;
    }
}