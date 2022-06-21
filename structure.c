#include "../headers/structure.h"
#include "../headers/carte.h"
#include <stdlib.h>

struct tableau{
    int ** t;
};


struct PileCarte {
    carte carte;
    struct PileCarte* suivant;
};

struct listecarte{
    carte carte;
    struct listecarte * suivant;
};



void empiler(PileCarte PileCartes, carte c)
{
    PileCarte  nouveau = malloc(sizeof(struct PileCarte));
    if (nouveau != NULL){
        nouveau->carte = c;
        nouveau->suivant = PileCartes;
    }
    PileCartes = nouveau;
}

carte depiler(PileCarte PileCartes)
{
    carte c = malloc(sizeof( carte));
    if (PileCartes != NULL)
    {
        PileCarte temporaire = PileCartes->suivant;
        
        c= PileCartes->carte;  
        free(PileCartes), PileCartes = NULL;
        PileCartes = temporaire;
    }
    return c;
}


void enleve(listecarte main, carte c){
    listecarte tmp = initialisationliste();
    tmp = main;
    while ((main=main->suivant) != NULL){
        if (main -> carte == c){
            tmp -> suivant = main -> suivant;
            free(main);
            break;
        }
        tmp = main;
    }
}



PileCarte initialisationpile(){
    PileCarte nouveau = malloc(sizeof(struct PileCarte));
    return nouveau;
}

listecarte initialisationliste(){
    listecarte nouveau = malloc(sizeof(struct listecarte));
    return nouveau;
}

void add(listecarte main, int i, carte c){
    int j = 0;
    listecarte tmp = initialisationliste();
    tmp=main;
    while ((main=main->suivant) != NULL){
        if (i==j){
            main -> carte = c;
            main -> suivant = tmp -> suivant;
        }
        j++;
        tmp = main;
    }
    main = tmp;
}


void swap(listecarte main, int i, int j){
    listecarte tmp = initialisationliste();
    listecarte tmp2 = initialisationliste();
    tmp=main;
    tmp2=main;
    for (int k =0 ; k<i ; k++){
        tmp=tmp->suivant;
    }
    carte c1 = malloc(sizeof( carte));
    c1 = tmp->carte;
    for (int k =0 ; k<j ; k++){
        tmp2=tmp2->suivant;
    }
    carte c2 = malloc(sizeof( carte));
    c2 = tmp2->carte;
    enleve(main,c2);
    add(main,i,c2);
    enleve(main,c1);
    add(main,j,c1);
}

carte getCarte(listecarte main){
    carte c = malloc(sizeof(carte));
    return c = main->carte;
}

carte getCarteFromIndex(listecarte main,int i){
    for (int k =0 ; k<i ; k++){
        main = main->suivant;
    } 
    carte c = malloc(sizeof(carte));
    c = getCarte(main);
    return c;
}