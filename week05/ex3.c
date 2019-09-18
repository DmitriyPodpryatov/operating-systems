#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 8
#define MIN 60

int count;

int producer_sleeps;
int consumer_sleeps;

void* producer() {
    if (count == 8) {
        // Sleep
        producer_sleeps = 1;
        pthread_exit(NULL);
    }
    else {
        count++;
    }
}

void* consumer() {
    if (count == 0) {
        // Sleep
        consumer_sleeps = 1;
        pthread_exit(NULL);
    }
    else {
        count--;
    }
}

int main() {
    pthread_t producer_id, consumer_id;

    count = 0;
    producer_sleeps = 1;
    consumer_sleeps = 1;

    // Time variables to print every minute. t is current time. st is start time
    time_t t, st;
    t = st = time(NULL);

    while(1) {
        if (producer_sleeps) {
            // Create a producer
            pthread_create(&producer_id, NULL, producer, NULL);
            producer_sleeps = 0;
        }
        // Print every minute if wake up
        else if (time(NULL) - t > MIN) {
            printf("PRODUCER  %d\n", count);
            t = time(NULL);
        }
        
        if (consumer_sleeps) {
            // Create a consumer
            consumer_sleeps = 0;
            pthread_create(&consumer_id, NULL, consumer, NULL);
        }
        // Print every minute if wake up
        else if (time(NULL) - t > MIN) {
            printf("CONSUMER  %d\n", count);
            t = time(NULL);
        }

    }

    pthread_exit(NULL); 
}