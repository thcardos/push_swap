<div align="center">

*This project has been created as part of the 42 curriculum by thcardos*

# ![push_swap](https://img.shields.io/badge/push_swap-9932CC?style=for-the-badge&logo=42&logoColor=white)

</div>

## ![Description](https://img.shields.io/badge/Description-B19CD9?style=flat-square)

<sub>The push_swap project is a highly restrictive sort algorithm challenge. The goal is to sort a stack of integers using two stacks (A and B) and a specific set of operations, aiming to do it in the lowest possible number of moves. This project is part of the 42 curriculum and enables students to practice advanced C concepts such as linked lists, algorithmic complexity, and sorting algorithms.

</sub>

<sub>

**`./push_swap [numbers]`** : Sorts the given arguments and prints the sequence of operations to stdout.
**`[numbers]`** : The integers to be sorted, passed as separate arguments or a single string.
**`Return Value:`** Nothing (prints to stdout), or "Error\n" to stderr if invalid input is provided.

</sub>

<sub>**Below is a detailed description of the allowed operations:** 
</sub>

<sub>**`sa` (swap a)** </sub>
<sub>- Swaps the top 2 elements of stack A. Does nothing if there is only one or no element.</sub>

<sub>**`sb` (swap b)** </sub>
<sub>- Swaps the top 2 elements of stack B. Does nothing if there is only one or no element.</sub>

<sub>**`ss`** </sub>
<sub>- Performs `sa` and `sb` at the same time.</sub>

<sub>**`pa` (push a)** </sub>
<sub>- Takes the first element of stack B and puts it at the top of stack A.</sub>

<sub>**`pb` (push b)** </sub>
<sub>- Takes the first element of stack A and puts it at the top of stack B.</sub>

<sub>**`ra` (rotate a)** </sub>
<sub>- Shifts all elements of stack A up by 1. The first element becomes the last.</sub>

<sub>**`rb` (rotate b)** </sub>
<sub>- Shifts all elements of stack B up by 1. The first element becomes the last.</sub>

<sub>**`rr`** </sub>
<sub>- Performs `ra` and `rb` at the same time.</sub>

<sub>**`rra` (reverse rotate a)** </sub>
<sub>- Shifts all elements of stack A down by 1. The last element becomes the first.</sub>

<sub>**`rrb` (reverse rotate b)** </sub>
<sub>- Shifts all elements of stack B down by 1. The last element becomes the first.</sub>

<sub>**`rrr`** </sub>
<sub>- Performs `rra` and `rrb` at the same time.</sub>

<sub>**Algorithm and Data Structure**</sub>

<sub>**`Linked Lists for Stacks`**</sub>
<sub>I use custom linked lists (`t_stack` and `t_node`) to represent the stacks.</sub>
<sub><sub>**Why:**</sub></sub>
<sub>- Allows O(1) push and pop operations at the top of the stack.</sub>
<sub>- Facilitates easy manipulation of elements without shifting large arrays.</sub>
<sub>- Matches the logical representation of a stack.</sub>

<sub>**`Cost-Based Sorting Algorithm (for > 5 elements)`**</sub>
<sub>The algorithm pushes elements to stack B until only 3 remain in A, sorts the 3, and then pushes elements back to A one by one based on a "cost" calculation.</sub>
<sub><sub>**Why:**</sub></sub>
<sub>- It drastically reduces the number of operations compared to naive sorting.</sub>
<sub>- The cost calculation evaluates the optimal position in both stacks simultaneously.</sub>
<sub>- It allows combining moves (like `rr` and `rrr`) to save operations.</sub>

<sub>**`Small Stack Sorting (for <= 5 elements)`**</sub>
<sub>Uses hardcoded logic and specific permutations to sort stacks of 2, 3, 4, and 5 elements in the absolute minimum number of moves.</sub>
<sub><sub>**Why:**</sub></sub>
<sub>- Recursion or complex algorithms are overkill and inefficient for very small sets.</sub>
<sub>- Hardcoding ensures the maximum score for small stack sizes in the evaluation.</sub>

<sub>**`Strict Input Parsing`**</sub>
<sub>The parsing logic checks for duplicates, non-numeric characters, and integers outside the `int` range.</sub>
<sub><sub>**Why:**</sub></sub>
<sub>- The subject strictly requires printing "Error\n" and exiting on any invalid input.</sub>
<sub>- Prevents undefined behavior and ensures robustness.</sub>

<sub>**`Chosen data types`**</sub>

<sub>

| Structure/Variable | Type | Justification |
|--------|------|---------------|
| `t_stack` | `struct` | Holds the top pointer and size of the stack |
| `t_node` | `struct` | Holds value, rank, costs, target, and next pointer |
| `val`, `cost_a`, `cost_b` | `int` | Standard integer type for values and operation counts |
| `num` (in parsing) | `long` | Used to safely check for `INT_MIN` and `INT_MAX` overflow before casting |

</sub>

## ![Instructions](https://img.shields.io/badge/Instructions-B19CD9?style=flat-square)

<sub>

**Compilation**
```bash
# Compile the main executable
make

# Clean object files
make clean

# Remove executable and clean all libraries
make fclean

# Recompile from scratch
make re
```
</sub>
<sub>

