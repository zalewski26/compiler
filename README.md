# Simple Imperative Language Compiler

This project is a simple imperative language compiler targeting virtual machine code, developed for the Formal Languages and Translation Techniques course at Wrocław University of Science and Technology.

## Overview

The compiler is designed to translate a simple imperative language into a set of instructions executable by a virtual machine. It is implemented in C++ and features a lexer and parser in the main application directory. Header files declaring necessary types are located in the `inc` directory, while class definition files for components such as program, command, expression, pidentifier, and more are found in the `src` directory.

## Compilation

To compile the project, navigate to the project directory and use the `make` command:

```sh
make
```

This will produce the `compiler` executable.

## Usage

Once compiled, you can run the compiler using the following command:

```sh
./compiler <input file name> <output file name>
```

Replace `<input file name>` with the name of your source file and `<output file name>` with the desired output file for the virtual machine code.

## Testing

The `test.py` Python script is provided to run a suite of tests, which are detailed on the course tutor's page. To execute all the required tests and compare the output with the expected results, run:

```sh
python3 test.py
```

This assumes you have a virtual machine executable named `virtual-machine` in the adjacent directory.

## Project Structure

- `/main` - Contains the lexer and parser implementation.
- `/inc` - Contains the header files with type declarations.
- `/src` - Contains the implementation of classes required for the compiler's functionality.

