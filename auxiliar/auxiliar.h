#ifndef AU5ILIARES_H_INCLUDED
#define AUXILIARES_H_INCLUDED       /* Funciones auxiliares para todo el programa*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include<wincon.h>
#include "../Maquina/Enigma.h"
#include "../Maquina/rotores.h"

void gotoxy(int x, int y);
void setColorTexto(WORD colors);
void lp(char numero);
void pulsetecla();
void scroll(char cadena[], int longitud);
unsigned short devuelvepos (char letra);
unsigned char getPos (char c,char cadena[]);
void pintaCaminito(unsigned short pos[], struct sEnigma enigma);
void pintaCaminito1(unsigned short pos[], struct sEnigma enigma);
void dibujointerno (int posi, int letracif, int a, int x, int direccion, char stecker[27], struct sRotor rotor,char reflector[]);
void dibujointerno1 (int posi, int letracif, int a, int x, int direccion, char stecker[27], char rotor[3][27],char reflector[]);
void pintaLetra(int posi, int x, char cadena[]);

#endif
