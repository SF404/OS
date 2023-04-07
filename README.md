# Operating System 
## Important Terms
1. __Process ->__ Program under execution is called "process".
Only single process can run at a time in one CPU (core).  

2. __Threads ->__ Lightweight process which runs within a programs's process and shares the same memory space.

3. __Registers ->__ Very small amount of storage located within the CPU. <br/>
Used to store data that is frequently accessed or manipulated by the CPU. <br/>
Registers are faster to access memory. <br/>

    Some important registers are: 
    - __Program Counter (PC)__: Keep track of the next instruction to be executed.
    - __Stack pointer (SP)__: Holds memory address of the top of the stack.
    - __Base Pointer (BP)__: 
    - __Status Register (FLAGS)__: Store the outcome of the most recent arthematic or logical operation. e.g carry, zero, overflow flags(Allocated memory overflow if value is **1**) . 
    
<br/>



4. __PC Architecture ->__ 

    <p align="center">
    <img src="https://user-images.githubusercontent.com/109202383/230194449-9d1b108b-b2da-4c16-b5a1-3cc76618f0a9.png" width="200"/>
    </p>

    - __Registers:__ High speed memory storing unit.

    - __ALU:__ (Arthematic Logic Unit) Performs all arthematic and logic operations.

    - __MMU:__ (Memory Management Unit) Converts virtual addresses into physical addresses.

    - __Cache:__ Smaller, faster memory. It stores copies of data from frequently used memory locations.

