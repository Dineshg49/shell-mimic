# shell-mimic

## OVERVIEW
The main objective is to mimic the behavior of the shell in the linux terminal.

## Running the shell
Compile the entire program using the make command and run the executable 
- > makefile 
- > ./a.out

To exit the shell use the quit command or press Ctlrl + D .
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
The function helps to support the semi-colon separated list of commands by tokenizing it.

- #### indiv.c
The function  tokenizes the command arguments and ignores unecessary spaces present in the command.

- #### exec.c
This function calls the specific builtin command used else the system commands is invoked.

- #### cd.c
The function cd allows us to navigate through the directories present in our system.

- #### pwd.c
This function prints the present working directory on the shell.

- #### echo.c
The function just prints again all the parameters passed to it in the same sense except it ignores all the uncessary which spaces.

- #### ls.c
This function displays the content of the directory . It supports flags like -a , -l ,-al ,-la and take multiple directories as input.

- #### pinfo.c
The commands prints the information regarding the current shell process or ant pid specified process.

- #### bg.c
This file has two function bgh and bg . The bgh  function runs given process in background while the bg function sets the status of the program running to stopped to runnning in the background.

 - #### delete.c
 This function deletes the process from the jobs list by taking input of the pid of the process.

 - #### fg.c
 The file contains two functions fgh and fg .The fgh function runs the given function in foreground while the  fg function pushes the background process given to foreground.

 - #### gopipe.c
 The gopipe function separates the pipe separated commands .

 - #### handler.c 
 It contains all the handler functions for when the child process stops and exits.

 - #### jobs.c
 It lists out all the background jobs along with their pid and the status.

 - #### kjob.c
 It changes the state of the given process based on the signal provided.

 - #### overkill.c
 It kills all the process in the background.

 - #### pipe.c
 It runs the pipe separated commands in different pipe arrays and is mainly responsible for pipes functionality.

 - #### redirection.c
 This function ensures the redirection between the files mentioned in the command.

 - #### set.c
 This contains functions of setenv and unsetenv.

 - #### signals.c
 This contains the all the signal handlers for keyboard interrupts like (ctrl + z) and (ctrl + c).
  
 