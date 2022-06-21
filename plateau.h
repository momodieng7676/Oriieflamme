/*==========================================================================================================================*/
#ifndef PLATEAU_H
#define PLATEAU_H
/*==========================================================================================================================*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include "carte.h"
#include "faction.h"
// #include "interface.h"
#include "structure.h"



typedef struct board* board;


/*@requires nothing
  @assigns nothing
  @ensures return un plateau et ses deux factions (les factions sont définis dans la structure du plateau)*/
board newBoard();


/*@requires b est un plateau valide
  @assigns nothing
  @ensures renvoie la liste des cartes posées sur le plateau
*/
carte** getCartesPosees(board b);


/*@requires b est un plateau valide
  @assigns nothing
  @ensures renvoie la liste des cartes retournées sur le plateau
*/
carte* getCartesRetournees(board b);

/*@requires nothing
  @assigns nothing
  @ensures libère la mémoire associé a un plateau*/
void freeBoard(board b);


/*@requires nothing
  @assings nothing
  @ensures initialise une nouvelle manche de jeu (nouveau plateau) et indiquer que le jeu est terminé le cas échéant */
board gameState(board b);


/*@requires board correctement défini
  @assigns nothing
  @ensures renvoie la liste des deux factions du jeu*/
faction* listFaction(board b);


/*@requires board correctement défini
  @assigns nothing
  @ensures renvoie la faction dont l'id est donné en paramètre*/
faction getFactionById(int id, board b);


/*@requires board correctement défini
  @assigns nothing
  @ensures renvoie la faction adverse de celle dont l'id est donné en paramètre*/
faction getFactionAdverse(int id, board b);


/*@requires nothing
  @assigns nothing
  @ensures retourne 1 la carte peut bien être posée à la position (x, y) du plateau b, 0 sinon*/
int validPosition(board b, int x, int y);


/*@requires board et card correctement définis
  @assigns board
  @ensures poser une carte face cachée sur le plateau*/
void placeCard(faction f,board b,carte c);


/*@requires board et card correctement définis 
  @assigns board 
  @ensures retourner la carte la plus en haut à gauche et activer son effet, et renvoyer cette carte*/
carte activateCard(board b);


/*@requires b et l correctement définis 
  @assigns board 
  @ensures attribut l comme liste de factions au plateau b*/
void setFactions(board b, faction* l);

/*@requires  Myboard est un plateau
  @assigns nothing
  @ensures return le nombre de carte retourne du plateau*/
int compteurCarteRetourne(board Myboard);


/*@requires Myboard est un plateau et nomCarte est le nom de la carte
  @assigns nothing
  @ensures renvoie le nombre de fois ou on a une carte donnée en parametre
*/
int compteurCarteSameNom(board Myboard,char* nomCarte);

/*@requires Myboard est un plateau et nomCarte est le nom de la carte
  @assigns nothing
  @ensures supprime une carte retouné du plateau 
*/
void supprimeCarte(board Myboard,char* NomCarte);

/*@requires Myboard est un plateau et nomCarte est le nom de la carte
  @assigns nothing
  @ensures supprime utout type de carte retourné ou pas 
*/
void supprimeAnyCarte(board Myboard,char* NomCarte);

/*@requires Myboard est un plateau et mycarte est la carte sur la quelle on applique l'effet 
  @assigns nothing
  @ensures renvoie la liste des cartes retournées sur le plateau
*/
void effetDesCartes(board Myboard,carte mycarte);


/*==========================================================================================================================*/
#endif // PLATEAU_H 
/*==========================================================================================================================*/