#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {

    int pid;

    pid = fork();

    // Parent
    if (pid > 0) {
        sleep(10);

        kill(pid, SIGKILL);
    }
    else {
        while(1) {
            printf("I'm alive\n");
            sleep(1);
        }
    }

    return 0;

}