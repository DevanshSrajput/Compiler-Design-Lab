# Compiler Design Lab

This repository contains the practical implementations of various compiler design concepts and algorithms developed during my Compiler Design Lab sessions in college.

## 📚 About

This repository serves as a collection of experiments and programs exploring fundamental compiler construction topics. It includes implementations of lexical analyzers, finite automata, grammar transformations, and other core compiler components.

**Current Status:** 4 experiments completed  
**More experiments will be added as the semester progresses.**

---

## 🔬 Experiments

### Experiment 1: Lexical Analyzer
**File:** `Lexical.c`

A simple lexical analyzer that tokenizes input source code by identifying:
- **Keywords:** `if`, `else`, `while`, `int`, `float`, `return`, `void`
- **Identifiers:** Variable and function names
- **Operators:** `+`, `-`, `*`, `/`, `<`, `>`, `=`
- **Special Symbols:** `()`, `{}`, `[]`, `;`, `,`
- **Numbers:** Numeric constants

**Example Input:** `int x = 5;`

---

### Experiment 2: DFA (Deterministic Finite Automaton)
**File:** `DFA.c`

Implementation of a DFA that accepts strings ending with "ab" over the alphabet {a, b}.

**Features:**
- Transition table construction and display
- String acceptance testing
- Demonstrates DFA design for pattern recognition

**Test Cases:** Includes validation for strings like "ab", "aab", "bab", "abab", "ba", "bb", "a", "abb"

---

### Experiment 3: DFA to NFA Conversion
**File:** `DFA_NFA.c`

Demonstrates the conversion of a DFA to an equivalent NFA (Non-deterministic Finite Automaton).

**Features:**
- DFA representation
- Equivalent NFA construction
- NFA simulation on input strings
- State transition visualization

**Example:** Simulates NFA behavior on the input string "aab"

---

### Experiment 4: Left Recursion Elimination & Left Factoring
**File:** `LeftFactoring.c`

A comprehensive tool for grammar transformation that performs:

1. **Left Recursion Elimination:**
   - Identifies and removes left recursion from production rules
   - Generates new non-terminals with appropriate transformations

2. **Left Factoring:**
   - Finds common prefixes in production alternatives
   - Factors out common prefixes to simplify grammar

**Input Format:** Productions in the form `A->α|β` (use 'e' for ε)

---

## 🚀 How to Run

### Prerequisites
- GCC compiler or any C compiler
- Terminal/Command Prompt

### Compilation and Execution

For any experiment, follow these steps:

```bash
# Compile the program
gcc <filename.c> -o <output_name>

# Run the program
./<output_name>
```

**Examples:**

```bash
# Lexical Analyzer
gcc Lexical.c -o lexical
./lexical

# DFA
gcc DFA.c -o dfa
./dfa

# DFA to NFA
gcc DFA_NFA.c -o dfa_nfa
./dfa_nfa

# Left Factoring
gcc LeftFactoring.c -o leftfactoring
./leftfactoring
```

---

## 📖 Topics Covered

- [x] Lexical Analysis
- [x] Finite Automata (DFA)
- [x] NFA and DFA Equivalence
- [x] Grammar Transformations (Left Recursion & Left Factoring)
- [ ] More topics to be added...

---

## 🔮 Future Additions

As the semester progresses, the following topics are expected to be added:

- Syntax Analysis (Parsers)
- Semantic Analysis
- Intermediate Code Generation
- Code Optimization
- Target Code Generation

---

## 👨‍💻 Author

**Devansh Rajput**

---

## 📝 License

This repository is for educational purposes as part of the Compiler Design Lab coursework.

---

## 📌 Notes

- All programs are written in C
- Each program is self-contained and can be run independently
- Test cases are included within the programs where applicable
- Comments and output formatting have been added for better understanding

---

*Last Updated: February 2026*
