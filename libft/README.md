<div align="center">

*This project has been created as part of the 42 curriculum by thcardos*

# ![Libft](https://img.shields.io/badge/Libft-9932CC?style=for-the-badge&logo=42&logoColor=white)

</div>

## ![Description](https://img.shields.io/badge/Description-B19CD9?style=flat-square)

<sub>**Libft** is a library of functions in C that recreates the standard functions of the C library, as well as including additional functions useful for future 42 projects. This project is the first project in the 42 curriculum and its aim is to familiarise students with programming in C, memory management and basic data structures.
</sub>

<sub>The main objective is to understand how standard C functions work internally and to develop a solid foundation of knowledge about string manipulation, memory, and linked lists.

<sub>**Below is a detailed description of each function and its logic:** 
</sub>

<sub>**Part 1 - Libc Functions**

<sub>These functions recreate standard C library functions with the same behavior.</sub>

<sub>**Character Verification Functions**</sub>

<sub>**`ft_isalpha`** 
</sub>

<sub>- Checks if a character is alphabetic (a-z, A-Z)</sub>

<sub>- Returns 1 if the character is a letter, 0 otherwise
</sub>

<sub>- Logic: Verifies if `c` is between 'a'-'z' or 'A'-'Z'
</sub>

<sub>**`ft_isdigit`**</sub>

<sub>- Checks if a character is a numeric digit (0-9)</sub>

<sub>- Returns 1 if the character is a digit, 0 otherwise</sub>

<sub>- Logic: Verifies if `c` is between '0'-'9'</sub>

<sub>**`ft_isalnum`**</sub>

<sub>- Checks if a character is alphanumeric</sub>

<sub>- Returns 1 if the character is a letter or digit, 0 otherwise</sub>

<sub>- Logic: Combines `ft_isalpha` and `ft_isdigit`</sub>

<sub>**`ft_isascii`**</sub>

<sub>- Checks if a character is in the ASCII table (0-127)</sub>

<sub>- Returns 1 if the character is ASCII, 0 otherwise</sub>

<sub>- Logic: Verifies if `c` is between 0 and 127</sub>

<sub>**`ft_isprint`**</sub>

<sub>- Checks if a character is printable (32-126)</sub>

<sub>- Returns 1 if the character is printable, 0 otherwise</sub>

<sub>- Logic: Verifies if `c` is between 32 and 126 (space to tilde)</sub>

<sub>**`ft_toupper`**</sub>

<sub>- Converts a lowercase letter to uppercase</sub>

<sub>- Returns the uppercase equivalent if `c` is lowercase, otherwise returns `c`</sub>

<sub>- Logic: If `c` is between 'a'-'z', subtracts 32 to convert to uppercase</sub>

<sub>**`ft_tolower`**</sub>

<sub>- Converts an uppercase letter to lowercase</sub>

<sub>- Returns the lowercase equivalent if `c` is uppercase, otherwise returns `c`</sub>

<sub>- Logic: If `c` is between 'A'-'Z', adds 32 to convert to lowercase</sub>

<sub>**String Functions**</sub>

<sub>**`ft_strlen`**</sub>

<sub>- Calculates the length of a string</sub>

<sub>- Returns the number of characters before the null terminator</sub>

<sub>- Logic: Iterates through the string until '\0' is found, counting characters</sub>

<sub>**`ft_strchr`**</sub>

<sub>- Locates the first occurrence of a character in a string</sub>

<sub>- Returns a pointer to the first occurrence of `c` in `s`, or NULL if not found</sub>

<sub>- Logic: Iterates through the string comparing each character with `c`</sub>

<sub>**`ft_strrchr`**</sub>

<sub>- Locates the last occurrence of a character in a string</sub>

<sub>- Returns a pointer to the last occurrence of `c` in `s`, or NULL if not found</sub>

<sub>- Logic: Iterates through the entire string and saves the position of the last match</sub>

<sub>**`ft_strncmp`**</sub>

<sub>- Compares two strings up to n characters</sub>

