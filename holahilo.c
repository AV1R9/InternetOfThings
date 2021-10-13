#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 10000

int saldo;

void *printHola(void *arg){
    char *p=(char *)arg;
    printf("Hola desde hilo: %s\n", p);
    pthread_exit(NULL);
}
pthread_mutex_t lockSaldo;


void *suma100(void *arg){
    int lsaldo;
    pthread_mutex_lock(&lockSaldo);
    lsaldo=saldo;
    lsaldo+=100;
    saldo=lsaldo;
    pthread_mutex_unlock(&lockSaldo);
    pthread_exit(NULL);
}

int main(){
    pthread_t threads[NUM_THREADS];
    char *s="Soy un hilo";
    saldo=0;
    // int d=5;
    for(int i=0; i<NUM_THREADS;i++){
        // pthread_create(&threads[i],NULL,printHola,(void *)s);
        pthread_create(&threads[i],NULL,suma100,NULL);

    };


    for(int i=0; i<NUM_THREADS;i++){
        // pthread_create(&threads[i],NULL,printHola,(void *)s);
        pthread_join(threads[i],NULL);

    };


    printf("Saldo final es %d\n", saldo);

    pthread_exit(NULL);
    return 0;
}