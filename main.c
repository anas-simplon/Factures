#include <stdio.h>
#include <string.h>

#define n 100

int actuel = 0;
struct Facture {
  char Client[30];
  char Articles[3];
  float Total_HT;
  int Taux_TVA;
  float Montant_TVA;
  float TTC;
  char Mode_payement[30];

};

void affichage(struct Facture *Facture)
{
    printf("\n*********************************\n\n");
    int i;
    for( i = 0 ; i < actuel ; i++)
    {
        printf("Nom :: %s  | Aticles::  %c,%c ,%C , | Montant TTC : %f\n",Facture[i].Client,Facture[i].Articles[0],Facture[i].Articles[1],Facture[i].Articles[2],Facture[i].TTC);
        printf("----------------------");
    }

    printf("\n*********************************\n\n");

}

int main() {

struct Facture Factures[n];
int  affichage_c= 0,continuer=0, nombre, i,j;

do{
    printf("Entrer le nombre de facture à traiter\n\n");
    scanf("%d",&nombre);

    for( i =0 ; i < nombre ; i++)
    {
        printf("\nSaisissez Le Nom du Client\n");
        scanf("%s",Factures[i+actuel].Client);
        printf("\nSaisissez les Articles: A,B ou C\n");
        for(j=0;j<3;j++){scanf("%s",&Factures[i+actuel].Articles[j]);}
        printf("\nEntrer le Montant HT\n");
        scanf("%f",&Factures[i+actuel].Total_HT);
        printf("\nEntrer le taux de TVA\n");
        scanf("%d",&Factures[i+actuel].Taux_TVA);
        Factures[i+actuel].Montant_TVA =(float) Factures[i+actuel].Total_HT * Factures[i+actuel].Taux_TVA / 100;
        Factures[i+actuel].TTC = Factures[i+actuel].Montant_TVA + Factures[i+actuel].Total_HT;
        while(getchar()!='\n');
    }
    actuel = actuel + i ;

//Menu d'affichage
    do{
    printf("\nPour Continuer Choisissez une Operation\n\n1 :: > AFFICHAGE\n 2 :: > SAISIE\n0 :: > Sortir\n");
    scanf("%d",&continuer);

            if(continuer == 2)          {continuer = 1;affichage_c = 0;}
            else if(continuer == 1)     {affichage(Factures);affichage_c = 1;}
            else                        {continuer = 0; affichage_c = 0;}

    }while(affichage_c == 1);

}while(continuer == 1);

  return 0;
}
