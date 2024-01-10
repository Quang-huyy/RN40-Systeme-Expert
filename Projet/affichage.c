#include "SystemExpert.h"

void afficherListeProposition(listeProposition l) {
    printf("Propositions: ");
    while (l != NULL) {
        printf("%c ", l->caractere);
        l = l->next;
    }
    printf("\n");
}

void afficherListeresultat(listeProposition l) {
    printf("Result: ");
    while (l != NULL) {
        printf("%c ", l->caractere);
        l = l->next;
    }
    printf("\n");
}

void afficherRegle(listeRegle r) {
    if (r != NULL) {
        printf("Premisse: \n");
        afficherListeProposition(r->premisse);
        printf("Conclusion: %c\n", r->conclusion);
    }
}