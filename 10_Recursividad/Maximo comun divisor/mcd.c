#include <stdio.h>

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
		printf("Login the first number:\n");
		scanf("%i",&a);

	}while(a<0);

	do{
		printf("Login the second number:\n");
		scanf("%i",&b);

	}while(a<0);

	if(a>b){
		printf("The mcd=%i\n",recursion(a,b));
	}
	else{
		printf("The mcd=%i\n",recursion(a,b));	
	}
	system("pause");
	return 0;

}