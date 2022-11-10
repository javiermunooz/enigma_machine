#include "auxiliar.h"
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <conio.h>
#include <time.h>
#include <dos.h>

void gotoxy(int x, int y) /*funcion para colocar el puntero en una parte determinada de la pantalla*/
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                             coord);
}

void setColorTexto(WORD colors) /*funci�n que cambia el color del texto*/
{
    HANDLE hConsole=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, colors);

}

void lp (char numero) /*funci�n que borra los datos de la pantalla para poder escribir*/
{


    if (numero =='2')
    {
        gotoxy(28,3);
        printf("  CONFIGURATION        ");
        gotoxy(3,7);
        printf("                                ");
        gotoxy(3,9);
        printf("                                ");
        gotoxy(3,11);
        printf("                                ");
        gotoxy(3,15);
        printf("                                ");

    }


}

void pulsetecla() /*Funcion que simula un system("pause") pero con pulse tecla*/
{
    printf("[Press key]");
    fflush(stdin);
    getch();

}

void scroll(char cadena[], int longitud) /*funcion que implementa el movimiento de una cadena a lo largo de la interfaz*/
{
    int i,a,u=38,w;

    gotoxy(3,15);
    printf("                                                  " );

    while( !kbhit() ) /*Mientras que el teclado no reciba ninguna pulsacion*/
    {
        a=u;

        for(i=0; i<longitud ; i++)
        {
            gotoxy(a,15);
            printf("%c", cadena[i]);
            gotoxy(70,15);
            a++;
        }
        Sleep(240);

        if(u==4)
        {
            for (w=0; w<3; w++)
            {

                gotoxy(4,15);
                printf("%s                                   ", cadena);
                Sleep(500);
                gotoxy(4,15);
                printf("                                                                  ");
                Sleep(500);
                gotoxy(4,15);
                printf("%s", cadena);
                gotoxy(4,15);


            }

            gotoxy(4,15);
            printf("%s", cadena);
            gotoxy(70,15);
            getch();
            return;

        }
        u--;
    }

}

unsigned short devuelvepos (char letra) /*Funcion que me devuelve la posicion de una letra en el abecedario*/
{
    char abecedario[26]="abcdefghijklmnopqrstuvwxyz";
    unsigned short i;

    for(i=0; i<26; i++)
    {
        if(letra == abecedario[i])
        {
            break;
        }
    }

    return i;

}

unsigned char getPos( char c,char cadena[]) /*Funcion que me devuelve la poscion de una letra en una cadena */
{
    unsigned char i=-1;

    for(i=0; i<26; i++)
    {
        if(c== cadena[i])
        {
            break;
        }
    }

    return i;
}

