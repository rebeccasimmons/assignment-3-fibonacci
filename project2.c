//
//  project2.c
//  A program that a parent thread calculates the Fibonacci sequence and has a child
//  thread prints it out
//  Created by Hope Simmons on 9/25/17.
//

#include <stdio.h>
#include <pthread.h>

#define SIZE 50

int fib[SIZE];
void* parent(void* n);

int main(int argc, char* argv[]) {
    int num; /* the fibonacci numbers */
    int i; /* loop instantiation */

    pthread_attr_t attr;
    
    printf("Please enter how many Fibonacci numbers would you like displayed:");
    scanf("%d",&num);
    printf("First 15 terms \n");
    
    if(num<0) {
        printf("Please enter a positive number\n");
    } else {
        pthread_attr_init(&attr); /* initializes the thread objects */
        pthread_t tid; /* pthread datatype */
        pthread_create(&tid, &attr, parent, (void*)(size_t)num); /* creates the pthread */
        pthread_join(tid, NULL); /* joins the threads and waits for thread termination */
        
        for(i=0; i<num; i++) {
            printf("%d,", fib[i]);
        }
    }
    return 0;
}

void* parent(void* n) {
    int x;
    int y;
    int z;
    int a;
    
    x = 0;
    y = 1;
    z = 0;
    
    int nums = (int)n; /* cast n as an int */
    
    for(a=0; a<=nums; a++) {
        fib[a]=z;
        x = y;
        y = z;
        z = x+y;
    }
    pthread_exit(0); /* exits the thread */
}
