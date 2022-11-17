#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_1(void *arg) {
	int * i = (int*) arg;
	printf("Nous sommes dans le thread %d.\n",*i);
	// Arrêt propre du thread
	pthread_exit(EXIT_SUCCESS);
}
void createThread( pthread_t * thread,int number)
{
		printf("Avant la création du thread.\n");
		// Création du thread
		pthread_create(thread1, NULL, thread_1, NULL);
}

int main(int argc,char * argv[]) {
	if(argc < 2)
	{
		printf("specify a number of cpu\n");
		return EXIT_FAILURE;
	}
	int nbThread = atoi(argv[1]);

	// Création de la variable qui va contenir le thread
	pthread_t thread1[nbThread];
	for(int i=0; i < nbThread;i++)
	{
		createThread(&thread1[i], i);
	}
	/*printf("Avant la création du thread.\n");
	// Création du thread
	pthread_create(&thread1, NULL, thread_1, NULL);*/
	pthread_join(thread1, NULL);
	//https://fr.manpages.org/pthread_getaffinity_np/3
	printf("%d \n",pthread_getaffinity_np(thread1));
	printf("Après la création du thread.\n");
	printf("%d \n",pthread_getaffinity_np(thread1));
	return EXIT_SUCCESS;
}