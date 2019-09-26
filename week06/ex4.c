#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void sigkillHandler(int sig_num) {
    signal(SIGKILL, sigkillHandler);
    printf("\nKILL signal has been intercepted.\n");
    fflush(stdout);
}

void sigstopHandler(int sig_num) {
    signal(SIGSTOP, sigstopHandler);
    printf("\nSTOP signal has been intercepted.\n");
    fflush(stdout);
}

void sigusr1Handler(int sig_num) {
    signal(SIGUSR1, sigusr1Handler);
    printf("\nUSR1 signal has been intercepted.\n");
    fflush(stdout);
}

int main() {

    signal(SIGINT, sigkillHandler);
    signal(SIGSTOP, sigstopHandler);
    signal(SIGUSR1, sigusr1Handler);

    while(1) {
        sleep(1);
    }

    return 0;

}