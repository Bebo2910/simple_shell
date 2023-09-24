## Simple Shell Project
interactive simple shell stimulating some functionality of UNIX system.
### Description
As part of my curriculum activities in ALX to practically apply learning outcomes, I undertook a Shell Project to stimulate a basic Unix-like command-line shell. this is including the use of system calls and memory allocation functions to store and process the inputs of the user.
1. **Shell Functionality**
Designed and implemented a user-friendly command-line interface with features including command parsing, and execution. the program starts with showing a prompt `:) ` to the user in case of interactive mode. while it also can excute the command line using redirection process in the non-interactive mode.
2. **Built-in Commands**
in this project we have included some built-in functions such as:
   - `cd`: it is a command that navigates directories that displays the same functionality in linux terminal, it handles arguments of the directories and returning home when their is no arguments. the builtin also updates the path of the working directory and can be tested using `pwd` command
   - `env`: it displays the current environment the user is using and could help excuting some sort of command in a changed environment.
   - `exit`: it is a command used to terminate the shell and exit the program after ensuring that all memory allocated is freed using the `free()` function.
3. **Error Handling** 
Implemented robust error handling mechanisms to gracefully handle various exceptional scenarios and provide informative error messages including:
   - `command is not found`: when the user misspells the command line or writes a command that's not available in the files of the project.
   - `(function): malloc failed`: when the allocation of the memory for a specific purpose is failed during the excution of the command line provided.
   - `No such file or directory`: when the user tries to access a non-existing directory or file

### Usage
By compiling the files using `gcc *.c -o my_program`, an excutable file called `my_program` is produced and become available to use. run the file using the path (if it is out of scope of your current directory) or simply use the name of the program in the format `./my_program` and the prompt will be shown and you could write the commands you desire to execute.

### Contribution
Feel free to modify and extend this project to suit your specific needs. You can enhance it by adding additional built-in functions like seting up environments, handling comments, and storing exit status. Contributions and improvements are welcome!

### License
This project is open-source and available under an open-source license.

### Authors
   - Abanoub Samy Farhan
   - Marian Demins
