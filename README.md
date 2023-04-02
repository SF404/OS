# Operating System 
## Important Terms
1. __Process ->__ Program under execution is called "process".
Only single process can run at a time in one CPU (core)
2. __Process State ->__ 
    1.  
  


> # Header Files
- ## __unistd.h__ (Unix-Standard)
     This Header file provides access to the __POSIX__ Operating System API.

    ```c
    #include<unistd.h>
    ```
- ## __fcntl.h__ (File-Control)
    This Header file is used to perform various file control operations on a file descriptor, such as changing the file access mode, open, close or setting file ststus flags.

    ```c
    #include<fcntl.h>
    ```
> # System Calls
- ## __Fork__
    - The fork() system call is used to creates duplicate copy of the parent process (called child process).
    - After the new child Process is created both the process (parent, child) will execute the next instruction.
    - Child process uses same pc(program counter) register, CPU registers, open file descriptors.
    - fork() dosent take any argument and returns an integer value.

         ```c
        int p = fork(); 
        ```
        - __p<0__ 

            Failed to create new child processs.

        - __p=0__

            Child process is created successfully.
            In child process value of p is 0.

        - __p>0__

             In parent process value of p is the PID(process ID) of the child process.
- ## __Exec__


- ## __Pipe__
    - used to move data between the commands.

        ```
        Command1 --> Command2
        ```
    - used for inter-process communication
        ```c
        int pipe (int pipefd[2]);
        ```
        pipe store two file descriptors in the array passed to the pipe.
        ```c
        int fd[2];
        pipe(fd);
        fd[0]; // file descriptor for using read end (recieve data)
        fd[1]; // file descriptor for using write end (send data)
        ````
    - if pipe return -1 when fails.
    



