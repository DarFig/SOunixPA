/*
*v2016.08.12
*
*ejemplo comunicación mediante tuberías sin nombre
*/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "../mic.h"

#define BUF 512

main(){
	int pid;
	char cadena[BUF];
	int fild[2];

	if(pipe(fild)== -1)
		error_fatal("pipe",-1);

	printf("-----Escribir END para terminar-----\n");

	if( (pid = fork() ) == -1){
		error_fatal("fork",-1);
	}else if(pid == 0 ){
		while( read(fild[0], cadena, BUF) > 0 && strcmp(cadena, "END\n" )!= 0)
			printf("Receptor: mensaje recibido: %s\n", cadena);
	}else{	
		while(fgets(cadena, sizeof(cadena), stdin )!= NULL && write(fild[1], cadena, strlen(cadena)+1)>0 && strcmp(cadena, "END\n")!= 0);
				
	}
	close(fild[0]);
	close(fild[1]);
	exit(0);
}
