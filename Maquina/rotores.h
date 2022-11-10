#ifndef ROTORES_H_INCLUDED
#define ROTORES_H_INCLUDED
#include <stdbool.h>
#include "../auxiliar/punto.h"
#include "../Config/config.h"
#include <stdio.h>
struct sListaRotores
{
    unsigned short 	num;
    struct sRotor * 	rotor;
};

struct sRotor
{
    char 	anillo [27];
    char 	cableado [27];
    char 	muesca [3];
    unsigned short 	num;
    char 	referencia [27];
};

void 	avanzaRotores (struct sListaRotores *pListaRotores);

void configRotores (struct sListaRotores *lista, struct sConfig config);

void configAnillos (struct sRotor *pRotor, int pos);

void pasoRotor (struct sRotor *pRotor, int num);

void genWalzenlage(int nrotor,	unsigned short walzen[]) ;

void fprintWalzenlage (int nRotores, unsigned short walzen[], FILE *pLbr) ;

void fprintRingstellung (int nrotor, unsigned short ring[], FILE *pLbr);

void genRingstellung(int nrotor, unsigned short ring[]);

void fprintGrundstellung (int nRotores, char grund[], FILE *pLbr);

void genGrundstellung (int nrotor, char grund[]);

void leeCfgRotor (struct sRotor *pRotor);

void dibujaRotor (struct sRotor rotor, struct sPunto coordRotor);

unsigned short 	opRotor (unsigned short in, struct sRotor rotor, bool dir);

#endif
