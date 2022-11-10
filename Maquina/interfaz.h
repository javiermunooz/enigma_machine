#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED   /*Incluye los prototipos de interfaz.c*/

void 	dibujaInterfazM3 (void);

void 	dibujaInterfazM4 (void);

/*void 	muestraEsquema (char stecker[], char rotor[][3][27], int coordRotor[][2], unsigned short walzen[], char reflector[], char muesca[][3]);*/

/*void 	dibujaEstator (void);*/

unsigned short 	printLetraPlana (char letra, FILE *ptPlano,unsigned short num);

void 	printLetraCifrada (char letra, FILE *ptCifrado, unsigned short num);

#endif
