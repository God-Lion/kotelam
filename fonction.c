#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include <math.h>
#include "main.h"
#define TAILLE_MAX 10000
struct compte
{
    int  fileNumero;
    char nom[50];
    char prenom[50];
    char sexe[15];
    char dateDeNaissance[100];
    long double  solde;
    long double  montant;
};
struct compte cp;
int  choix;
char affiche[TAILLE_MAX];
long double  montant;
long double  solde = 0;
int numeroCompte;
FILE *fichier = NULL;

#if defined WIN32 || defined WIN64
#        include <windows.h>
#        define sleep(x) Sleep(1000 * (x))
#else
#        include <unistd.h>
#endif
void politesse()
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int hrs = tm.tm_hour;
    if (hrs < 12)
        printf("\n                   BONJOUR %s\n", user);
    else
        printf("\n                   BONSOIR %s\n", user);
}

/*-----------------------------------------------------------------------------------------------------*/

void partiePrincipale()
{
    color(1,7);
    system("cls");
    color(3,7);
    politesse();
    color(1,7);
    printf("\n\n\n\t\t\t\t\t\t\t   KOTELAM\n\n");
    printf("\t\t\t\t\t\t Koperativ Tet Ansanm Pou Lavi Miyo\n\n\n");

    printf("\t\t\t\t 1-CREATION DE COMPTE\n");
    printf("\t\t\t\t 2-DEPOT\n");
    printf("\t\t\t\t 3-RETRAIT\n");
    printf("\t\t\t\t 4-TOUS LES COMPTES\n");
    printf("\t\t\t\t 5-A PROPOS DE LA KOTELAM\n");
    printf("\t\t\t\t 6-RECHERCHER UN COMPTE\n");
    printf("\t\t\t\t 7-QUITTER\n\n");
    printf("\t\t\t\t   ");scanf("%d",&choix);

    switch(choix)
    {
        case 1:
            printf("\n\n\n");
            defilement("                                           ============     ");
            system("cls");
            creationCompte();
            printf("\n\n");
            resterOuQuitter();
        break;
        case 2:
            printf("\n\n\n");
            defilement("                 ============     ");
            system("cls");
            depot(cp.montant);
            printf("\n\n");
            resterOuQuitter();
        break;
        case 3 :
            printf("\n\n\n");
            defilement("                  ============    ");
            system("cls");
            retrait(cp.montant);
            printf("\n\n");
            resterOuQuitter();
        break;
        case 4:
            printf("\n\n\n");
            defilement("                  ============     ");
            system("cls");
            printf("\n\n\n\n LES COMPTES \n\n\n");
            fichier = fopen("clientKotelam.txt","r");
                if(fichier == NULL)
                    exit(1);
                    while(fgets(affiche,TAILLE_MAX,fichier) != NULL)
                        printf("%s", affiche);

                    fclose(fichier);
            printf("\n\n");
            resterOuQuitter();
        break;
        case 5:
            printf("\n\n\n");
            defilement("                  ============       ");
            system("cls");
            information();
            printf("\n\n");
            resterOuQuitter();
        break;
        case 6:
            printf("\n\n\n");
            defilement("                  ============       ");
            system("cls");
            rechercheCompte();
            printf("\n\n");
            resterOuQuitter();
        break;
        case 7:
             system("cls");
             printf("\n\n\n\n\n\n\n\n");
             defilement("                        ...SHUT DOWN...                     ");
             printf("\n\n\n");
        break;
        default:
            printf("MAUVAIS CHOIX\n");
            resterOuQuitter();
    }
}

