#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int valor;
	struct nodo *izdo;
	struct nodo *dcho;
}Nodo;

 typedef Nodo Arbol;

//------Crear Nodo------//
Nodo *crearNodo(int valor){
	Nodo* nuevoNodo=(Nodo*)malloc(sizeof(Nodo));
	nuevoNodo->valor=valor;
	nuevoNodo->izdo=NULL;
	nuevoNodo->dcho=NULL;
	return nuevoNodo;//------Crear Nodo------//
}
//------Destruir Nodo------//
void destruirNodo(Nodo * nodo){
	nodo->izdo= nodo->dcho=NULL;
	free(nodo);
}
//------Insertar------//
void Insertar(Nodo **arbol, int valor){
	if(*arbol==NULL){
		Nodo * nuevoNodo=crearNodo(valor);
		*arbol=nuevoNodo;
	}else{
		int valorRaiz=(*arbol)->valor;
		if(valor<valorRaiz){
			Insertar(&(*arbol)->izdo,valor);
		}else{
			Insertar(&(*arbol)->dcho,valor);
		}
	}
}
//------Comprobar------//
int Existe(Nodo* arbol, int valor){
	if(arbol==NULL){
		return 0;
	}else if(arbol->valor==valor){
		return 1;
	}else if (valor<arbol->valor){
		return Existe(arbol->izdo, valor);
	}else{
		return Existe(arbol->dcho,valor);
	}
}

void determinarExistencia (Nodo* arbol, int valor ){
	if(Existe(arbol,valor)){
		printf("El nodo %d existe en el arbol\n",valor );
	}else{
		printf("El nodo %d No existe en el arbol\n",valor );
	}
}

int main(){
	Arbol *arbol = NULL;
	
	Insertar(&arbol,5);
	Insertar(&arbol,10);
	Insertar(&arbol,4);
	Insertar(&arbol,9);
	Insertar(&arbol,15);
	determinarExistencia(arbol, 10);
	determinarExistencia(arbol, 3);
	determinarExistencia(arbol, 9);
	system("pause");
	return 0;
}
