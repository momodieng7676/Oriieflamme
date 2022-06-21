#include "../headers/carte.h"
#include "../headers/faction.h"
#include "../headers/plateau.h"


Boolean TestInitFaction(){
    board board = newBoard();
    return board.factions[0].id==getId(board.factions[0]) && board.factions[0]->nom == getNomFaction(board.factions[0]) && board.factions[0].pointsddrs == getPointsddrs(board.factions[0]) && board.factions[0].main==getMain(board.factions[0]) && board.factions[0].pioche == getPioche(board.factions[0]);
}


Boolean presencedunetroisiememanche(board b){
    int i = getNbMancheGagnees(b.factions[0]);
    int j = getNbMancheGagnees(b.factions[1]);
    return i+j == 2;
}

Boolean useddrawandshuffletest(faction f){
    int i = UsedDrawAndShuffle(f)
    return i==1;
}


Boolean aposeunecarte(carte c){
    int* i = getPos(c);
    return i[0] != -1;
}

Boolean vainqueurdelapartie(faction f){
    return f.nbMancheGagnees==2;
}
