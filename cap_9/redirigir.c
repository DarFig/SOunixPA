/*
*v2016.08.12
*redirigir <programa1> <programa2> 
*
*redirige la salida estandar de programa1 a la entrada estandar de programa2
*
*/

#include <stdio.h>
#include <unistd.h>
#include "../mic.h"

main(int argc, char *argv[]){
	int pid;
	int fild[2];
	
	if(argc < 3){
		fprintf(stderr,"Número de argumentos incorrecto");
		exit(-1);
	}
	if( pipe(fild) == -1 )
		error_fatal("pipe", -1);
	if( (pid = fork()) == -1 ){

		error_fatal("fork", -1);

	}else if(pid == 0){//hijo

		close(0);
		dup(fild[0]);
		close(fild[0]);
		close(fild[1]);
		
		execlp(argv[2],argv[2], 0);
		
	}else{//padre

		close(1);
		dup(fild[1]);
		close(fild[0]);
		close(fild[1]);
		
		execlp(argv[1], argv[1], 0);

	}
	exit(0);
}		
