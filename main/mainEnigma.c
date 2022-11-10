#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include"menus.h"
#include"../Maquina/interfaz.h"

int main()
{
    system(" title Enigma Machine");
    srand((unsigned)time(NULL));
    gestionMenuPrincipal ();
    return 0;
}
