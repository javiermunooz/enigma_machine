#ifndef REFLECTOR_H_INCLUDED
#define REFLECTOR_H_INCLUDED

struct sReflector
{
    char 	conexiones [27];
    char 	modelo;

};
void 	leeCfgReflector (char archivo[], struct sReflector *pRef);

unsigned short 	opReflector (unsigned short in, struct sReflector reflector);

void 	dibujaReflector (struct sReflector reflector);

#endif
