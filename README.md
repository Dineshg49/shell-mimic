# shell-mimic

## OVERVIEW
The main objective is to mimic the behavior of the shell in the linux terminal.

## Running the shell
- Compile the entire program using the make command and run the executable 
> makefile 
> ./a.out

## IMPLEMENTATION
The code is written in the modular form . Almost each function has its own code file and the header file.

### The different files and their roles :
- #### main.c
This is the first file invoked when executable runs. It runs the infinite loop for the shell so that it takes input from the user after every iteration untill forcefully stopped.

- #### initial.c
This function helps to store the name of the home directory from which the shell invoked .

- #### prompt.c
This function provides us with the prompt after every set of commands user run with the username , hostname and the current working directory with respect to the home directory.

- #### input.c
The function takes the input from the user in the form of a line.

- #### divide_arg.c
The function helps to support the semi-colon separated list of commands.

