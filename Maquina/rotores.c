#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "rotores.h"
#include "../auxiliar/auxiliar.h"

void genWalzenlage( int nrotor,unsigned short walzen[]) /*Selecciona el numero de los rotores*/
{
    int i = 0;
    int u;

    if(nrotor>3)
    {
        walzen[0] = 9+(rand( )%2);

        for (i=1; i<4; i++)  /*Genero tres elementos aleatorios del (1-8)*/
        {
            walzen[i] = 1+(rand( )%8);

            for(u=0; u<i; u++)
            {
                if(walzen[u]==walzen[i]) /*Si algun elemento se repite con uno anterior lo vuelvo a generar */
                {
                    i--;
                    break;
                }
            }
        }
    }
    else
    {
        walzen[3]=0;

        for (i=0; i<3; i++)  /*Genero tres elementos aleatorios del (1-8)*/
        {
            walzen[i] = 1+(rand( )%8);

            for(u=0; u<i; u++)
            {
                if(walzen[u]==walzen[i]) /*Si algun elemento se repite con uno anterior lo vuelvo a generar */
                {
                    i--;
                    break;
                }
            }
        }
    }

}

void genRingstellung(int nrotor,unsigned short ring[]) /*Selecciona aleatoriamente la poscion de los anillos*/
{
    int i, u;

    if(nrotor>3)
    {
        for (i=0; i<4; i++)
        {
            ring[i]= 1+(rand()%26); /*Genero un n�mero del 1-26 que representar�a una letra de entrada*/

            for(u=0; u<i; u++)
            {
                if (ring[i]==ring[u])
                {
                    i--;
                    break;
                }
            }
        }
    }
    else
    {
        ring[3]=0;

        for (i=0; i<3; i++)
        {
            ring[i]= 1+(rand()%26); /*Genero un n�mero del 1-26 que representar�a una letra de entrada*/

            for(u=0; u<i; u++)
            {
                if (ring[i]==ring[u])
                {
                    i--;
                    break;
                }
            }
        }
    }

}

void genGrundstellung (int nrotor, char grund[]) /*Crea aleatoriamente las tres posciones del grund*/
{
    int i = 0, u;

    for (i=0; i<nrotor; i++)  /*Genero tres elementos aleatorios del (1-8)*/
    {
        grund[i] = 65+(rand( )%26);

        for(u=0; u<i; u++)
        {
            if(grund[u]==grund[i]) /*Si algun elemento se repite con uno anterior lo vuelvo a generar */
            {
                i--;
                break;
            }
        }
    }

    grund[nrotor]='\0';
}

void fprintGrundstellung (int nRotores, char grund[], FILE *pLbr) /*Imprime la posicion del grund en los dos archivos de config*/
{
    int i;

    fprintf(pLbr, "       ");

    for(i=0; i<nRotores; i++) /*imprimo las posiciones de los anillos*/
    {
        fprintf(pLbr, "%c ", grund[i]);

    }
    fprintf(pLbr,"       |\n");

}

void fprintRingstellung (int nrotor, unsigned short ring[], FILE *pLbr) /*Imprime los anillos en los dos archivos de config*/
{
    int i;

    fprintf(pLbr,"  ");

    for(i=0; i<nrotor; i++) /*imprimo las posiciones de los anillos*/
    {
        if(ring[i]<10)
        {
            fprintf(pLbr, "0%hu ", ring[i]);
        }
        else
        {
            fprintf(pLbr, "%2.d ", ring[i]);
        }
    }
    fprintf(pLbr," |");
}

void fprintWalzenlage (int nRotores, unsigned short walzen[], FILE *pLbr) /*Imprime los rotores en los dos archivos de config*/
{
    int i;

    for(i=0; i<nRotores; i++) /*Imprimo los tres elementos de la cadena rotor asignando un numero romano a cada numero deciaml*/
    {
        switch (walzen[i])
        {
        case 1:
            fprintf(pLbr,"I    ");
            break;
        case 2:
            fprintf(pLbr,"II   ");
            break;
        case 3:
            fprintf(pLbr,"III  ");
            break;
        case 4:
            fprintf(pLbr,"IV   ");
            break;
        case 5:
            fprintf(pLbr,"V    ");
            break;
        case 6:
            fprintf(pLbr,"VI   ");
            break;
        case 7:
            fprintf(pLbr,"VII  ");
            break;
        case 8:
            fprintf(pLbr,"VIII ");
            break;
         case 9:
            fprintf(pLbr,"Beta ");
            break;
         case 10:
            fprintf(pLbr,"Gamma ");
            break;
        default:
            printf("APPLICATION ERROR");
            break;
        }

    }

    fprintf(pLbr,"|");

}

