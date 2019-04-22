#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct{
	char nom[20];
	int prix;
}article;

void add(article *tab,int N){
	printf("Ajout des articles : \n");
	printf("\n");
	for(int i=0;i<N;i++){
		printf("article %d : \n",i+1);
		printf("nom : ");
		scanf("%s",tab[i].nom);
		printf("prix : ");
		scanf("%d",&tab[i].prix);
		printf("\n");
	}
	printf("\n");
}

void affiche(article *tab,int N){
	printf("affichage des articles : \n");
	printf("\n");
	for(int i=0;i<N;i++){
		printf("article %d : \n",i+1);
		printf("nom : %s\n",tab[i].nom);
		printf("prix : %d\n",tab[i].prix);
		printf("\n");
	}
}

void save(article *tab,int N,char *rep){
	FILE *fichier=NULL;
	fichier=fopen(rep,"ab");
	for(int i=0;i<N;i++){
		fwrite(&tab[i],sizeof(article),1,fichier);
	}
	fclose(fichier);
}

void read(char *rep){
	FILE *fichier=NULL;
	fichier=fopen(rep,"rb");
	int i=0;
	printf("\n");
	article x;
	while(fread(&x,sizeof(article),1,fichier)){
		printf("article %d\n",i+1);
		printf("nom : %s\n",x.nom);
		printf("prix : %d\n",x.prix);
		printf("\n");
		i++;
	}
}

void menu(){
	printf("******************MENU***************\n");
	printf("** 1 : ajouter des articles        **\n");
	printf("** 2 : afficher des articles       **\n");
	printf("** 3 : sauvegarder                 **\n");
	printf("** 4 : lire le fichier sauvegarder **\n");
	printf("** 5 : quitter                     **\n");
	printf("*************************************\n");
	printf("\n");
	int op;
	article d[20];
	do{
		printf("Entrer l\'operation a effectuer : ");
		scanf("%d",&op);
		switch(op){
			case 1 : printf("combien d\'article voulez vous entrer ?");
					 int n;
					 scanf("%d",&n);
					 add(d,n);
					 break;
			case 2 : printf("combien d\'article voulez vous afficher ?");
					 int o;
					 scanf("%d",&o);
					 affiche(d,o);
					 break;
			case 3 : printf("entrer le nom du fichier ou sauvegarder : ");
				     char m[20];
				     scanf("%s",m);
				     printf("le nombre de fichier a sauvegarder : ");
					 int b;
					 scanf("%d",&b);
				     save(d,b,m);
		    case 4 : printf("entrer le nom du fichier a lire : ");
				     char mooo[20];
				     scanf("%s",mooo);
				     read(mooo);

		}
	}while(op!=5);

}
int main(){
	menu();
}