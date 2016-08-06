#include <stdio.h>
#include <stdlib.h>

main(){
	if(fork () == 0){
		printf("Soy el hijo. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
		printf("*********************************************************************\n");
		sleep(8);
		//Al despertarse, el padre ha terminado
		printf("Soy le hijo. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
		printf("*********************************************************************\n");	
		setpgrp();
		printf("Soy le hijo. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
		printf("*********************************************************************\n");
		exit(0);
	}
	printf("Soy el padre. PID = %d, PPID = %d, Grupo = %d\n", getpid(), getppid(), getpgrp());
	printf("---------------------------------------------------------------------\n");
	sleep(4);
	printf("El padre muere\n");
	printf("---------------------------------------------------------------------\n");
	exit(0);
}
