#include "../headers/plateau.h"
#include "../headers/faction.h"
#include "../headers/carte.h"
#include "../headers/interface.h"
#include <stdlib.h> 


int main(void){

    board plateau = newBoard();
    printBoard(plateau);
    faction* f = listFaction(plateau);
    board tmp = gameState(plateau);
    while(tmp !=NULL){

        plateau= gameState(plateau);



        Draw(f[0]);
        Draw(f[1]);
        printHand(f[0]);
        printHand(f[1]);

        
        if(useOption(f[0])==1){
            if(UsedDrawAndShuffle(f[0])==0){
                DrawAndShuffle(f[0]);
            }
        }
        if(useOption(f[1])==1){
            if (UsedDrawAndShuffle(f[1])==0){
                DrawAndShuffle(f[1]);
            }
        }


        for(int carte = 0;carte < 8 ;carte ++){

            placeCard(f[0],plateau,pickCard(f[0]));
            placeCard(f[1],plateau,pickCard(f[1]));
        }

        for(int Opencard = 0 ; Opencard < 16 ;Opencard++){
            
            printEffect(activateCard(plateau));
        }

        tmp = gameState(plateau);

    }

    printWinner(plateau);
    freeBoard(plateau);

    return 0;
}