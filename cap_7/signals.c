/*8-ago-2016
*Muestra la tabla de Señales UNIX System V
*
*/
#include <stdio.h>
#include <stdlib.h>

main(){
	printf("__________________________________________________________________\n");
	printf("| Nombre | # |    Accion por defecto     |  No se |  Restaura   | \n");
	printf("|        |   |___________________________|  puede |   rutina    | \n");
	printf("|        |   | Genera | Termina | Ignora | ignorar|    por      | \n");
	printf("|        |   |  core  |         |        |        |  defecto    | \n");
	printf("------------------------------------------------------------------\n");
	printf("__________________________________________________________________\n");
	printf("| SIGHUP | 1 |        |    x    |        |        |      x      | \n");
	printf("| SIGINT | 2 |        |    x    |        |        |      x      | \n");
	printf("|SIGQUIT | 3 |   x    |    x    |        |        |      x      | \n");
	printf("| SIGILL | 4 |   x    |    x    |        |        |             | \n");
	printf("|SIGTRAP | 5 |   x    |    x    |        |        |             | \n");
	printf("| SIGIOT | 6 |   x    |    x    |        |        |      x      | \n");
	printf("| SIGEMT | 7 |   x    |    x    |        |        |      x      | \n");
	printf("| SIGFPE | 8 |   x    |    x    |        |        |      x      | \n");
	printf("|SIGKILL | 9 |        |    x    |        |   x    |      x      | \n");
	printf("| SIGBUS |10 |   x    |    x    |        |        |      x      | \n");
	printf("|SIGSEGV |11 |   x    |    x    |        |        |      x      | \n");
	printf("| SIGSYS |12 |   x    |    x    |        |        |      x      | \n");
	printf("|SIGPIPE |13 |        |    x    |        |        |      x      | \n");
	printf("|SIGALRM |14 |        |    x    |        |        |      x      | \n");
	printf("|SIGTERM |15 |        |    x    |        |        |      x      | \n");
	printf("|SIGUSR1 |16 |        |    x    |        |        |      x      | \n");
	printf("|SIGUSR2 |17 |        |    x    |        |        |      x      | \n");
	printf("| SIGCLD |18 |        |         |    x   |        |      x      | \n");
	printf("| SIGPWR |19 |        |         |    x   |        |             | \n");
	printf("------------------------------------------------------------------\n");
	exit(0);
}
