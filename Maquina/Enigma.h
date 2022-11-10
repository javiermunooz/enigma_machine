#ifndef ENIGMA_H_INCLUDED
#define ENIGMA_H_INCLUDED

#include "rotores.h"
#include "reflector.h"
#include "../auxiliar/punto.h"
struct sEnigma
{
    struct sConfig 	config;
    struct sListaRotores listaRotores;
    struct sReflector 	reflector;

};

void 	configuracion (struct sEnigma *pEnigma);

void 	muestraEsquema (struct sEnigma enigma, struct sPunto coordRotor[]);


#endif