<sub>- Returns 0 if equal, negative if `s1 < s2`, positive if `s1 > s2`</sub>

<sub>- Logic: Compares characters one by one until finding a difference, reaching `n`, or finding '\0'</sub>

<sub>**`ft_strlcpy`**</sub>

<sub>- Copies a string to a destination buffer with size limit</sub>

<sub>- Returns the total length of the string it tried to create</sub>

<sub>- Logic: Copies up to `size - 1` characters and always null-terminates the destination</sub>

<sub>**`ft_strlcat`**</sub>

<sub>- Concatenates strings with size limit</sub>

<sub>- Returns the total length of the string it tried to create</sub>

<sub>- Logic: Appends `src` to the end of `dst`, ensuring null-termination and size limit</sub>

<sub>**`ft_strnstr`**</sub>

<sub>- Locates a substring in a string (limited to len bytes)</sub>

<sub>- Returns a pointer to the beginning of the located substring, or NULL if not found</sub>

<sub>- Logic: Searches for the first occurrence of `little` in `big` within `len` bytes</sub>

<sub>**`ft_strdup`**</sub>

<sub>- Duplicates a string in dynamically allocated memory</sub>

<sub>- Returns a pointer to the new string, or NULL if allocation fails</sub>

<sub>- Logic: Allocates memory with `malloc`, copies the string, and returns the pointer</sub>

<sub>**Memory Functions**</sub>

<sub>**`ft_memset`**</sub>

<sub>- Fills a block of memory with a specific byte</sub>

<sub>- Returns a pointer to the memory area `s`</sub>

<sub>- Logic: Sets the first `n` bytes of `s` to the value `c`</sub>

<sub>**`ft_bzero`**</sub>

<sub>- Sets a block of memory to zero</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Calls `ft_memset` with value 0</sub>

<sub>**`ft_memcpy`**</sub>

<sub>- Copies n bytes from src to dest (no overlap handling)</sub>

<sub>- Returns a pointer to `dest`</sub>

<sub>- Logic: Copies `n` bytes from `src` to `dest` byte by byte</sub>

<sub>**`ft_memmove`**</sub>

<sub>- Copies n bytes from src to dest (handles overlapping)</sub>

<sub>- Returns a pointer to `dest`</sub>

<sub>- Logic: Checks if regions overlap and copies forward or backward accordingly to avoid data corruption</sub>

<sub>**`ft_memchr`**</sub>

<sub>- Locates a byte in a block of memory</sub>

<sub>- Returns a pointer to the matching byte, or NULL if not found</sub>

<sub>- Logic: Searches for the first occurrence of `c` in the first `n` bytes of `s`</sub>

<sub>**`ft_memcmp`**</sub>

<sub>- Compares two blocks of memory</sub>

<sub>- Returns 0 if equal, negative if `s1 < s2`, positive if `s1 > s2`</sub>

<sub>- Logic: Compares the first `n` bytes of `s1` and `s2` byte by byte</sub>

<sub>**Conversion Functions**</sub>

<sub>**`ft_atoi`**</sub>

<sub>- Converts a string to an integer</sub>

<sub>- Returns the converted integer value</sub>

<sub>- Logic: Skips whitespace, handles sign (+/-), converts digits to integer until a non-digit is found</sub>

<sub>**`ft_calloc`**</sub>

<sub>- Allocates memory and initializes it to zero</sub>

<sub>- Returns a pointer to the allocated memory, or NULL if allocation fails</sub>

<sub>- Logic: Allocates `nmemb * size` bytes with `malloc` and initializes to zero with `ft_bzero`</sub>

<sub>**Part 2 - Additional Functions**</sub>

<sub>These functions provide additional string manipulation capabilities not in the standard library.</sub>

<sub>**`ft_substr`**</sub>

<sub>- Extracts a substring from a string</sub>

<sub>- Returns a new string (substring), or NULL if allocation fails</sub>

<sub>- Logic: Allocates memory for `len` characters, copies characters starting from index `start`</sub>

