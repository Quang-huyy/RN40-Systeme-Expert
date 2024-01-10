#include "SystemExpert.h"

// Fonction pour remplir la base de connaissances avec des règles prédéfinies
listeBaseDeConnaissance remplirBaseDeConnaissance() {
    // Crée une nouvelle base de connaissances
    listeBaseDeConnaissance l = creerBaseDeConnaisance();
    
    // Règle 1
    listeRegle nouvelleRegle1 = creerListeRegle();
    nouvelleRegle1->premisse = ajouterPropositionQ(nouvelleRegle1->premisse, 'A');
    nouvelleRegle1->premisse = ajouterPropositionQ(nouvelleRegle1->premisse, 'B');
    ajouterConclusionRegle('D', nouvelleRegle1);
    l = ajouterRegleQ(l, nouvelleRegle1);

    // Règle 2
    listeRegle nouvelleRegle2 = creerListeRegle();
    nouvelleRegle2->premisse = ajouterPropositionQ(nouvelleRegle2->premisse, 'C');
    nouvelleRegle2->premisse = ajouterPropositionQ(nouvelleRegle2->premisse, 'D');
    ajouterConclusionRegle('F', nouvelleRegle2);
    l = ajouterRegleQ(l, nouvelleRegle2);

    return l;
}

// Fonction pour exécuter le moteur d'inférence
listeProposition moteurInference(listeBaseDeConnaissance l, listeProposition baseDeFait, listeProposition listeResultat) {
    while (baseDeFait != NULL) {        // Parcourt chaque fait dans la base de faits
        listeBaseDeConnaissance bdc = l;        
        while (bdc != NULL) {       // Parcourt chaque règle dans la base de connaissances
            if (bdc->regle != NULL) {       // Vérifie si la règle a une prémisse non vide
                    listeProposition temp = bdc->regle->premisse;       // Récupère la liste de prémisse de la règle
                    bool trouve = false;
                    while (temp != NULL && !trouve) {       // Parcourt chaque proposition dans la prémisse                    
                        if (testProposition(temp, baseDeFait->caractere)) {     // Vérifie si la proposition correspond au fait
                            trouve = true;
                            bdc->regle->premisse =      
                                supprimerProposition(bdc->regle->premisse, baseDeFait->caractere);      // Met à jour la prémisse en supprimant la proposition correspondante
                            if (testRegleVide(bdc->regle->premisse)) {      // Vérifie si la prémisse est devenue vide
                                listeResultat = ajouterPropositionQ(listeResultat, bdc->regle->conclusion);     // Ajoute la conclusion à la liste des résultats
                                baseDeFait = ajouterPropositionQ(baseDeFait, bdc->regle->conclusion);       // Ajoute la conclusion à la base de faits pour les itérations suivantes
                            }
                        } 
                        else {
                            temp = temp->next;
                        }
                    }
            }
            bdc = bdc->next;
        }
        baseDeFait = supprimerProposition(baseDeFait, baseDeFait->caractere);       // Supprime le fait actuel de la base de faits pour passer au suivant
    }
    return listeResultat;       // Retourne la liste des résultats de l'inférence
}



int main() {
    int input;
    int input2;
    baseDeFait = NULL;
    listeProposition listeResultat = NULL;     // Liste pour stocker les résultats de l'inférence
    listeBaseDeConnaissance BaseDeConnaissance = remplirBaseDeConnaissance();
    do {
        printf("Type 1 to enter a fact, 2 to launch the inference engine, 3 to display the knowledge base, 4 to display the fact base, 5 to reset the knowledge base.\n");
        scanf(" %d", &input);
        
        switch (input) {

            case 1:
                do{
                    printf("Type 1 to enter a fact, 2 to quit.\n");
                    scanf("%d", &input2);
                    if (input2 == 1) {
                        char fait;
                        printf("Enter a fact : ");
                        scanf(" %c", &fait);
                        baseDeFait = ajouterPropositionQ(baseDeFait, fait);
                    } else if (input2 == 2) {
                        break;
                    }
                }while(input2 == 1 || input2 == 2);
                break; 

            case 2:
                listeResultat = moteurInference(BaseDeConnaissance, baseDeFait,listeResultat);
                afficherListeresultat(listeResultat);
                baseDeFait = NULL;
                listeResultat = NULL;
                break;

            case 3:
                while (BaseDeConnaissance != NULL) {
                    afficherRegle(BaseDeConnaissance->regle);
                    BaseDeConnaissance = BaseDeConnaissance->next;
                }
                break;

            case 4:
                afficherListeProposition(baseDeFait);
                break;
            case 5:
                BaseDeConnaissance = remplirBaseDeConnaissance();
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        }while(input == 1 || input == 2 || input == 3 || input == 4 || input == 5 || input2 == 1 || input2 == 2); 

    return 0;
}