void pintaCaminito(unsigned short pos[], struct sEnigma enigma) /*Funcion que se encarga del funcionamiento general de los cables*/
{
    int i,u, x;
    int a;

    for(u=11; u<=37; u++) /*Imprime marcos verticales originales*/
    {
        gotoxy(2,u);
        printf("%c",179);

        gotoxy(6,u);
        printf("%c",179);

        gotoxy(8,u);
        printf("%c",179);

        gotoxy(14,u);
        printf("%c",179);

        gotoxy(16,u);
        printf("%c",179);

        gotoxy(22,u);
        printf("%c",179);
        gotoxy(8,u);
        printf("%c",179);

        gotoxy(24,u);
        printf("%c",179);

        gotoxy(30,u);
        printf("%c",179);

        gotoxy(32,u);
        printf("%c",179);

        gotoxy(34,u);
        printf("%c",179);

        gotoxy(36,u);
        printf("%c",179);

        gotoxy(42,u);
        printf("%c",179);

        gotoxy(47,u);
        printf("%c",179);

        gotoxy(88,u);
        printf("%c",179);

    }

    gotoxy(32,38);
    printf("%c",192);

    gotoxy(34,38);
    printf("%c",217);

    gotoxy(35,38);
    printf(" ");

    gotoxy(36,38);
    printf("%c",192);

    gotoxy(42,38);
    printf("%c",217);

    gotoxy(47,38);
    printf("%c",192);

    gotoxy(88,38);
    printf("%c",217);

    gotoxy(88,12);
    printf("%c",180);

    gotoxy(88,27);
    printf("%c",180);

    gotoxy(47,12);
    printf("%c",195);

    gotoxy(47,27);
    printf("%c",195);

    gotoxy(47,23);
    printf("%c",192);

    gotoxy(47,25);
    printf("%c",218);

    gotoxy(88,23);
    printf("%c",217);

    gotoxy(88,25);
    printf("%c",191);

    gotoxy(47, 24);
    printf(" ");

    gotoxy(88, 24);
    printf(" ");


    for(u=11; u<=37; u++) /*Borra lineas en medio de espacios en blancos*/
    {
        gotoxy(44, u);
        printf(" ");

        gotoxy(45, u);
        printf(" ");

        gotoxy(46, u);
        printf(" ");

        gotoxy(38, u);
        printf(" ");

        gotoxy(43, u);
        printf(" ");

        gotoxy(27, u);
        printf(" ");

        gotoxy(26, u);
        printf(" ");


        gotoxy(31, u);
        printf(" ");

        gotoxy(35, u);
        printf(" ");


        gotoxy(23, u);
        printf(" ");

        gotoxy(15, u);
        printf(" ");

        gotoxy(7, u);
        printf(" ");

        gotoxy(39,u);
        printf(" ");

        gotoxy(19, u);
        printf(" ");

        gotoxy(18, u);
        printf(" ");

        gotoxy(11, u);
        printf(" ");

        gotoxy(10, u);
        printf(" ");

        gotoxy(3, u);
        printf(" ");

    }


    gotoxy(65, 8);
    printf(" ");

    gotoxy(65, 10);
    printf(" ");

    gotoxy(65, 9);
    printf(" ");

    for(i=64; i>43; i--)
    {
        gotoxy(i, 9);
        printf(" ");
    }

    gotoxy(44, 9);
    printf(" ");

    gotoxy(44, 10);
    printf(" ");

    setColorTexto(252);

    /*Imprime primeras lineas hasta llegar la tabla*/

    gotoxy(65, 8);
    printf("%c",179 );

    gotoxy(65, 10);
    printf("%c",193 );

    gotoxy(65, 9);
    printf("%c",180 );

    for(i=64; i>43; i--)
    {
        gotoxy(i, 9);
        printf("%c",196 );
        Sleep(20);
    }

    gotoxy(44, 9);
    printf("%c",218);

    /*Imprime columna hasta llegar a la primera letra del stecker*/

    for(i=10; i<pos[0]+11; i++)
    {
        gotoxy(44, i);
        printf("%c", 179);
        Sleep(20);
    }

    gotoxy(44, i);
    printf("%c", 217);

    gotoxy(43, i);
    printf("%c", 196);

    gotoxy(42, i);
    printf("%c", 195);

    a= pos[0]+13;
    x=39;

    dibujointerno1(pos[0], pos[1], a,x,1, enigma.config.stecker,0,0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/

    gotoxy(36, pos[1]+11);
    printf("%c", 180);
    Sleep(20);

    gotoxy(35, pos[1]+11);
    printf("%c", 196);
    Sleep(20);

    gotoxy(34, pos[1]+11);
    printf("%c", 195);

    gotoxy(32, pos[1]+11);
    printf("%c", 180);
    Sleep(20);

    gotoxy(31, pos[1]+11);
    printf("%c", 196);
    Sleep(20);

    gotoxy(30, pos[1]+11);
    printf("%c", 195);

    x=35;

    for (u=1; u<=3; u++)
    {
        a=pos[u]+13;
        x-=8;
        dibujointerno(pos[u], pos[u+1], a, x,1, 0,enigma.listaRotores.rotor[3-u],0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/
        Sleep(20);
    }

    a= pos[u] +13;
    x-=8;

    dibujointerno1(pos[u], pos[u+1],a, x, 2,0,0,enigma.reflector.conexiones);/*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/


    setColorTexto(242);

    gotoxy(8, pos[5]+11);
    printf("%c", 180);
    Sleep(20);

    gotoxy(7, pos[5]+11);
    printf("%c", 196);
    Sleep(20);

    gotoxy(6, pos[5]+11);
    printf("%c", 195);

    x=2;

    for(u=5; u<=7; u++)
    {
        a=pos[u]+13;
        x+=8;
        dibujointerno(pos[u], pos[u+1], a, x,0,0, enigma.listaRotores.rotor[-5+u],0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/
        gotoxy(x-3, a+2);

        Sleep(20);
    }


    a= pos[8]+13;

    x=38;
    gotoxy(36, pos[8]+11);
    printf("%c", 180);
    Sleep(20);

    gotoxy(35, pos[8]+11);
    printf("%c", 196);
    Sleep(20);

    gotoxy(34, pos[8]+11);
    printf("%c", 195);

    dibujointerno1(pos[8], pos[9], a,x,0, enigma.config.stecker,0,0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/

    gotoxy(42, pos[9]+11);
    printf("%c", 195);

    gotoxy(43, pos[9]+11);
    printf("%c", 196);

    gotoxy(44, pos[9]+11);
    printf("%c", 196);

    gotoxy(45, pos[9]+11);
    printf("%c", 191);

    if(pos[9]+11>29)
    {
        gotoxy(45, pos[9]+11);
        printf("%c", 217);

        for(i=pos[9]+10; i>29; i--)
        {
            gotoxy(45, i);
            printf("%c", 179);
            Sleep(20);
        }
        gotoxy(45, 29);
        printf("%c", 218);
    }
    else if(pos[9]+11==29)
    {

        gotoxy(45, pos[9]+11);
        printf("%c", 196);
        Sleep(20);
        gotoxy(46, pos[9]+11);
        printf("%c", 196);
        Sleep(20);
    }
    else
    {
        for(i=pos[9]+12; i<29; i++)
        {
            gotoxy(45, i);
            printf("%c", 179);
            Sleep(20);
        }
        gotoxy(45, 29);
        printf("%c", 192);
    }


    gotoxy(46, 29);
    printf("%c", 196);
    Sleep(20);
    gotoxy(47, 29);
    printf("%c", 180);

    setColorTexto(249);



}

void dibujointerno (int posi, int letracif, int a, int x, int direccion, char stecker[27], struct sRotor rotor,char reflector[]) /*Funcion que se encargade de pintar los cables dentro de los rotores*/
{
    char abc[26]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(direccion==1) /*IDA*/
    {

        pintaLetra(posi,x+2, rotor.referencia);/*Llamada a la funcion pintaLetra*/
        pintaLetra(posi,x+1, rotor.cableado);/*Llamada a la funcion pintaLetra*/



        if(posi==letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 196);
            gotoxy(x-1, posi+11);
            printf("%c", 196);

            setColorTexto(207);
            pintaLetra(letracif,x-2, rotor.anillo);/*Llamada a la funcion pintaLetra*/
            setColorTexto(252);


        }
        else if(posi>letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 192);
            Sleep(10);

            for(a= posi+9 ; a>= letracif+10; a--)
            {
                gotoxy(x, a+1);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 191);
            Sleep(10);

            gotoxy(x-1, a+2);
            printf("%c", 196);
            Sleep(10);


            setColorTexto(207);
            pintaLetra(letracif,x-2, rotor.anillo);/*Llamada a la funcion pintaLetra*/
            setColorTexto(252);


            gotoxy(x-3, a+2);
            printf("%c", 180);

            gotoxy(x-4, a+2);
            printf("%c", 196);

            gotoxy(x-5, a+2);
            printf("%c", 195);




        }
        else
        {
            gotoxy(x, posi+11);
            printf("%c", 218);
            Sleep(10);

            for(a=posi+10; a<=letracif+9 ; a++)
            {

                gotoxy(x, a+2);
                printf("%c", 179);
                Sleep(10);
            }


            pintaLetra(posi,x+2, rotor.referencia);/*Llamada a la funcion pintaLetra*/
            pintaLetra(posi,x+1, rotor.cableado);/*Llamada a la funcion pintaLetra*/


            gotoxy(x, a+1);
            printf("%c", 217);
            Sleep(10);

            gotoxy(x-1, a+1);
            printf("%c", 196);
            Sleep(10);



            setColorTexto(207);
            pintaLetra(letracif,x-2, rotor.anillo);/*Llamada a la funcion pintaLetra*/
            setColorTexto(252);


            gotoxy(x-3, a+1);
            printf("%c", 180);

            gotoxy(x-4, a+1);
            printf("%c", 196);

            gotoxy(x-5, a+1);
            printf("%c", 195);



        }

    }
    else if(direccion==2) /*REFLECTOR*/
    {


        pintaLetra(posi,x+2, reflector);/*Llamada a la funcion pintaLetra*/
        pintaLetra(posi,x+1, abc);/*Llamada a la funcion pintaLetra*/


        if(posi==letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 196);
            gotoxy(x-1, posi+11);
            printf("%c", 196);
        }
        else if(posi>letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 192);
            Sleep(10);

            for(a= posi+9 ; a>= letracif+10; a--)
            {
                gotoxy(x, a+1);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 218);
            Sleep(10);
        }
        else
        {
            gotoxy(x, posi+11);
            printf("%c", 218);
            Sleep(10);

            for(a=posi+10; a<=letracif+9 ; a++)
            {

                gotoxy(x, a+2);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+1);
            printf("%c", 192);
            Sleep(10);

        }

        setColorTexto(242);
        pintaLetra(letracif,x+2, reflector);/*Llamada a la funcion pintaLetra*/
        pintaLetra(letracif,x+1, abc);/*Llamada a la funcion pintaLetra*/

    }
    else /*VUELTA*/
    {

        setColorTexto(47);

        pintaLetra(posi,x-1,rotor.anillo);/*Llamada a la funcion pintaLetra*/

        setColorTexto(242);


        if(posi==letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 196);
            Sleep(20);
            gotoxy(x+1, posi+11);
            printf("%c", 196);
            Sleep(10);


            pintaLetra(letracif,x+2, rotor.cableado);/*Llamada a la funcion pintaLetra*/
            pintaLetra(letracif,x+3, rotor.referencia);/*Llamada a la funcion pintaLetra*/

        }
        else if(posi>letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 217);
            Sleep(10);

            for(a= posi+9 ; a>= letracif+10; a--)
            {
                gotoxy(x, a+1);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 218);
            Sleep(10);

            gotoxy(x+1, a+2);
            printf("%c", 196);
            Sleep(10);



            pintaLetra(letracif,x+2, rotor.cableado); /*Llamada a la funcion pintaLetra*/
            pintaLetra(letracif,x+3, rotor.referencia);/*Llamada a la funcion pintaLetra*/


            gotoxy(x+4, a+2);
            printf("%c", 195);
            Sleep(10);

            gotoxy(x+5, a+2);
            printf("%c", 196);
            Sleep(10);

            gotoxy(x+6, a+2);
            printf("%c", 180);

        }
        else
        {
            gotoxy(x, posi+11);
            printf("%c", 191);
            Sleep(10);
            for(a= posi+9 ; a<= letracif+8; a++)
            {
                gotoxy(x, a+3);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 192);
            Sleep(10);

            gotoxy(x+1, a+2);
            printf("%c", 196);
            Sleep(10);


            pintaLetra(letracif,x+2, rotor.cableado); /*Llamada a la funcion pintaLetra*/
            pintaLetra(letracif,x+3, rotor.referencia); /*Llamada a la funcion pintaLetra*/

            gotoxy(x+4, a+2);
            printf("%c", 195);
            Sleep(10);

            gotoxy(x+5, a+2);
            printf("%c", 196);
            Sleep(10);

            gotoxy(x+6, a+2);
            printf("%c", 180);

        }
    }
}