/*-----------------------------------------------------------------------------------------------------*/

    void creationCompte()
{
    printf("\n\n\n\n\n\t\t\tCREATION DE COMPTE\n\n\n");
    printf("\t\t\t\t 1- COMPTE EPARGNE A VUE\n");
    printf("\t\t\t\t 2- COMPTE EPARGNE A TERME\n");
    printf("\n\t\t\t 3- MENU PRINCIPAL\n");
    scanf("%d",&choix);

    switch(choix)
    {
        case 1:
            system("cls");
            printf("\n\n\n\n\n\t\t     CREATION COMPTE EPARGNE A VUE\n");
            enregistrement();
        break;
        case 2:
            system("cls");
            printf("\n\n\n\n\n\t\t     CREATION COMPTE EPARGNE A TERME\n");
            enregistrement();
        break;
        case 3:
            system("cls");
            printf("\n\n\n\n\n\n\n\n\n");
            defilement("                       MENU PRINCIPAL                   ");
            system("cls");
            partiePrincipale();
        default:
            printf("MAUVAIS CHOIX\n\n");
            printf("            \t\tPRESSEZ 1 pour retourner au menu PRECEDENT\n\n");
            printf("PRESSEZ 2 pour retourner au MENU PRINCIPAL ou pour QUITTER le programme\n      ");
                scanf("%d",&choix);

            switch(choix)
            {
                case 1:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\n\n");
                    defilement("             RETOUR...         ");
                    system("cls");
                    creationCompte();
                break;
                case 2:
                    system("cls");
                    printf("\n\n\n\n");
                    resterOuQuitter();
                break;
                default:
                    system("cls");
                    printf("\n\n\n\n\n\n\n\t\t\tMAUVAIS CHOIX");
            }
       }
}

/*-----------------------------------------------------------------------------------------------------*/

void enregistrement()
{
    int n;
    i = 1;

        printf("\n\n\t\t\t\tCOMBIEN DE COMPTE VOULEZ-VOUS CREER?\n");
        printf("\n\t\t\t\t\t");
        scanf("%d", &n);

        for(i = 1 ; i <= n ; i++)
        {
            printf("\n");
            printf("\t\t\t\t\t\t    *NOM :              ");
            fflush(stdin);
                fgets(cp.nom, sizeof (cp.nom), stdin);
            clean(cp.nom, stdin);
            printf("\n\t\t\t\t\t\t *PRENOM :              ");
            fflush(stdin);
                fgets(cp.prenom, sizeof (cp.prenom), stdin);
            clean(cp.prenom, stdin);
            printf("\n\t\t\t\t*GENRE(masculin/feminin) :              ");
            fflush(stdin);
                fgets(cp.sexe, sizeof (cp.sexe), stdin);
            clean(cp.sexe, stdin);
            printf("\n\t\t\t\t      *DATE DE NAISSANCE :              ");
            fflush(stdin);
                fgets(cp.dateDeNaissance, sizeof (cp.dateDeNaissance), stdin);
            clean(cp.dateDeNaissance, stdin);
            //printf("\n\t\t\t     *ENTREZ LE NUMERO DU COMPTE :              ");
              //  scanf("%d",&cp.fileNumero);
            printf("\n\t\t\t      *ENTREZ LE MONTANT INITIAL :              ");
                scanf("%Lf", &cp.montant);
            printf("\n\t\t\t      *ENTREZ LE MONTANT INITIAL :              %Lf", cp.montant);
            /*if (cp.montant < 500)
            {

                printf("\n\n\n\t\tMontant insuffisant\n Ajustez le:\n");
                printf("\n\t\t\t\t      *ENTREZ LE MONTANT INITIAL:             ");
                    scanf("%Lf", &cp.montant);
            }
            else
            {*/
                printf("\n\n");
                fichier=fopen("clientKotelam.txt","a");
                 if(fichier == NULL)
                    exit(1);

                	cp.fileNumero = numero_compte();
                fprintf(fichier,"%d %s %s %s %s %.2Lf \n\n", cp.fileNumero, cp.nom, cp.prenom, cp.sexe, cp.dateDeNaissance, cp.montant);
                fclose(fichier);
                printf("\n\t\t\t\t\t\t\t LE COMPTE A ETE CREE AVEC SUCCES");
                printf("\n\n\t\t\t\t\t\t\t LE CLIENT %s %s  DE NUMERO COMPTE #%d", cp.nom, cp.prenom, cp.fileNumero);
           /* }*/
        }
}

