#include "../headers/plateau.h"
#include "../headers/faction.h"
#include "../headers/interface.h"
#include "../headers/carte.h"
#include "../headers/structure.h"

int NbManchesGagantes = 2; 
int gameOver = 0; // Prends la valeur 1 si le jeu est terminé et 0 sinon


struct board {
    carte** cartesPosees;
    faction* factions;
};

board newBoard(){
    board new_plateau = malloc(sizeof(struct board));
    faction* factions = malloc(2*sizeof(struct faction*));
    factions[0] = newFaction();
    factions[1] = newFaction(); 
    setFactions(new_plateau, factions);
    //Initialisation de la faction1 du plateau
    setNomFaction(factions[0], "Faction 1");
    setOptionDrawandShuffle(factions[1], 0);
    setId(factions[0],0);
    setPointsddrs(factions[0],0);
    listecarte hand = initialisationliste();
    setMain(factions[0],hand);
    //Initialisation de la faction2 du plateau
    setNomFaction(factions[1], "Faction 2");
    setOptionDrawandShuffle(factions[2], 0);
    setId(factions[1],1);
    setPointsddrs(factions[1],0);
    setMain(factions[1],hand);
    return new_plateau;
}

carte** getCartesPosees(board b){
    return b->cartesPosees;
}


carte* getCartesRetournees(board b){
    carte* liste = newCarteList();
    int cpt = 0;
    for (int i=0; i<4; i++){
        for (int j=0; j<4; j++){
            if ( getCartesPosees(b)[i][j] != NULL && getFace(getCartesPosees(b)[i][j]) ){
                liste[cpt] = getCartesPosees(b)[i][j];
                cpt++;
            }
        }
    }
    return liste;
}

void freeBoard(board b){
    free(b);
}

board gameState(board b){
    if (getNbMancheGagnees(listFaction(b)[0]) ==  NbManchesGagantes || getNbMancheGagnees(listFaction(b)[1]) ==  NbManchesGagantes){
        gameOver = 1;//Indication de la fin du jeu
        return b;
    } 
    b = newBoard();
    return b;
    //Initialisation du plateau
}
faction* listFaction(board b){
    faction* f = malloc(2*sizeof(struct faction*));
    f[0] = b->factions[0];
    f[1] = b->factions[1];
    return f;
}

faction getFactionById(int id, board b){
    for (int i=0; i<2; i++){
        if ( id == getId(listFaction(b)[i]) ){
            return listFaction(b)[i];
        }
    }
    return NULL;
}

faction getFactionAdverse(int id, board b){
    for (int i=0; i<2; i++){
        if ( id != getId(listFaction(b)[i]) ){
            return listFaction(b)[i];
        }
    }
    return NULL;
}

int validPosition(board b, int x, int y){
    if ( x<0 || y<0 || x>=4 || y>=4 || getCartesPosees(b)[x][y] != NULL ){
        return 0;
    }
    return 1;
}

void placeCard(faction f, board b, carte c){
    int* pos = choosePosition(f,b);//recupérer la position où déposer la carte
    b->cartesPosees[pos[0]][pos[1]] = c;//et y déposer c
    //Supprimer c de la main de f avec les listes chainées (Jinkey)
}

//__________________________________________________________________________________________________

int compteurCarteRetourne(board Myboard){
    int compteur = 1;
    carte* cartesRetournees = getCartesRetournees(Myboard);
    for (int i  = 0 ;i < 16 ;i ++){
        if(cartesRetournees[i] != NULL )
            compteur++;
    }
    return compteur;
}

int compteurCarteSameNom(board Myboard,char* nomCarte){
    int compteur = 1;
    carte* cartesRetournees = getCartesRetournees(Myboard);
    for(int j = 0 ;j <  compteurCarteRetourne(Myboard);j++){
        if(strcmp(getNom(cartesRetournees[j]),nomCarte)==0)
            compteur++;
    }   
    return compteur;
}

