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
void createFork(int i) {
	printf("Démarage du process %d \n",i);
	pid_t pid = fork();
	if (pid == -1) {
		// Il y a une erreur
		perror("fork");
	} else if (pid == 0) {
		// On est dans le fils
		printf("Mon PID est %i et celui de mon père est %i\n", getpid(),	getppid());
		sleep(5);
		exit(0);
	} else {
		// On est dans le père
		printf("Mon PID est %i et celui de mon fils est %i\n", getpid(), pid);
	}
}


int main(int argc,char* argv[]) {

  if(argc < 2)
  {
    printf("nbr argument insuffisant");
    exit(0);
  }
  int nbprocess = atoi(argv[1]);
  for(int i = 0; i <nbprocess; i++){
	createFork(i);
  }
  exit(0);
  
}