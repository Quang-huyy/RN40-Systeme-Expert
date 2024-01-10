#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct Proposition{
    char caractere;
    struct Proposition *next;
}Proposition;

typedef Proposition* listeProposition;

typedef struct Regle{
    listeProposition premisse;
    char conclusion;
}Regle;

typedef Regle* listeRegle;

typedef struct BaseDeConnaissance{
    listeRegle regle;
    struct BaseDeConnaissance *next;
}BaseDeConnaissance;

typedef BaseDeConnaissance* listeBaseDeConnaissance;

//Affichage
void afficherListeProposition(listeProposition liste);
void afficherRegle(listeRegle regle);

//liste Regle
listeRegle creerListeRegle();
listeProposition creerListeProposition();
listeProposition ajouterPropositionQ(listeProposition l, char propo);
void ajouterConclusionRegle(char c, listeRegle l);
bool testProposition(listeProposition l, char propo);
listeProposition supprimerProposition(listeProposition l, char propo);
bool testRegleVide(listeProposition l);
char accederTeteListeProposition(listeRegle l);
char accederConclusion(listeRegle l);

//Base de connaisance
listeBaseDeConnaissance creerBaseDeConnaisance();
listeBaseDeConnaissance ajouterRegleQ(listeBaseDeConnaissance l, listeRegle r);
listeBaseDeConnaissance PremiereRegle(listeBaseDeConnaissance l);
listeBaseDeConnaissance remplirBaseDeConnaissance();

//Moteur d'inférence
listeProposition baseDeFait;
listeProposition listeResultat;

listeProposition moteurInference(listeBaseDeConnaissance l, listeProposition baseDeFait, listeProposition listeResultat);
void afficherListeresultat(listeProposition l);