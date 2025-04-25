Simple Shell
Description
This is a simple UNIX command line interpreter (shell) that can handle commands with arguments, execute programs by searching in the PATH, and provide built-in commands. It was created as part of the Holberton School curriculum.

Features
Display a prompt and wait for user input
Execute commands with arguments
Handle the PATH environment variable
Implement built-in commands:
exit: Exit the shell
env: Print the current environment
Handle errors and "end of file" condition (Ctrl+D)

Compilation
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh


Usage
Interactive Mode
./hsh
$ ls -l
$ pwd
$ exit


Non-Interactive Mode
echo "ls -l" | ./hsh


Files
main.c: Main shell loop and core functionality
builtins.c: Implementation of built-in commands
helpers.c: Helper functions for string manipulation and memory management
shell.h: Header file with function prototypes and data structures

FLOWCHART:

https://media.discordapp.net/attachments/1359096991908495432/1364910426491715624/Capture_decran_2025-04-24_122540.png?ex=680c0c24&is=680abaa4&hm=4d87c4cbc81f29bd391203c64e89e38f892935fefbacb6e90d16e7e1701c4b60&=&format=webp&quality=lossless&width=1082&height=969
