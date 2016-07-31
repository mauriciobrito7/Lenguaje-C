#include <stdio.h>
#include <stdlib.h>

//Invertir un número
//Invest a number
void invertirNumero(int n){
	if(n<10)
		printf("%i",n);
	else{
		printf("%i",n%10 );
		if(n>10) invertirNumero(n/10);
	}	
}

int main(){
	int n;
	printf("Introduzca el numero a invertir:\n");
	scanf("%i",&n);
	invertirNumero(n);
	printf("\n");
	system("pause");
	return 0;
}