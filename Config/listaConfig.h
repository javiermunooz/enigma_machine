#ifndef LISTACONFIG_H_INCLUDED /* Declaracion de funciones contenidas en libroclaves*/
#define LISTACONFIG_H_INCLUDED

struct sListaConfig
{
    int numero;

    struct sConfig *conf;
};

void rotorInservible(void);

void muestralibroClaves(char nombre[], struct sListaConfig *listaconfig);

void filtraConfiguraciones (struct sListaConfig listaconfig, int rotor);


#endif
