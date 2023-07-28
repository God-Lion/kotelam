/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>*/
#include "main.h"
/*
struct Pass_sys
{
	char password_systeme[N];
	char name_systeme[N];
};
struct Pass_sys pass;*/
//char user[N];
//int i = 0;
char *masquer_password();
int rech_user_pass(char Username_saisie[N], char password_saisie[N]);
void access();
  void access()
{

	char *pass;

	system("cls");
	forme1();
    printf("\n\t\t\t\t\t\t| Username           |\n");
    printf("\t\t\t\t\t\t|                    |\n");
    printf("\t\t\t\t\t\t| ");
    	scanf("%s", user);
    printf("\t\t\t\t\t\t|____________________|\n");
    printf("\t\t\t\t\t\t|                    | \n");
	printf("\t\t\t\t\t\t| Password           | \n");
    printf("\t\t\t\t\t\t|                    | \n");
    printf("\t\t\t\t\t\t| ");
			pass = masquer_password();
	if (rech_user_pass(user, pass) == 1)
	{
		partiePrincipale();
	}
	else
	{
		for (i = 0 ; i < 3 ; i++)
		{
			if (rech_user_pass(user, pass) != 1)
			{
				system("cls");
				forme1();
				printf("\n\t\t\t\t\t\t| Username again     |\n");
    			printf("\t\t\t\t\t\t|                    |\n");
    			printf("\t\t\t\t\t\t| ");
    				scanf("%s", user);
    			printf("\t\t\t\t\t\t|____________________|\n");
    			printf("\t\t\t\t\t\t|                    | \n");
				printf("\t\t\t\t\t\t| Password again     | \n");
    			printf("\t\t\t\t\t\t|                    | \n");
    			printf("\t\t\t\t\t\t| ");
					pass = masquer_password();
				if (rech_user_pass(user, pass) == 1)
				{
					partiePrincipale();
				}break;
			}
		}
		if (rech_user_pass(user, pass) != 1)
		{
			printf("\n Can't Connect \n  Wrong User");
		}
	}
}

/*-----------------------------------------------------------------------------------------------------*/

	char *masquer_password()
{
	static char password_saisie[50];
	char c = ' ';
	//int i = 0;
			 while(i <= 50)
			 {
			 	password_saisie[i] = getch();
			 	c = password_saisie[i];
			 	if (c == 13) break;
			 	else printf("*");
			 	i++;
			 }
			 password_saisie[i] = '\0';
			 i = 0;
	return password_saisie;
}

/*-----------------------------------------------------------------------------------------------------*/

int rech_user_pass(char Username_saisie[N], char password_saisie[N])
{
	FILE *fichier = fopen("password_systeme.password", "r");
	do
	{
		fscanf(fichier," %s %s \n", &pass.name_systeme, &pass.password_systeme);
		fflush(stdin);
		if ((strcmp(pass.name_systeme, Username_saisie)) == 0 && (strcmp(pass.password_systeme, password_saisie)) == 0)
		{
			fclose(fichier);
			return 1;
		}
	} while (!feof(fichier));
	fclose(fichier);
	return -1;
}
