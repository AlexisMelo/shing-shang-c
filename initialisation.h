#define RIEN 0
#define VIDE 1
#define TAILLE 10

typedef struct
{
  int type;
  int couleur;
} Pion;

typedef struct
{
  int deplacable;
  Pion *pion;
} Cellule;

enum couleur
{
  ROUGE,
  BLEU
};

enum type
{
  SINGE,
  LION,
  DRAGON,
  PORTAIL
};

void creation_plateau(Cellule cellule[][TAILLE], Pion pion[], Pion portail[]);
void creation_pion(Pion pion[], Pion portail[]);
void affichage_plateau(Cellule cellule[][TAILLE]);

void saisiepion(int* p_x, int* p_y);
void saisiearrive(int* p_x, int* p_y);
int verif_saisie_pion(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[]);
int verif_saisie_arrive(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[]);
int verif_saisie_arrive_vide(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[]);
int verif_saisie_arrive_singe(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[]);
int verif_saisie_arrive_lion(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[]);
int verif_saisie_arrive_dragon(int x, int y, int flag, Cellule cellule[][TAILLE], Pion pion[]);
