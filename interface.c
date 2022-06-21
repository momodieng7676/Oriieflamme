#include "../headers/interface.h"

/*struct interface{
    board plateau;
};*/

void printBoard(board p){
    char* l;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if ( getCartesPosees(p)[i][j] == NULL ){
                l = "  .  ";
            } else {
                l = getLabel(getCartesPosees(p)[i][j]);
            }
            printf("  %s ", l);
        }
        printf("\n");
    }
}

void printHand(faction f){
    char* l;
    for (int i=0; i<8; i++){
        if ( sizeof(getCarteFromIndex(getMain(f),i)) == sizeof(carte) ){
            l = getLabel(getCarteFromIndex(getMain(f),i));
        } else { l="  .  "; }
        printf("  %s ", l);
    }
    printf("\n");

}

int useOption(faction f){
    int choice = 2;
    printf("Faction %d : entrez 1 si vous souhaitez  vider votre main et repiocher à nouveau, 0 sinon : ", getId(f));
    while ( choice != 0 && choice != 1 ){
        printf("Faction %d : entrez 1 si vous souhaitez  vider votre main et repiocher à nouveau, 0 sinon : ", getId(f));
        scanf("%d", &choice);
        printf("\n");
    }
    return choice;
}

carte pickCard(faction f){
    printHand(f);

    for ( int i=0; i<8; i++ ){
        printf("%03d ", i);
    }

    int choice;
    printf("Faction %d : entrez le numéro de la carte que vous souhaitez poser : ", getId(f));
    scanf("%d", &choice);
    while ( getCarteFromIndex(getMain(f),choice) == NULL ){
        printHand(f);

        for ( int i=0; i<8; i++ ){
            printf("%03d ", i);
        }
        printf("Faction %d : entrez le numéro de la carte que vous souhaitez poser : ", getId(f));
        scanf("%d", &choice);
        printf("\n");
    }

    return getCarteFromIndex(getMain(f),choice);
}

int* choosePosition(faction f, board b){
    int x = -1;
    int y = -1;

    int* pos = malloc(2);

    printf("Faction %d : entrer les coordonées de la case sur laquelle poser la carte : ", getId(f));
    printf("Exemple : 1 2");
    scanf("%d %d", &x, &y);

    while ( !validPosition(b, x, y) ){
        printf("Faction %d : entrer les coordonées de la case sur laquelle poser la carte : ", getId(f));
        printf("Exemple : 1 2\n");
        scanf("%d %d", &x, &y);
        printf("\n");
    }
    pos[0] = x;
    pos[1] = y;

    return pos;
}

void printEffect(carte c){
    printf("Carte %s : %s \n", getNom(c), getDesc(c));
}

void printWinner(board b){
    for (int i=0; i<2; i++){
        if ( getNbMancheGagnees(listFaction(b)[i]) == 2 ){
            printf("Le vainqueur de la partie est : %s !!!\n", getNomFaction(listFaction(b)[i]));
        }
    }
}