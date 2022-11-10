#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include <ctype.h>
#include "../Config/config.h"
#include "rotores.h"
#include "../auxiliar/auxiliar.h"
#include "interfaz.h"
#include "cifrado.h"
#include "stecker.h"
#include "reflector.h"
#include "Enigma.h"
#include "../auxiliar/punto.h"


void inicCifrado (void) /*Inicia el proceso de cifrado o descifrado cargando la configuraci�n necesaria*/
{
    struct sEnigma enigma;
    int cont=0;
    FILE*pLbb;

    selecModelo(&enigma.config);   /*Llamada a la funcon selectModelo OJO! (amibuguedad en el diagrama y las especifiaciones es irrelevante)*/

    switch(enigma.config.numRotores) /*Comprueba la existencia del archivo de configuracion de ese modelo*/
    {
    case 3:

        if(enigma.config.modeloETW =='B')
        {
            pLbb = fopen("BASEDATOS/libro_M3_B.bin", "rb");
            if (pLbb==NULL)
            {
                MessageBox(0,"A config file for this model must be generated","FILE MISSING",MB_ICONERROR);
                return;
            }
            fclose(pLbb);

        }
        else
        {
            pLbb = fopen("BASEDATOS/libro_M3_C.bin", "rb");
            if (pLbb==NULL)
            {
                MessageBox(0,"A config file for this model must be generated","FILE MISSING",MB_ICONERROR);
                return;
            }
            fclose(pLbb);

        }
        break;

    case 4:

        if(enigma.config.modeloETW=='B')
        {
            pLbb = fopen("BASEDATOS/libro_M4_B.bin", "rb");
            if (pLbb==NULL)
            {
                MessageBox(0,"A config file for this model must be generated","FILE MISSING",MB_ICONERROR);
                return;
            }
            fclose(pLbb);

        }
        else
        {
            pLbb = fopen("BASEDATOS/libro_M4_C.bin", "rb");
            if (pLbb==NULL)
            {
                MessageBox(0,"A config file for this model must be generated","FILE MISSING",MB_ICONERROR);
                return;
            }
            fclose(pLbb);

        }
        break;

    default:
        printf("APPLICATION ERROR");
        break;
    }


    gotoxy(24,3);
    printf("       DAY SELECTION           ");
    gotoxy(3,6);
    printf("                                   ");
    gotoxy(3,8);
    printf("                                   ");
    gotoxy(3,10);
    printf("                                   ");
    gotoxy(3,12);
    printf("                                   ");

    gotoxy(3,15);
    printf("Enter the day to generate config (1-31): ");

    do /*Control para que la opcion este entre las disponibles*/
    {
        if (cont==0)
        {
            fflush(stdin);
            scanf("%d", &enigma.config.dia);
            cont++;
        }
        else
        {
            if(enigma.config.dia<0) MessageBox(0,"Days cannot have a negative value","INPUT ERROR",MB_ICONERROR);
            if(enigma.config.dia>31) MessageBox(0,"Day must be 1-31","INPUT ERROR",MB_ICONERROR);

            gotoxy(3,15);
            printf("                                                                   ");

            fflush(stdin);
            gotoxy(3,15);
            printf("Enter the day to generate config (1-31): ");
            scanf("%d", &enigma.config.dia);
        }

    }
    while( enigma.config.dia<1 || enigma.config.dia>31 || enigma.config.dia%1!=0); /*Requerimiento de la opcion en el menu principal*/

    enigma.reflector.modelo=enigma.config.modeloETW;   /*Asignacion del modelo en el campo de reflector de la estructura*/

    configuracion(&enigma);                            /*Llamada a la funcon configuracion*/

    configRotores(&enigma.listaRotores, enigma.config); /*Llamada a la funcon configrotores*/

    if(enigma.config.numRotores==3)
    {
        dibujaInterfazM3();                             /*Llamada a la funcon configuracion DibujainterfazM3*/
    }
    else
    {
        dibujaInterfazM4();                              /*Llamada a la funcon configuracion DibujainterfazM4*/

    }

    MessageBox(0,"Enter the message one character at a time.\nPress [ESC] to end","MANUAL",MB_ICONINFORMATION);

    procesoCifrado(enigma);                              /*Llamada a la funcon configuracion procesoCifrado*/

    return;
}

