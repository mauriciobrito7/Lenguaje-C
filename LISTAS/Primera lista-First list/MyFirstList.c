#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int dato;
    struct Node * sig;
}Node;

/*
    Funciones de la lista-Functions list:
    Node *createList(Node *p);
    Node * crcreateNodent dato);
    Node *insertIntoListAtTheEnd(int dato, Node *p);
    Node* insertIntoTheStartList(int dato, Node *p);
    void printList(Node * p);
    void destroyNode(Node * Node);
    Node * deleteTheBeginnning(Node *p); 
    Node * deleteSpecificNode(int dato, Node *p);
    Node * deleteList(Node *p);

 */

//Initialize list-Inicializando la lista en NULL
Node *createList(Node *p)
{
    return p=NULL;
}

Node * createNode(int dato)
{
    //Creating the node- Creando el Nodo, reservamos memoria
    Node *newNode;
    newNode=(Node*)malloc(sizeof(Node));

    //If you not have been able to allocate memory-Si no se pudo reservar memoria que muestre el siguiente mensaje
    if(!newNode)
    {
       printf("Could not create memory for the node\n");            
       printf("No se pudo create memoria para el nodo\n");
       return NULL;
    }
    else
    {
    //If you  have been able to allocate memory- Si se pudo reservar memoria entonces que registre el dato  y que el siguiente elemento al que
    //apunte sea NULL
        newNode->dato=dato;
        newNode->sig=NULL;
    }   
    return newNode;
}

//Insertar al final de la lista
Node *insertIntoListAtTheEnd(int dato, Node *p)
{
     Node *pAuxilary ,*newNode;
     newNode=createNode(dato);

     //If you could create the node is inserted into the list
     //Si se pudo crear el nodo que haga la inserción
     if(newNode)
     {
          //If the list is empty 
          //Si la lista esta vacia que la cabeza apunte al nodo recien creado
         if(!p)
               p=newNode;
         else
         {
         //pAuxiliary used to move between nodes
         //el pAuxiliary lo usamos para movernos entre los nodos de la lista 
         //hacemos que apunte al primer elemento de la lista y luego lo movemos hasta al final para hacer la inserción
              pAuxilary=p;
              while(pAuxilary->sig)
                pAuxilary=pAuxilary->sig;
              pAuxilary->sig=newNode;
         }

         return p;
    }
    return NULL;
}

Node* insertIntoTheStartList(int dato, Node *p)
{
    Node *newNode;
    newNode=createNode(dato);
     if(newNode){
        if(!p)
            p=newNode;
        else{
            newNode->sig=p;
            p=newNode;
            return p;
        }
     }
    return p;
}

void printList(Node * p)
{
    Node *pAuxilary;
    pAuxilary=p;

    while(pAuxilary)
    {
        printf("%d-> ",pAuxilary->dato);
        pAuxilary=pAuxilary->sig;
    }
    printf("NULL\n");
}

void destroyNode(Node * Node)
{
    free(Node);
}

Node * deleteTheBeginnning(Node *p)
{
    if(p){
        Node* eliminado;
        eliminado=p;
        p=p->sig;
        destroyNode(eliminado);
    }

    return p;
}

Node * deleteTheEnd(Node *p)
{
    
    if(p){
        Node *pAuxilary, *NodeAnterior;
        pAuxilary=p;
        while(pAuxilary->sig){
            NodeAnterior=pAuxilary;
            pAuxilary=pAuxilary->sig;
     }       
        NodeAnterior->sig=NULL;
     destroyNode(pAuxilary);
     
    }   
    
    return p;

}

Node * deleteSpecificNode(int dato, Node *p)
{   
    Node *pAuxilary, *NodeAnterior;
  
    pAuxilary=p;
    while(pAuxilary){
        if(pAuxilary->dato==dato)
            break;
        NodeAnterior=pAuxilary;
        pAuxilary=pAuxilary->sig;
    }
    if(pAuxilary){
        if(pAuxilary==p)
           pAuxilary=pAuxilary->sig;

        else{
            NodeAnterior->sig=pAuxilary->sig;
            destroyNode(pAuxilary);
        }
        printf("Node destroyed\n");
        printf("Nodo destruido\n");
    }
    else{
        printf("Sorry it has not found a Node with that data\n");
        printf("Lo siento no se ha encontrado un Node con ese dato\n");
    }
    return p;
}

Node * deleteList(Node *p)
{
    Node *pAuxilary;
    
    while(pAuxilary){
        pAuxilary=p;
        p=p->sig;
        destroyNode(pAuxilary); 
    }
}

int main ()
{
     Node *p;
     p = createList(p); 
     p = insertIntoListAtTheEnd(9, p);
     p = insertIntoListAtTheEnd(10, p);
     p = insertIntoListAtTheEnd(11, p);
     p=insertIntoTheStartList(1,p);
     p=insertIntoTheStartList(0,p);
     printList(p);
     p=deleteTheBeginnning(p);
     p=deleteTheEnd(p);
     p=deleteSpecificNode(9,p);
     printList(p);
     p=deleteList(p);
     free(p);
     return 0;
}