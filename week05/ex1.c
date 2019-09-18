#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define N 3

pthread_t thread_id[N];

void* print_hello(int i) {
    printf("Some text from thread %d with index %d\n", (int) pthread_self(), i);
    pthread_exit(NULL);
} 

int main(int argc, char* argv[]) {
    int return_code;

    for(int i = 0; i < N; i++) {
        return_code = pthread_create(&thread_id[i], NULL, print_hello, i);
        if (return_code) {
            printf("\nERROR: return code from pthread_create is %d\n", return_code);
            exit(1);
        }
        printf("\nIt is thread %d. Created new thread %d with index %d\n",
                (int) pthread_self(), (int) thread_id[i], i);
        
        pthread_join(thread_id[i], NULL); // This is fix
    }

    pthread_exit(NULL);
}

/*
    Program outputs messages in random order.

    After fix (pthread_join(thread_id[i], NULL) has been added) the threads run in the order because
    pthread_join forces threads to wait until previous thread has finished.
*/