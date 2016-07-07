//Hacer una funcion recursiva que diga cual el numero mayor dentro de un vector
//Make a recursive function that says that the largest number in a vector
#include <stdio.h>
#include <conio.h>
#define L 10

int mayor(int v[], int maximo, int x){
	if(x==0)
		return maximo;
	if (maximo< v[x])
		maximo=v[x];
	return mayor(v,maximo,--x);
}

int main (){

	int v[L]={2,3,6,8,12,20,50,22,4,5};

	int maximo=v[0];
	printf("El numero maximo es :%i", mayor(v,maximo,L));
	getch();
}