void leeCfgRotor (struct sRotor *pRotor) /*Lee la configuracion de un rotor*/
{
    FILE*ptr;
    int i=0;
    ptr=fopen("BASEDATOS/cableadoRotores.cfg","rt"); /*Abre el archivo e informacion*/

    if (ptr==NULL)
    {
        MessageBox(0,"Error opening cableadoRotores.cfg","FILE MISSING",MB_ICONERROR);
        exit(1);
    }


    do /*Introduce la informacion referente al modelo selecionado en la lista dinamica*/
    {
        fscanf(ptr,"%s",pRotor->cableado);
        fscanf(ptr,"%s",pRotor->muesca);
        i++;
    }
    while (i<pRotor->num);

    fclose(ptr); /*Cierra el archivo*/
}

void configRotores (struct sListaRotores *lista, struct sConfig config) /*implementa la configuraci�n de los tres rotores de la m�quina Enigma*/
{
    int i,u;
    char aux[27]= {"0"};


    for(i=0; i<26; i++) /*Lleno una cadena con el abecedario*/
    {
        aux[i]= (i+65);
    }


    for (i=0; i<config.numRotores; i++)
    {
        for(u=0; u<26; u++)
        {
            if(config.grund[i]==aux[u])
            {
                break;
            }

        } /*Obtengo la posicion en el abecedario del grund*/

        configAnillos(&lista->rotor[i], config.ringS[i]); /*Llamada a la funcion configanillos*/

        pasoRotor(&lista->rotor[i], u);            /*Llamada a la funcion pasoRotor*/
    }
}

void configAnillos (struct sRotor *pRotor, int pos) /*Cinfugra los rotores segun la psicion del ring*/
{
    int i,u, a = 0;
    char aux[27]= {"0"}, aux1[27]= {"0"};


    for(i=0; i<26; i++) /*Lleno las tres cadenas con el abecedario y las acabo en \0*/
    {
        pRotor->referencia[i]=(i+65);
        pRotor->anillo[i]=(i+65);
        aux1[i]= (i+65);
    }

    pRotor->anillo[26]='\0';
    pRotor->referencia[26]='\0';

    for(i=0; i<26; i++) /*Coloco la poscion de las 26 letras segun como me indica el anillo*/
    {
        for(u=0; u<pos-1 ; u++)
        {
            if (pRotor->cableado[i]== 'Z')
            {
                pRotor->cableado[i]= 'A';

            }
            else
            {
                pRotor->cableado[i]=pRotor->cableado[i]+1;
            }
        }
    }

    for (i=0; i <26; i ++)
    {
        aux[i]= pRotor->cableado[i];
    }

    for(i=0; i<26; i++) /*ajusto las otras dos cadenas al anillo*/
    {
        if(i+pos<27)
        {
            pRotor->cableado[i+pos-1]=aux[i];
            pRotor->referencia[i+pos-1]=aux1[i];
        }
        else
        {
            a= (i+pos)-26;
            pRotor->cableado[a-1]=aux[i];
            pRotor->referencia[a-1]=aux1[i];
        }


    }

}

void pasoRotor (struct sRotor *pRotor, int num) /*implementa el avance paso a paso de un rotor*/
{
    int i;
    char aux[27]= {"0"}, aux1[27]= {"0"}, aux2[27]= {"0"};


    for(i=0; i<26; i++) /*Copio las tres cadenas en tres auxiliares*/
    {
        aux[i]=pRotor->anillo[i];
        aux1[i]=pRotor->cableado[i];
        aux2[i]=pRotor->referencia[i];
    }

    aux[26]='\0';
    aux1[26]='\0';
    aux2[26]='\0';

    for(i=0; i<26; i++) /*Implemento la codificacion letra a letra de cada cadena*/
    {
        if(26>(i+num))
        {
            pRotor->anillo[i]=aux[i+num];
            pRotor->cableado[i]=aux1[i+num];
            pRotor->referencia[i]=aux2[i+num];
        }
        else
        {
            pRotor->anillo[i]=aux[i+num-26];
            pRotor->cableado[i]=aux1[i+num-26];
            pRotor->referencia[i]=aux2[i+num-26];

        }
    }

}

