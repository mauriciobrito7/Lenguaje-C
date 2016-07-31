#include <stdio.h>
//Maximo comun divisor
//Algoritmo de Euclides
//mcd(15,9)=mcd(9,15%9)=mcd(9,6)=mcd(6,3)=mcd(3,0), mcd=3

int recursion(int a, int b){
	if(b==0)
		return a;
	recursion(b,a%b);
}

int main (){
	int a,b;

	printf("Recursion\n");
	do{
		printf("Introduzca el primer numero:\n");
		scanf("%i",&a);

	}while(a<0);

	do{
		printf("Introduzca el segundo numero:\n");
		scanf("%i",&b);

	}while(a<0);

	if(a>b){
		printf("El mcd=%i\n",recursion(a,b));
	}
	else{
		printf("El mcd=%i\n",recursion(a,b));	
	}
	system("pause");
	return 0;

}