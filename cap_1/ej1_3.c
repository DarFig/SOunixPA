#include "mic.h"
//Prueba la función error_fatal
int main(){
	errno = 2;
	error_fatal("No se puede abrir el fichero", -1);
	printf("Esta linea no debería ejecutarse");
}
