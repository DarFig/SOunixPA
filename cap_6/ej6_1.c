/*8-ago-2016
*ej6_2 <opcion>
*opciones:
*	-l	execl
*	-v	execv
*	-le	execle
*	-ve	execve
*	-lp	execlp
*	-vp	execvp
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define EQ(st1, st2) (strcmp((st1),(st2))== 0)

int main(int argc, char *argv[]){
	if(argc!=2){
		fprintf(stderr, "Numero de argumentos incorrecto\n");
		exit(-1);
	}	
	if(EQ(argv[1],"-l"))
		execl("/bin/ls","-al","/usr/bin");	
	if(EQ(argv[1],"-v")){
		char *const arg[]={"-al","/usr/bin"};
		execv("/bin/ls",arg);
	}
	if(EQ(argv[1],"-le"))
		execle("/bin/ls","-al","/usr/bin", NULL);
	if(EQ(argv[1],"-ve")){
		char *const arg[]={"-al","/usr/bin"};
		execve("/bin/ls", arg, NULL);
	}
	if(EQ(argv[1],"-lp"))
		execlp("ls","-al","/usr/bin");
	if(EQ(argv[1],"-vp")){	
		char *const arg[]={"-al","/usr/bin"};	
		execvp("ls", arg);
	}
	fprintf(stderr, "No se reconoce la orden\n");
	exit(-1);
}
