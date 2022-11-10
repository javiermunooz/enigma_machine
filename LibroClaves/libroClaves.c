#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include"libroClaves.h"
#include "conio.h"
#include"../auxiliar/auxiliar.h"
#include"../Maquina/rotores.h"
#include "../Config/config.h"
#include"../Maquina/stecker.h"

void generaLibroClaves(void) /*Funcion que genera el libro de claves*/
{

    struct sConfig configuracio1;
    int i,tag = 31;

    FILE *pLbr;
    FILE *pLbb;

    selecModelo(&configuracio1);

    switch(configuracio1.numRotores)
    {
    case 3:

        if(configuracio1.modeloETW =='B')
        {
            pLbr = fopen("BASEDATOS/libro_M3_B.txt", "wt");
            pLbb = fopen("BASEDATOS/libro_M3_B.bin", "wb");
        }
        else
        {
            pLbr = fopen("BASEDATOS/libro_M3_C.txt", "wt");
            pLbb = fopen("BASEDATOS/libro_M3_C.bin", "wb");
        }
        break;
    case 4:
        if(configuracio1.modeloETW=='B')
        {
            pLbr = fopen("BASEDATOS/libro_M4_B.txt", "wt");
            pLbb = fopen("BASEDATOS/libro_M4_B.bin", "wb");
        }
        else
        {
            pLbr = fopen("BASEDATOS/libro_M4_C.txt", "wt");
            pLbb = fopen("BASEDATOS/libro_M4_C.bin", "wb");
        }
        break;

    default:
        printf("ERROR EN LA APLICACION");
        break;
    }

    if(configuracio1.numRotores==4)
    {
        fprintf(pLbr, "GEHEIM!                          SS SONDER-PROJEKT ABTEILUNG             NOVEMBER 1941  \n");
        fprintf(pLbr,"---------------------------------------------------------------------------------------------------\n");
        fprintf(pLbr, "|Tag |     Walzenlage      | Ringstellung  |      Steckerverbindungen       |    Grundstellung     |\n");
        fprintf(pLbr,"---------------------------------------------------------------------------------------------------\n");
    }
    else
    {
        fprintf(pLbr, "GEHEIM!                          SS SONDER-PROJEKT ABTEILUNG             NOVEMBER 1941  \n");
        fprintf(pLbr,"-----------------------------------------------------------------------------------------\n");
        fprintf(pLbr, "|Tag |  Walzenlage   |Ringstellung|      Steckerverbindungen       |     Grundstellung  |\n");
        fprintf(pLbr,"-----------------------------------------------------------------------------------------\n");

    }


    for (i=0; i<31; i++) /*Bucle que repite las llamadas 30 veces*/
    {

        genWalzenlage(configuracio1.numRotores,configuracio1.walzen);                 /*Llamada a la funcion genwalzenlage*/
        genRingstellung(configuracio1.numRotores, configuracio1.ringS);                 /*Llamada a la funcion genringstellung*/
        genStecker(configuracio1.stecker);                                         /*Llamada a la funcion genstecker*/
        genGrundstellung(configuracio1.numRotores, configuracio1.grund);
        fprintf(pLbr,"| %2.d |", tag);
        fprintWalzenlage(configuracio1.numRotores,configuracio1.walzen,pLbr);          /*Llamada a la funcion fprintwalzenlage*/
        fprintRingstellung(configuracio1.numRotores,configuracio1.ringS,pLbr);           /*Llamada a la funcion fprintringstellung*/
        fprintStecker(configuracio1.stecker,pLbr);                                    /*Llamada a la funcion fprintstecker*/
        fprintGrundstellung(configuracio1.numRotores,configuracio1.grund,pLbr);          /*Llamada a la funcion fprintGrundstellung*/

        configuracio1.dia=tag;

        fwrite(&configuracio1, sizeof(struct sConfig), 1, pLbb);

        tag--;
    }

    if(configuracio1.numRotores==4)
    {
        fprintf(pLbr,"---------------------------------------------------------------------------------------------------\n");

    }
    else
    {
        fprintf(pLbr,"-----------------------------------------------------------------------------------------\n");

    }

    fclose(pLbr);
    fclose(pLbb);

}


