#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include "config.h"
#include "listaConfig.h"
#include "../auxiliar/auxiliar.h"

void rotorInservible(void)
{
    struct sListaConfig listaconfig;
    int rotor;


    gotoxy(3,15);
    printf("Introduce el rotor averiado:");
    scanf("%d",&rotor);

    system("cls");

    muestralibroClaves("BASEDATOS/libro_M4_B.bin", &listaconfig);

    filtraConfiguraciones(listaconfig,rotor);

    muestralibroClaves("BASEDATOS/libro_M4_B.bin", &listaconfig);

    muestralibroClaves("BASEDATOS/eliminados.bin", &listaconfig);

    free(listaconfig.conf);

}

void muestralibroClaves(char nombre[], struct sListaConfig *listaconfig)
{
    FILE*ptr;
    int i, u;

    ptr=fopen(nombre, "rb");

    fseek(ptr,0,SEEK_END);

    listaconfig->numero=ftell(ptr)/sizeof(struct sConfig);

    listaconfig->conf=malloc(listaconfig->numero*sizeof(struct sConfig));

    fseek(ptr,0,SEEK_SET);

    fread(&listaconfig->conf[0],sizeof(struct sConfig),listaconfig->numero,ptr);

    fclose (ptr);

    for(i=0; i<=listaconfig->numero-1; i++)
    {
        printf("%d ", listaconfig->conf[i].dia);

        for(u=0; u<=3; u++)
        {
            printf("%hu ", listaconfig->conf[i].walzen[u]);
        }
        for(u=0; u<=3; u++)
        {
            printf("%hu ", listaconfig->conf[i].ringS[u]);
        }
        printf("%s ", listaconfig->conf[i].stecker);

        for(u=0; u<=3; u++)
        {
            printf("%c ", listaconfig->conf[i].grund[u]);
        }
        printf("\n");
    }

    system("pause");
}

void filtraConfiguraciones (struct sListaConfig listaconfig, int rotor)
{
    int i,u;
    FILE*ptr;
    FILE*pLbb;

    ptr= fopen("BASEDATOS/eliminados.bin", "wb");
    pLbb=fopen("BASEDATOS/libro_M4_B.bin", "wb");

    for (i=0; i<=listaconfig.numero-1; i++)
    {
        if (rotor== listaconfig.conf[i].walzen[0] ||rotor== listaconfig.conf[i].walzen[1] ||rotor== listaconfig.conf[i].walzen[2] || rotor== listaconfig.conf[i].walzen[3])
        {
            fwrite(&listaconfig.conf[i], sizeof(struct sConfig), 1, ptr);

            printf("%d ", listaconfig.conf[i].dia);

            for(u=0; u<=3; u++)
            {
                printf("%hu ", listaconfig.conf[i].walzen[u]);
            }

            printf("No valido\n");

        }
        else
        {
            fwrite(&listaconfig.conf[i], sizeof(struct sConfig), 1, pLbb);

            printf("%d ", listaconfig.conf[i].dia);

            for(u=0; u<=3; u++)
            {
                printf("%hu ", listaconfig.conf[i].walzen[u]);
            }

            printf("Valido\n");

        }
    }
    fclose(ptr);
    fclose(pLbb);
    system("pause");
}
