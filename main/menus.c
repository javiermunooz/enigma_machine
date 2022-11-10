#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include"menus.h"
#include"../Maquina/interfaz.h"
#include"../auxiliar/auxiliar.h"
#include"../LibroClaves/libroClaves.h"
#include"../Config/config.h"
#include"../Maquina/cifrado.h"
#include"../Config/listaConfig.h"

void gestionMenuPrincipal(void) /*Gestiona las diferentes opciones del menu*/
{
    char opcion;
    int i;
    system("color F4");

    system("mode con cols=73 lines=21");

    gotoxy(1,1);
    printf("%c", 201);

    gotoxy(1,17);
    printf("%c", 200);

    gotoxy(71,1);
    printf("%c", 187);

    gotoxy(71,17);
    printf("%c", 188);

    for (i= 2; i<= 70; i++)
    {
        gotoxy(i,1);
        printf("%c",205);
        gotoxy(i,17);
        printf("%c",205);
        gotoxy(i,5);
        printf("%c",205);
        gotoxy(i,13);
        printf("%c",205);
    }

    for (i=2; i<=16; i++)
    {
        gotoxy(1,i);
        printf("%c",186);
        gotoxy(71,i);
        printf("%c",186);
    }

    gotoxy(1,5);
    printf("%c", 204);

    gotoxy(71,5);
    printf("%c", 185);

    gotoxy(1,13);
    printf("%c", 204);

    gotoxy(71,13);
    printf("%c", 185);



    while (1)
    {
        opcion = menuPrincipal(); /*Muestra las opciones del menu principal*/

        switch(opcion)
        {
        case '1':
            inicCifrado(); /*Llama a la funcion inicCifrado*/
            break;

        case '2':

            generaLibroClaves(); /*llama a la funcion generalibroclaves*/
            break;
        case '3':
            rotorInservible();
            break;

        case '0':
            gotoxy(0,17);
            system("cls");
            return;  /*Finaliza el programa*/
        }
    }
}


char menuPrincipal(void) /*Recoge la opcion elegida por el usuario*/
{
    char opcion;
    int i;
    setColorTexto(249);
    setlocale(LC_CTYPE, "Default");



    system("mode con cols=73 lines=20");

    gotoxy(1,1);
    printf("%c", 201);

    gotoxy(1,17);
    printf("%c", 200);

    gotoxy(71,1);
    printf("%c", 187);

    gotoxy(71,17);
    printf("%c", 188);

    for (i= 2; i<= 70; i++)
    {
        gotoxy(i,1);
        printf("%c",205);
        gotoxy(i,17);
        printf("%c",205);
        gotoxy(i,5);
        printf("%c",205);
        gotoxy(i,13);
        printf("%c",205);
    }

    for (i=2; i<=16; i++)
    {
        gotoxy(1,i);
        printf("%c",186);
        gotoxy(71,i);
        printf("%c",186);
    }

    gotoxy(1,5);
    printf("%c", 204);

    gotoxy(71,5);
    printf("%c", 185);

    gotoxy(1,13);
    printf("%c", 204);

    gotoxy(71,13);
    printf("%c", 185);


    gotoxy(28,3);
    printf("MAIN MENU");
    gotoxy(3,6);
    printf("1.-Cipher/Decipher a message.");
    gotoxy(3,8);
    printf("2.-Generate keys.");
    gotoxy(3,10);
    printf("3.-Delete rotors.");
    gotoxy(3,12);
    printf("0.-Quit.");
    gotoxy(3,15);
    printf("Select an option: ");

    do
    {
        fflush(stdin);
        opcion = getch();
    }
    while(opcion !='1' && opcion !='2' && opcion!='0' && opcion!='3'); /*Requerimiento de la opcion en el menu principal*/

    return opcion;
}
