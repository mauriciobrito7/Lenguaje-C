//Una función en C es un subprograma que devuelve un unico valor, un conjunto de valores
//o realiza alguna tarea especifica.

#include <stdio.h>
#include <stdlib.h>

int maximo(int x, int y);

int main(){
	int x=5,y=6,max;
	max=maximo(x,y); //Se pasa una copia de x & y, se guarda el retorno

	printf("El valor maximo es %i\n",max );

	system("pause");
	return 0;
}

int maximo(int a, int b){
	if(a>b)
		return a;
	else
		return b;
}