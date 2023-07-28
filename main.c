#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <mmsystem.h>
#include "main.h"

int main(int argc, char* argv[])
{
    color(14,0);
            system("cls");
      afficher_kotelam();
    color(9,0);
      loading();
    color(0,3);
            system("cls");
        printf("\n\n\n\n\n\n\n");
        defilement("                   BIENVENUE A KOTELAM APP...");
        printf("\n\n\n\n\t\t\t\tPressez ENTER pour continuer...");
    getchar();
        //Beep(1000,60); Beep(4000,60); Beep(3000,60); Beep(2000,60);
            system("cls");
    access();
    forme2();
    basdepage();
    getch();
    return 0;
}
