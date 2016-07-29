/*
*tratamiento genérico de errores
*falta definir array de codigos asociados a cada error
*27-jul-2016
*/
#ifndef MIC_H
#define MIC_H
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
//char errores [] ={};
void error(char *nfichero, int nro_linea, char *mensaje){
	fprintf(stderr,"%s (%d). ERROR: , %s. %s\n", nfichero, nro_linea, sys_errlist[errno], mensaje);
}

void error_fatal(char *mensaje, int codigo_salida){
	fprintf(stderr,"ERROR FATAL: ,%s.%s\n", sys_errlist[errno], mensaje);
	exit(codigo_salida);
}
#endif
