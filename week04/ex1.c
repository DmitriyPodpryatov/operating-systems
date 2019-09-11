#include <stdio.h>
#include <stdlib.h>

int main() {

    int n = rand() % 100;
    int pid;

    pid = fork();

    // pif = 0 => child process
    if (pid == 0) {
        printf("Hello from child %d - %d\n", pid, n);
    }
    else {
        printf("Hello from parent %d - %d\n", pid, n);
    }

    return 0;

}

/*
-----------Output----------
Hello from parent 7412 - 83
Hello from child 0 - 83

Hello from parent 7414 - 83
Hello from child 0 - 83

Hello from parent 7416 - 83
Hello from child 0 - 83

Hello from parent 7418 - 83
Hello from child 0 - 83

Hello from parent 7420 - 83
Hello from child 0 - 83

Hello from parent 7422 - 83
Hello from child 0 - 83

Hello from parent 7424 - 83
Hello from child 0 - 83

Hello from parent 7426 - 83
Hello from child 0 - 83

Hello from parent 7428 - 83
Hello from child 0 - 83

Hello from parent 7430 - 83
Hello from child 0 - 83
-----------Output----------

Children's pid are always zero.
Parent's pids are different every time because they are unique
*/