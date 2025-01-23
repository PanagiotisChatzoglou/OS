#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];
    pipe(fd);
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        close(fd[1]); // Close writing end
        char buffer[50];
        read(fd[0], buffer, sizeof(buffer));
        printf("Child received: %s\n", buffer);
        close(fd[0]);
    } else {
        // Parent process
        close(fd[0]); // Close reading end
        char message[] = "Hello from parent";
        write(fd[1], message, strlen(message) + 1);
        close(fd[1]);
    }
    return 0;
}
