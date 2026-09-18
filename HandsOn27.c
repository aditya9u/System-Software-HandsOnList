#include <stdio.h>
#include <unistd.h>

int main() {
    // Demonstration of execl (uncomment to test individual system call)
    execl("/bin/ls", "ls", "-Rl", NULL);
    
    // execlp("ls", "ls", "-Rl", NULL);
    // char *env[] = { NULL }; execle("/bin/ls", "ls", "-Rl", NULL, env);
    // char *args[] = {"ls", "-Rl", NULL}; execv("/bin/ls", args);
    // char *args[] = {"ls", "-Rl", NULL}; execvp("ls", args);
    return 0;
}