<sub>**`ft_strjoin`**</sub>

<sub>- Concatenates two strings into a new string</sub>

<sub>- Returns a new string containing `s1` followed by `s2`, or NULL if allocation fails</sub>

<sub>- Logic: Allocates memory for both strings, copies `s1`, then appends `s2`</sub>

<sub>**`ft_strtrim`**</sub>

<sub>- Removes characters from the beginning and end of a string</sub>

<sub>- Returns a trimmed copy of the string, or NULL if allocation fails</sub>

<sub>- Logic: Finds the start and end positions by skipping characters in `set`, then extracts the substring</sub>

<sub>**`ft_split`**</sub>

<sub>- Splits a string into an array of strings using a delimiter</sub>

<sub>- Returns an array of strings, or NULL if allocation fails</sub>

<sub>- Logic: Counts words separated by `c`, allocates array, extracts each word into a new string</sub>

<sub>**`ft_itoa`**</sub>

<sub>- Converts an integer to a string</sub>

<sub>- Returns a string representing the integer, or NULL if allocation fails</sub>

<sub>- Logic: Calculates number of digits, handles negative numbers, converts each digit to character</sub>

<sub>**`ft_strmapi`**</sub>

<sub>- Applies a function to each character of a string</sub>

<sub>- Returns a new string with the function applied, or NULL if allocation fails</sub>

<sub>- Logic: Creates a new string, applies function `f` to each character with its index</sub>

<sub>**`ft_striteri`**</sub>

<sub>- Applies a function to each character of a string (modifies in place)</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Iterates through the string applying function `f` to each character with its index</sub>

<sub>**`ft_putchar_fd`**</sub>

<sub>- Writes a character to a file descriptor</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Uses `write` system call to output character `c` to file descriptor `fd`</sub>

<sub>**`ft_putstr_fd`**</sub>

<sub>- Writes a string to a file descriptor</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Uses `write` to output the entire string `s` to file descriptor `fd`</sub>

<sub>**`ft_putendl_fd`**</sub>

<sub>- Writes a string followed by a newline to a file descriptor</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Calls `ft_putstr_fd` followed by `write` to output a newline character</sub>

<sub>**`ft_putnbr_fd`**</sub>

<sub>- Writes an integer to a file descriptor</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Handles negative numbers and edge cases, converts digits to characters recursively and writes them</sub>

<sub>**Part 3 - Linked Lists**</sub>

<sub>These functions provide a complete set of operations for managing singly linked lists.</sub>

<sub>**Structure:**</sub>

```c
typedef struct s_list
{
    void            *content;  // Pointer to the data
    struct s_list   *next;     // Pointer to the next node
}   t_list;
```
<sub>**`ft_lstnew`**</sub>

<sub>- Creates a new list node</sub>

<sub>- Returns a pointer to the new node, or NULL if allocation fails</sub>

<sub>- Logic: Allocates memory for a new node, initializes `content` with the parameter, sets `next` to NULL</sub>

<sub>**`ft_lstadd_front`**</sub>

<sub>- Adds a node at the beginning of the list</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Sets `new->next` to the current first node, updates the list head to point to `new`</sub>

<sub>**`ft_lstadd_back`**</sub>

<sub>- Adds a node at the end of the list</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: If list is empty, sets head to `new`; otherwise traverses to the last node and sets its `next` to `new`</sub>

<sub>**`ft_lstsize`**</sub>

<sub>- Counts the number of nodes in a list</sub>

<sub>- Returns the number of nodes</sub>

<sub>- Logic: Traverses the list from head to tail, counting each node</sub>

<sub>**`ft_lstlast`**</sub>

<sub>- Returns the last node of the list</sub>
<sub>- Returns a pointer to the last node, or NULL if list is empty</sub>
<sub>- Logic: Traverses the list until finding a node whose `next` is NULL</sub>

<sub>**`ft_lstdelone`**</sub>

<sub>- Deletes a single node</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Calls the `del` function on the node's content, then frees the node itself</sub>

