#include "SystemExpert.h"

// Fonction pour créer une nouvelle règle
listeRegle creerListeRegle(){
    listeRegle l = (listeRegle)malloc(sizeof(Regle));       
    l->premisse = NULL;
    l->conclusion = '\0';
    return l;
}

// Fonction pour créer une nouvelle propositions
listeProposition creerProposition(){
    listeProposition l = (listeProposition)malloc(sizeof(Proposition));
    l->caractere = '\0';
    l->next = NULL;
    return l;
}

// Fonction pour ajouter une proposition à la fin de la liste
listeProposition ajouterPropositionQ(listeProposition l, char propo){
    listeProposition k = l;
    listeProposition temp = creerProposition();
    temp->caractere = propo;

     // Si la liste est vide, retourne la nouvelle proposition comme liste
    if(k == NULL){
        return temp;
    }
    else{
    while(k->next != NULL){
        k = k->next;
    }
    k->next = temp;
    return l;
    }
}

// Fonction pour ajouter une conclusion à une règle
void ajouterConclusionRegle(char c, listeRegle l){
    // Vérifie si la règle n'est pas nulle
    if(l!=NULL){
    l->conclusion = c;
    }
}

// Fonction pour tester si une proposition est présente dans la liste
bool testProposition(listeProposition l, char propo){
    bool test = false;
    // Si la liste est vide, retourne faux
    if(l == NULL){
        return test;
    }
    if(l->caractere == propo){
        return test = true;
    }
    else{
        test = testProposition(l->next, propo);         // Récursivement, teste la proposition suivante dans la liste
    }
    return test;
} 

// Fonction pour supprimer une proposition de la liste
listeProposition supprimerProposition(listeProposition l, char propo){
    listeProposition k = l;

    // Si la liste est vide, retourne la liste inchangée
    if(l == NULL){
        return l;
    }

    // Si la proposition à supprimer est en tête de liste
    if(l->caractere == propo){
        listeProposition temp = l;
        l = l->next;
        free(temp);
        return l;
    }

    // Parcourt la liste jusqu'à trouver la proposition à supprimer
    while(k->next->caractere != propo && k->next != NULL){
        k = k->next;
    }
    if(k->next!=NULL){
        listeProposition temp = k->next->next;
        free(k->next);
        k->next = temp;
    }
    return l;
}

// Fonction pour tester si la liste de propositions d'une règle est vide
bool testRegleVide(listeProposition l){
    bool test = false;
    // Si la liste est vide, retourne vrai
    if(l == NULL){
        return test = true;
    }
    return test;
}

// Fonction pour accéder au caractère en tête de la liste de propositions d'une règle
char accederTeteListeProposition(listeRegle l){
    // Si la règle est nulle, retourne le caractère nul
    if(l==NULL){
        return '\0';
    }
    return l->premisse->caractere;
}

// Fonction pour accéder à la conclusion d'une règle
char accederConclusion(listeRegle l){
    // Si la règle est nulle, retourne le caractère nul
    if(l==NULL){
        return '\0';
    }
    return l->conclusion;
}
