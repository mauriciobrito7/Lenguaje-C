#include <stdio.h>
#include <stdlib.h>

int main (){
	int op;

	printf("Menu\n");
	printf("[1]Opcion 1\n");
	printf("[2]Opcion 2\n");
	printf("[3]Opcion 3\n");
	scanf("%i",&op);

	switch(op){
		case 1: printf("Se ingreso la opcion 1\n"); break;
		case 2: printf("Se ingreso la opcion 2\n"); break;
		case 3: printf("Se ingreso la opcion 3\n"); break;
		default: printf("Opcion incorrecta\n"); break;
	}

	system("pause");
	return 0;
}