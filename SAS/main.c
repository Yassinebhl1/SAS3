#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h> // Include string.h for string manipulation functions

int k = 0; // Initialize k to zero

struct tacheList
{
    int id;
    int status;
    int jour;
    int annee;
    int mois;
    char titre[100];
    char description[500];
};
struct tacheList taches[100]; // Define the global array with a specific size
struct tacheList nvtache;

void ajouter()
{

    nvtache.id = k + 1;

    printf("identifiant:%d", nvtache.id); //identifiant
    printf("\nTitre:");                  //titre
    scanf(" %[^\n]s", nvtache.titre);
    printf("description:"); //description
    scanf(" %[^\n]s", nvtache.description);
    printf("deadline:");
    printf("\njour: ");
    scanf("%d",&nvtache.jour);
    printf("mois: ");
    scanf("%d",&nvtache.mois);
    printf("annee: ");
    scanf("%d",&nvtache.annee);

    printf("1.TODO        2.DOING        3.DONE");
    printf("\nstatus:");
    scanf("%d", &nvtache.status);
    taches[k] = nvtache;
    k++;
    printf("Task added successfully.\n");
    printf("\n");
}

void trierAlphabetique()
{
    // Function to sort tasks alphabetically by title
    int i, j;
    struct tacheList temp;

    for (i = 0; i < k - 1; i++)
    {
        for (j = 0; j < k - i - 1; j++)
        {
            if (strcmp(taches[j].titre, taches[j + 1].titre) > 0)
            {
                temp = taches[j];
                taches[j] = taches[j + 1];
                taches[j + 1] = temp;
            }
        }
    }
}

void affichagelist()
{
    printf("\nListe de toutes les taches:\n");
    for (int i = 0; i < k; i++)
    {
        printf("<<<<<<<<tache numero:%d>>>>>>>>", i + 1);
        printf("\nidentifiant:%d", taches[i].id); //identifiant
        printf("\nTitre:%s", taches[i].titre);   //titre
        printf("\ndescription:%s", taches[i].description); //description
        printf("\ndeadline:");
        printf("jour: ");
        printf("mois: ");
        printf("annee: ");
        printf("\n1.TODO        2.DOING        3.DONE");
        switch (taches[i].status)
        {
        case 1:
            printf("\nstatut :TODO");
            break;
        case 2:
            printf("\nstatut :DOING");
            break;
        case 3:
            printf("\nstatut :DONE");
            break;
        default:
            printf("\nStatut : Inconnu");
            break;
        }
        printf("\n");
    }
    printf("\n");
}
void modifier()
{
    int n;
    int i;
    int idmodifier;
    printf("enter l'identifiant qui vous voulez modifier: ");
    scanf("%d",&idmodifier);
    for(i=0; i<k; i++)
    {
        if(taches[i].id == idmodifier)
        {

            printf(" -->1.description\n");
            printf(" -->2.status\n");
            printf(" -->3.deadline\n");
            printf("votre choix est: ");
            scanf("%d",&n);
            switch(n){
            case 1:
                printf("modifier la discreption:");
                scanf(" %[^\n]s",&taches[i].description);
                break;
            case 2:
                printf("modifier les status:(1.TODO     2.DOING     3.DONE) ");
                scanf("%d", &taches[i].status);
                break;
           /* case 3:
                printf("modifier les deadlines:");
                scanf("");
                break;*/



            }
        }

    }

}





void removelist() {}

int main()
{
    int choix;

    puts("     /============================================================\\");
    puts("                                  MENU                             ");
    puts("     \\============================================================/");

    puts("------------------>1. Ajouter une nouvelle tache");
    puts("------------------>2. Ajouter plusieurs nouvelles taches");
    puts("------------------>3. Afficher la liste de toutes les tâches"); // Added option for sorting
    puts("------------------>4. Modifier une tache:");
    puts("------------------>5. Supprimer une tache par identifiant");
    puts("------------------>6. Statistiques");
    puts("------------------>7. Rechercher les Taches");
    puts("------------------>8. Exit");

    printf("-->> ");
    scanf("%d", &choix);

    while (true)
    {
        switch (choix)
        {
            int n;
        case 1:
            ajouter();
            main();
            return 0;
            break;
        case 2:
            printf("combien de taches souhaitez-vous ajouter: ");
            scanf("%d", &n);
            for (int i = 0; i < n; i++)
            {
                ajouter();
            }
            main();
            return 0;
            break;
        case 3:
            printf("    3. Afficher la liste de toutes les taches:\n");
            trierAlphabetique(); // Call the sorting function
            affichagelist();
            main();
            return 0;
            break;
        case 4:
            printf("    4. Modifier une tache:\n");
            modifier();
            main();
            return 0;
            break;
        case 5:
            printf("    5. Supprimer une tache par identifiant:\n");
            break;
        case 6:
            printf("    6. Statistiques:\n");
            break;
        case 7:
            printf("    7. Rechercher les Taches:\n");
            break;
        case 8:
            return 0;
            break;
        default:
            printf("Choix invalide. Veuillez réessayer.\n");
            main();
            return 0;
        }
    }

    return 0;
}
