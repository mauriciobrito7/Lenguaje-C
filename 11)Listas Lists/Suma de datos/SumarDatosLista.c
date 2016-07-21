#include <stdio.h>
#include <stdlib.h>
//Sume los datos de una lista enlazada recursivamente

typedef struct Nodo{
	int dato;
	struct Nodo *sig;
}Nodo;

Nodo * insertarEnLaLista(Nodo *p, int dato){
	Nodo *nuevoNodo;
	nuevoNodo=(Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->sig=NULL;
	nuevoNodo->dato=dato;

	if(!p)
		p=nuevoNodo;
	else{
		Nodo * pAux;
		pAux=p;
		while(pAux->sig)
			pAux=pAux->sig;
		pAux->sig=nuevoNodo;
	}
	return p;
}

void mostrarElementosDeLaLista(Nodo * p){
	Nodo* pAux;
	pAux=p;
	while(pAux){
		printf("%i\n",pAux->dato );
		pAux=pAux->sig;
	}
}

int suma (Nodo *p){
	if(p)
	return p->dato + suma(p=p->sig);
}

int main(){

	Nodo *p;
	p=NULL;
	p=insertarEnLaLista(p,8);
	p=insertarEnLaLista(p,4);
	p=insertarEnLaLista(p,30);
	p=insertarEnLaLista(p,45);	
	mostrarElementosDeLaLista(p);
	printf("La suma de los elementos es: %i\n", suma(p));
	mostrarElementosDeLaLista(p);
	system("pause");
	return 0;

}