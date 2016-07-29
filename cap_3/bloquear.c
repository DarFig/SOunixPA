/*
*v29-07-2016
*-------------------------------------------
*$bloquear <opcion> <[opcion]> <fichero>
*version2 utilizando flock
*Opciones:
*	principales:
*	-c	lock compartido
*	-e	lock exclusivo
*	secundarias:
*	-n	No bloqueante
*	-b 	Bloqueante
* Hay que pasar al menos una opcion primaria; la segundaria se asume bloqueante
*por omisión	
*/
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include "../mic.h"

#define EQUAL(st1, st2) (strcmp((st1),(st2)) == 0)

void bloqueante(char *arg, int fd){
	if(EQUAL(arg,"-c")){
		if((flock(fd,LOCK_SH)) == -1) error_fatal("flock", -1);
	}else if(EQUAL(arg,"-e")){
		if((flock(fd,LOCK_EX)) == -1) error_fatal("flock", -1);	
	}else{	
		fprintf(stderr,"Argumento no valido\n");
		exit(-1);		
		
	}
}
void noBloqueante(char *arg, int fd){
	if(EQUAL(arg,"-c")){
		if((flock(fd,LOCK_SH|LOCK_NB)) == -1) error_fatal("flock", -1);
	}else if(EQUAL(arg,"-e")){
		if((flock(fd,LOCK_EX|LOCK_NB)) == -1) error_fatal("flock", -1);	
	}else{	
		fprintf(stderr,"Argumento no valido\n");
		exit(-1);		
		
	}
}

int main(int argc, char *argv[]){
	int fd;
	
	if(argc==3){//asume  bloqueante
		if((fd = open(argv[2], O_RDWR|O_CREAT, 0744)) == -1) error_fatal("Error en el fichero",-1);
		
		bloqueante(argv[1], fd);
		
	}else if(argc==4){//se especifica modo
		if((fd = open(argv[3], O_RDWR|O_CREAT, 0744)) == -1) error_fatal("Error en el fichero",-1);
		
		if(EQUAL(argv[2],"-n")){
			noBloqueante(argv[1],fd);
		}else if(EQUAL(argv[2],"-b")){
			bloqueante(argv[1],fd);
		}else{	
			fprintf(stderr,"Argumento no valido\n");
			exit(-1);		
		}	
	}else{
		error_fatal("Numero de argumentos incorrecto", -1);
	}
	
	printf("El fichero estará bloqueado 20s\n");
	sleep(20);

	if((flock(fd,LOCK_UN)) == -1) error_fatal("flock", -1);	
	printf("Fichero desbloqueado\n");

	close(fd);
	exit(0);
}
