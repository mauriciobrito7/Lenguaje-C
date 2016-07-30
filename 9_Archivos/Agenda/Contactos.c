//Agenda
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMBRE_ARCHIVO "contactos.bin"
#define NOMBRE_ARCHIVO_AUX "contactos_aux.bin"
//Contactos
typedef struct contactatos{
	char nombre[20];
	char direccion[30];
	int telefono;
}Contactos;
//Funciones
void menu();
Contactos crearContacto();
void guardarContacto(Contactos contacto);
void mostrarContactos();
void borrarContacto();
void pausar();

int main (){

	menu();
	pausar();
	return 0;
}

void menu()
{
	int op;
	do{
		system("cls");
		printf("[1]Crear contacto\n");
		printf("[2]Mostrar contactos\n");
		printf("[3]Borrar contacto\n");
		printf("[4]Salir\n");
		printf("Ingrese la opción: ");
		scanf("%i",&op);
	if(op>0 && op<5){
		system("cls");
		switch(op){
			case 1:
				guardarContacto(crearContacto());
				break;
			case 2:
				mostrarContactos();
				break;
			case 3:
                borrarContacto();
                break;
			case 4:
				exit(1);
			default:
				printf("Error de ingreso\n");
				pausar();
		}
	}
	}while(op!=4);
}
//Creando el contacto
Contactos crearContacto()
{
	Contactos contacto;
	printf("nombre:\n");
	fflush(stdin);
	gets(contacto.nombre);
	printf("direccion:\n");
	fflush(stdin);
	gets(contacto.direccion);
	printf("Numero de telefono:\n");
	scanf("%i",&contacto.telefono);

	return contacto;
}

void guardarContacto(Contactos contacto)
{
	FILE* file;
	//si el archivo existe va a
	//gregar el nuevo contacto que creamos al final del archivo
	//no va a sobreescribir
	file=fopen(NOMBRE_ARCHIVO,"ab");

	if(!file){
		printf("Error\n");
		pausar();
		exit(1);
	}
	else{
		//Recibe 4 parametros:
		//1-Dirección de memoria de la variable que queremos guardar
		//2-El tamaño del tipo de dato
		//3-La cantidad de datos que queremos guardar
		//4-La variable del archivo
		fwrite(&contacto, sizeof(Contactos),1, file);
		printf("Contacto guardado!\n");
		pausar();
		fclose(file);
	}

}

void borrarContacto()
{
	system("cls");
	FILE *file, *fileAux;
	Contactos contacto;
	fileAux=fopen(NOMBRE_ARCHIVO_AUX,"wb");
	file=fopen(NOMBRE_ARCHIVO,"rb");

	if(!file){
		printf("Vacio\n");
	}
	else{

		char nombre[20];
		printf("Nombre del contacto a borrar:\n");
		fflush(stdin);
		gets(nombre);
		//Recibe los mismos parametros que fwrite
		while(fread(&contacto, sizeof(Contactos),1, file)){

            if (strcmp(contacto.nombre,nombre)!= 0)
                fwrite(&contacto, sizeof(Contactos),1, fileAux);
		}
		fclose(file);
        fclose(fileAux);
        fileAux=fopen(NOMBRE_ARCHIVO_AUX,"rb");
        file=fopen(NOMBRE_ARCHIVO,"wb");
		while(fread(&contacto, sizeof(Contactos),1, fileAux)){

            fwrite(&contacto, sizeof(Contactos),1, file);
		}
	}
    pausar();
	fclose(file);
	fclose(fileAux);
}
//Mostrar contactos
void mostrarContactos()
{
	FILE *file;
	file=fopen(NOMBRE_ARCHIVO,"rb");
	if(!file){
		printf("Vacio\n");
	}
	else{
		Contactos contacto;
		printf("%-20s %-30s %-30s\n", "nombre", "direccion","telefono");
		//recibe los mismo parametros que fwrite
		while(fread(&contacto, sizeof(Contactos),1, file)){
			printf("%-20s %-30s %-30i\n", contacto.nombre, contacto.direccion,contacto.telefono);
		}
		fclose(file);
		printf("\n");
		pausar();

	}
}

void pausar()
{
	system("pause");
}
