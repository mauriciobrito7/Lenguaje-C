#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estructura que representa a los elementos en la cola

typedef struct Document{
	char *name;
	struct Document *next;
}Document;

Document *first=NULL, *last=NULL;

void pause(){
    system("pause");
}

Document * createDocument(Document *_document, char *name){
	_document=(Document*) malloc(sizeof(Document));
	_document->name=(char*)malloc((sizeof(char)*strlen(name))+1);
	if(!_document){
		printf("No se ha podido reservar memoria para la cola\n");
		pause();
		exit(1);
	}
	else{
		_document->name=name;
		_document->next=NULL;
		free(name);
	}

	return _document;
	}

void push(Document *_document, char *name){
 	_document=createDocument(_document, name);

 	if(!first){
 		first=_document;
 		last=_document;
 	}
 	else{
 		last->next=_document;
 		last=_document;
 	}

}

void showDocuments(Document *_document){

	printf("%s \n",_document->name );
	free(_document);

}

Document* pop(Document* _document){
	Document *_documentA;
	_documentA=first;
	first=first->next;

	showDocuments(_documentA);
}


int main (){
	Document *_document;
	push(_document, "Java.doc");
	push(_document, "Goglang.doc");
	push(_document, "C#.doc");
	push(_document, "JavaScript.doc");
	pop(_document);
	pop(_document);
	pause();
	return 0;
}
