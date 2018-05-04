#include <stdio.h> 
#include <stdlib.h> 
//Type Pile 
typedef struct 
cellule {
    int valeur;
    struct cellule *suivant;
} Cellule;
typedef Cellule * Pile;

Pile creerPile();

int estVide(Pile p);

void empiler(Pile *p, int x);

void depiler(Pile *p);

int sommet(Pile p);

void afficher(Pile p); 

int egal(Pile p,Pile p2);
Pile couper (Pile p,int i);
Pile emplier_deux(Pile p,Pile p2);

int main()
{
    Pile maPile;
    maPile=creerPile();
    int i;
    for(i=0; i<20; i+=2)
        empiler(&maPile,i);
        printf("pile1\n");
    afficher(maPile);
  /*  if(!estVide(maPile))
        printf("Le sommet de la pile est %d\n",sommet(maPile));
    depiler(&maPile);
    afficher(maPile);*/
   Pile p2; 
  p2= creerPile();
  for(i=0; i<20; i+=3)
        empiler(&p2,i);
        printf("pile2:\n");
   afficher(p2);
//if (egal(maPile,p2)==1)
//printf("les deux piles sont egales \n");
//else printf("les deux piles ne sont pas egales\n");

 afficher(couper(maPile,4));
 
 Pile p;
 p=emplier_deux(maPile,p2);
 printf("pile3\n");
  afficher(couper(maPile,4));
 //afficher(p);
    return 0;
}



Pile creerPile()
{
    return NULL;
}

int estVide(Pile p) {
    return p==NULL;
}

void empiler(Pile *p, int x) {
    Cellule *nouv;
    nouv = (Cellule *)malloc(sizeof(*nouv));
    nouv->valeur=x;
    nouv->suivant=*p;
    *p=nouv;
}

void depiler(Pile *p) {
    if(!estVide(*p)){
    Pile ancien;
    ancien = *p;
    *p = (*p)->suivant;
    free(ancien);
    }
    else
        printf("La pile est dÃ©jÃ  vide!\n");
}

int sommet(Pile p) {
    return p->valeur;
}

void afficher(Pile p) {
    Pile tmp;
    tmp = creerPile();
    if(estVide(p)){
        printf("La pile est vide!\n");
    }
    else{
        while(!estVide(p)){
            printf("%d\n",sommet(p));
            empiler(&tmp,sommet(p));
            depiler(&p);
        }
        while(!estVide(tmp)){
            empiler(&p,sommet(tmp));
            depiler(&tmp);
        }
    }
}
int egal (Pile p,Pile p2)
{
	Pile tmp,tmp2;
	int res=1;
	tmp = creerPile();
	tmp2 = creerPile();
	while (!estVide(p) && !estVide(p2) && res==1){
		if(sommet(p)!=sommet(p2))
		 res = 0;
		else {
			empiler(&tmp,sommet(p));
			empiler(&tmp2,sommet(p2));
			depiler(&p);
			depiler(&p2);
		}
	}
	if ( estVide(p) && estVide(p2))
		res = 1;
		while(!estVide(tmp)){
			empiler(&p,sommet(tmp));
			depiler(&tmp);
		}
		while(!estVide(tmp2)){
			empiler(&p2,sommet(tmp2));
			depiler(&tmp2);
		}
	return res;
}
Pile couper (Pile p ,int i)
{int j;
	Pile tmp,tmp2;
	tmp = creerPile();
	tmp2 = creerPile();
	while (!estVide(p))
	{
		empiler(&tmp,sommet(p));
		depiler(&p);
	}
	j=0;
	while(!estVide(tmp) && j<i)
	{
		empiler(&tmp2,sommet(tmp));
		empiler(&p,sommet(tmp));
		depiler(&tmp);
		j++;
	}
	
	while(!estVide(tmp)){
		empiler(&p,sommet(tmp));
		depiler(&tmp);
	}
		 
return tmp2;
}
	
	
	Pile emplier_deux(Pile p,Pile p2)
	{
	Pile tmp;
	tmp = creerPile();
	while (!estVide(p2))
	{
	empiler(&tmp,sommet(p2));
	depiler(&p2);
}
while(!estVide(tmp)){
	empiler(&p,sommet(tmp));
	depiler(&tmp);
}
	while (!estVide(tmp))
	{
	empiler(&p2,sommet(tmp));
	depiler(&tmp);
}
return p;}

	