void dibujaRotor (struct sRotor rotor, struct sPunto coordRotor) /*Dinuja las tres cadenas del rotor en la interfaz*/
{
    int i;

    for(i=0; i<27; i++)
    {
        if(rotor.anillo[i]==rotor.muesca[0]&& rotor.anillo[i]!='\0') /*Imprime letra del anillo si es muesca*/
        {
            setColorTexto(126);
            gotoxy(coordRotor.x,coordRotor.y+i);
            printf("%c", rotor.anillo[i]);
            setColorTexto(249);
        }
        else if(rotor.anillo[i]==rotor.muesca[1]&& rotor.anillo[i]!='\0') /*Imprime letra del anillo si es muesca*/
        {
            setColorTexto(126);
            gotoxy(coordRotor.x,coordRotor.y+i);
            printf("%c", rotor.anillo[i]);
            setColorTexto(249);
        }
        else if(rotor.anillo[i]==rotor.muesca[2] && rotor.anillo[i]!='\0') /*Imprime letra del anillo si es muesca*/
        {
            setColorTexto(126);
            gotoxy(coordRotor.x,coordRotor.y+i);
            printf("%c", rotor.anillo[i]);
            setColorTexto(249);
        }
        else /*Imprime letra del anillo normal*/
        {
            setColorTexto(121);
            gotoxy(coordRotor.x,coordRotor.y+i);
            printf("%c", rotor.anillo[i]);
            setColorTexto(249);
        }


        gotoxy(coordRotor.x+3,coordRotor.y+i); /*Imprime el cableado*/
        printf("%c", rotor.cableado[i]);

        gotoxy(coordRotor.x+4,coordRotor.y+i); /*Imprime la referencia*/
        printf("%c", rotor.referencia[i]);

    }

    gotoxy(coordRotor.x+1,40);

    switch (rotor.num) /*Imprime el walzen perteneciente al rotor*/
    {
    case 1:
        printf("I");
        break;
    case 2:
        printf("II");
        break;
    case 3:
        printf("III");
        break;
    case 4:
        printf("IV");
        break;
    case 5:
        printf("V");
        break;
    case 6:
        printf("VI");
        break;
    case 7:
        printf("VII");
        break;
    case 8:
        printf("VIII");
        break;
    case 9:
        printf("Beta");
        break;
    case 10:
        printf("Gamma");
        break;
    default:
        printf("APPLICATION ERROR");
        break;
    }

    gotoxy(coordRotor.x+2,7);
    printf("%c", rotor.anillo[0]);
}

void avanzaRotores (struct sListaRotores *pListaRotores)  /*implementa el avance que experimentan los rotores de la m�quina Enigma.*/
{
    pasoRotor(&pListaRotores->rotor[pListaRotores->num-1], 1); /*Llamada a la funcion pasoRotor*/

    if(pListaRotores->rotor[pListaRotores->num-2].muesca[0] == pListaRotores->rotor[pListaRotores->num-2].anillo[0] || pListaRotores->rotor[pListaRotores->num-2].muesca[1] == pListaRotores->rotor[pListaRotores->num-2].anillo[0]
            || pListaRotores->rotor[pListaRotores->num-2].muesca[2] == pListaRotores->rotor[pListaRotores->num-2].anillo[0])
    {
        pasoRotor(&pListaRotores->rotor[pListaRotores->num-3],1); /*Llamada a la funcion pasoRotor*/
    }

    if(pListaRotores->rotor[pListaRotores->num-1].anillo[25] == pListaRotores->rotor[pListaRotores->num-1].muesca[0] || pListaRotores->rotor[pListaRotores->num-1].anillo[25] == pListaRotores->rotor[pListaRotores->num-1].muesca[1]
            || pListaRotores->rotor[pListaRotores->num-1].anillo[25] == pListaRotores->rotor[pListaRotores->num-1].muesca[2] || pListaRotores->rotor[pListaRotores->num-2].muesca[0] == pListaRotores->rotor[pListaRotores->num-2].anillo[0] ||
            pListaRotores->rotor[pListaRotores->num-2].muesca[1] == pListaRotores->rotor[pListaRotores->num-2].anillo[0] ||  pListaRotores->rotor[pListaRotores->num-2].muesca[2] == pListaRotores->rotor[pListaRotores->num-2].anillo[0])
    {
        pasoRotor(&pListaRotores->rotor[pListaRotores->num-2], 1); /*Llamada a la funcion pasoRotor*/
    }

}

unsigned short 	opRotor (unsigned short in, struct sRotor rotor, bool dir) /*mplanta la operaci�n de cifrado que se realiza en un rotor.*/
{
    unsigned short i ;

    if(dir == false)
    {
        i= getPos(rotor.cableado[in], rotor.anillo);
    }
    else if(dir == true)
    {
        i= getPos(rotor.anillo[in], rotor.cableado);
    }

    return i;
}


