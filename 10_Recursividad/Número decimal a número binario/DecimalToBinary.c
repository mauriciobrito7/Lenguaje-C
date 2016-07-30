//Hacer una funcion recursiva que convierta un numero decimal a binario
#include <stdio.h>
#include <stdlib.h>
void conversor_binario(int n){

	if(n!=0){		
		conversor_binario(n/2);
		printf("%i", n%2);
	}
}

int main (){
	int n=4;
	conversor_binario(n);
	system("pause");
	return 0;
}