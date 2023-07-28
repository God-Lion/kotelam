#include "main.h"

void afficher_kotelam()
{
	FILE *fichier = NULL;
	char texte[N];
    	fichier = fopen("kotelam.txt", "r");
     	if (fichier != NULL)
     	{
     		while (fgets(texte, N, fichier) != NULL)
    		{
     			 printf("%s ", texte);
     		}
     		fclose(fichier);
     	}
     	else
     		printf("Something missing in the program");
}

/*-----------------------------------------------------------------------------------------------------*/

  void loading()
{
    int i;
    printf("\n\n\t\t\t\t\t\t     Telechargement\n\n");
    char str[] = "                                                                                                           ";
    for(i = 0 ; i <= 100 ; i++)
    {
        printf("\r|||||%s", str);
        str[i] = '|';
        Sleep(50);
    }
}

/*-----------------------------------------------------------------------------------------------------*/

void forme1()
{
    FILE *fichier = NULL;
    char texte[N];
        fichier = fopen("forme!.txt", "r");
        if (fichier != NULL)
        {
            while (fgets(texte, N, fichier) != NULL)
            {
                 printf("%s ", texte);
            }
            fclose(fichier);
        }
        else
            printf("Something missing in the program");
}

/*-----------------------------------------------------------------------------------------------------*/

void forme2()
{
    FILE *fichier = NULL;
    char texte[N];
        fichier = fopen("forme2.txt", "r");
        if (fichier != NULL)
        {
            while (fgets(texte, N, fichier) != NULL)
            {
                 printf("%s", texte);
            }
            fclose(fichier);
        }
        else
            printf("Something missing in the program");
}

/*-----------------------------------------------------------------------------------------------------*/

  void color(int t,int f)
{
  HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,f*16+t);
}
