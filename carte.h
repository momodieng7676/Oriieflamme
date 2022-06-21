/*=======================================================================*/
#ifndef CARTE_H
#define CARTE_H

/*=======================================================================*/

//Type abstrait pour les cartes
typedef struct carte* carte;

/*@requires nothing
  @assigns nothing
  @ensures renvoie une nouvelle carte
*/
carte newCarte();

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie le nom de la carte
*/
char* getNom(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie la description de la carte
*/
char* getDesc(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie le nombre d'occurences de la carte
*/
int getNbOcc(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie l'état de la carte : 0 si elle n'a pas encore été piochée, 1 sinon
*/
int getEtat(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie le sens de la carte : 0 si elle est posée face cachée, 1 sinon
*/
int getFace(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie la position de la carte sur le plateau. Les coordonnées (-1, -1) signifient qu'elle n'a pas encore été posée
*/
int* getPos(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie l'identifiant de la faction à laquelle appartient la carte. 0 signifie qu'elle n'appartient à aucune faction
*/
int getFactionId(carte c);

/*@requires c est une carte valide
  @assigns nothing
  @ensures renvoie les deux lettres caractérisant la carte
*/
char* getLabel(carte c);

/*@requires c est une carte valide
  @assigns c
  @ensures donne le nom n à la carte c
*/
void setNom(carte c, char* n);

/*@requires c est une carte valide
  @assigns c
  @ensures donne la description d à la carte c
*/
void setDesc(carte c, char* d);

/*@requires c est une carte valide
  @assigns c
  @ensures met le nombre d'occurences de c à n
*/
void setNbOcc(carte c, int n);

/*@requires c est une carte valide
  @assigns c
  @ensures met l'état de la carte c à e
*/
void setEtat(carte c, int e);

/*@requires c est une carte valide
  @assigns c
  @ensures met le sens de la carte à f
*/
void setFace(carte c, int f);

/*@requires c est une carte valide
  @assigns c
  @ensures met la carte c à la position p
*/
void setPos(carte c, int* p);

/*@requires c est une carte valide
  @assigns c
  @ensures attribue la carte c à la faction i
*/
void setFactionId(carte c, int i);

/*@requires c est une carte valide
  @assigns c
  @ensures attribue l comme label à la faction c
*/
void setLabel(carte c, char* l);

/*@requires c est une carte valide
  @assigns c
  @ensures permet d'allouer l'espace nécessaire à l'initialisation des cartes
*/
carte* newCarteList();

/*@requires nothing
  @assigns nothing
  @ensures renvoie une pile de toutes les cartes du jeu : la boite à idées
*/
/*PileCarte allCards();*/

/*=======================================================================*/
#endif // CARTE_H
/*=======================================================================*/