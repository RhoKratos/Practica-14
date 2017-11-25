#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <direct.h>
#include <ctype.h>
int main()
{
	FILE *doc;
	char nombrearchivo[20];
	char letra;
	int numcaracter,numpalabras=0,numeros=0,i;
	printf("Nombre del archivo:");
	gets(nombrearchivo);
	fflush(stdin);
	strcat(nombrearchivo,".txt");
	doc = fopen(nombrearchivo,"r");
	if(doc == NULL)
	{
		printf("El archivo no existe '%s'.\n",162,nombrearchivo);
		return 0;
	}
	while(!feof(doc))
	{
		letra=fgetc(doc);
		if(letra==' ')
		{
			numpalabras++;
		}
		if(isdigit(letra))
		{
			numeros++;
		}
	}
	fclose(doc);
	doc=fopen("palabras.txt","w");
	fprintf(doc,"Son %d palabras",numpalabras);
	fclose(doc);

	doc=fopen("numeros.txt","w");
	fprintf(doc,"Son %d digitos",numeros);
	fclose(doc);
	
	return 0;
}