<sub>**`ft_lstclear`**</sub>

<sub>- Deletes all nodes in the list</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Iterates through the list, deleting each node with `ft_lstdelone` and sets the head to NULL</sub>

<sub>**`ft_lstiter`**</sub>

<sub>- Applies a function to each node's content</sub>

<sub>- No return value (void)</sub>

<sub>- Logic: Traverses the list and applies function `f` to each node's content</sub>

<sub>**`ft_lstmap`**</sub>

<sub>- Creates a new list by applying a function to each node</sub>

<sub>- Returns a pointer to the new list, or NULL if allocation fails</sub>

<sub>- Logic: Iterates through the original list, applies `f` to each content, creates new nodes, and builds a new list. If any allocation fails, clears the new list using `del`</sub>

## ![Instructions](https://img.shields.io/badge/Instructions-B19CD9?style=flat-square)

<sub>

**Compilation with the library**
```bash
gcc -Wall -Wextra -Werror your_program.c -L. -lft -o program
```

**Available commands**

| Comand | Description |
|---------|-------------|
| `make` | Compiles the library |
| `make clean` | Deletes all the object files (.o) |
| `make fclean` | Deletes the object files and the library |
| `make re` | Compiles everything again |

</sub>

<sub>**Testing the functions:**</sub>

<sub>Here you have the [Main File](https://github.com/thcardos/Libft/blob/main/README.md) I have created to test my functions.
</sub>


<sub>

**Memory verification with Valgrind:**
```bash
# Compile your program with the library
gcc -g -Wall -Wextra -Werror your_program.c -L. -lft -o program

# Run with Valgrind
valgrind --leak-check=full ./program

# Show all possible Leaks
valgrind --leak-check=full --show-leak-kinds=all ./test_libft

# Display detailed information about the errors
valgrind --leak-check=full --track-origins=yes ./test_libft

# Save the report to a file
valgrind --leak-check=full --log-file=valgrind_report.txt ./test_libft
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


**Using GDB (GNU Debugger)**

GDB is an interactive debugger that allows you to inspect your program while it runs.

**Basic usage:**
```bash
# Compile with debugging symbols
gcc -g -Wall -Wextra -Werror main.c -L. -lft -o test

# Start GDB
gdb ./test
```

**GDB commands**

| Comand | Description |
|---------|-------------|
| `run` | Execute the program |
| `break main` | Set a breakpoint at main function |
| `break your_program` | Set a breakpoint at your_program |
| `next` | Execute next line (step over) |
| `step` | Execute next line (step into) |
| `print variable` | Print variable value |
| `continue` | Continue execution |
| `quit` | Exit GDB |

**Using AddressSanitizer**

AddressSanitizer detects memory errors at runtime.

```bash
gcc -g -fsanitize=address -Wall -Wextra -Werror main.c -L. -lft -o test
./test
```
This will automatically detect:

- Buffer overflows

- Use after free

- Memory leaks

- Double free


## ![Resoures](https://img.shields.io/badge/Resources-B19CD9?style=flat-square)

**References used:**

- [Libft Subject (v19.0)](Libft%20es.subject.pdf) - Official project subject

- [Learn-C.org](https://www.learn-c.org/) - Interactive C tutorial.

- [Make Tutorial](https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/) - Makefiles tutorial.

- [C Reference Manual](https://en.cppreference.com/w/c) - Complete C reference documentation.

- [GeeksforGeeks - C Programming](https://www.geeksforgeeks.org/c-programming-language/) - C tutorials and examples.

- [Stack Overflow](https://stackoverflow.com/questions) - Community for resolving specific queries.

</sub>

<sub>**Use of AI**</sub>

<sub>During the development of this project artificial intelligence has been used as a **learning support tool**, not as a shortcut. Similar to consulting a book or asking a classmate, AI has been used to:</sub>


<sub>- Understand concepts that were not clear in the documentation.</sub>

<sub>- Obtain guidance on what to study.</sub>

<sub>- Improve the presentation of documentation.</sub>

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