void pintaLetra(int posi, int x, char cadena[]) /*Funcion que se encarga de pintar una letra en concreta en una cadena*/
{
    gotoxy(x,11+posi);
    printf("%c", cadena[posi]);
}

void dibujointerno1 (int posi, int letracif, int a, int x, int direccion, char stecker[27], char rotor[3][27],char reflector[]) /*Funcion que se encargade de pintar los cables dentro de los rotores*/
{
    char abc[26]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    if(direccion==1) /*IDA*/
    {
        if(rotor== 0)
        {
            pintaLetra(posi,x+2, abc);/*Llamada a la funcion pintaLetra*/
            pintaLetra(posi,x+1, stecker);/*Llamada a la funcion pintaLetra*/
        }
        if(stecker==0)
        {
            pintaLetra(posi,x+2, rotor[2]);/*Llamada a la funcion pintaLetra*/
            pintaLetra(posi,x+1, rotor[1]);/*Llamada a la funcion pintaLetra*/
        }


        if(posi==letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 196);
            gotoxy(x-1, posi+11);
            printf("%c", 196);
            if(rotor==0)
            {
                pintaLetra(posi,x-2, abc);/*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x-6, abc);/*Llamada a la funcion pintaLetra*/
            }
            if(stecker==0)
            {
                setColorTexto(207);
                pintaLetra(letracif,x-2, rotor[0]);/*Llamada a la funcion pintaLetra*/
                setColorTexto(252);
            }

        }
        else if(posi>letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 192);
            Sleep(10);

            for(a= posi+9 ; a>= letracif+10; a--)
            {
                gotoxy(x, a+1);
                printf("%c", 179);
                Sleep(10);
            }

            if(rotor== 0)
            {
                pintaLetra(posi,x+2, abc);/*Llamada a la funcion pintaLetra*/
                pintaLetra(posi,x+1, stecker);/*Llamada a la funcion pintaLetra*/
            }
            if(stecker==0)
            {
                pintaLetra(posi,x+2, rotor[2]);/*Llamada a la funcion pintaLetra*/
                pintaLetra(posi,x+1, rotor[1]);/*Llamada a la funcion pintaLetra*/
            }

            gotoxy(x, a+2);
            printf("%c", 191);
            Sleep(10);

            gotoxy(x-1, a+2);
            printf("%c", 196);
            Sleep(10);

            if(rotor== 0)
            {
                pintaLetra(letracif,x-2, abc);
            }
            if(stecker==0)
            {
                setColorTexto(207);
                pintaLetra(letracif,x-2, rotor[0]);/*Llamada a la funcion pintaLetra*/
                setColorTexto(252);
            }

            gotoxy(x-3, a+2);
            printf("%c", 180);

            gotoxy(x-4, a+2);
            printf("%c", 196);

            gotoxy(x-5, a+2);
            printf("%c", 195);

            if(rotor== 0)
            {
                pintaLetra(letracif,x-6, abc);/*Llamada a la funcion pintaLetra*/
            }


        }
        else
        {
            gotoxy(x, posi+11);
            printf("%c", 218);
            Sleep(10);

            for(a=posi+10; a<=letracif+9 ; a++)
            {

                gotoxy(x, a+2);
                printf("%c", 179);
                Sleep(10);
            }

            if(rotor== 0)
            {
                pintaLetra(posi,x+2, abc);/*Llamada a la funcion pintaLetra*/
                pintaLetra(posi,x+1, stecker);/*Llamada a la funcion pintaLetra*/
            }
            if(stecker==0)
            {
                pintaLetra(posi,x+2, rotor[2]);/*Llamada a la funcion pintaLetra*/
                pintaLetra(posi,x+1, rotor[1]);/*Llamada a la funcion pintaLetra*/
            }

            gotoxy(x, a+1);
            printf("%c", 217);
            Sleep(10);

            gotoxy(x-1, a+1);
            printf("%c", 196);
            Sleep(10);


            if(rotor== 0)
            {
                pintaLetra(letracif,x-2, abc);
            }
            if(stecker==0)
            {
                setColorTexto(207);
                pintaLetra(letracif,x-2, rotor[0]);/*Llamada a la funcion pintaLetra*/
                setColorTexto(252);
            }

            gotoxy(x-3, a+1);
            printf("%c", 180);

            gotoxy(x-4, a+1);
            printf("%c", 196);

            gotoxy(x-5, a+1);
            printf("%c", 195);

            if(rotor== 0)
            {
                pintaLetra(letracif,x-6, abc);/*Llamada a la funcion pintaLetra*/
            }


        }

    }
    else if(direccion==2) /*REFLECTOR*/
    {


        pintaLetra(posi,x+2, reflector);/*Llamada a la funcion pintaLetra*/
        pintaLetra(posi,x+1, abc);/*Llamada a la funcion pintaLetra*/


        if(posi==letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 196);
            gotoxy(x-1, posi+11);
            printf("%c", 196);
        }
        else if(posi>letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 192);
            Sleep(10);

            for(a= posi+9 ; a>= letracif+10; a--)
            {
                gotoxy(x, a+1);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 218);
            Sleep(10);
        }
        else
        {
            gotoxy(x, posi+11);
            printf("%c", 218);
            Sleep(10);

            for(a=posi+10; a<=letracif+9 ; a++)
            {

                gotoxy(x, a+2);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+1);
            printf("%c", 192);
            Sleep(10);

        }

        setColorTexto(242);
        pintaLetra(letracif,x+2, reflector);/*Llamada a la funcion pintaLetra*/
        pintaLetra(letracif,x+1, abc);/*Llamada a la funcion pintaLetra*/

    }
    else /*VUELTA*/
    {
        if(rotor== 0)
        {
            pintaLetra(posi,x-5, abc);/*Llamada a la funcion pintaLetra*/
            pintaLetra(posi,x-1, abc);/*Llamada a la funcion pintaLetra*/

        }
        if(stecker==0)
        {
            setColorTexto(47);

            pintaLetra(posi,x-1, rotor[0]);/*Llamada a la funcion pintaLetra*/

            setColorTexto(242);
        }

        if(posi==letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 196);
            Sleep(10);
            gotoxy(x+1, posi+11);
            printf("%c", 196);
            Sleep(10);

            if(rotor== 0)
            {

                pintaLetra(letracif,x+2, stecker);/*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x+3, abc);/*Llamada a la funcion pintaLetra*/
            }

            if(stecker==0)
            {
                pintaLetra(letracif,x+2, rotor[1]);/*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x+3, rotor[2]);/*Llamada a la funcion pintaLetra*/
            }
        }
        else if(posi>letracif)
        {
            gotoxy(x, posi+11);
            printf("%c", 217);
            Sleep(10);

            for(a= posi+9 ; a>= letracif+10; a--)
            {
                gotoxy(x, a+1);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 218);
            Sleep(10);

            gotoxy(x+1, a+2);
            printf("%c", 196);
            Sleep(10);

            if(rotor== 0)
            {

                pintaLetra(letracif,x+2, stecker);/*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x+3, abc);/*Llamada a la funcion pintaLetra*/
            }
            if(stecker==0)
            {
                pintaLetra(letracif,x+2, rotor[1]); /*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x+3, rotor[2]);/*Llamada a la funcion pintaLetra*/
            }

            gotoxy(x+4, a+2);
            printf("%c", 195);
            Sleep(10);

            gotoxy(x+5, a+2);
            printf("%c", 196);
            Sleep(10);

            gotoxy(x+6, a+2);
            printf("%c", 180);

        }
        else
        {
            gotoxy(x, posi+11);
            printf("%c", 191);
            Sleep(10);

            for(a= posi+9 ; a<= letracif+8; a++)
            {
                gotoxy(x, a+3);
                printf("%c", 179);
                Sleep(10);
            }

            gotoxy(x, a+2);
            printf("%c", 192);
            Sleep(10);

            gotoxy(x+1, a+2);
            printf("%c", 196);
            Sleep(10);

            if(rotor== 0)
            {

                pintaLetra(letracif,x+2, stecker); /*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x+3, abc);     /*Llamada a la funcion pintaLetra*/
            }
            if(stecker==0)
            {
                pintaLetra(letracif,x+2, rotor[1]); /*Llamada a la funcion pintaLetra*/
                pintaLetra(letracif,x+3, rotor[2]); /*Llamada a la funcion pintaLetra*/
            }

            gotoxy(x+4, a+2);
            printf("%c", 195);
            Sleep(40);

            gotoxy(x+5, a+2);
            printf("%c", 196);
            Sleep(10);

            gotoxy(x+6, a+2);
            printf("%c", 180);

        }
    }
}

