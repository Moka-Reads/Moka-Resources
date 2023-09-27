#include <stdio.h>
#include <pthread.h>

// Function executed by the first thread
void *thread_function1(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Thread 1: Hello, World! %d\n", i);
    }
    return NULL;
}

// Function executed by the second thread
void *thread_function2(void *arg)
{
    for (int i = 0; i < 5; i++)
    {
        printf("Thread 2: Goodbye, World! %d\n", i);
    }
    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    // Create the first thread
    if (pthread_create(&thread1, NULL, thread_function1, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Create the second thread
    if (pthread_create(&thread2, NULL, thread_function2, NULL) != 0)
    {
        perror("pthread_create");
        return 1;
    }

    // Wait for both threads to finish
    if (pthread_join(thread1, NULL) != 0)
    {
        perror("pthread_join");
        return 1;
    }
    if (pthread_join(thread2, NULL) != 0)
    {
        perror("pthread_join");
        return 1;
    }

    return 0;
}
