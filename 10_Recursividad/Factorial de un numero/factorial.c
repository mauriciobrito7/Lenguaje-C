//Factorial de un número de forma recursiva
#include <stdio.h>
#include <stdlib.h>
int factorial(int n){
	if (n==0)
		return 1;
	else{
		return n* factorial(n-1);
	}
}

int main (){
	int n=5;
	printf("El factorial de %i es %i",n, factorial(n));
	system("pause");
	return 0;
}