void procesoCifrado (struct sEnigma enigma)
{
    FILE *ptPlano;
    FILE *ptCifrado;
    struct sPunto *coordRotor;
    char letra;
    unsigned short posi[13];

    if(enigma.config.numRotores==3) /*Lleno el vector coordrotor con las coordenadas correspondientes a la version m3*/
    {
        coordRotor=malloc(3* sizeof(struct sPunto));
        coordRotor[0].x=9;
        coordRotor[0].y=11;
        coordRotor[1].x=17;
        coordRotor[1].y=11;
        coordRotor[2].x=25;
        coordRotor[2].y=11;
    }
    else /*Lleno el vector coordrotor con las coordenadas correspondientes a la version m4*/
    {
        coordRotor=malloc(4* sizeof(struct sPunto));
        coordRotor[0].x=9;
        coordRotor[0].y=11;
        coordRotor[1].x=17;
        coordRotor[1].y=11;
        coordRotor[2].x=25;
        coordRotor[2].y=11;
        coordRotor[3].x=33;
        coordRotor[3].y=11;
    }

    abreArchivosMensaje(&ptPlano, &ptCifrado); /*Llamada a la funcion abre archivos mensaje*/

    muestraEsquema(enigma, coordRotor);         /*Llamada a la funcion muestraEsquema*/

    if(enigma.config.numRotores==3)
    {
        while(1) /*Bucle infinito*/
        {
            gotoxy(65,7);
            letra = leeLetra(0);

            if(letra==27)
            {
                break;
            }

            avanzaRotores(&enigma.listaRotores); /*Llamada a la funcion avanzarotor*/

            muestraEsquema(enigma,coordRotor); /*Llamada a la funcion muestraEsquema*/

            printLetraPlana(letra,ptPlano,enigma.config.numRotores);

            posi[0]= devuelvepos(letra); /*Devuelve la posicion de la letra metida en el abecedario*/

            posi[1]=opStecker(posi[0], enigma.config.stecker); /*Devulve la letra compa�era de la letra metida en stecker*/

            posi[2]=opRotor(posi[1], enigma.listaRotores.rotor[2], false); /*Devulve la letra compa�era de la letra metida en rotor*/

            posi[3]=opRotor(posi[2],enigma.listaRotores.rotor[1], false);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[4]=opRotor(posi[3], enigma.listaRotores.rotor[0], false);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[5]=opReflector(posi[4],enigma.reflector);/*Devulve la letra compa�era de la letra metida en el reflector*/

            posi[6]=opRotor(posi[5],enigma.listaRotores.rotor[0], true);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[7]=opRotor( posi[6],enigma.listaRotores.rotor[1], true);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[8]=opRotor(posi[7],enigma.listaRotores.rotor[2], true);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[9]=devuelvepos(97+posi[8]); /*Llamada a la funcion auxiliar devuelvepos*/

            posi[9]=opStecker(posi[9], enigma.config.stecker); /*Devulve la letra compa�era de la letra metida en el stecker*/

            pintaCaminito(posi,enigma); /*Llamada a la funcion auxiliar pintaCaminito*/

            printLetraCifrada(enigma.config.stecker[posi[8]], ptCifrado,enigma.config.numRotores); /*Llamada a la funcion printletracifrada*/


        }
    }
    else
    {
        while(1) /*Bucle infinito*/
        {
            gotoxy(76,7);
            letra = leeLetra(0);

            if(letra==27)
            {
                break;
            }

            avanzaRotores(&enigma.listaRotores); /*Llamada a la funcion avanzarotor*/

            muestraEsquema(enigma,coordRotor); /*Llamada a la funcion muestraEsquema*/

            printLetraPlana(letra,ptPlano,enigma.config.numRotores);

            posi[0]= devuelvepos(letra); /*Devuelve la posicion de la letra metida en el abecedario*/

            posi[1]=opStecker(posi[0], enigma.config.stecker); /*Devulve la letra compa�era de la letra metida en stecker*/

            posi[2]=opRotor(posi[1], enigma.listaRotores.rotor[3], false); /*Devulve la letra compa�era de la letra metida en rotor*/

            posi[3]=opRotor(posi[2],enigma.listaRotores.rotor[2], false);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[4]=opRotor(posi[3],enigma.listaRotores.rotor[1], false); /*Devulve la letra compa�era de la letra metida en rotor*/

            posi[5]=opRotor(posi[4], enigma.listaRotores.rotor[0], false);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[6]=opReflector(posi[5],enigma.reflector);/*Devulve la letra compa�era de la letra metida en el reflector*/

            posi[7]=opRotor(posi[6],enigma.listaRotores.rotor[0], true);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[8]=opRotor( posi[7],enigma.listaRotores.rotor[1], true);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[9]=opRotor(posi[8],enigma.listaRotores.rotor[2], true);/*Devulve la letra compa�era de la letra metida en rotor*/

            posi[10]=opRotor(posi[9],enigma.listaRotores.rotor[3], true);

            posi[11]=devuelvepos(97+posi[10]); /*Llamada a la funcion auxiliar devuelvepos*/

            posi[11]=opStecker(posi[11], enigma.config.stecker); /*Devulve la letra compa�era de la letra metida en el stecker*/

            pintaCaminito1(posi,enigma); /*Llamada a la funcion auxiliar pintaCaminito1*/

            printLetraCifrada(enigma.config.stecker[posi[10]], ptCifrado,enigma.config.numRotores);/*Llamada a la funcion printletracifrada*/

        }
    }

    cierraArchivosMensaje(ptPlano, ptCifrado); /*Llamada a la funcion cierra archivos mensaje*/

}

void abreArchivosMensaje (FILE **ptPlano, FILE **ptCifrado) /*Se encarga de la correcta apertura de los archivos*/
{
    *ptPlano=fopen("BASEDATOS/mensajePlano.txt","wt"); /*Abre el archivo que le entra como referencia*/

    *ptCifrado=fopen("BASEDATOS/mensajeCifrado.txt", "wt");

    if (ptPlano==NULL)
    {
        gotoxy(55,30);
        printf("Could not open file");
        pulsetecla();
        exit(1);
    }

    if (ptCifrado==NULL)
    {
        gotoxy(55,30);
        printf("Could not open file");
        pulsetecla();
        exit(1);
    }

}

void cierraArchivosMensaje (FILE *ptPlano, FILE *ptCifrado) /*Se encarga del correcto cierre de los archivos*/
{
    if (fclose(ptPlano)!=0) /*Cntrol de cierre*/
    {
        MessageBox(0,"Could not close file","PlainText",MB_ICONERROR);
        printf("Error en cierre de archivo.\n");
        exit(1);
    }
    if (fclose(ptCifrado)!=0) /*Cntrol de cierre*/
    {

        MessageBox(0,"Could not close file","PlainText",MB_ICONERROR);
        printf("Error en cierre de archivo.\n");
        exit(1);
    }

    system("cls");
}

char leeLetra (unsigned short dx) /*Funcion que se encarga de leer la letra metida por teclado*/
{
    char letra = '0';

    while( letra!=27 )
    {
        letra=getch();
        letra=tolower(letra);

        if(letra>96 && letra<123)
        {
            break;
        }
    }

    return letra;
}
