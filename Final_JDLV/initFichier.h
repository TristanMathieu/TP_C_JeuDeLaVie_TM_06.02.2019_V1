#ifndef INITFICHIER_H_INCLUDED
#define INITFICHIER_H_INCLUDED

//Includes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Constantes
#define PATH "historique_cellules.txt"

//Protocoles
extern void enregistrementFichier(int cellNaissantes, int cellMortes, int cellVivantes, int nCycle);

#endif // INITFICHIER_H_INCLUDED
