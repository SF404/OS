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
        int exec (const char *path, const *char argv[]);
        ```
        - __path__ -> The path of executable file. This can be absolute or relative.
        - __argv__ -> Array of argumants to be passed to executable file. The last element must be null.
    - If the return value of exec is __-1__ it means that __exec__ failed and control return to caller.
- ## __Open__
    - ### __Terminology__
        - __File Descriptor__ -> An integer that uniquely identifies an open file.
        - __File Descriptor Table__ -> Collection of indices of file descriptor.
        __Each process has its file descriptor table__.
        - __Standard File Descriptor__ -> By default first three entries of **FDT** are automaticaly filled.

            __Entries (FD)__
            - __0__ -> Read from **stdin**  (Keyboard)
            - __1__ -> Write to **stdout**  (Display)
            - __2__ -> Write to **stderr** (Error)
    - __Input/Output calls__
        - __Create__

            ```c
            int create ("file name", mode);
            ```
        - __Open__

            ```c
            int open ("path", modes);
            ```
        - __Close__

            ```c
            int close (int fd);
            ```
        - __Read__

            ```c
            size_t read (int fd, buff, sizeOfBuff);
            ```
        - __Write__
        
            ```c
            size_t write (int fd, buff, sizeOfBuff);
            ```

