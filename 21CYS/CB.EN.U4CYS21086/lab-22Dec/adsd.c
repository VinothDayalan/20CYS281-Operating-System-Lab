#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
void *printWelcomeMessage() {
    int value1;
    int value2;
    printf("Enter the 1st element:");
    scanf("%d",&value1);
    printf("Enter the 2nd element:");
    scanf("%d",&value2);
    int total = value1 + value2;
    printf("%d",total);
   
}

int main () {

   pthread_t threads;
   int result;
   
      
      result = pthread_create(&threads, NULL, printWelcomeMessage, NULL);
      
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
      
   
   // Exit the thread
   pthread_exit(NULL);
}