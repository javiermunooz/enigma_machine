#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"
#include "../Maquina/reflector.h"
#include "../auxiliar/auxiliar.h"
#include "../Maquina/rotores.h"

void selecModelo (struct sConfig *pConfig)
{
    int opcion=-1;

    gotoxy(24,3);
    printf("SELECT AN ENIGMA MODEL");
    gotoxy(3,7);
    printf("                                 ");
    gotoxy(3,9);
    printf("                                 ");
    gotoxy(3,11);
    printf("                                 ");
    gotoxy(3,15);
    printf("                                 ");


    gotoxy(3,6);
    printf("1. 3-rotor M3 Kriegsmarine UKW = B");
    gotoxy(3,8);
    printf("2. 3-rotor M3 Kriegsmarine UKW = C");
    gotoxy(3,10);
    printf("3. 4-rotor M4 Kriegsmarine UKW = B");
    gotoxy(3,12);
    printf("4. 4-rotor M4 Kriegsmarine UKW = C");

    gotoxy(3,15);
    printf("Select an option:");


    while (opcion<='0' || opcion >'4')
    {
        opcion=getch();
    }

    switch (opcion)
    {
    case '1':
        pConfig->numRotores=3;
        pConfig->modeloETW='B';
        break;
    case '2':
        pConfig->numRotores=3;
        pConfig->modeloETW='C';
        break;
    case '3':
        pConfig->numRotores=4;
        pConfig->modeloETW='B';
        break;
    case '4':
        pConfig->numRotores=4;
        pConfig->modeloETW='C';
        break;
    default:
        printf("APPLICATION ERROR");
        break;
    }

}

void leeConfig 	(struct sConfig *pConfig)  /*Lee la informacin de los archivos de datos para la configuracion de ese dia*/
{
    FILE*pLbb;
    int numero, i;

    pConfig->walzen[3]=0;

    switch(pConfig->numRotores) /*Dependiende del tipo de configuracion que sea abre uno u otro archivo*/
    {
    case 3:

        if(pConfig->modeloETW =='B')
        {
            pLbb = fopen("BASEDATOS/libro_M3_B.bin", "rb");

        }
        else
        {
            pLbb = fopen("BASEDATOS/libro_M3_C.bin", "rb");
        }
        break;

    case 4:

        if(pConfig->modeloETW=='B')
        {
            pLbb = fopen("BASEDATOS/libro_M4_B.bin", "rb");
        }
        else
        {
            pLbb = fopen("BASEDATOS/libro_M4_C.bin", "rb");
        }
        break;

    default:
        printf("APPLICATION ERROR");
        break;
    }

    fseek(pLbb,0,SEEK_END);

    numero=ftell(pLbb)/sizeof(struct sConfig);

    fseek(pLbb,0,SEEK_SET);

    for(i=0; i<=numero; i++)
    {
        if(pConfig->dia==i)
        {
            fread(pConfig,sizeof(struct sConfig),1,pLbb);
            break;
        }
    }
    fclose(pLbb); /*Cierra el archivo*/
}

void 	muestraConfig (struct sConfig config) /*muestra en la consola la configuraci�n de la m�quina Enigma*/
{
    int i,u,a=0,w=0;
    char aux[26]=" ";
    char compro[20]=" ";

    gotoxy(3,6);
    printf("                                   ");
    gotoxy(3,8);
    printf("                                   ");
    gotoxy(3,10);
    printf("                                   ");
    gotoxy(3,12);
    printf("                                   ");

    for  (i=0; i<26; i++) /*Llena una cadena con el abecedario*/
    {
        aux[i]=(i+65);
    }

    gotoxy(3,7);
    printf("UKW              : %c\n", config.modeloETW);
    gotoxy(3,8);
    printf("Walzen           : ");

    for(i=0; i<4; i++) /*Imprimo los tres elementos de la cadena rotor asignando un numero romano a cada numero deciaml*/
    {
        if(config.walzen[i]!=0)
        {
            switch (config.walzen[i])
            {
            case 1:
                printf("I ");
                break;
            case 2:
                printf("II ");
                break;
            case 3:
                printf("III ");
                break;
            case 4:
                printf("IV ");
                break;
            case 5:
                printf("V ");
                break;
            case 6:
                printf("VI ");
                break;
            case 7:
                printf("VII ");
                break;
            case 8:
                printf("VIII ");
                break;
            case 9:
                printf("Beta ");
                break;
            case 10:
                printf("Gamma ");
                break;
            default:
                printf("APPLICATION ERROR");
                break;
            }
        }


    }
    printf("\n");

    gotoxy(3,9);
    printf("Ringstellung     : ");

    for(i=0; i<4; i++) /*imprimo las posiciones de los anillos*/
    {
        if(config.ringS[i]!=0)
        {
            if(config.ringS[i]<10)
            {
                printf("%c-0%d  ", aux[config.ringS[i]-1], config.ringS[i]);
            }
            else
            {
                printf("%c-%2.d  ", aux[config.ringS[i]-1],config.ringS[i]);
            }
        }

    }

    printf("\n");

    gotoxy(3,10);
    printf("Stecker          :");

    for(i=0; i<26; i++) /*Comrpuebo que letras estan cambiadas*/
    {
        a=0;

        if(aux[i]!= config.stecker[i] )
        {

            for (u=0; u<20; u++)
            {
                if(aux[i]==compro[u]) /*Compruebo que la letra que est� cambiada no la he impreso con su pareja ya*/
                {
                    a=1;
                }
            }

            if(a!=1)
            {
                printf(" %c%c", config.stecker[i], aux[i]); /*Si aun no la he impreso entonces la imprimo en el archivo de text*/
                compro[w]= config.stecker[i];
                w++;
            }
        }
    }

    gotoxy(3,11);
    printf("Grund            : ");

    for(i=0; i<4; i++) /*imprimo las posiciones de los anillos*/
    {

        printf("%c ", config.grund[i]);

    }


}
