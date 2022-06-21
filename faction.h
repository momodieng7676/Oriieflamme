/*=======================================================================*/
#ifndef FACTION_H
#define FACTION_H
/*=======================================================================*/
#include "carte.h"
#include "structure.h"


//Type abstrait pour les factions
typedef struct faction* faction;

/*@requires rien
  @assigns rien
  @ensures renvoie une nouvelle faction
*/
faction newFaction();

/*@requires f est une faction valide
  @assigns f
  @ensures vide la main de la faction dans sa pioche
*/
void EmptyHand(faction f);


/*@requires f est une faction valide
  @assigns rien
  @ensures retourne 1 si f a utilisé l'option de remélanger sa main et la boite à idées
           et de repiocher ses cartes, 0 sinon
*/
int UsedDrawAndShuffle(faction f);


/*@requires f est une faction valide
  @assigns f
  @ensures Remélange la main de f et la boite à idées et repioche ses cartes
*/
void DrawAndShuffle(faction f);


/*@requires f est une faction valide
  @assigns f
  @ensures Mélange la pioche de f
*/
void Shuffle(faction f);


/*@requires f est une faction valide
  @assigns f
  @ensures Repioche les cartes de f
*/
void Draw(faction f);

/*@requires f est une faction valide
  @assigns nothing
  @ensures renvoie l'identifiant de la faction
*/
int getId(faction f);

/*@requires f est une faction valide
  @assigns nothing
  @ensures renvoie le nom de la faction
*/
char* getNomFaction(faction f);

/*@requires f est une faction valide
  @assigns nothing
  @ensures renvoie le nombre de points ddrs de la faction
*/
int getPointsddrs(faction f);

/*@requires f est une faction valide
  @assigns nothing
  @ensures renvoie la main de la faction f
*/
listecarte getMain(faction f);

/*@requires f est une faction valide
  @assigns nothing
  @ensures donne la main hand à la faction f
*/
void setMain(faction f, listecarte hand);

/*@requires f est une faction valide
  @assigns nothing
  @ensures renvoie le nombre de manches gagnées par la faction f
*/
int getNbMancheGagnees(faction f);

/*@requires f est une faction valide
  @assigns nothing
  @ensures renvoie la valeur de l'attribut optionDrawandShuffle
*/
int getOptionDrawandShuffle(faction f);

/*@requires f est une faction valide
  @assigns f
  @ensures donne la liste de carte m comme main à la faction f
*/

/*void setMain(faction f, struct listecarte m);*/

/*@requires f est une faction valide
  @assigns f
  @ensures donne l'identifiant i n à la faction f
*/
void setId(faction f, int i);

/*@requires f est une faction valide
  @assigns f
  @ensures donne le nom n à la faction f
*/
void setNomFaction(faction f, char* n);

/*@requires f est une faction valide
  @assigns f
  @ensures met l'option DrawandShuffle de la faction f 
*/
void setOptionDrawandShuffle(faction f, int o);

/*@requires f est une faction valide
  @assigns f
  @ensures initialise les points ddrs de la faction f 
*/
void setPointsddrs(faction f, int n);

/*@requires f est une faction valide
  @assigns f
  @ensures incrémente le nombre de manches gagnées par la faction f
*/
void incrNbMancheGagnees(faction f);

/*@requires f est une faction valide
  @assigns f
  @ensures ajoute p points ddrs à la faction f
*/
void addPointsddrs(faction f, int p);


/*=======================================================================*/
#endif // FACTION_H
/*=======================================================================*/