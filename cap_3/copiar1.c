/*
*Ejercicio copia basica de ficheros mediante llamadas al sistema
*29-jul-2016
*/

#include <stdio.h>
#include <fcntl.h>
#include "../mic.h"

char buff[BUFSIZ];

int main(int argc, char * argv[]){
	int fd_orig, fd_dest, numbytes;
	
	if(argc!=3) error_fatal("Número de argumentos incorrecto: copiar1 <origen> <destino>", -1);
		
	if((fd_orig = open(argv[1], O_RDONLY)) == -1) error_fatal("El fichero origen no existe o no se puede abrir",-1);
	
	if((fd_dest = open(argv[2], O_WRONLY)) == -1) error_fatal("El fichero destino no existe o no se puede abrir",-1);

	while((numbytes = read(fd_orig, buff, sizeof(buff))) > 0)
		write(fd_dest, buff, numbytes);
	close(fd_orig);
	close(fd_dest);

	exit(0);
}
