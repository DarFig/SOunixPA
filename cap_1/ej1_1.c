/*
*muestra todos los código de error
*27-jul-2016
*/
#include <stdio.h>
main(){
	int i;
	for(i = 1; i<sys_nerr; i++)
		printf("%d:%s\n",i, sys_errlist[i]);
}
