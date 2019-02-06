#include "typeCell.h"

int main(){
    //Initialisation de l'aléatoire
    srand(time(NULL));

    //Initialisation des variables
    cellule cTab[TAILLE][TAILLE];
    int nCycle=0;
    char nFinProg='0';

    //Coeur du programme
    initTableau(cTab);
    procedureAffichage(cTab, nCycle);

    do{
        nCycle+=1;
        gestionCellules(cTab, nCycle);
        procedureAffichage(cTab, nCycle);
        printf("\nContinuer?\nN'importe : oui\n0 : non\n");
        fflush(stdin);
        scanf("%c", &nFinProg);
    }while(nFinProg!='0');

    return 0;
}
