#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deplacement.h"
#include "initialisation.h"

void saisiepion(int* p_x, int* p_y)
{
  printf("Coordonnées de départ \n");
  scanf("%d",p_x);
  scanf("%d",p_y);

}

void saisiearrive(int* p_x, int* p_y)
{
  printf("Coordonnées d'arrivée \n");
  scanf("%d",p_x);
  scanf("%d",p_y);
}

int verif_saisie_arrive(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[])
{
  int res=0;
  verif_saisie_arrive_vide(x,y,flag,cellule,pion);
  if (cellule[x][y].pion->type==SINGE)
  {
    res=verif_saisie_arrive_singe(x,y,flag,cellule,pion);
  }
  if (cellule[x][y].pion->type==LION)
  {
    res=verif_saisie_arrive_lion(x,y,flag,cellule,pion);
  }
  if (cellule[x][y].pion->type==DRAGON)
  {
    res=verif_saisie_arrive_dragon(x,y,flag,cellule,pion);
  }
  return res;
}

int verif_saisie_pion(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[])
{
  int res = 0;

  if(cellule[x][y].deplacable != 1
    && cellule[x][y].pion != NULL
    && cellule[x][y].pion->type != PORTAIL)
  {
    if(flag == cellule[x][y].pion->couleur)
    {
      res = 1;
    }
  }

  return res;
}

int verif_saisie_arrive_vide(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[])
{
  int res = 0;

  if(cellule[x][y].deplacable != 1
    && (cellule[x][y].pion == NULL
    || (cellule[x][y].pion->type == PORTAIL
    && cellule[x][y].pion->couleur != flag)))
  {
    res=1;
  }

  return res;
}
