#include <stdio.h>
#include <stdlib.h>
//Ciclo anidado 
//Tabla de multiplicar
int main (){
	int i,j;
	for(i=0;i<=9;i++){
		for(j=0;j<=10;i++){
			printf("%i*%i=%i\n",i,j,i*j );
		}
		printf("\n");
	}
	system("pause");
	return 0;
}