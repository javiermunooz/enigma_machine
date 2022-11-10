#ifndef CONFIG_H_INCLUDED /* Declaracion de funciones contenidas en libroclaves*/
#define CONFIG_H_INCLUDED

/*void 	configuracion (int nRotores, unsigned short walzen[], char stecker[], unsigned short ring[], char grund[], char rotor[][3][27], char muesca[][3], char reflector[]);*/

struct sConfig
{
    int 	dia;
    char 	grund [5];
    char 	modeloETW;
    unsigned short 	numRotores;
    unsigned short 	ringS [4];
    char 	stecker [27];
    unsigned short 	walzen [4];

};

void leeConfig (struct sConfig *pConfig);

void muestraConfig (struct sConfig config);

void selecModelo (struct sConfig *pConfig);




#endif
