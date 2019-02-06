#include "typeCell.h"
#include "initFichier.h"

/*-----------------------------------
 Descriptions : Initialise le tableau utilisé pour stocker nos cellules
 Entrées : cTab(non initialisé)
 Sorties : cTab(initialisé)
-----------------------------------*/

void initTableau(cellule cTab[TAILLE][TAILLE]){
    //Initialisation des variables
    int i;
    int j;

    //Coeur du programme

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            cTab[i][j].visuel='X';
            cTab[i][j].etat='X';
        }
    }


    for(i=1;i<TAILLE-1;i++){
        for(j=1;j<TAILLE-1;j++){
            if((rand()%3)==1){
                cTab[i][j].visuel='_';
                cTab[i][j].etat='d';
            }else{
                cTab[i][j].visuel='o';
                cTab[i][j].etat='v';
            }
        }
    }
}

/*-----------------------------------
 Descriptions : Gestion d'un cycle de cellules
 Entrées : cTab, numéro du cycle
 Sorties : cTab(actualisé)
 Note : On doit passer par ici pour enregistrer le résultats dans un fichier
-----------------------------------*/

void gestionCellules(cellule cTab[TAILLE][TAILLE], int nCycle){
    //Initialisation des variables
    int i;
    int j;
    int cellAdj=0;

    int cellNaissantes=0;
    int cellMortes=0;
    int cellVivantes=0;

    //Coeur du programme
    for(i=1;i<TAILLE-1;i++){
        for(j=1;j<TAILLE-1;j++){
            if(cTab[i-1][j-1].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i-1][j].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i-1][j+1].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i][j-1].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i][j+1].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i+1][j-1].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i+1][j].etat=='v'){
                cellAdj+=1;
            }
            if(cTab[i+1][j+1].etat=='v'){
                cellAdj+=1;
            }
            if((cellAdj==3)&&(cTab[i][j].etat!='v')){
                cTab[i][j].visuel='o';
                cTab[i][j].etat='n';
                cellMortes+=1;
            }else{
                if((cellAdj==2)||((cellAdj==3)&&(cTab[i][j].etat=='v'))){

                }else{
                    cTab[i][j].visuel='_';
                    cTab[i][j].etat='m';

                }
            }
            cellAdj=0;
        }
    }

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            if(cTab[i][j].etat=='n'){
                cTab[i][j].etat='v';
                cellNaissantes+=1;
            }
            if(cTab[i][j].etat=='m'){
                cTab[i][j].etat='d';
                cellMortes+=1;
            }
            if(cTab[i][j].etat=='v'){
                cellVivantes+=1;
            }
        }
    }

    enregistrementFichier(cellNaissantes, cellMortes, cellVivantes, nCycle);
}


/*-----------------------------------
 Descriptions : Procedure d'affichage de notre tableau de cellules
 Entrées : cTab
 Sorties : cTab(visuel pour notre utilisateur)
-----------------------------------*/

void procedureAffichage(cellule cTab[TAILLE][TAILLE], int nCycle){
    //Initialisation des variables
    int i;
    int j;

    //Coeur du programme
    printf("\nCycle %d\n\n", nCycle);

    for(i=0;i<TAILLE;i++){
        for(j=0;j<TAILLE;j++){
            printf("%c ",cTab[i][j].visuel);
        }
        printf("\n");
    }
}

