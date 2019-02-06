#ifndef TYPECELL_H_INCLUDED
#define TYPECELL_H_INCLUDED

//Includes générales
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Constantes
#define TAILLE 30

//Types
typedef struct cellule{
    char etat;//n=naissante / v=vivante / m=mourante / d=completement morte / X=zone hors jeu
    char visuel;
}cellule;

//Protocoles
extern void initTableau(cellule cTab[TAILLE][TAILLE]);
extern void procedureAffichage(cellule cTab[TAILLE][TAILLE], int nCycle);
extern void gestionCellules(cellule cTab[TAILLE][TAILLE], int nCycle);

#endif // TYPECELL_H_INCLUDED
