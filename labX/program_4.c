#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd = open("pids.txt", O_CREAT | O_WRONLY | O_APPEND, 0644);
    if (fd == -1) {
        perror("Error opening file");
        return 1;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        dprintf(fd, "Child PID: %d\n", getpid());
    } else {
        // Parent process
        dprintf(fd, "Parent PID: %d\n", getpid());
    }

    close(fd);
    return 0;
}
