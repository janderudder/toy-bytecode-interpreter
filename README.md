# Bytecode interpreter VM


A very simplistic and small virtual machine interpreting a custom byte code.

It has no call stack, no concept of RAM. Just a pointer to an array of instructions and registers that can store natural numbers or pointers to C-strings.



## Some features

Every arithmetic operation stores the value in place, in the register referred to by the first operand.

Every test that fails skips the next instruction.

All jumps are relative, and can go backwards.



## Instructions

The format of an instruction is
```c
struct { OpCode; RegIndex; Nat; };
```

`OpCode` is a scoped enum that fits in a single byte and describes the operation.

The `RegIndex` type is 1 byte long and stores only the index of a register inside the machine. This is the first operand of the operation.

The second operand is a `Nat` value taking 64 bits that can store a constant natural number, or a Register Index, or a pointer to a string (usual null terminated C-string).

Most `OpCode` values come in pairs, e.g. `SET` and `SETC`, `ADD` and `ADDC`, etc.
The only difference is in the way the operation will treat the second operand of the instruction (the `Nat` number). The 'C' letter in the name means 'constant', and in that case the operation expects to work directly on a constant value stored in the `Nat` part. Whereas the "normal" version of the instruction treats the second operand as a register index, and will first fetch the value in the machine's memory before doing the operation.

There are no instructions really taking a single operand. Instead, they just look only in the second operand, for instance `Instruction{JMP, 0, R1}`.

The list of all opcodes is in `include/bytecode/OpCode.hpp`.



## Sample programs

The project comes with some sample byte-code programs. Compiling the project gives an executable that expects the name of a sample program as first argument, and, depending on the selected sample, some numbers to work with.

Here's a list of the available sample programs:

    hello
    div
    fib
    pow

Check their bytecode in the `src/sample` folder.

You'll notice they use some shorthand notation, or factory functions, to create proper instructions. For example the line `jmp(6)` actually returns `Instruction{OpCode::JMPC, 0, 6}`.


## What's next ?

Inputs, a call stack, maybe a compiler ? Or something unrelated entirely.
Maybe get in touch: janderudder.dev@gmail.com
