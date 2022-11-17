#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Nombre total de thread
#define NB_FORK 2
// Limite de l'incrément
#define INCREMENT_LIMIT 1
// Initialisation de la donnée
int data = 0;

// Fonction exécutée dans le fork
void job() {
	int tid = getpid();
	while (data < INCREMENT_LIMIT) {
		data++;
		printf("fork [ %i ] data [ %i ]\n", tid, data);
		// Pause l'exécution du fork pendant 1 seconde
		sleep(1);
	}
	printf("Fin du fork %i\n", tid);
	exit(EXIT_SUCCESS);
}
// Fonction qui attend chacun des processus fils
void waitForAll() {
	int status;
	pid_t pid;
	int n = 0;
	while (n < NB_FORK) {
		pid = wait(&status);
		printf("Fork [%i] terminé avec le code %i\n", pid, status);
		n++;
	}
}

int main(int argc,char* argv[]) {

  if(argc < 2)
  {
    printf("nbr argument insuffisant");
    exit(0);
  }
  int NB_CPU = atoi(argv[1]);
  printf("test %d \n \n",NB_CPU);
  
	for (int i = 0; i < NB_CPU; i++) {
		pid_t pid = fork();
		if (pid == -1) {
			// Il y a une erreur
			perror("fork");
			return EXIT_FAILURE;
		} else if (pid == 0) {
			// On est dans le fils
			job();
		} else {
			// On est dans le père
		}
	}
	waitForAll();
	return EXIT_SUCCESS;
}