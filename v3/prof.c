#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/sysinfo.h>
#include <sched.h>
#define NB_CPU 4
void createThread(pthread_t * thread, int *i);
void *thread_1(void *arg) {
        int *i = (int*) arg;
        int previousCpu = sched_getcpu();
        printf("Démarrage du thread %d sur le CPU %d.\n", *i, previousCpu);
        while(1){
                int cpu = sched_getcpu();
                if(cpu != previousCpu){
                        printf("Bascule du thread %d sur le CPU %d\n", *i, cpu);
                        previousCpu = cpu;
                }
        }
        // Arrêt propre du thread
        pthread_exit(EXIT_SUCCESS);
}
int main(int argc, char * argv[]) {
        int nbThread = NB_CPU;
        // Création de la variable qui va contenir le thread
        pthread_t thread[nbThread];
        int positions[nbThread];
        for(int i=0; i < nbThread; i++){
                positions[i] = i;
                createThread(&thread[i], &positions[i]);
        }
        for(int i=0; i < nbThread; i++){
                pthread_join(thread[i], NULL);
        }
        return EXIT_SUCCESS;
}
void createThread(pthread_t * thread, int *i){
        //int cpu = sched_getcpu();
        //printf("Avant la création du thread %d sur le CPU %d.\n", *i, cpu);
        // Création du thread
            pthread_create(thread, NULL, thread_1, i);
        //printf("Après la création du thread %d.\n", *i);
}