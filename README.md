# Operating System 
> # Header Files
- ## __unistd.h__ (Unix-Standard)
     This Header file provides access to the __POSIX__ Operating System API.

    ```c
    #include<unistd.h>
    ```
- ## __fcntl.h__ (File-Control)
    This Header file is used to perform various file control operations on a file descriptor, such as changing the file access mode, open, close or setting file status flags.

    ```c
    #include<fcntl.h>
    ```
> # System Calls
- ## __Fork__
    - The fork() system call is used to creates duplicate copy of the parent process (called child process).
    - After the new child Process is created both the process (parent, child) will execute the next instruction.
    - Child process uses same pc(program counter) register, CPU registers, open file descriptors.
    - fork() doesn't take any argument and returns an integer value.

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
    - When program invokes exec system call, the operating system replaces the current process's code and data with the code and data of the new process specified by the user.
    - Exec system call replaces the current process image with a new process image.

        ```c
        int exec(const char *path, const *char argv[]);
        ```
        - __path__ -> The path of executable file. This can be absolute or relative.
        - __argv__ -> Array of argumants to be passed to executable file. The last element must be null.
    - If the return value of exec is __-1__ it means that __exec__ failed and control return to caller.
- ## __Open__
    

