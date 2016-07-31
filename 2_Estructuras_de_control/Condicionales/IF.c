//Realiza un programa en C que lea tres números enteros positivos distintos e imprima el mayor 
//y el menor valor de los tres. Intente que el programa realice el menor número de comparaciones
//posibles entre los números.
#include <stdio.h>
#include <stdlib.h>

int main (){
	int x,y,z,max,min;

	printf("Ingrese el primer numero");
	scanf("%i",&x);
	printf("Ingrese el segundo numero");
	scanf("%i",&y);
	printf("Ingrese el tercer numero");
	scanf("%i",&z);

	if(x>y && x>z)
		max=x;
	else
		max=y;
	if(z>y)
		max=z;
	printf("El numero mayor es %i \n",max );

	if(x<y && x<z)
		min=x;
	else
		min=y;
	if(z<y)
		min=z;
	printf("El numero menor es %i \n",min );
	system("pause");
	return 0;
}