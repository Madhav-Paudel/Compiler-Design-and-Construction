# Compiler Lab Programs

This project contains two C++ programs developed for compiler-design laboratory work:

- `lab1.cpp` — Lexical Analyzer
- `lab2.cpp` — Syntax Parser

## Project Overview

### 1. Lexical Analyzer
The lexical analyzer reads source code line by line, tokenizes it, and prints each token in the format:

`<lexeme, token_type>`

It recognizes:

- Keywords
- Identifiers
- Numbers
- Arithmetic operators
- Relational operators
- Assignment operator
- Parentheses and braces
- Semicolon and comma
- Unknown symbols

#### Example input for Lab 1
This is the same type of input shown in the screenshot. After starting the program, enter the code below and finish with `END` on a new line:

```text
int x = 10;
int y = 20;
if (x >= y) {
    z = x + y * 2;
}
while (x < 100) {
    x = x + 1;
}
END
```

#### Example output for Lab 1
```text
<int, KEYWORD>
<x, IDENTIFIER>
<=, ASSIGN>
<10, NUMBER>
<;, SEMICOLON>
...
```

### 2. Parser
The parser reads a list of tokens and checks whether they follow a simple grammar for function declarations and assignments.

It validates structures such as:

- `void functionName() { ... }`
- variable declarations like `int x = 10;`
- assignments like `a = b + 5;`

If the token sequence does not match the grammar, it prints a syntax error.

---

## Files in the Project

```text
compiler/
├── lab1.cpp
├── lab2.cpp
├── README.md
├── lab1.exe
├── lab2.exe
```

---

## How to Compile

Open a terminal in the project folder and run:

```bash
g++ lab1.cpp -o lab1
```

```bash
g++ lab2.cpp -o lab2
```

On Windows, you may also use:

```powershell
g++ lab1.cpp -o lab1.exe
```

```powershell
g++ lab2.cpp -o lab2.exe
```

---

## How to Run

### Run the Lexical Analyzer

```bash
./lab1
```

or on Windows:

```powershell
.\lab1.exe
```

Then type source code lines and finish with:

```text
END
```

### Run the Parser

```bash
./lab2
```

or on Windows:

```powershell
.\lab2.exe
```

Then enter:

1. Your name and roll number
2. Number of tokens
3. Each token as:

```text
lexeme token_type
```

#### Example input for Lab 2

```text
17
void void
main IDENTIFIER
( (
) )
{ {
int int
x IDENTIFIER
= =
5 NUMBER
; ;
x IDENTIFIER
= =
x IDENTIFIER
+ +
1 NUMBER
; ;
} }
```

#### Example explanation for Lab 2
- First line = number of tokens
- Each following line = `lexeme token_type`
- The above input represents a small function such as:

```text
void main() {
    int x = 5;
    x = x + 1;
}
```

This is the example people can use while running the parser program.

---

## Expected Behavior

### Lexical Analyzer Output

```text
<if, KEYWORD>
<x, IDENTIFIER>
<==, EQUAL>
<10, NUMBER>
```

### Parser Output

```text
PARSING SUCCESSFUL
The input follows the grammar.
```

If the token sequence is invalid, the parser shows a syntax error message.

---

## Notes

- Each program is an independent C++ executable.
- `lab1.cpp` and `lab2.cpp` are meant to be compiled and run separately.
- This project is a simple academic implementation for learning compiler concepts.

---

## Author

This project was created as part of a compiler/language design lab assignment.
