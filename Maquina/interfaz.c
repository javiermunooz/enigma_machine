#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#include"../auxiliar/auxiliar.h"
#include"interfaz.h"
#include "stecker.h"
#include"reflector.h"
#include"rotores.h"


void dibujaInterfazM3(void) /*Dibuja la interfaz de la maquina engima*/
{
    int i,u;

    system("mode con cols=91 lines=46"); /*definicion del tama�o de la consola*/

    for (i=1; i<=90 ; i++)
    {
        gotoxy(i,0);
        printf("%c",205);
        gotoxy(i,4);
        printf("%c",205);
        gotoxy(i,44);
        printf("%c",205);
    }

    for(i=1; i<45; i++ )
    {
        gotoxy(0,i);
        printf("%c",186);

        gotoxy(90,i);
        printf("%c",186);
    }

    gotoxy(0,0);
    printf("%c",201);

    gotoxy(0,44);
    printf("%c",200);

    gotoxy(90,44);
    printf("%c",188);

    gotoxy(90,0);
    printf("%c",187);

    gotoxy(0,4);
    printf("%c",204);

    gotoxy(90,4);
    printf("%c",185);


    for (u=2; u<=42; u++)
    {
        gotoxy(u,10);
        printf("%c",196);

        gotoxy(u+46, 10);
        printf("%c",196);

        gotoxy(u,38);
        printf("%c",196);

        gotoxy(u+46, 10);
        printf("%c",196);

        gotoxy(u+46, 38);
        printf("%c",196);

        gotoxy(u+46, 12);
        printf("%c",196);

        gotoxy(u+46, 27);
        printf("%c",196);

        gotoxy(u+46, 23);
        printf("%c",196);

        gotoxy(u+46, 25);
        printf("%c",196);

    }

    gotoxy(2,10);
    printf("%c",218);

    gotoxy(6,10);
    printf("%c",191);

    gotoxy(7,10);
    printf(" ");

    for (u=8; u<25; u= u+ 8)
    {
        gotoxy(u,10);
        printf("%c",218);

        gotoxy(u+6,10);
        printf("%c",191);

        gotoxy(u+7,10);
        printf(" ");

    }


    gotoxy(32,10);
    printf("%c",218);

    gotoxy(34,10);
    printf("%c",191);

    gotoxy(35,10);
    printf(" ");

    gotoxy(36,10);
    printf("%c",218);

    gotoxy(42,10);
    printf("%c",191);

    gotoxy(47,10);
    printf("%c",218);

    gotoxy(88,10);
    printf("%c",191);


    for(u=11; u<=38; u++)
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

    gotoxy(2,38);
    printf("%c",192);

    gotoxy(6,38);
    printf("%c",217);

    gotoxy(7,38);
    printf(" ");

    for (u=8; u<25; u= u+ 8)
    {
        gotoxy(u,38);
        printf("%c",192);

        gotoxy(u+6,38);
        printf("%c",217);

        gotoxy(u+7,38);
        printf(" ");

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

    setlocale(LC_CTYPE, "English");
    gotoxy(37,2);
    printf("Enigma Machine");
    setlocale(LC_CTYPE, "C");

    gotoxy(4,6);
    printf("U");

    gotoxy(4,7);
    printf("K");

    gotoxy(4,8);
    printf("W");

    gotoxy(33,6);
    printf("E");

    gotoxy(33,7);
    printf("T");

    gotoxy(33,8);
    printf("W");

    gotoxy(38,6);
    printf("S");

    gotoxy(38,7);
    printf("C");

    gotoxy(38,8);
    printf("E");

    gotoxy(39,6);
    printf("T");

    gotoxy(39,7);
    printf("K");

    gotoxy(39,8);
    printf("R");


    gotoxy(62,11);
    printf("Plain text");

    gotoxy(62,26);
    printf("Ciphered text");

    gotoxy(48,7);
    printf("Enter character:");

    gotoxy(73,7);
    printf("[ESC >> >> end]");
}

void dibujaInterfazM4(void)
{
    int i,u;

    system("mode con cols=104 lines=46");

    for (i=1; i<=103 ; i++)
    {
        gotoxy(i,0);
        printf("%c",205);
        gotoxy(i,4);
        printf("%c",205);
        gotoxy(i,44);
        printf("%c",205);
    }

    for(i=1; i<45; i++ )
    {
        gotoxy(0,i);
        printf("%c",186);

        gotoxy(103,i);
        printf("%c",186);
    }

    gotoxy(0,0);
    printf("%c",201);

    gotoxy(0,44);
    printf("%c",200);

    gotoxy(103,44);
    printf("%c",188);

    gotoxy(103,0);
    printf("%c",187);

    gotoxy(0,4);
    printf("%c",204);

    gotoxy(103,4);
    printf("%c",185);


    for (u=2; u<=42; u++)
    {
        gotoxy(u,10);
        printf("%c",196);

        gotoxy(u+8,10);
        printf("%c",196);

        gotoxy(u+58, 10);
        printf("%c",196);

        gotoxy(u,38);
        printf("%c",196);

        gotoxy(u+8,38);
        printf("%c",196);

        gotoxy(u+58, 10);
        printf("%c",196);

        gotoxy(u+58, 38);
        printf("%c",196);

        gotoxy(u+58, 12);
        printf("%c",196);

        gotoxy(u+58, 27);
        printf("%c",196);

        gotoxy(u+58, 23);
        printf("%c",196);

        gotoxy(u+58, 25);
        printf("%c",196);

    }

    gotoxy(2,10);
    printf("%c",218);

    gotoxy(6,10);
    printf("%c",191);

    gotoxy(7,10);
    printf(" ");

    for (u=8; u<25; u= u+ 8)
    {
        gotoxy(u,10);
        printf("%c",218);

        gotoxy(u+6,10);
        printf("%c",191);

        gotoxy(u+7,10);
        printf(" ");


    }


    gotoxy(32,10);
    printf("%c",218);

    gotoxy(38,10);
    printf("%c",191);

    gotoxy(39,10);
    printf(" ");

    gotoxy(40,10);
    printf("%c",218);

    gotoxy(42,10);
    printf("%c",191);

    gotoxy(43,10);
    printf(" ");

    gotoxy(44,10);
    printf("%c",218);

    gotoxy(50,10);
    printf("%c",191);

    gotoxy(59,10);
    printf("%c",218);

    gotoxy(100,10);
    printf("%c",191);


    for(u=11; u<=38; u++)
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

        gotoxy(50,u);
        printf("%c",179);

        gotoxy(59,u);
        printf("%c",179);

        gotoxy(100,u);
        printf("%c",179);

    }

    gotoxy(2,38);
    printf("%c",192);

    gotoxy(6,38);
    printf("%c",217);

    gotoxy(7,38);
    printf(" ");

    for (u=8; u<25; u= u+ 8)
    {
        gotoxy(u,38);
        printf("%c",192);

        gotoxy(u+6,38);
        printf("%c",217);

        gotoxy(u+7,38);
        printf(" ");

    }


    gotoxy(32,38);
    printf("%c",192);

    gotoxy(38,38);
    printf("%c",217);

    gotoxy(39,38);
    printf(" ");

    gotoxy(40,38);
    printf("%c",192);

    gotoxy(42,38);
    printf("%c",217);

    gotoxy(43,38);
    printf(" ");

    gotoxy(44,38);
    printf("%c",192);

    gotoxy(50,38);
    printf("%c",217);

    gotoxy(59,38);
    printf("%c",192);

    gotoxy(100,38);
    printf("%c",217);

    gotoxy(100,12);
    printf("%c",180);

    gotoxy(100,27);
    printf("%c",180);

    gotoxy(59,12);
    printf("%c",195);

    gotoxy(59,27);
    printf("%c",195);

    gotoxy(59,23);
    printf("%c",192);

    gotoxy(59,25);
    printf("%c",218);

    gotoxy(100,23);
    printf("%c",217);

    gotoxy(100,25);
    printf("%c",191);


    gotoxy(59, 24);
    printf(" ");

    gotoxy(100, 24);
    printf(" ");

    setlocale(LC_CTYPE, "English");
    gotoxy(45,2);
    printf("Enigma Machine");
    setlocale(LC_CTYPE, "C");

    gotoxy(4,6);
    printf("U");

    gotoxy(4,7);
    printf("K");

    gotoxy(4,8);
    printf("W");

    gotoxy(41,6);
    printf("E");

    gotoxy(41,7);
    printf("T");

    gotoxy(41,8);
    printf("W");

    gotoxy(46,6);
    printf("S");

    gotoxy(46,7);
    printf("C");

    gotoxy(46,8);
    printf("E");

    gotoxy(47,6);
    printf("T");

    gotoxy(47,7);
    printf("K");

    gotoxy(47,8);
    printf("R");


    gotoxy(74,11);
    printf("Plain text");

    gotoxy(74,26);
    printf("Ciphered text");

    gotoxy(60,7);
    printf("Enter character:");

    gotoxy(81,7);
    printf("[ESC >> >> end]");
}

