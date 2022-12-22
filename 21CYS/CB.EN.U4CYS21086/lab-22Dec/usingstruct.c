#include <pthread.h>
#include <stdlib.h>
#include <stdio.h> 
#include <unistd.h>

struct number {
    int a;
    int b;
};

void *addition ( void *s){

    struct number *z = (struct number *)s;
    printf("Adding %d and %d gives %d\n",z->a,z->b,z->a + z->b);
    pthread_exit(NULL);
}

int main(){

    int result;
    pthread_t threads[5];
    struct number k[5];
        printf("Enter the first value:\t");
        scanf("%d", &k[1].a);
        printf("Enter the second value:\t");
        scanf("%d", &k[1].b);
        result = pthread_create(&threads[1], NULL, addition,&k[1]);

        if (result) {
      
         printf("Error in creating thread, %d ", result);
         exit(-1);
    }
    pthread_exit(NULL);
}