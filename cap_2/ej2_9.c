/*
*
*28-jul-2016
*/

#include <stdio.h>

main(){
	FILE *fd[6];
	int i;
	for(i=0;i<3;i++){
		fd[i]=fopen("/dev/tty", "r");
		printf("Apertura %d, corresponde con descriptor %d\n", i, fd[i]);
	}
	for(i=3;i<6;i++){
		fd[i]=fopen("/dev/tty", "w");
		printf("Apertura %d, corresponde con descriptor %d\n", i, fd[i]);
	}
	
	for(i=0;i<6;i++){
		fprintf(fd[i], "Mensaje dirigido al flujo nro. %d\n", i);
	}
	for(i=0;i<6;i++){
		fclose(fd[i]);
	}
}
