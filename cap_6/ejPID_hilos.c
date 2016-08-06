#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
/*
*compilacion cc -o ejPID_hilos ejPID_hilos.c -lpthread
*/

void *hijo(void *id){
	printf("Soy el hijo. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
	printf("*********************************************************************\n");
	sleep(6);
	printf("Soy le hijo. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
	printf("*********************************************************************\n");	
	setpgrp();
	printf("Soy le hijo. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
	printf("*********************************************************************\n");

	pthread_exit(id);
}
void *padre(void *id){
	printf("Soy el padre. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
	printf("---------------------------------------------------------------------\n");

	pthread_exit(id);
}

main(){
	pthread_t hilos[2];
	int id[2] = {1,2};
	int *salida;

	if(fork () == 0){
		if(pthread_create(&hilos[0], NULL, hijo, &id[0]))
			perror("pthread_create");
		
		if(pthread_join(hilos[0],(void**)&salida))
			perror("pthread_join");
		
	}else{
		if(pthread_create(&hilos[1], NULL, padre, &id[1]))
			perror("pthread_create");
		
		if(pthread_join(hilos[1],(void**)&salida))
			perror("pthread_join");
		
	}
	sleep(10);
	exit(0);
}
