#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main() {

    int pid[2];

    int pipedes[2];
    int value;
    int status;

    if (pipe(pipedes)) {
        exit(1);
    }

    printf("Process forks\n");
    pid[0] = fork();

    // Parent
    if (pid[0] > 0) {

        printf("Process forks second time\n");
        pid[1] = fork();

        // Parent
        if (pid[1] > 0) {
            printf("Send pid of second child to first child\n");
            close(pipedes[0]);
            write(pipedes[1], &value, sizeof(value));
            close(pipedes[1]);

            printf("Parent starts waiting\n");
            waitpid(pid[1], &status, 0);
            printf("Parent ends waiting\n");
        }
        // Second child
        else {
            
        }

    }
    // First child
    else {
        close(pipedes[1]);
        read(pipedes[0], &value, sizeof(value));
        close(pipedes[0]);
        printf("First child read pid\n");

        sleep(3);
        printf("First child kills second child\n");
        kill(value, SIGSTOP);
    }

    return 0;

}