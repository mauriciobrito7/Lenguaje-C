#include <stdio.h>
#include <stdlib.h>

int factorial(int x);

int main (){
	int x,fact;
	printf("Introduce el numero a calcular\n");
	scanf("%i",&x);
	fact=factorial(x);

	printf("%i!=%i\n",x,fact );
	system("pause");
	return 0;
}

int factorial(int x){
	int i,j;
	j=1;
	for(i=1;i<=x;i++){
		j*=i;
	}
	return j;
}