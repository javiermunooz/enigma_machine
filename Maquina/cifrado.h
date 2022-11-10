#ifndef CIFRADO_H_INCLUDED
#define CIFRADO_H_INCLUDED
#include "Enigma.h"

void inicCifrado (void);

void abreArchivosMensaje (FILE **ptPlano, FILE **ptCifrado);

void cierraArchivosMensaje (FILE *ptPlano, FILE *ptCifrado);

void procesoCifrado (struct sEnigma enigma);

char leeLetra (unsigned short dx);

#endif