/*-----------------------------------------------------------------------------------------------------*/

    int numero_compte()
{
    int nombreMystere = 0;
    const int MAX = 100, MIN = 1;

        srand(time(NULL));
        nombreMystere = (rand() % (MAX - MIN + 1)) + MIN;
    return nombreMystere;
}

/*-----------------------------------------------------------------------------------------------------*/

void depot()
{
    FILE *fic;
    long double nouvSoldeDepot;

        printf("\n\n\n\n\t\t\t\tEntrer le numero du compte de la personne: \n");
        printf("\t\t\t\t");
            scanf("%d", &numeroCompte);
        printf("\n\t\t\t\tEntrez le montant a deposer\n");
        printf("\t\t\t\t");
            scanf("%Lf", &montant);

    fichier=fopen("clientKotelam.txt","r");
    fic=fopen("TempClientKotelam.txt","a");

        do
        {
            fscanf(fichier,"%d %s %s %s %s %Lf \n", &cp.fileNumero, &cp.nom, &cp.prenom, &cp.sexe, &cp.dateDeNaissance, &cp.montant);
            fflush(stdin);

               if(cp.fileNumero != numeroCompte)
               {

                  fprintf(fic,"%d %s %s %s %s %.2Lf \n", cp.fileNumero, cp.nom, cp.prenom, cp.sexe, cp.dateDeNaissance, cp.montant);

               }
               else
               {
                          nouvSoldeDepot = cp.montant + montant;
                          printf("nouvSoldeDepot %.2Lf\n", nouvSoldeDepot);
                 fprintf(fic,"%d %s %s %s %s %.2Lf \n", cp.fileNumero, cp.nom, cp.prenom, cp.sexe, cp.dateDeNaissance, cp.montant=nouvSoldeDepot);
               }

        }while(!feof(fichier));

    fclose(fic);
    fclose(fichier);
    remove("clientKotelam.txt");
    rename("TempClientKotelam.txt","clientKotelam.txt");
    printf("\n\n\n\n\t\t\t\tvous venez d'ajouter %.2Lfa ton compte\n\t\t\t\t votre solde est: %.2Lf", montant, nouvSoldeDepot);
}

/*-----------------------------------------------------------------------------------------------------*/

void retrait()
{
    FILE *fic;
    long double nouvSoldeRetrait = 0;

        printf("\n\n\n\n\t\t\t\tEntrer le numero du compte de la personne: \n");
        printf("\t\t\t\t");
            scanf("%d", &numeroCompte);
        printf("\n\n\n\n\t\t\t\tEntrez le montant a retirer\n");
        printf("\t\t\t\t");
            scanf("%Lf", &montant);

    fichier=fopen("clientKotelam.txt","r");
    fic=fopen("TempClientKotelam.txt","a");

    do
    {
        fscanf(fichier,"%d %s %s %s %s %Lf \n", &cp.fileNumero, &cp.nom, &cp.prenom, &cp.sexe, &cp.dateDeNaissance, &cp.montant);
              fflush(stdin);

        if(cp.fileNumero != numeroCompte)
            fprintf(fic,"%d %s %s %s %s %Lf \n", cp.fileNumero, cp.nom, cp.prenom, cp.sexe, cp.dateDeNaissance, cp.montant);
        else
        {
            if(cp.montant < montant + 500)
            {
                printf("\n\n\n");
                printf("VOUS N'AVEZ PAS SUFFISAMMENT DE FONDS POUR EFFECTUER CE RETRAIT\n");
                getchar();
                printf("\t\t\tPressez enter pour continuer\n");
                defilement("       MENU PRINCIPAL...");
                system("cls");
                partiePrincipale();
            }
            else
            {
                nouvSoldeRetrait=cp.montant-montant;
                fprintf(fic,"%d %s %s %s %s %.Lf \n", cp.fileNumero, cp.nom, cp.prenom, cp.sexe, cp.dateDeNaissance, cp.montant = nouvSoldeRetrait);
            }
        }
    }while(!feof(fichier));
    fclose(fic);
    fclose(fichier);
    remove("clientKotelam.txt");
    rename("TempClientKotelam.txt","clientKotelam.txt");
    printf("\n\n\n\n\t\t\t\tvous venez de retirer %.Lf a ton compte\n\t\t\t\t votre solde est: %.Lf", montant, nouvSoldeRetrait);
    fflush(stdin);
}