void pintaCaminito1(unsigned short pos[], struct sEnigma enigma) /*Funcion que se encarga del funcionamiento general de los cables*/
{
    int i,u, x;
    int a;

    for(u=11; u<=37; u++) /*Imprime marcos verticales originales*/
    {
        gotoxy(2,u);
        printf("%c",179);

        gotoxy(6,u);
        printf("%c",179);

        gotoxy(8,u);
        printf("%c",179);

        gotoxy(14,u);
        printf("%c",179);

        gotoxy(16,u);
        printf("%c",179);

        gotoxy(22,u);
        printf("%c",179);
        gotoxy(8,u);
        printf("%c",179);

        gotoxy(24,u);
        printf("%c",179);

        gotoxy(30,u);
        printf("%c",179);

        gotoxy(32,u);
        printf("%c",179);

        gotoxy(38,u);
        printf("%c",179);

        gotoxy(40,u);
        printf("%c",179);

        gotoxy(42,u);
        printf("%c",179);

        gotoxy(44,u);
        printf("%c",179);

        gotoxy(34,u);
        printf(" ");

        gotoxy(35,u);
        printf(" ");

        gotoxy(50,u);
        printf("%c",179);

        gotoxy(59,u);
        printf("%c",179);

    }

    gotoxy(59,12);
    printf("%c",195);

    gotoxy(59,27);
    printf("%c",195);

    gotoxy(59,23);
    printf("%c",192);

    gotoxy(59,25);
    printf("%c",218);

    gotoxy(59, 24);
    printf(" ");

    gotoxy(54, 10);
    printf(" ");


    for(u=11; u<=36; u++) /*Borra lineas en medio de espacios en blancos*/
    {
        gotoxy(54, u);
        printf(" ");

        gotoxy(55, u);
        printf(" ");

        gotoxy(56, u);
        printf(" ");

        gotoxy(57,u);
        printf(" ");

        gotoxy(58, u);
        printf(" ");

        gotoxy(53, u);
        printf(" ");

        gotoxy(52, u);
        printf(" ");

        gotoxy(51, u);
        printf(" ");

        gotoxy(43, u);
        printf(" ");

        gotoxy(46, u);
        printf(" ");

        gotoxy(47, u);
        printf(" ");

        gotoxy(39, u);
        printf(" ");

        gotoxy(43, u);
        printf(" ");

        gotoxy(27, u);
        printf(" ");

        gotoxy(26, u);
        printf(" ");

        gotoxy(31, u);
        printf(" ");

        gotoxy(23, u);
        printf(" ");

        gotoxy(15, u);
        printf(" ");

        gotoxy(7, u);
        printf(" ");

        gotoxy(39,u);
        printf(" ");

        gotoxy(19, u);
        printf(" ");

        gotoxy(18, u);
        printf(" ");

        gotoxy(11, u);
        printf(" ");

        gotoxy(10, u);
        printf(" ");

        gotoxy(3, u);
        printf(" ");

    }

    gotoxy(76, 8);
    printf(" ");

    gotoxy(76, 10);
    printf("%c", 196 );

    gotoxy(76, 9);
    printf(" " );

    for(i=75; i>53; i--)
    {
        gotoxy(i, 9);
        printf(" " );

    }

    gotoxy(54, 9);
    printf(" ");

    /*Imprime primeras lineas hasta llegar la tabla*/

    setColorTexto(252);

    gotoxy(76, 8);
    printf("%c",179 );

    gotoxy(76, 10);
    printf("%c",193 );

    gotoxy(76, 9);
    printf("%c",180 );

    for(i=75; i>53; i--)
    {
        gotoxy(i, 9);
        printf("%c",196 );
        Sleep(10);
    }

    gotoxy(54, 9);
    printf("%c",218);

    /*Imprime columna hasta llegar a la primera letra del stecker*/

    for(i=10; i<pos[0]+11; i++)
    {
        gotoxy(54, i);
        printf("%c", 179);
        Sleep(10);
    }

    gotoxy(54, i);
    printf("%c", 217);

    gotoxy(53, i);
    printf("%c", 196);

    gotoxy(52, i);
    printf("%c", 196);

    gotoxy(51, i);
    printf("%c", 196);

    gotoxy(50, i);
    printf("%c", 195);

    a= pos[0]+13;
    x=47;

    dibujointerno1(pos[0], pos[1], a,x,1, enigma.config.stecker,0,0);

    gotoxy(40, pos[1]+11);
    printf("%c", 180);
    Sleep(10);

    gotoxy(39, pos[1]+11);
    printf("%c", 196);
    Sleep(10);

    gotoxy(38, pos[1]+11);
    printf("%c", 195);

    x=43;

    for (u=1; u<=4; u++)
    {
        a=pos[u]+13;
        x-=8;
        dibujointerno(pos[u], pos[u+1], a, x,1, 0, enigma.listaRotores.rotor[4-u],0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/
        Sleep(10);
    }

    a= pos[u] +13;
    x-=8;

    dibujointerno1(pos[u], pos[u+1],a, x, 2,0,0,enigma.reflector.conexiones);/*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/

    setColorTexto(242);

    gotoxy(8, pos[6]+11);
    printf("%c", 180);
    Sleep(10);

    gotoxy(7, pos[6]+11);
    printf("%c", 196);
    Sleep(10);

    gotoxy(6, pos[6]+11);
    printf("%c", 195);

    x=2;

    for(u=6; u<=9; u++)
    {
        a=pos[u]+13;
        x+=8;
        dibujointerno(pos[u], pos[u+1], a, x,0,0, enigma.listaRotores.rotor[-6+u],0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/
        gotoxy(x-3, a+2);

        Sleep(10);
    }

    a= pos[8]+13;

    x=46;

    gotoxy(43, pos[10]+11);
    printf("%c", 196);
    Sleep(10);

    gotoxy(42, pos[10]+11);
    printf("%c", 195);

    gotoxy(44, pos[9]+11);
    printf("%c", 180);
    Sleep(10);

    dibujointerno1(pos[10], pos[11], a,x,0, enigma.config.stecker,0,0); /*Llamada a la funcion que pinta internamente el cable dentro de los rotores*/

    gotoxy(50, pos[11]+11);
    printf("%c", 195);

    gotoxy(51, pos[11]+11);
    printf("%c", 196);

    gotoxy(52, pos[11]+11);
    printf("%c", 196);

    gotoxy(53, pos[11]+11);
    printf("%c", 191);

    if(pos[11]+11>29)
    {
        gotoxy(53, pos[11]+11);
        printf("%c", 217);

        for(i=pos[11]+10; i>29; i--)
        {
            gotoxy(53, i);
            printf("%c", 179);
            Sleep(10);
        }
        gotoxy(53, 29);
        printf("%c", 218);
    }
    else if(pos[11]+11==29)
    {

        gotoxy(53, pos[11]+11);
        printf("%c", 196);
        Sleep(10);
        gotoxy(53, pos[11]+11);
        printf("%c", 196);
        Sleep(10);
    }
    else
    {
        for(i=pos[11]+12; i<29; i++)
        {
            gotoxy(53, i);
            printf("%c", 179);
            Sleep(10);
        }
        gotoxy(53, 29);
        printf("%c", 192);
    }


    gotoxy(54, 29);
    printf("%c", 196);
    Sleep(10);
    gotoxy(55, 29);
    printf("%c", 196);
    Sleep(10);
    gotoxy(56, 29);
    printf("%c", 196);
    Sleep(10);
    gotoxy(57, 29);
    printf("%c", 196);
    Sleep(10);
    gotoxy(58, 29);
    printf("%c", 196);
    Sleep(10);
    gotoxy(59, 29);
    printf("%c", 180);

    setColorTexto(249);

}
