/*
*Utiliza la funcion error contenida en mic.h para mostrar un mensaje asociado a cada tipo de error
*27-jul-2016
*/
#include "mic.h"
#include <stdio.h>
#include <errno.h>
main(){
	extern int sys_nerr;
	int i;
	char mensaje[50];
	
	for(i=1; i<sys_nerr; i++){
		sprintf(mensaje, "Error nro. %d", i);
		errno = i;
		error(__FILE__, __LINE__, mensaje);
	}
}
