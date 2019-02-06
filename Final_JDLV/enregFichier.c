#include "initFichier.h"

/*-----------------------------------
 Descriptions : Gestion d'un cycle de cellules
 Entrées : Nb cell naissantes, mortes, vivantes, et le numéro du cycle
 Sorties : Fichier d'archives
-----------------------------------*/

void enregistrementFichier(int cellNaissantes, int cellMortes, int cellVivantes, int nCycle){
    //Initialisation des variables
    FILE *pFile;
    char sNbC[20];
    char sNbN[20];
    char sNbM[20];
    char sNbV[20];

    //Convertion des variables Int vers String
    itoa(nCycle,sNbC,10);
    itoa(cellNaissantes,sNbN,10);
    itoa(cellMortes,sNbM,10);
    itoa(cellVivantes,sNbV,10);

    //Ouverture du fichier
    pFile = fopen(PATH,"a");

    fputs("Cycle ",pFile);
    fputs(sNbC,pFile);
    fputc('\n',pFile);
    fputc('\n',pFile);

    fputs("Cellules Naissantes : ",pFile);
    fputs(sNbN,pFile);
    fputc('\n',pFile);

    fputs("Cellules Mortes : ",pFile);
    fputs(sNbM,pFile);
    fputc('\n',pFile);

    fputs("Cellules Vivantes : ",pFile);
    fputs(sNbV,pFile);
    fputc('\n',pFile);
    fputc('\n',pFile);
    fputc('\n',pFile);

    //Fermeture du fichier
    fclose(pFile);
}