/*-----------------------------------------------------------------------------------------------------*/

int recherche(int number)
{
    fichier=fopen("clientKotelam.txt","r");
    do
    {
        fscanf(fichier,"%d %s %s %s %s %Lf \n", &cp.fileNumero, &cp.nom, &cp.prenom, &cp.sexe, &cp.dateDeNaissance, &cp.montant);
        fflush(stdin);
        if(cp.fileNumero == number)
        {
            fclose(fichier);
            return 1;
        }
    }while(!feof(fichier));
    fclose(fichier);
    return -1;
}

/*-----------------------------------------------------------------------------------------------------*/

void rechercheCompte()
{

    FILE *fichier;
    int num;
    printf("Entrer le numero du compte de la personne: \n");
        scanf("%d", &num);
    fichier = fopen("clientKotelam.txt","r");
    do
    {
        fscanf(fichier,"%d %s %s %s %s %Lf \n", &cp.fileNumero, &cp.nom, &cp.prenom, &cp.sexe, &cp.dateDeNaissance, &cp.montant);
        fflush(stdin);
        if(cp.fileNumero == num)
        {
            printf("\n\n\n");
            printf("NUMERO COMPTE:        %d\n", cp.fileNumero);
            printf("   NOM:               %s\n", cp.nom);
            printf("PRENOM:               %s\n", cp.prenom);
            printf("  SEXE:               %s\n", cp.sexe);
            printf(" SOLDE:               %d\n", cp.montant);
            printf("DATE DE NAISSANCE:    %s\n", cp.dateDeNaissance);
        }
    }while(!feof(fichier));
    fclose(fichier);
}

/*-----------------------------------------------------------------------------------------------------*/

static void
scroll(char const *s)
{
    char const *p;

    for (p = s + strlen(s); p != s ; p--)
    {
        char const *q;

        for (q = p ; *q != '\0'; q++)
            putchar(*q);

        for (q = s; q != p ; q++)
            putchar(*q);

        putchar('\r');
        fflush(stdout);
        sleep(0.06);
    }
}

/*-----------------------------------------------------------------------------------------------------*/

void defilement(char const *s)
{
    scroll(s);
}

/*-----------------------------------------------------------------------------------------------------*/

void information()
{
    printf("A PROPOS\n");
}

void resterOuQuitter()
{
    printf("\n\n");
    printf("Pressez 1 pour retourner dans le MENU PRINCIPAL                   Pressez 0 pour QUITTER le programme\n\n");
            scanf("%d",&choix);
    switch(choix)
    {
        case 0:
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            defilement("                    ...SHUT DOWN...                     ");
            printf("\n\n\n");
        break;
        case 1:
            system("cls");
            printf("\n\n\n\n\n\n\n\n");
            defilement("               ...MENU PRINCIPAL...");
            system("cls");
            partiePrincipale();
        break;
        default :
            printf("QUITTER");
    }
}

/*-----------------------------------------------------------------------------------------------------*/

void clean(const char *buffer, FILE *fp)
{
    char *p = strchr(buffer,'\n');
    if (p != NULL)
        *p = 0;
    else
    {
        int c;
        while ((c = fgetc(fp)) != '\n' && c != EOF);
    }
}

/*-----------------------------------------------------------------------------------------------------*/

void basdepage()
{

    printf("\n\t\t\t\t      %s _ %s\n", __DATE__, __TIME__);
    printf("\n\t\t\t\t copyright@@@ design by STELLAIRE");
}
