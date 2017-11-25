#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <direct.h>

main()
{
	FILE *doc;
	char nombrearchivo[20];
	char descripcion_archivo[100]="";
	int numcaracter;
	printf("Nombre del archivo:");
	gets(nombrearchivo);
	fflush(stdin);
	strcat(nombrearchivo,".txt");
	doc = fopen(nombrearchivo,"r");
	if(doc == NULL)
	{
		doc = fopen(nombrearchivo,"a");
		printf("Se cre%c correctamente el archivo '%s'.\n",162,nombrearchivo);

	}
	else
	{
		printf("El archivo '%s' ya existe.\n" ,nombrearchivo);
		doc = fopen(nombrearchivo,"w");
	}
	printf("Ingrese descripci%cn del archivo:",162);
	gets(descripcion_archivo);
	fflush(stdin);
	numcaracter=strlen(descripcion_archivo);
	printf("%d",numcaracter);
	fwrite(&descripcion_archivo,numcaracter,1,doc);
	fclose(doc);
}
