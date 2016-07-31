#include <stdio.h>
#include <stdlib.h>

void nuevoValor(int &x){
	x=5;
}

int main(){
	int x=6;
	nuevoValor(x);
	printf("El nuevo valor de X=%i\n",x );
	system("pause");
	return 0;
}