#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "../auxiliar/auxiliar.h"

void genStecker(char conexiones[27]) /*genera una cadena de caracteres que contiene las conexiones establecidas aleatoriamente*/
{
    char Entrada[26];
    char aux1[10];
    char aux[10];
    int i, u, o=0;

    for  (i=0; i<26; i++) /*Genero dos cadenas auxiliares con el abecedario*/
    {
        Entrada[i]=(i+65);
        conexiones[i]=(i+65);
    }

    for (i=0; i<10; i++)  /*Diez repeticiones*/
    {
        o=0;

        aux[i] = (rand( )%26) ; /*Genero un número del 1-26 que representaría una letra de entrada*/

        aux1[i] = (rand( )%26) ; /*Genero un numero que representa una letra de salida*/

        if (aux1[i] == aux[i])   /* Si las letras coinciden no me vale porque no sería un cambio*/
        {
            i --;
            o=1;               /*Descuento esta iteracción fallida de mi bucle*/
        }
        else if(o==0)
        {
            for ( u= 0; u<i; u++)
            {
                if (aux[i]==aux[u] || aux1[i] == aux1[u] || aux[i] == aux1[u] || aux1[i] == aux[u]) /* Si no coinciden pero ya han salido una vez, tampoco me vale*/
                {
                    i--;
                    o=1;                                  /*Descuento esta iteracción fallida de mi bucle*/
                }
            }
        }

        if(o==0)
        {
            conexiones[(int)aux[i]]= conexiones[(int)aux1[i]];
            conexiones[(int)aux1[i]]= Entrada[(int)aux[i]];/*Si no coinciden y ambas no han salido ninguna vez entonces hago la transformacion*/

        }
    }

    conexiones[26]='\0';
}

void 	fprintStecker (char stecker[], FILE *pLbr) /*escribe la parte correspondiente al panel de conexiones*/
{
    int i,u,a=0,w=0;
    char aux[26]=" ";
    char compro[20]=" ";

    for  (i=0; i<26; i++) /*Llene una cadena con el abecedario*/
    {
        aux[i]=(i+65);
    }
    for(i=0; i<26; i++) /*Comrpuebo que letras estan cambiadas*/
    {
        a=0;

        if(aux[i]!= stecker[i] )
        {

            for (u=0; u<20; u++)
            {
                if(aux[i]==compro[u]) /*Compruebo que la letra que está cambiada no la he impreso con su pareja ya*/
                {
                    a=1;
                }
            }

            if(a!=1)
            {
                fprintf(pLbr," %c%c", stecker[i], aux[i]); /*Si aun no la he impreso entonces la imprimo en el archivo de text*/
                compro[w]= stecker[i];
                w++;
            }
        }
    }
    fprintf(pLbr,"  |");
}

void dibujaStecker 	(char stecker[],unsigned short dx )
{
    int u,i;
    char aux[27]=" ";

    for  (i=0; i<26; i++) /*Llene una cadena con el abecedario*/
    {
        aux[i]=(i+65);
    }
    for(u=11; u<=37; u++)
    {
        gotoxy(37+dx,u);
        printf("%c", aux[u-11]);

        gotoxy(40+dx,u);
        printf("%c", stecker[u-11]);

        gotoxy(41+dx,u);
        printf("%c", aux[u-11]);
    }
}

void dibujaEstator (dx) /*dibuja en la interfaz de la versión 2 una representación esquemática del estator o ETW*/
{
    int u,i;
    char aux[27]=" ";

    for  (i=0; i<26; i++) /*Llena una cadena con el abecedario*/
    {
        aux[i]=(i+65);
    }
    for(u=11; u<=37; u++) /*Lo imprime*/
    {
        gotoxy(33+dx,u);
        printf("%c", aux[u-11]);

    }
}

unsigned short 	opStecker (unsigned short posIn, char stecker[]) /*implementa el comportamiento del panel de conexiones cuando se teclea una letra*/
{

    char abecedario[26]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unsigned char i;

    for(i=0; i<26; i++)
    {
        if( stecker[posIn] == abecedario[i])
        {
            break;
        }
    }

    return i;

}
