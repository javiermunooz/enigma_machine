all:Enigma.exe

Enigma.exe: auxiliar.o libroClaves.o mainEnigma.o menus.o interfaz.o cifrado.o reflector.o rotores.o stecker.o config.o Enigma.o listaConfig.o
	gcc -o Enigma.exe auxiliar.o libroClaves.o mainEnigma.o menus.o interfaz.o cifrado.o reflector.o rotores.o stecker.o config.o Enigma.o listaConfig.o

auxiliar.o: auxiliar/auxiliar.c auxiliar/auxiliar.h
	gcc -Wall -pedantic -ansi -c auxiliar/auxiliar.c

libroClaves.o: LibroClaves/libroClaves.c LibroClaves/libroClaves.h auxiliar/auxiliar.h Maquina/rotores.h Maquina/stecker.h
	gcc -Wall -pedantic -ansi -c LibroClaves/libroClaves.c

mainEnigma.o: main/mainEnigma.c Maquina/interfaz.h main/menus.h
	gcc -Wall -pedantic -ansi -c main/mainEnigma.c

Enigma.o: Maquina/Enigma.c Config/config.h auxiliar/auxiliar.h Maquina/rotores.h Maquina/Enigma.h Maquina/stecker.h 
	gcc -Wall -pedantic -ansi -c Maquina/Enigma.c 

menus.o: main/menus.c main/menus.h auxiliar/auxiliar.h Maquina/interfaz.h Maquina/cifrado.h Config/config.h LibroClaves/libroClaves.h 
	gcc -Wall -pedantic -ansi -c main/menus.c 

interfaz.o: Maquina/interfaz.c Maquina/interfaz.h auxiliar/auxiliar.h Maquina/interfaz.h Maquina/rotores.h Maquina/stecker.h Maquina/reflector.h
	gcc -Wall -pedantic -ansi -c Maquina/interfaz.c

cifrado.o: Maquina/cifrado.c Maquina/cifrado.h auxiliar/auxiliar.h Maquina/interfaz.h Maquina/cifrado.h Config/config.h Maquina/rotores.h Maquina/stecker.h Maquina/reflector.h auxiliar/punto.h Maquina/Enigma.h
	gcc -Wall -pedantic -ansi -c Maquina/cifrado.c

reflector.o: Maquina/reflector.c Maquina/reflector.h auxiliar/auxiliar.h
	gcc -Wall -pedantic -ansi -c Maquina/reflector.c

rotores.o: Maquina/rotores.c Maquina/rotores.h auxiliar/auxiliar.h
	gcc -Wall -pedantic -ansi -c Maquina/rotores.c

stecker.o: Maquina/stecker.c Maquina/stecker.h auxiliar/auxiliar.h
	gcc -Wall -pedantic -ansi -c Maquina/stecker.c

config.o: Config/config.c Config/config.h Maquina/reflector.h auxiliar/auxiliar.h Maquina/rotores.h
	gcc -Wall -pedantic -ansi -c Config/config.c

listaConfig.o: Config/listaConfig.c Config/listaConfig.h Config/config.h auxiliar/auxiliar.h Maquina/rotores.h
	gcc -Wall -pedantic -ansi -c  Config/listaConfig.c

clean:
	del Enigma.exe auxiliar.o libroClaves.o mainEnigma.o menus.o interfaz.o cifrado.o reflector.o rotores.o stecker.o config.o Enigma.o listaConfig.o