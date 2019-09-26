#include <stdio.h>
#include <signal.h>

void sigintHandler(int sig_num) {
    signal(SIGINT, sigintHandler);
    printf("\nCtrl+C signal has been intercepted. You cannot terminate the program.\n");
    fflush(stdout);
}

int main() {

    signal(SIGINT, sigintHandler);

    while(1) {}

    return 0;

}