#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "initialisation.h"

void creation_plateau(Cellule cellule[][TAILLE], Pion pion[], Pion portail[])
{
	int i,j;

	//Définition des élements deplacable
	for(i=0; i<TAILLE; i++)
	{
		if(i != 4 && i != 5)
		{
			cellule[i][0].deplacable = 1;
		}
	}

	for(i=0; i<TAILLE; i++)
	{
		if(i != 4 && i != 5)
		{
			cellule[i][9].deplacable = 1;
		}
	}

	//Initialisation de toute les valeurs du pointeurs pion à NULL
	for(i=0; i<TAILLE; i++)
	{
		for(j=0; j<TAILLE; j++)
		{
			cellule[i][j].pion = NULL;
		}
	}

	//Pion rouge
	cellule[0][1].pion=&pion[2];
	cellule[0][8].pion=&pion[2];

	cellule[0][2].pion=&pion[1];
	cellule[1][1].pion=&pion[1];
	cellule[0][7].pion=&pion[1];
	cellule[1][8].pion=&pion[1];

	cellule[0][3].pion=&pion[0];
	cellule[1][2].pion=&pion[0];
	cellule[2][1].pion=&pion[0];
	cellule[0][6].pion=&pion[0];
	cellule[1][7].pion=&pion[0];
	cellule[2][8].pion=&pion[0];

	//Pion bleu
	cellule[9][1].pion=&pion[5];
	cellule[9][8].pion=&pion[5];

	cellule[9][2].pion=&pion[4];
	cellule[8][1].pion=&pion[4];
	cellule[9][7].pion=&pion[4];
	cellule[8][8].pion=&pion[4];

	cellule[9][3].pion=&pion[3];
	cellule[8][2].pion=&pion[3];
	cellule[7][1].pion=&pion[3];
	cellule[9][6].pion=&pion[3];
	cellule[8][7].pion=&pion[3];
	cellule[7][8].pion=&pion[3];

	//Portail rouge
	cellule[1][4].pion=&portail[0];
	cellule[1][5].pion=&portail[0];

	//Portail bleu
	cellule[8][4].pion=&portail[1];
	cellule[8][5].pion=&portail[1];

}

void creation_pion(Pion pion[], Pion portail[])
{

  pion[0].type=SINGE;
  pion[0].couleur=ROUGE;

  pion[1].type=LION;
  pion[1].couleur=ROUGE;

  pion[2].type=DRAGON;
  pion[2].couleur=ROUGE;

  pion[3].type=SINGE;
  pion[3].couleur=BLEU;

  pion[4].type=LION;
  pion[4].couleur=BLEU;

  pion[5].type=DRAGON;
  pion[5].couleur=BLEU;

  portail[0].type = PORTAIL;
  portail[0].couleur = ROUGE;

  portail[1].type = PORTAIL;
  portail[1].couleur = BLEU;

}


void affichage_plateau(Cellule cellule[][TAILLE])
{
	int i, j;

	printf("    0  1  2  3  4  5  6  7  8\n");

	for(i=0; i<TAILLE; i++)
	{
		printf(" %d ", i);
		for(j=0; j<TAILLE; j++)
		{

			printf("\033[%dm", 0); //Normal
			printf("\033[%dm", 47);
			printf("\033[%dm", 30);

			if(cellule[i][j].pion != NULL)
			{
				if(cellule[i][j].pion->couleur == ROUGE)
				{
					printf("\033[%dm", 41); //Rouge
				}
				else
				{
					printf("\033[%dm", 44); //Bleu
				}

				printf(" %d ", cellule[i][j].pion->type);
			}
			else if(cellule[i][j].deplacable == 0)
			{
			  printf(" %d ", cellule[i][j].deplacable);
			}
			else
			{
			  printf("   ");
			}

		}
		printf("\n");
	}
}
