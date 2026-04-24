# Design and Implementation of a Mini Compiler for a Domain Specific Language using Flex, Bison and C

## 📌 Project Description

This project implements a **mini compiler** for a simple Domain Specific Language (DSL).
The compiler processes input code through multiple stages including lexical analysis, parsing, Abstract Syntax Tree (AST) construction, semantic analysis, and intermediate code generation.

---

## ⚙️ Tools Used

* Flex (Lexical Analysis)
* Bison (Parsing)
* GCC Compiler
* C Programming Language
* WSL (Ubuntu)

---

## 🧩 Compiler Architecture

```
Input Code
    ↓
Lexical Analysis (Flex)
    ↓
Parsing (Bison)
    ↓
Abstract Syntax Tree (AST)
    ↓
Semantic Analysis
    ↓
Intermediate Code Generation
```

---

## 🚀 Steps to Run

1. Clone the repository:

```
git clone <repo-link>
cd Compiler-Design-DSL_RegNo_Name
```

2. Compile the project:

```
make
```

3. Run the compiler:

```
./compiler test/test1.dsl
```

---

## 📝 Sample Input

```
let x = 10;
let y = 20;
let z = x + y * 2;
print z;
```

---

## 📤 Sample Output

```
Parsing Successful!

Abstract Syntax Tree:
DECL: x
  NUM: 10
DECL: y
  NUM: 20
DECL: z
  BINOP: +
    ID: x
    BINOP: *
      ID: y
      NUM: 2
PRINT
  ID: z

Semantic Analysis:
No errors found ✔

Intermediate Code:
t1 = y * 2
t2 = x + t1
z = t2
print z
```

---

## 📁 Folder Structure

```
Compiler-Design-DSL_RegNo_Name/
│── src/        (source code files)
│── docs/       (report and documentation)
│── test/       (input test cases)
│── output/     (execution results)
│── README.md
```

---

## 👨‍💻 Team Details

* Name: Raga Amirtha
* Reg No: RA2311026050054

---

## ✅ Conclusion

This project demonstrates the complete working of a compiler pipeline from source code to intermediate representation using Flex, Bison, and C.
