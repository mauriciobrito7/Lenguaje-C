//Hacer la suma y el producto de dos numeros de manera recursiva
#include <stdio.h>
#include <conio.h>

int suma(int n, int n2){
	if(n2==0)
		return n;

	return suma(++n,--n2);
}

int multiplicacion (int n, int n2){
	if (n2==1)
		return n;
	return n + multiplicacion(n, --n2);

}


int main (){
	int  n=8, n2=6;
	printf("El resultado de la suma %i\n",suma(n,n2));
	printf("El resultado de la multiplicacion %i\n",multiplicacion(n,n2));
	getch();
	return 0;
}