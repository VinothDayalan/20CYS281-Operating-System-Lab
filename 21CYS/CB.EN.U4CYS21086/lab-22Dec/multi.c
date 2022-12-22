#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>
void *printWelcomeMessage(void *thread) {
    
   sleep(2);    
   long name = (long ) thread;
   printf("\n[THREAD] Hello, Welcome %ld.", name);
   pthread_exit(NULL);
   
}

int main () {
   pthread_t threads[5];

   char thread[10][15] = {"Amritha","Praveen","Saurabh","Sangeetha","Lakshmy","Srinivasan","Ramaguru"};   
   int result;
   
   for(int i = 0; i < 7; i++ ) {
   
      printf("\n[MAIN] Creating thread, %d", i);
      
      result = pthread_create(&threads[i], NULL, printWelcomeMessage, (void *)thread[i]);
      
      if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
      }
      
   }
   
   pthread_exit(NULL);
}