5. __Physical Address Space__ (Actual memory locations available in computer's **RAM**)

    <p>
    <img width="300" src="https://user-images.githubusercontent.com/109202383/230199389-e5efaff9-1cab-46ee-9721-856bbe6bd0de.png"/>
    </p>

    - **Max Size of RAM** depends on architecture of the **CPU**.

        **32-bit** Architecture => 2<sup>32</sup> => **4GB RAM**

        **64-bit** Architecture => 2<sup>64</sup> => **16EB RAM**

    - **Memory Units**

        ||||
        |-|-|-|
        |1 Bit      |0, 1| |
        |8 Bits     | 1 Byte||
        |1024 Bytes | 1 KB |2<sup>10</sup> Bytes|
        |1024 KB    | 1 MB |2<sup>20</sup> Bytes|
        |1024 MB    | 1 GB |2<sup>30</sup> Bytes|
        |1024 GB    | 1 TB |2<sup>40</sup> Bytes|
        |1024 TB    | 1 PB |2<sup>50</sup> Bytes|
        |1024 PB    | 1 EB |2<sup>60</sup> Bytes|
        |1024 EB    | 1 ZB |2<sup>70</sup> Bytes|
        
    - **Memory Maped I/O :** 
        - Peripheral devices are assigned a range memory addresses, that corrosponds to the device register's and control structure. 
        - The CPU can read and write to the device's register by reading and writing to a corrosponding register.

    - **VGA Memory**
        - Memory used by **GPU** to store images and data for display on monitor.

    - **Low Addresses** 
        - Memory reserved for **OS, BIOS, low-level components**.

<hr/>
<br/>

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

<hr/>
<br/>

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
- ## __Input Output System Calls__
    - ### __Terminology__
        - __File Descriptor__ -> An integer that uniquely identifies an open file.
        - __File Descriptor Table__ -> Collection of indices of file descriptor.
        __Each process has its file descriptor table__.
        - __Standard File Descriptor__ -> By default first three entries of **FDT** are automaticaly filled.

            __Entries (FD)__
            - __0__ -> Read from **stdin**  (Keyboard)
            - __1__ -> Write to **stdout**  (Display)
            - __2__ -> Write to **stderr** (Error)
    - ### __Input/Output calls__
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
- ## __Wait__
    When a process calls the "wait" system call, the operating system blocks the parent process until one of the child process terminates, and then returns information about the child process.

    ```c
    int wait(int *status);
    int wait(NULL);
    ```

    - The "status" variable will be used to store the exit status of the child process that has terminated.
    - The exit status is stored in the "status" variable using a bit field structure. The lower 8 bits of the "status" variable store the exit code of the child process, while the upper 8 bits store additional information such as whether the child process terminated due to a signal, and if so, which signal it was.
    - The "wait" system call returns the process ID of the terminated child process to the parent process.

- ## __Waitpid__
    Similar to "wait", the only difference is that "wait" waits for any child process to terminate and collect its exit status, while "waitpid" waits for a specific child process to terminate and collect its exit status. The specific child's pid is passed to the "waitpid" as argument.

    ```c
    pid_t waitpid (pid_t pid, int *status, int options);
    ```

    __Options__ to specify additional behaviour.


- ## __Pipe__ (Inter-Process Communication)
    - used to move data between the two processes.

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
    - pipe return -1 when fails. 
- ## __Inter-Process Communication using Shared Memory__
    - System calls used:

        ```c
        int shmget(key_t key, size_t size, int shmflg); // It is used to create the shared memory senment
        void *shmat(int shmid, void *shmaddr, int shmflag); // It is used to attach the shared segment to with the process
        ```
    - In this method of communication we write two programs:
    
      - program 1: __Sender__
        
        - Create the shared segment
        - Attach to it
        - Write some content into it.

      - Program 2: __Receiver__

        - Attach itself to the shared segment
        - Read the data written by Program 1.

- ## __Signal__
    - Signal is software intrupt delivered to process or thread by the Operating System.
    - It intrupts the normal flow of execution and transfers control to a signal handler. 

        ```c
        signal(int sigNum, void handler);
        // e.g
        signal(SIGINT, handler);

        ```
        Here are some commonly used signal numbers

        __SIGINT__ (2) -> Ctrl+C
        
        __SIGTSTP__ (20) -> Ctrl+Z

        __SIGTERM__ (15) -> Termination signal

        __SIGKILL__ (9) -> Forced termination signal

        __SIGSEGV__ (11) -> Segmentation fault signal 

<hr/>

# __Installing XV6 Operating System using QEMU(Emulator) On Ubuntu__

XV6 is Operating System developed by MIT. Used as a teaching tool to learn about Operating System.
## __Steps involved in Installation:__
- ### __Update Ubuntu Operating System__
    
    ```properties
    sudo apt-get update
    ```

    ![1](https://user-images.githubusercontent.com/109202383/230532369-e9808233-87db-4fc0-b092-fecab9814506.png)
- ### __Install QEMU__ (Virtualization tool which allows to run one or more virtual machines)

    ```properties
    sudo apt-get install qemu
    ```
    
    ![2](https://user-images.githubusercontent.com/109202383/230532366-f70dac83-ed83-4c2d-9bef-965e77333101.png)
    ```properties
    sudo apt-get install qemu-kvm 
    # QEMU KVM allows to access physical resources on Virtual Machine.
    ```

    ![4](https://user-images.githubusercontent.com/109202383/230532360-97382282-a3cf-44ba-89a0-f1ad79b873a6.png)

- ### __Clone XV6 from Github__

    ![3](https://user-images.githubusercontent.com/109202383/230532362-a5352b71-b44d-4330-9720-06a5322fc139.png)

    ```properties
    git clone https://github.com/mit-pdos/xv6-public.git
    ```

    ![5](https://user-images.githubusercontent.com/109202383/230532356-ef8e8c6f-9796-4966-b469-021d369a5b24.png)
    
- ### __Run XV6__
  
    ```properties
    cd xv6-public
    ```
    
    ```properties
    make qemu
    # or you can run qemu in same window(terminal) as
    make qemu-nox
    ```
    ![6](https://user-images.githubusercontent.com/109202383/230532345-6828124f-b212-4f89-9979-8b823d760c3f.png)

<hr/>