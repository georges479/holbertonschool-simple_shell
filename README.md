DESCRIPTION:

This is a simple UNIX command line interpreter (shell) that can handle commands with arguments, execute programs by searching in the PATH, and provide built-in commands. It was created as part of the Holberton School curriculum.

FEATURES:

Display a prompt and wait for user input
Execute commands with arguments
Handle the PATH environment variable
Implement built-in commands:
exit: Exit the shell
env: Print the current environment
Handle errors and "end of file" condition (Ctrl+D)

COMPILATION:

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


USAGE:

Interactive Mode
./hsh
$ ls -l
$ pwd
$ exit


NON-INTERACTIVE MODE:

echo "ls -l" | ./hsh


FILES:

main.c: Main shell loop and core functionality
builtins.c: Implementation of built-in commands
helpers.c: Helper functions for string manipulation and memory management
shell.h: Header file with function prototypes and data structures

FLOWCHART:

![Texte alternatif](Capture_decran_2025-04-24_122540.png)
