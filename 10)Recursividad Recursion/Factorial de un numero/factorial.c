//Factorial de un número

#include <stdio.h>
#include <conio.h>

int factorial(int n){
	if (n==0)
		return 1;
	else{
		return n* factorial(n-1);
	}
}


int main (){
	int n=5;

	printf("The factorial of %i is %i",n, factorial(n));
	getch();
	return 0;
}