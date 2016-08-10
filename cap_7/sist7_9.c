/*
*v2016-8-10
*
*ej7_1 <señal> <pid>
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>



//función tipo system, con limite de espera para impedir bloqueo en llamada al sistema
sistema(const char *orden, int espera){
	int pid, tty, estado, w;
	
	fflush(stdout);
	//Abrir el terminal
	if((tty = open ("/dev/tty", O_RDWR)) == -1){
		perror("sistema");
		return(-1);
	}
	if((pid = fork()) == 0){
	//hijo
		close(0); dup(tty);
		close(1); dup(tty);
		close(2); dup(tty);
		close(tty);
		
		execlp("sh", "sh", "-c", orden, NULL);
		exit(127);
	}
	close(tty);
	sleep(espera);
	estado = kill(pid, SIGTERM);
	return estado;
}

//main

main(){
	sistema("clear", 1);
	sistema("ps -eax | grep agetty", 1);
	sistema("sleep 10", 5);

}

