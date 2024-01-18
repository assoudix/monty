# Monty Interpreter

This is a simple interpreter for the Monty stack language. This interpreter is capable of processing Monty bytecode files. Monty is a stack-based programming language with a set of commands for manipulating a stack data structure.


## Extensibility

I made sure to code this program using function pointers, as such, new commands can easily be added. Just modify the file (opcode_to_func.c) by adding a new opcode and the corresponding command, then code the command in a separate source file.

## Features

- Supports basic Monty commands like push, pop, pall, pint.
- Built using function pointers, so new commands can be easily and readily added.
- Ignores comments and whitespace-only lines in bytecode files.
- Easy-to-use and minimalistic codebase.

## Usage

1. Clone this repository: 'git clone github.com/assoudix/monty'.
2. Compile the interpreter: `gcc *.c -o monty`.
3. Run Monty bytecode files: `./monty path/to/bytecode.m`.
4. (optional) Remove the bf directory: 'rm -r bf'.

## Example Bytecode

Sample Monty bytecode files can be found in the Holberton program. I am not allowed to share them publicly, as the language is not open source.

## Credit

This Monty Interpreter was developed by Omar Assoudi in the year 2023.
README.md and license were drafted with ChatGPT.

## License

This project is licensed under the MIT License - see the License file for details.