//Prends en entré une un plateau et le nom d'une carte puis supprime cette carte de la liste des cartes posées sur le plateau si elle est retournée
void supprimeCarte(board Myboard,char* NomCarte){
    carte** cartesPosees = getCartesPosees(Myboard);
    for(int i = 0 ; i < 4;i++){
        for (int j = 0 ;j<4;++j){
            if(getFace(cartesPosees[i][j])==1 && strcmp(getNom(cartesPosees[i][j]),NomCarte)==0 )
                cartesPosees[i][j]=NULL;
        }
    }  

}
//Prends en entré une un plateau et le nom d'une carte puis supprime cette carte de la liste des cartes posées sur le plateau 
void supprimeAnyCarte(board Myboard,char* NomCarte){
    carte** cartesPosees = getCartesPosees(Myboard);
    for(int i = 0 ; i < 4;i++){
        for (int j = 0 ;j<4;++j){
            if(strcmp(getNom(cartesPosees[i][j]),NomCarte)==0 )
                cartesPosees[i][j]=NULL;
        }
    }  
}
//Cette fonction permet d'appliquer les effets des cartes    
//Elle utilise un switch et traite les cases en fonction du nom de la carte 
void effetDesCartes(board Myboard,carte mycarte){
    //Declaration des tableaux des cartes posees et retournees
    faction propritaire = getFactionById(getFactionId(mycarte),Myboard);
    carte* cartesRetournees = getCartesRetournees(Myboard);
    carte** cartesPosees = getCartesPosees(Myboard);
    faction adversaire = getFactionAdverse(getFactionId(mycarte),Myboard);

    //Recuperation du tableau des position de la carte 
    int *Position = getPos(mycarte);
    int ligne = Position[0];
    int colonne = Position[1];
    int compteur = 0 ;


    if (strcmp(getNom(mycarte),"FISE")==0)
        addPointsddrs(propritaire, 1);


    else if (strcmp(getNom(mycarte),"FISA")==0){
        if (compteurCarteRetourne(Myboard)%2==0)
            addPointsddrs(propritaire, 1);
    }
        
    else if (strcmp(getNom(mycarte),"FC")==0){
        if (compteurCarteSameNom(Myboard,"FC") >= 1)
            addPointsddrs(propritaire, 4);
        }

    else if (strcmp(getNom(mycarte),"EcologIIE")==0){
        for(int i = 0;i<compteurCarteRetourne(Myboard);i++){
            if (strcmp(getNom(cartesRetournees[i]),"FC")==0 || strcmp(getNom(cartesRetournees[i]),"FISE")==0 || strcmp(getNom(cartesRetournees[i]),"FISA")==0)
                addPointsddrs(propritaire, 1);
            } 
    }
        
    else if (strcmp(getNom(mycarte),"iiiEns")==0){}

    //On supprime les premieres et dernieres cartes 
    else if (strcmp(getNom(mycarte),"Soirée sans alcool")==0){ 
        if (compteurCarteSameNom(Myboard,"Alcool") >= 1){
            supprimeCarte(Myboard,"FC");
            supprimeCarte(Myboard,"FISE");
            supprimeCarte(Myboard,"FISA");
            for (int j = 0 ;j <4 ;++j){
                supprimeAnyCarte(Myboard,getNom(cartesPosees[0][j]));
                supprimeAnyCarte(Myboard,getNom(cartesPosees[3][j]));
            }
        }
        addPointsddrs(propritaire,5);   
    }

    //On recupere la position de la carte et on supprime toutes les cartes proches de la cartes a partir de cette position 
    else if (strcmp(getNom(mycarte),"Alcool")==0){
        int i = Position[0];
        int j = Position[1];
        if(cartesPosees[i-1][j-1] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i-1][j-1]));
        if(cartesPosees[i-1][j] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i-1][j]));
        if(cartesPosees[i-1][j+1] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i-1][j+1]));
        if(cartesPosees[i][j-1] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i][j-1]));
        if(cartesPosees[i][j+1] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i][j+1]));
        if(cartesPosees[i+1][j-1] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i+1][j-1]));
        if(cartesPosees[i+1][j] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i+1][j]));
        if(cartesPosees[i+1][j+1] != NULL)
            supprimeAnyCarte(Myboard,getNom(cartesPosees[i+1][j+1]));
            
    }

    
    else if (strcmp(getNom(mycarte),"Café")==0){
        supprimeCarte(Myboard,"Thé");
        supprimeCarte(Myboard,"Alcool");
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if (strcmp(getNom(cartesRetournees[i]),"Ecocup")==0)
                addPointsddrs(propritaire,1);
        }
        addPointsddrs(propritaire,-1);
    }

    else if (strcmp(getNom(mycarte),"Café")==0){ 
        supprimeCarte(Myboard,"Café");
        supprimeCarte(Myboard,"Alcool");
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if (strcmp(getNom(cartesRetournees[i]),"Ecocup")==0)
                addPointsddrs(propritaire,1);       
        }
        addPointsddrs(propritaire,-1);  
    }

    else if (strcmp(getNom(mycarte), "Ecocup")==0){}

    else if (strcmp(getNom(mycarte), "reprographie")==0){}   
    //On parcours la listes des cartes posées sur le plateau puis on choisi ce qui ne sont pas supprimers et qui ne sont pas retournés 
    //Ensuite on verifie la faction qui a posé la carte et on lui donne les points 
    else if (strcmp(getNom(mycarte), "Isolation du bâtiment")==0){ 
        for(int i = 0 ; i < 4;i++){
            for (int j = 0 ;j<4;++j){
                if(cartesPosees[i][j] != NULL && getFace(cartesPosees[i][j])==0){
                    if(getFactionId(cartesPosees[i][j])==getId(propritaire))
                        addPointsddrs(propritaire,1);
                    addPointsddrs(adversaire,1);
                }
            }
        }
    }

    else if (strcmp(getNom(mycarte),"Parcours sobriété numérique")==0){  
        for(int i = 0 ; i < 4;i++){  //On parcours les lignes et on retourne les cartes les plus a gauche et les plus a droite  
            setFace(cartesPosees[i][0],1);
            setFace(cartesPosees[i][3],1);
        }
    }
    //On retire 3 points a la faction adverse
    else if (strcmp(getNom(mycarte),"Heures supplémentaires")==0){ 
        addPointsddrs(adversaire,-3);}      
    
    //On choisit une ligne et une colonne au hazard avec rand et on verifie si elle est pas retourné 
    //si oui on passe a une autre carte et sinon on le retourne puis on arrete 
    else if (strcmp(getNom(mycarte),"Kahina Bouchama")==0){
        int i = 0;
        int ligneRand = rand()%4;
        int colonneRand = rand()%4;
        while(getFace(cartesPosees[ligneRand][colonneRand]) == 1 || i ==0 ){
            ligneRand = rand()%4;
            colonneRand = rand()%4;
            if (getFace(cartesPosees[ligneRand][colonneRand]) == 0)
                supprimeCarte(Myboard,getNom(cartesPosees[ligne][colonneRand]));
            i++;
        }
    }
    else if (strcmp(getNom(mycarte),"Kevin Goilard")==0){ //on sait que une ligne contient 4 cartes donc on boucle sur 4 colonnes 
        int ligneRandom = rand()%4;
        for (int i = 0 ; i < 4;i++){
            supprimeAnyCarte(Myboard,getNom(cartesPosees[ligneRandom][i]));
            addPointsddrs(propritaire,2);}
    }
    else if (strcmp(getNom(mycarte),"Massinissa Merabet")==0){}

    else if (strcmp(getNom(mycarte),"Vitéra Y")==0){
        if (getPointsddrs(propritaire) > getPointsddrs(adversaire) )
            addPointsddrs(adversaire, 3);

        if (getPointsddrs(propritaire) < getPointsddrs(adversaire) )
            addPointsddrs(propritaire, 3);
    }

    else if (strcmp(getNom(mycarte),"Jonas Senizergues")==0){ 
        supprimeCarte(Myboard,"Heures supplémentaires");
    }

    else if (strcmp(getNom(mycarte),"Fetia Bannour")==0){ 
        int verif=0;
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if(strcmp(getNom(cartesRetournees[i]),"Heures supplémentaires")==0)
                verif = 1;
        }
        if(verif == 1){
            for(int j = 0 ;j < 4;j++){
                supprimeAnyCarte(Myboard,getNom(cartesPosees[ligne][j]));
                supprimeAnyCarte(Myboard,getNom(cartesPosees[j][colonne]));
            }
        }
        else
            for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
                if((getFace(cartesRetournees[i]) == 1 )&& (strcmp(getNom(cartesRetournees[i]),"Catherine Dubois")==0 || strcmp(getNom(cartesRetournees[i]),"Anne-Laure Ligozat")==0 
                || strcmp(getNom(cartesRetournees[i]),"Guillaume Burel")==0 ||strcmp(getNom(cartesRetournees[i]),"Christophe Mouilleron")==0 ||strcmp(getNom(cartesRetournees[i]),"Thomas Lim")==0
                ||strcmp(getNom(cartesRetournees[i]),"Julien Forest")==0||strcmp(getNom(cartesRetournees[i]),"Dimitri Watel")==0))
                    addPointsddrs(propritaire,1);
            }
    }
    // On supprime la premere et la derniere colonne et la la premiere et la derniere ligne 
    else if (strcmp(getNom(mycarte),"Catherine Dubois")==0){ 
        supprimeAnyCarte(Myboard,getNom(cartesPosees[ligne][0]));
        supprimeAnyCarte(Myboard,getNom(cartesPosees[ligne][3]));
        supprimeAnyCarte(Myboard,getNom(cartesPosees[0][colonne]));
        supprimeAnyCarte(Myboard,getNom(cartesPosees[3][colonne]));
    }
    else if (strcmp(getNom(mycarte), "Anne-Laure Ligozat")==0){} 

    else if (strcmp(getNom(mycarte),"Guillaume Burel")==0){
        if (getPointsddrs(adversaire) > getPointsddrs(propritaire)){
            addPointsddrs(adversaire, -3);
            addPointsddrs(propritaire, 3);
        }
    }

    else if (strcmp(getNom(mycarte),"Christophe Mouilleron")==0){
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if(strcmp(getNom(cartesRetournees[i]),"Heures supplémentaires")==0){
                for(int j = 0 ;j < compteurCarteRetourne(Myboard);j++){
                    if(strcmp(getNom(cartesRetournees[j]),"Heures supplémentaires")!=0 &&  strcmp(getNom(cartesRetournees[j]),"Christophe Mouilleron")!=0)
                    supprimeCarte(Myboard,getNom(cartesRetournees[j]));
                }
            }
        }
    }
    else if (strcmp(getNom(mycarte),"Thomas Lim")==0){ 
        int verif=0;
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if(strcmp(getNom(cartesRetournees[i]),"Julien Forest")==0)
                verif = 1;
        }
        if(verif == 0){
            for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
                if(strcmp(getNom(cartesRetournees[i]),"FISE")==0)
                    addPointsddrs(propritaire,3);
            }
        }
        else {
            for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
                if(strcmp(getNom(cartesRetournees[i]),"FISE")==0)
                    addPointsddrs(adversaire,-1);
            }
        }
    }
    else if (strcmp(getNom(mycarte),"Julien Forest")==0){
        if (compteurCarteSameNom(Myboard,"Café")>=1){
            for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
                if(strcmp(getNom(cartesRetournees[i]),"FISE")==0)
                    addPointsddrs(propritaire,6);
            }
        }
    }
    else if (strcmp(getNom(mycarte),"Dimitri Watel")==0){ 
        if (compteurCarteSameNom(Myboard,"Thé")>=1){
            for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
                if(strcmp(getNom(cartesRetournees[i]),"FISA")==0 || strcmp(getNom(cartesRetournees[i]),"FC")==0)
                    addPointsddrs(propritaire,3);
            }
        }
    }
    else if (strcmp(getNom(mycarte),"Djibril-Aurélien-Dembele-Cabot")==0){ 
        compteur= 0;
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if(getPos(cartesRetournees[i])[0] == ligne)
                compteur++;
        }
        if (compteur > 3)
            addPointsddrs(propritaire,5);

    }
    else if (strcmp(getNom(mycarte),"Eric Lejeune")==0){ }

    else if (strcmp(getNom(mycarte),"Lucienne Pacavé")==0){
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if((strcmp(getNom(cartesRetournees[i]),"FISA")==0) && (getPos(cartesRetournees[i])[0] == ligne || getPos(cartesRetournees[i])[1] == colonne) )
                addPointsddrs(propritaire,5);
        }
    }

    else if (strcmp(getNom(mycarte),"Katrin Salhab")==0){ 
        compteur = 0;
        for(int i = 0 ;i < compteurCarteRetourne(Myboard);i++){
            if(strcmp(getNom(cartesRetournees[i]),"Djibril-Aurélien-Dembele-Cabot")==0 )
                compteur ++;
            if(strcmp(getNom(cartesRetournees[i]),"Eric Lejeune")==0 )
                compteur++;
            if (strcmp(getNom(cartesRetournees[i]),"Lucienne Pacavé")==0)
            compteur ++;
                    
        }
        if(compteur == 3)
            addPointsddrs(propritaire,10);
        for(int colonneChange = 0 ; colonneChange < 4; colonneChange ++){
            if(cartesPosees[ligne][colonneChange] != NULL && getNom(cartesPosees[ligne][colonneChange]) != getNom(mycarte))
                setFace(cartesPosees[ligne][colonneChange],1);
        }
    } 
    //On recupere la position de la carte et on regarde si c'est la derniere carte si oui la manche se termine et on donne la victoire de la manche 
    //a la faction qui l'a pausé       
    else if (strcmp(getNom(mycarte),"Laurent Prével")==0){  
        if(ligne == 3 && colonne==3)
            incrNbMancheGagnees(propritaire);
    }
    else{
        return;}

}





//________________________________________________________________________________________________________

carte activateCard(board b){
    int i,j;
    carte c = newCarte();
    while(i<4){
        while(j<4){
            if(getFace(getCartesPosees(b)[i][j])==0){ //Recherche de la carte la plus en haut à gauche
            c = getCartesPosees(b)[i][j];
            setFace(c,1);
            effetDesCartes(b, c);
            //return c;
            }
            j+=1; 
        }
        i+=1;
    }
    return c;
}

void setFactions(board b, faction* l){
    b->factions = l;
}


