#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Element{
	char *name;
	struct Element* next;
}Element;

Element *top;

void pause(){
	system("pause");
}

Element *createElement(Element *_element, char *name){
	_element=(Element*)malloc(sizeof(Element));
	_element->name=(char*)malloc((sizeof(char)*strlen(name)+1));
	if (!_element){
		printf("No se he podido reservar memoria para el registro\n");
		system("pause");
		exit(1);
	}
	else{
		_element->name=name;
		_element->next=NULL;
	}
	return _element;
}

void push(Element *_element, char *name){
	_element=createElement(_element,name);

	if(!top){
		top=_element;
	}
	else{
		_element->next=top;
		top=_element;
	}
}

void showElement(Element *_element){
	printf("%s\n", _element->name);
}


void pop(){
	Element *_elementA=top;
	top=top->next;
	showElement(_elementA);
}


int main(){
	Element *_element;
	push(_element,"hello");
	pop();
	push(_element,"bye");
	pop();

pause();
return 0;
}