void 	printLetraCifrada (char letra, FILE *ptCifrado, unsigned short num) /* Muestra la letra que recibe como par�metro en la ventana "Texto cifrado" de la interfaz. Escribe la letra que recibe como par�metro en el archivo de texto para el texto cifrado.*/
{
    static int contador = 0;
    int size;

    size = ftell(ptCifrado);

    if(num==3) /*Complicado algortimo que se encargar de imprimirme correctamente la letra en la version de tres rotores*/
    {
        if(size==0)
        {
            contador=0;
        }


        letra = toupper(letra);

        if(contador%25==0 && contador!=0)
        {
            gotoxy(51+ contador-30*(contador/25)+ (contador/5),(contador/25)+28);
            printf("%c", letra);
            gotoxy(51+ contador-30*(contador/25)+(contador/5),(contador/25)+28);

        }
        else if(contador%5==0 &&contador!=0)
        {
            gotoxy(51+ contador-30*(contador/25)+(contador/5), (contador/25)+28);
            printf("%c", letra);
        }
        else
        {
            gotoxy(51+ contador-30*(contador/25)+(contador/5), (contador/25)+28);
            printf("%c", letra);
        }

        if((contador+1)%25==0 && (contador+1)!=0)
        {
            fprintf(ptCifrado, "%c", letra);
            fprintf(ptCifrado, "\n");

        }
        else if((contador+1)%5==0 && (contador+1)!=0)
        {
            fprintf(ptCifrado, "%c", letra);
            fprintf(ptCifrado, " ");
        }
        else
        {
            fprintf(ptCifrado, "%c", letra);
        }

        contador ++;
    }
    else /*Complicado algortimo que se encargar de imprimirme correctamente la letra en la version de cuatro rotores*/
    {
        if(size==0)
        {
            contador=0;
        }


        letra = toupper(letra);

        if(contador%25==0 && contador!=0)
        {
            gotoxy(65+ contador-30*(contador/25)+ (contador/5),(contador/25)+28);
            printf("%c", letra);
            gotoxy(65+ contador-30*(contador/25)+(contador/5),(contador/25)+28);

        }
        else if(contador%5==0 &&contador!=0)
        {
            gotoxy(65+ contador-30*(contador/25)+(contador/5), (contador/25)+28);
            printf("%c", letra);
        }
        else
        {
            gotoxy(65+ contador-30*(contador/25)+(contador/5), (contador/25)+28);
            printf("%c", letra);
        }

        if((contador+1)%25==0 && (contador+1)!=0)
        {
            fprintf(ptCifrado, "%c", letra);
            fprintf(ptCifrado, "\n");

        }
        else if((contador+1)%5==0 && (contador+1)!=0)
        {
            fprintf(ptCifrado, "%c", letra);
            fprintf(ptCifrado, " ");
        }
        else
        {
            fprintf(ptCifrado, "%c", letra);
        }

        contador ++;
    }

}

