/*
* fusionar v0.1 une dos ficheros y crea un tercero como suma de los anteriores
*29-jul-2016
*/
#include <stdio.h>
#include <fcntl.h>
#include "../mic.h"

char buff[BUFSIZ];
int main(int argc, char *argv[]){
	int fd_o1, fd_o2, fd_d, nbytes;	

	if(argc != 4) error_fatal("Argumentos incorrectos: fusion <origen1> <origen2> <destino>", -1);
	
	if((fd_o1 = open(argv[1], O_RDONLY)) == -1) error_fatal("Error en origen1", -1);
	if((fd_o2 = open(argv[2], O_RDONLY)) == -1) error_fatal("Error en origen2", -1);
	if((fd_d = open(argv[3], O_WRONLY | O_CREAT | O_TRUNC, 0666)) == -1) error_fatal("Error en destino", -1);

	while((nbytes = read(fd_o1, buff, sizeof(buff))) > 0){
		write(fd_d, buff, nbytes);
	}
	while((nbytes = read(fd_o2, buff, sizeof(buff))) > 0){
		write(fd_d, buff, nbytes);
	}
	
	close(fd_o1);
	close(fd_o2);
	close(fd_d);
	exit(0);
}