**Testing**
```bash
# Pass no arguments
./push_swap

# Pass numbers as separate arguments
./push_swap 3 2 1 5 4

# Pass numbers as a single string
./push_swap "3 2 1 5 4"

# Pass already ordered numbers
./push_swap 1 2 3 5 6 7

# Test with an error
./push_swap 3 2 1 1 4
./push_swap 0 one 2
./push_swap 2147483648
```
</sub>
<sub>

**Test benchmark limits**
```bash
# For 100 it should be  fewer than 700 operations
ARG="$(shuf -i 1-100 -n 100 | tr '\n' ' ')"
./push_swap $ARG | wc -l

# For 500 it should be  fewer than 5500 operations
ARG="$(shuf -i 1-500 -n 500 | tr '\n' ' ')"
./push_swap $ARG | wc -l
```
</sub>

<sub>

**Using the checker:**
```bash
# Pass a list of numbers and test it
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG

# Generate a random list of 100 numbers and test it
ARG="$(shuf -i 1-100 -n 100 | tr '\n' ' ')"
./push_swap $ARG | ./checker_linux $ARG
```
</sub>

<sub>

**Memory verification with Valgrind:**
```bash
# Run Valgrind on the executable
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1 5 4

# Run with Valgrind
valgrind --leak-check=full ./push_swap 3 2 1 5 4

# Show all possible Leaks
valgrind --leak-check=full --show-leak-kinds=all ./push_swap 3 2 1 5 4

# Display detailed information about the errors
valgrind --leak-check=full --track-origins=yes ./push_swap 3 2 1 5 4

# Save the report to a file
valgrind --leak-check=full --log-file=valgrind_report.txt ./push_swap 3 2 1 5 4
```

**🟩Without errors🟩**
```bash
HEAP SUMMARY:
    in use at exit: 0 bytes in 0 blocks
  total heap usage: X allocs, X frees, Y bytes allocated

All heap blocks were freed -- no leaks are possible
```

**🟥With errors🟥**
```bash
LEAK SUMMARY:
   definitely lost: 24 bytes in 1 blocks
```
This indicates that there is memory that was allocated with malloc but never freed with free.

**Using LLDB**

LLDB is the default debugger for macOS and LLVM-based systems. It provides similar functionality to GDB with a modern interface.

```bash
# Start LLDB with the executable and arguments
lldb -- ./push_swap 3 2 1 5 4
```

LLDB commands |Description
|---|---|
| b main|Set a breakpoint at main function|
| r|Execute the program|
| gui|Opens the interface|
| `n`|Execute next line (step over)|
| `s`| Execute next line (step in) |
|`c`|Continue execution|
|`h`|Shows help dialog|
|`esc`|Exit interface|
| exit|Exit LLDB|



**Using AddressSanitizer**

AddressSanitizer detects memory errors at runtime.

```bash
# Add -fsanitize=address -g to your CFLAGS in the Makefile, then:
make re
./push_swap 3 2 1 5 4
```
This will automatically detect:

- Buffer overflows

- Use after free

- Memory leaks

- Double free


## ![Resoures](https://img.shields.io/badge/Resources-B19CD9?style=flat-square)

**References used:**

- [push_swap Subject (v10.0)]() - Official project subject

- [Learn-C.org](https://www.learn-c.org/) - Interactive C tutorial.

- [C Reference Manual](https://en.cppreference.com/w/c) - Complete C reference documentation.

- [Linked List in C](https://www.geeksforgeeks.org/dsa/introduction-to-linked-list-data-structure/) - Introduction to Linked List - Data Structure and Algorithm Tutorials.

- [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/) - C tutorials and examples.

- [Stack Overflow](https://stackoverflow.com/questions) - Community for resolving specific queries.

</sub>

<sub>**Use of AI**</sub>

<sub>During the development of this project artificial intelligence has been used as a **learning support tool**, not as a shortcut. Similar to consulting a book or asking a classmate, AI has been used to:</sub>


<sub>- Understand concepts that were not clear in the documentation.</sub>

<sub>- Obtain guidance on what to study.</sub>

<sub>- Improve the presentation of documentation.</sub>

<sub>- Understand error messages from the terminal.</sub>

<sub>However, **the entire process of reasoning, implementation, and debugging has been manual**, ensuring the development of essential skills for the rest of the 42 curriculum and for taking exams without external dependencies.</sub>

<sub>**Educational Use:**</sub>


<sub>- **README Aesthetics:** Visual design, badges, markdown formatting, and documentation structure.</sub>

<sub>- **Resource Guidance:** Advice on which resources, documentation, and tutorials to look for to learn specific concepts.</sub>

<sub>- **Definitions for notes:** Creation of clear and concise definitions of programming concepts for my personal notes.</sub>

<sub>- **Debugging tips:** Suggestions on debugging tools and methodologies (Valgrind, GDB, etc.)</sub>


<sub>**Not used for:**</sub>


<sub>- **Code generation:** All function code has been written manually without AI assistance.

<sub>- **Exercise solving:** Algorithms and logic have been developed independently.

<sub>- **Direct copying of solutions:** AI-generated answers have not been used to implement functions.