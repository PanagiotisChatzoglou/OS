#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler(int sig) {
    printf("Child received signal: %d\n", sig);
    exit(0);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // Child process
        signal(SIGUSR1, signal_handler);
        while (1); // Wait for signal
    } else {
        // Parent process
        sleep(1); // Give child time to set up
        kill(pid, SIGUSR1);
    }
    return 0;
}
