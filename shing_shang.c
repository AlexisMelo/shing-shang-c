#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialisation.h"
#include "deplacement.h"

int main()
{
	int x=0,y=0;
	int flag=ROUGE;
	Pion pion[6];
	Pion portail[2];
	Cellule cellule[TAILLE][TAILLE] = {0};
	creation_pion(pion, portail);
	creation_plateau(cellule, pion, portail);
	affichage_plateau(cellule);

	while(flag>=0)
	{
		do
		{
			saisiepion(&x, &y);
		}while(verif_saisie_pion(x, y, flag, cellule, pion) != 1);

		do
		{
			saisiearrive(&x, &y);
		}while(verif_saisie_arrive(x, y, flag, cellule, pion) != 1);


		printf("ozeroz\n");
		printf("%d,%d",x,y);
		//saisiearrive(&x,&y);
	}


}