unsigned short 	printLetraPlana (char letra, FILE *ptPlano, unsigned short num) /* Muestra la letra que recibe como par�metro en la ventana "Texto plano" de la interfaz.Escribe la letra que recibe como par�metro en el archivo de texto para el texto plano.*/
{
    static int contador = 0;
    int size;

    size = ftell(ptPlano);

    if(num==3) /*Complicado algortimo que se encargar de imprimirme correctamente la letra en la version de tres rotores*/
    {
        if(size==0)
        {
            contador=0;
        }

        letra = toupper(letra);

        if(contador==250)
        {
            MessageBox(0,"Maximum number of characters exceeded\n(250 characters)", "MANUAL", MB_ICONINFORMATION);
            exit(1);
        }
        if(contador%25==0 && contador!=0)
        {
            gotoxy(51+ contador-30*(contador/25)+ (contador/5),(contador/25)+13);
            printf("%c", letra);
            gotoxy(51+ contador-30*(contador/25)+(contador/5),(contador/25)+13);

        }
        else if(contador%5==0 && contador!=0)
        {
            gotoxy(51+ contador-30*(contador/25)+(contador/5), (contador/25)+13);
            printf("%c", letra);

        }
        else
        {
            gotoxy(51+ contador-30*(contador/25)+(contador/5), (contador/25)+13);
            printf("%c", letra);
        }



        if((contador+1)%25==0 && (contador+1)!=0)
        {
            fprintf(ptPlano, "%c", letra);
            fprintf(ptPlano, "\n");

        }
        else if((contador+1)%5==0 && (contador+1)!=0)
        {
            fprintf(ptPlano, "%c", letra);
            fprintf(ptPlano, " ");
        }
        else
        {
            fprintf(ptPlano, "%c", letra);
        }

        contador ++;
    }
    else /*Complicado algortimo que se encargar de imprimirme correctamente la letra en la version de Cuatro rotores*/
    {
        if(size==0)
        {
            contador=0;
        }

        letra = toupper(letra);

        if(contador==250)
        {
            MessageBox(0,"Maximum number of characters exceeded\n(250 characters)","MANUAL",MB_ICONINFORMATION);
            exit(1);
        }
        if(contador%25==0 && contador!=0)
        {
            gotoxy(65+ contador-30*(contador/25)+ (contador/5),(contador/25)+13);
            printf("%c", letra);
            gotoxy(65+ contador-30*(contador/25)+(contador/5),(contador/25)+13);

        }
        else if(contador%5==0 && contador!=0)
        {
            gotoxy(65+ contador-30*(contador/25)+(contador/5), (contador/25)+13);
            printf("%c", letra);

        }
        else
        {
            gotoxy(65+ contador-30*(contador/25)+(contador/5), (contador/25)+13);
            printf("%c", letra);
        }



        if((contador+1)%25==0 && (contador+1)!=0)
        {
            fprintf(ptPlano, "%c", letra);
            fprintf(ptPlano, "\n");

        }
        else if((contador+1)%5==0 && (contador+1)!=0)
        {
            fprintf(ptPlano, "%c", letra);
            fprintf(ptPlano, " ");
        }
        else
        {
            fprintf(ptPlano, "%c", letra);
        }

        contador ++;
    }

    return 0;
}

