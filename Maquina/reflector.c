#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "../auxiliar/auxiliar.h"
#include "reflector.h"

void leeCfgReflector (char archivo[], struct sReflector *pRef) /*abre el archivo de configuraci�n del reflector y lee la cadena de caracteres que contiene el cableado de dicho reflector.*/
{
    FILE*ptr;
    char modo;

    ptr= fopen(archivo, "rt"); /*Abre el archivo de configuracion de reflector*/

     if (ptr==NULL)
    {
        MessageBox(0,"Error opening reflector.cfg","FILE MISSING",MB_ICONERROR);
        exit(1);
    }

    fscanf(ptr, "%c", &modo);
    fscanf(ptr, " ");

    /*leemos la configuracion del reflector C o B*/

    if(pRef->modelo == modo)
    {
        fgets(pRef->conexiones,27, ptr);
    }
    else
    {
        fgets(pRef->conexiones,27, ptr);
        fscanf(ptr, "\n%c ", &modo);
        fgets(pRef->conexiones,27, ptr);
    }

    fclose(ptr); /*Cerramos el archivo*/
}

void 	dibujaReflector (struct sReflector reflector) /* dibuja en la interfaz de la versi�n 2 una representaci�n esquem�tica del reflector de la m�quina Enigma.*/
{
    int u,i;
    char aux[27]=" ";

    for  (i=0; i<26; i++) /*Llene una cadena con el abecedario*/
    {
        aux[i]=(i+65);
    }

    for(u=11; u<=37; u++) /*Imprime el reflector*/
    {
        gotoxy(4,u);
        printf("%c", aux[u-11]);

        gotoxy(5,u);
        printf("%c", reflector.conexiones[u-11]);

    }

    gotoxy(4,40);
    printf("%c", reflector.modelo);

}

unsigned short 	opReflector (unsigned short in, struct sReflector reflector) /*mplementa el cifrado que realiza el reflector*/
{
    unsigned short i;
    char abecedario[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for(i=0; i<26; i++)
    {
        if(reflector.conexiones[in]==abecedario[i])
        {
            break;
        }
    }

    return i;
}

