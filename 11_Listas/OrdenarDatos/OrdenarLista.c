#include <stdio.h>
#include <stdlib.h>
//Ordenar los datos de una lista 

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

int longitudLista(Nodo *p){
	int cont;
	Nodo *pAux=p;
	while(pAux){
		cont++;
		pAux=pAux->sig;
	}
	return cont;
}

Nodo * ordenarLista (Nodo *p){
	int dato,longitud=longitudLista(p);
	Nodo *pAux;
	while(longitud>0){
		pAux=p;
		while(pAux->sig){
			if(pAux->dato > pAux->sig->dato){
				dato=pAux->dato;
				pAux->dato=pAux->sig->dato;
				pAux->sig->dato=dato;
			}
		pAux=pAux->sig;	
		}
	longitud--;
	}
	return p;
}

int main(){

	Nodo *p;
	p=NULL;
	p=insertarEnLaLista(p,4);
	p=insertarEnLaLista(p,3);
	p=insertarEnLaLista(p,8);
	p=insertarEnLaLista(p,2);
	p=insertarEnLaLista(p,9);
	p=insertarEnLaLista(p,0);
	p=insertarEnLaLista(p,20);	
	mostrarElementosDeLaLista(p);
	p=ordenarLista(p);
	printf("\n");
	mostrarElementosDeLaLista(p);
	system("pause");
	return 0;

}