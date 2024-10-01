#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int thread_alive = 1;

void cancellation_handler(void *arg){
    printf("I wasn't done!\n");
}

void* message_loop(void *arg){
    const char* importantInfo[] = {
        "Mares eat oats",
        "Does eat oats",
        "Little lambs eat ivy",
        "A kid will eat ivy too"
    };
    pthread_cleanup_push(cancellation_handler, arg);
    for (int i = 0; i < 4; i++) {
        sleep(4);
        pthread_testcancel();
        printf("Thread: %s\n", importantInfo[i]);
    }
    pthread_cleanup_pop(0);
    thread_alive = 0;
    return (void*) 42;
}

int main() {
    pthread_t t;
    void *result;
    pthread_create(&t, NULL, message_loop, NULL);
    sleep(5);
    if (thread_alive)
    {
        pthread_cancel(t);
    }
    pthread_join(t, &result);
    //if(result == PTHREAD_CANCELED){
    //    printf("I wasn't done!\n");
    //}
}