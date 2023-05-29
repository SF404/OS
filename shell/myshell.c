#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

// function to extracte arguments from input string
void parseInput(char *command, char **parsedInput)
{
    int i;
  
    for (i = 0; i < 100; i++) {
        parsedInput[i] = strsep(&command, " ");
        if (parsedInput[i] == NULL)
            break;
        if (strlen(parsedInput[i]) == 0)
            i--;
    }
}

// function for executing Command
void executeCommand(char **parsedInput)
{
    // creating child process to execute command
    pid_t pid = fork(); 
  
    if (pid == -1) {
        printf("\nFailed forking child..\n");
        return;
    } else if (pid == 0) {
        if (execvp(parsedInput[0], parsedInput) < 0) {
            printf("!Could not execute command..");
        }
        exit(0);
    } else {
        // waiting for child to terminate
        wait(NULL); 
        return;
    }
}

// system command handler
void closeShell(){
    printf("---------------\n");
    printf("|     Bye     |\n");
    printf("---------------\n");
    exit(0);
}
// system command handler
void printShell(){
    printf("\n       + --------------------------- +\n");
    printf("       |                             |\n");
    printf("       |  Welcome To Suhaib's Shell  |\n");
    printf("       |                             |\n");
    printf("       + --------------------------- +\n");
    printf("       |  List of Commands:          |\n");
    printf("       + --------------------------- +\n");
    printf("       |   ls                        |\n");
    printf("       |   cat                       |\n");
    printf("       |   ls                        |\n");
    printf("       |   mkdir                     |\n");
    printf("       |   rm                        |\n");
    printf("       |   exit                      |\n");
    printf("       |   .....                     |\n");
    printf("       |   .....                     |\n");
    printf("       + --------------------------- +\n");
}

// Function to identify system commands
int systemCommands(char **parseInput)
{
    char *systemCommandList[2]={"exit", "help"};
    if(strcmp(parseInput[0],systemCommandList[0])==0) {
        closeShell();
        return 0;
    }
    if(strcmp(parseInput[0],systemCommandList[1])==0) {
        printShell();
        return 0;
    }

    return 1;
}

int main()
{
    // Array to store input
    char command[100];   
    

    while (1)
    {
        // print username for every input line
        printf("\nsuhai> ");

        // taking input
        fgets(command, sizeof(command), stdin);

        // removing null charecter from input 
        command[strcspn(command, "\n")] = '\0';

        // Array to store Arguments
        char *parsedInput[100];

        // function to seperate (extract) arguments from input string 
        parseInput(command, parsedInput);

        // Execute the command only if no system command is detected 
        if(systemCommands(parsedInput))
        executeCommand(parsedInput);
    }
    
    return 0;
}
