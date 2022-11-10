#ifndef STECKER_H_INCLUDED
#define STECKER_H_INCLUDED

void 	fprintStecker (char stecker[], FILE *pLbr);

void genStecker(char conexiones[]);

void 	dibujaStecker (char stecker[], unsigned short dx);

unsigned short 	opStecker (unsigned short posIn, char stecker[]);

void 	dibujaEstator (unsigned short dx);

#endif
