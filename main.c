/**
 * TD Création d'une application console pour gerer la vente d'une moto
 * d'un entreprise X
 *
 * Groupe 08
 * 
 * @author Tsirimanjaka
 * @author Clermond
 * @author Armel
 * @author Tantely
 */

/*
 * Cette instruction veut dire qu'on va utilise la bibliotheque standard
 * d'entrer et de sortie de la language de programmation C.
 *
 * stdio = STantarD d' Input/Otput
 */
#include <stdio.h>

/*
 * Cette instruction veut dire qu'on a definie comme constante de notre application
 * le nombre maximun de donner que l'utilisateur peut entrer dans l'application.
 *
 * La valeur maximale de moto que l'utilisateur peut ajouter dans l'application
 * est de 100
 */
#define MAX_MOTOS 100

// Structure de données pour une moto
typedef struct {
    char nom_client[50];
    char marque[20];
    int numero;
    float prix;
} Moto;

/**
 * Cette fonction est utiliser pour ajouter une moto dans la liste des vente,
 * la fonction va dabord verifier :
 *
 *  * Si l'utilisateur atteint le nombre maximent
 *    de moto inscrit dans la liste. Si la liste est plein la fonction va renvoyer
 *    une alerte a l'ecran que la liste est plein.
 *
 *  * Si la la nombre totale des moto dans la liste ne depasse pas encore la maximale
 *    la fonction va demander a l'utilisateur de donner le nom du client, la marque de
 *    la moto, la numero de la moto et puis la prix de la moto. puis ajouter les information
 *    dans la liste des moto vendue.
 *
 *    @param motos est la tableau contenant la liste des moto vendu
 *    @param nb_motos est l'index du tableau incrementer de 1 a
 *    chaque appele du foction.
 *
 *    @return void;
 */
void ajouter_moto(Moto motos[], int *nb_motos) {

    // Condition qui verifie si la liste est plen ou pas
    if (*nb_motos == MAX_MOTOS) {

        // Renvoye une alerte si la listes est pleine.
        printf("La liste de motos est pleine.\n");
        return;
    }

    // Initialise la structure moto
    Moto moto;

    // Recupere le nom du client
    printf("Nom du client : ");
    fgets(moto.nom_client, 50, stdin);

    // Recupere la marque du moto
    printf("Marque : ");
    fgets(moto.marque, 20, stdin);

    // Recupere le numero du moto
    printf("Numéro : ");
    scanf("%d", &moto.numero);

    // Recupere la prix du moto
    printf("Prix : ");
    scanf("%f", &moto.prix);
    
    getchar(); // Lire le caractère '\n' laissé dans le flux d'entrée par scanf

    // Ajouter les infomation sur la moto vendue dans la liste
    motos[*nb_motos] = moto;

    // Incremente l'indexe
    (*nb_motos)++;
}

// Fonction pour afficher toutes les motos dans la liste
void afficher_motos(Moto motos[], int nb_motos) {
    if (nb_motos == 0) {
        printf("La liste de motos est vide.\n");
        return;
    }

    printf("Liste des motos :\n");
    for (int i = 0; i < nb_motos; i++) {
        printf("Moto %d :\n", i+1);
        printf("\tNom du client : %s", motos[i].nom_client);
        printf("\tMarque : %s", motos[i].marque);
        printf("\tNuméro : %d\n", motos[i].numero);
        printf("\tPrix : %.2f Ar\n", motos[i].prix);
    }
}

int main() {
    Moto motos[MAX_MOTOS];
    int nb_motos = 0;
    int choix = 0;

    while (choix != 3) {
        printf("\nQue voulez-vous faire ?\n");
        printf("1. Ajouter une moto à la liste\n");
        printf("2. Afficher toutes les motos de la liste\n");
        printf("3. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);
        getchar(); // Lire le caractère '\n' laissé dans le flux d'entrée par scanf

        switch (choix) {
            case 1:
                ajouter_moto(motos, &nb_motos);
                break;
            case 2:
                afficher_motos(motos, nb_motos);
                break;
            case 3:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide.\n");
                break;
        }
    }

    return 0;
}
