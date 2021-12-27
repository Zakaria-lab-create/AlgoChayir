#include <stdio.h>
#include <stdlib.h>


typedef struct element element;
struct element
{
    int donnee;
    struct element *suivant;
};

typedef element* liste_chainee;

void Insert(liste_chainee *sl, int Val)
{
    element *tmp = NULL;
    element *csl = *sl;
    element *elem = malloc(sizeof(element));
    if(!elem) exit(EXIT_FAILURE);
    elem->donnee = Val;
    while(csl && csl->donnee < Val)
    {
        tmp = csl;
        csl = csl->suivant;
    }
    elem->suivant = csl;
    if(tmp) tmp->suivant = elem;
    else *sl = elem;
}
liste_chainee ajouterEnFin(liste_chainee liste, int val)
{
    // On crÃ©e un nouvel Ã©lÃ©ment
    element* nouvelElement = malloc(sizeof(element));
    
    //On assigne la val au nouvel Ã©lÃ©ment
    nouvelElement->donnee = val;
    
    //On ajoute en fin, donc aucun Ã©lÃ©ment ne va suivre 
    nouvelElement->suivant = NULL;
    
    if(liste == NULL)
    {
        // Si la liste est vide il suffit de renvoyer l'Ã©lÃ©ment crÃ©Ã© 
        return nouvelElement;
    }
    else
    {
        // Sinon, on parcourt la liste Ã  l'aide d'un pointeur temporaire et on
        // indique que le dernier Ã©lÃ©ment de la liste est reliÃ© au nouvel Ã©lÃ©ment 
        element* temp=liste;
        while(temp->suivant != NULL)
        {
            temp = temp->suivant;
        }
        temp->suivant = nouvelElement;
        return liste;
    }
}


void afficher(liste_chainee liste)
{
    element *tmp = liste;
    // Tant que l'on n'est pas au bout de la liste 
    while(tmp != NULL)
    {
        // On affiche 
        printf("\nLa valeur enregistrer est %d\n", tmp->donnee);
        //On avance d'une case 
        tmp = tmp->suivant;
    }
}


int main()
{
	int *ma_data, valeur,taille_ma_data, i;
    liste_chainee ma_liste = NULL;
    liste_chainee ma_listeI = NULL;
    
	printf("Entrer la taille du tableau:");
	scanf("%d",&taille_ma_data);
	ma_data = calloc(taille_ma_data,sizeof(int));
	
	for(i=0; i<taille_ma_data; i++)
	{
	printf("Entrer valeur[%d]:",i);
	scanf("%d", &valeur);
    ma_liste = ajouterEnFin(ma_liste, valeur);
        
    Insert(&ma_listeI,valeur);
        
	}
    afficher(ma_liste);
    
    afficher(ma_listeI);
    //system("PAUSE");
	return 0;
}
