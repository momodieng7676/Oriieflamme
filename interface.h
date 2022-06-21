/*=======================================================================*/
#ifndef INTERFACE_H
#define INTERFACE_H

#include <stdbool.h>
#include "plateau.h"
#include "faction.h"
#include "carte.h"
/*=======================================================================*/

//Type encodant les interfaces permettant les échanges d'information entre les joueurs
//typedef struct interface interface;

/*@requires p est un plateau valide
  @assigns nothing
  @ensures affiche le plateau du jeu
*/
void printBoard( board p);

/*@requires f est une faction valide
  @assigns nothing
  @ensures affiche la main de la faction f 
*/
void printHand(faction f);

/*@requires f est une faction valide
  @assigns f
  @ensures demande à une faction si elle veut utiliser son option permettant de vider sa main, de mélanger sa pioche et de repiocher : 1 si oui, 0 sinon
*/
int useOption(faction f);

/*@requires f est une faction valide
  @assigns f
  @ensures demande quelle carte de sa main la faction f souhaite poser face cachée sur le plateau
*/
carte pickCard(faction f);

/*@requires f est une faction valide
  @assigns f
  @ensures demande à quelle position la faction souhaite poser sa carte
*/
int* choosePosition(faction f,  board b);

/*@requires c est une carte valide
  @assigns nothing
  @ensures affiche les effets d'une carte qui vient d'être retournée sur le plateau
*/
void printEffect(carte c);

/*@requires b est un plateau valide
  @assigns nothing
  @ensures affiche le vainqueur du plateau b
*/
void printWinner( board b);

/*=======================================================================*/
#endif // INTERFACE_H
/*=======================================================================*/
