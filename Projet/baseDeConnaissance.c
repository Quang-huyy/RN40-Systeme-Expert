#include "SystemExpert.h"

// Fonction pour créer une nouvelle base de connaissances
listeBaseDeConnaissance creerBaseDeConnaisance(){
    listeBaseDeConnaissance l = (listeBaseDeConnaissance)malloc(sizeof(BaseDeConnaissance));
    l->regle = NULL;
    l->next = NULL;
    return l;
}

// Fonction pour ajouter une règle à la fin de la base de connaissances
listeBaseDeConnaissance ajouterRegleQ(listeBaseDeConnaissance l, listeRegle r){
    listeBaseDeConnaissance k = l;
    listeBaseDeConnaissance temp = creerBaseDeConnaisance();
    temp->regle = r;
    while(k->next != NULL){
        k = k->next;
    }
    k->next = temp;
    return l;
}
// Fonction pour obtenir la première règle d'une base de connaissances
listeBaseDeConnaissance PremiereRegle(listeBaseDeConnaissance l){
    // Si la base de connaissances est vide, retourne NULL
    if(l==NULL){
        return NULL;
    }
    return l;
}