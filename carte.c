#include "../headers/carte.h"
#include "../headers/structure.h"
#include <stdlib.h>



struct carte {
    char* nom;
    char* desc;
    int nbOcc;
    int etat;
    int face;
    int* pos;
    int factionId;
    char* label;
};
carte newCarte(){
    return malloc(sizeof(struct carte));
}

char* getNom(carte c){
    return c->nom;
}


char* getDesc(carte c){
    return c->desc;
}


int getNbOcc(carte c){
    return c->nbOcc;
}

int getEtat(carte c){
    return c->etat;
}

int getFace(carte c){
    return c->face;
}

int* getPos(carte c){
    return c->pos;
}

int getFactionId(carte c){
    return c->factionId;
}

char* getLabel(carte c){
    return c->label;
}

void setNom(carte c, char* n){
    c->nom = n;
}


void setDesc(carte c, char* d){
    c->desc = d;
}


void setNbOcc(carte c, int n){
    c->nbOcc = n;
}

void setEtat(carte c, int e){
    c->etat = e;
}

void setFace(carte c, int f){
    c->face = f;
}

void setPos(carte c, int* p){
    c->pos = p;
}

void setFactionId(carte c, int i){
    c->factionId = i;
}

void setLabel(carte c, char* l){
    c->label = l;
}





carte* newCarteList(){
    return malloc(sizeof(struct carte)*16);
}