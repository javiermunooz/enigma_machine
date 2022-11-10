#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <dos.h>
#include"rotores.h"
#include "Enigma.h"
#include "../Config/config.h"
#include "../auxiliar/auxiliar.h"
#include "stecker.h"

void configuracion 	(struct sEnigma *pEnigma)
{
    int u;

    pEnigma->listaRotores.num=pEnigma->config.numRotores;   /*Aisgnacion del numero de rotores correspondiente al campo de la lista*/

    pEnigma->listaRotores.rotor=malloc(pEnigma->config.numRotores * sizeof(struct sRotor)); /*reserva dinamica el vector de rotres de 3 o 4 de tama�o */

    leeConfig(&pEnigma->config);     /*Llamada a la funcion c leecofing*/

    muestraConfig(pEnigma->config);  /*Llamada a la funcion  muestraConfig*/

    pEnigma->listaRotores.rotor[0].num= pEnigma->config.walzen[0];
    pEnigma->listaRotores.rotor[1].num= pEnigma->config.walzen[1];
    pEnigma->listaRotores.rotor[2].num= pEnigma->config.walzen[2];
    pEnigma->listaRotores.rotor[3].num= pEnigma->config.walzen[3];


    gotoxy(3,15);
    scroll("PRESS ANY KEY TO CONTINUE",32);

    for(u=0; u<pEnigma->listaRotores.num; u++)
    {
       leeCfgRotor(&pEnigma->listaRotores.rotor[u]); /*Llamada a la fiuncon leeCfgRotor*/
    }

    leeCfgReflector("BASEDATOS/reflector.cfg", &pEnigma->reflector); /*Llamada a la fiuncon leeCfgReflector*/

}

void muestraEsquema (struct sEnigma enigma,struct sPunto coordRotor[]) /*muestra la configuracion actual de la maquina*/
{
    int i;

    if(enigma.listaRotores.num==3)
    {
        dibujaStecker(enigma.config.stecker,0); /*Llamada a la funcion dibujastecker*/
        dibujaEstator(0);
        dibujaReflector(enigma.reflector);/*Llamada a la funcion dibujareflector*/

        for (i=0; i<3; i ++)
        {
            dibujaRotor(enigma.listaRotores.rotor[i], coordRotor[i]);/*Llamada a la funcion dibujasrotor*/
        }
    }
    if(enigma.listaRotores.num==4)
    {
        dibujaStecker(enigma.config.stecker,8); /*Llamada a la funcion dibujastecker*/
        dibujaEstator(+8);           /*Llamada a la funcion dibujaestator*/
        dibujaReflector(enigma.reflector);/*Llamada a la funcion dibujareflector*/

        for (i=0; i<4; i ++)
        {
            dibujaRotor(enigma.listaRotores.rotor[i],coordRotor[i]);/*Llamada a la funcion dibujasrotor*/
        }
    }

}
