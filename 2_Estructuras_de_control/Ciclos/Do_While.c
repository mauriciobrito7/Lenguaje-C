#include <stdio.h>
#include <stdlib.h>
//Igual que el while pero el bloque se ejecuta al menos una vez

int main (){
	char c;
	do{
		printf("Introduce una letra :\n");
		fflush(stdin); // Limpiar el buffer
		scanf("%c",&c);
	}while(c!='s' || c!='S');
	system("pause");
	return 0;
}