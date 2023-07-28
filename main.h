#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#if defined WIN32 || defined WIN64
#include <windows.h>
#define sleep(x) Sleep(1000 * (x))
#else
#include <unistd.h>
#endif

#define TAILLE_MAX 10000
#define N 1000
struct Pass_sys
{
	char password_systeme[N];
	char name_systeme[N];
};
struct Pass_sys pass;
/*struct compte
{
	char nom[50];
	char prenom[50];
	char sexe[15];
	char dateDeNaissance[100];
	int  fileNumero;
	int  solde;
	int  montant;
};

int  choix;
char affiche[TAILLE_MAX];
int  montant;
int  solde=0;
int numeroCompte;

FILE *fichier = NULL;

struct compte cp;
*/
char user[N];
int i;
void afficher_kotelam();
void loading();
void forme1();
char *masquer_password();
int rech_user_pass(char Username_saisie[N], char password_saisie[N]);
void access();
void politesse();
void color(int t,int f);
void defilement(char const *s);
void basdepage();
void creationCompte();
void enregistrement();
void depot();
void retrait();
void information();
void partiePrincipale();
int recherche(int number);
void rechercheCompte();
void clean(const char *buffer, FILE *fp);
void forme2();
void resterOuQuitter();














