/*=======================================================================*/
#ifndef STRUCTURE_H
#define STRUCTURE_H
/*=======================================================================*/

#include "carte.h"



//typedef struct tableau tableau;

typedef struct PileCarte* PileCarte;

typedef struct listecarte* listecarte;

/*@requires nothing
  @assigns pilecarte
  @ensures empile la carte c a la pilecarte pilecarte*/
void empiler(PileCarte PileCarte, carte c);

/*@requires pilecarte non vide
  @assigns pilecarte
  @ensures depile la pilecarte et renvoie la carte qui a ete depilee*/
carte depiler(PileCarte Pile);

/*@requires listecarte main non vide
  @assigns listecarte main
  @ensures enleve la carte c a la listecarte main*/
void enleve(listecarte main, carte c);

/*@requires nothing
  @assigns listecarte main
  @ensures ajoute la carte c a la ie position de la listecarte main*/
void add(listecarte main,int i, carte c);

/*@requires listecarte main contient les cartes i et j 
  @assigns listecarte main
  @ensures intervertie les carte aux positions i et j a la listecarte main*/
void swap(listecarte main,int i,int j);

/*@requires nothing 
  @assigns nothing
  @ensures initialise une pilecarte*/
PileCarte initialisationpile();


/*@requires nothing 
  @assigns nothing
  @ensures initialise une listecarte*/
listecarte initialisationliste();


/*@requires nothing 
  @assigns nothing
  @ensures retourne la carte a la position i de la listecarte main*/
carte getCarteFromIndex(listecarte main,int i);

/*@requires nothing 
  @assigns nothing
  @ensures retourne la carte de listecarte main*/
carte getCarte(listecarte main);

/*=======================================================================*/
#endif // STRUCTURE_H
/*=======================================================================*/


