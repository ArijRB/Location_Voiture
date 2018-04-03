#ifndef PROGRAMMES_H_INCLUDED
#define PROGRAMMES_H_INCLUDED
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <myconio.h>
#include <stdio.h>
#include <string.h>
#include "control.h"
/****** DEFINITION DES STRUCTURES *********/
typedef struct
  {
     int j;
     int m;
     int a;
  } date1;
  typedef struct
  {
   char mat[10];
   char marque [20];
   char couleur [20];
   int prix_l;
   date1 DA ; /*date d'achat*/
   char etat ; /* l ou d */
   } voiture;
   struct cellule1
   {
   voiture info1;
   struct cellule1 * suiv1;
   };
 typedef struct cellule1 * liste_voit;
    typedef struct
  {
  char  cin [20];
  char nom [20];
  char prenom [20];
  int age;
  char adr[50];
  char tel[9];

  }client;
   struct cellule2
   {
   client info2;
   struct cellule2 * suiv2;
   };
  typedef struct cellule2 * liste_clt;
     typedef struct
  {
   int h ;//heure
   int j;
   int m;
   int a;

  }date2;
  typedef struct
  {
   long int num;
   char cin [20];
   char mat [9];
   date2 DL;
   date2 DR;
   int DureeL;
   float mt_p;
  }location;
   struct cellule3
   {
   location info3;
   struct cellule3 * suiv3;
   };
  typedef struct cellule3 * liste_loc;
  /************ CONTROL DE SAISIE *****************/
int validechar(char ch[])
{
   int i;
   char car;
   for(i=0;ch[i];i++)
   {
       car=toupper(ch[i]);
        if(!(car>='A' && car<='Z'))
            return 0;
   }
   return 1;
}
int validemat(char ch[])
{
   int i;
   char car;int ok=1;
   for(i=0;i<3;i++)
   {
       car=toupper(ch[i]);
        if(!(car>='0' && car<='9'))
            ok=0;
   }
    if (ok=1)
   {
       car=toupper(ch[i]);
        if(!(ch[3]=='T' && ch[4]=='N'))
            ok=0;
   }
    if (ok=1)
    for(i=5;i<9;i++)
   {
       car=toupper(ch[i]);
        if(!(car>='0' && car<='9'))
            ok=0;
   }

   return ok;
}
int validenum(char ch[])
{
   int i;
   char car;
   for(i=0;ch[i];i++)
   {
       car=toupper(ch[i]);
        if(!(car>='0' && car<='9'))
            return 0;
   }
   return 1;
}
int validenumt(char ch[])
{
   int i;
   char car;
   if (strlen(ch) != 8)
    return 0;
   for(i=0;ch[i];i++)
   {
       car=toupper(ch[i]);
        if(!(car>='0' && car<='9'))
            return 0;
   }
   if (ch[0] == '0')
    return 0;
   return 1;
}
int jmax(date1 d)
{
    switch(d.m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11:return 30;
        case 2 :
                if(d.a%4==0 && (d.a%100!=0 || d.a%400==0))
                    return 29;
                else
                    return 28;
    }
}
int validedate(date1 d)
{
    return ((d.a>1900)&& (d.m>=1 && d.m<=12) && (d.j>=1 && d.j<=jmax(d)));
}

date1 saisie_date1()
 {
 date1 d;
     do
     {
         fflush(stdin);
         gotoxy(6,15);
         printf("Donner le jour :");
         scanf("%d",&d.j);
         fflush(stdin);
         gotoxy(6,16);
         printf("Donner le mois :");
         scanf("%d",&d.m);
         fflush(stdin);
         gotoxy(6,17);
         printf("Donner l'annee :");
         scanf("%d",&d.a);
     }while(!(validedate(d)==1));
     return d;
 }
 /*******  Gestion de parc automobile ********/
 // chercher la taille d'une liste des voitures
 int taille(liste_voit l)
{   liste_voit p=l;
	 int x=0;
	 while(p!=NULL)
	 {   x++;
		  p=p->suiv1;
	 }
    return  x;
}
// chercher une voiture par sa matricule
liste_voit Rech_voit_mat(liste_voit l,char v[])
{
    liste_voit p=l;
    while(p)
    {
        if(strcmp(p->info1.mat,v)==0)
            return p;
        p=p->suiv1;
    }
    fflush(stdin);
    return NULL;
}
// saisie d'une voiture
voiture saisie_voiture(liste_voit l)
{
  voiture p;char ch1[20],ch2[20];

do
     {
         gotoxy(4,9);
         fflush(stdin);
         textcolor(3);
         printf("\5\5 Saisir une Matricule Unique : (...TN....)");
         textcolor(2);
         gotoxy(38,9);
         gets(p.mat);
     } while(!(Rech_voit_mat(l,p.mat)==NULL&&validemat(p.mat)==1));
	do
	{
    fflush(stdin);
    gotoxy(4,10);
    textcolor(3);
	 printf("\5\5 Saisir la marque : ");
	textcolor(2);
	 gets(p.marque);
	}while(!(validechar(p.marque)==1));
	do
	{
	 fflush(stdin);
	 gotoxy(4,11);
	 textcolor(3);
	 printf("\5\5 Saisir le couleur : ");
	 textcolor(2);
	 gets(p.couleur);
     }while(!(validechar(p.couleur)==1));

	do{

	  fflush(stdin);
	 gotoxy(4,12);
	 textcolor(3);
	 printf("\5\5 Saisir le prix : ");
	 textcolor(2);
	 scanf("%d",&p.prix_l);
	} while (!(p.prix_l>0));
	 gotoxy(4,13);
	 textcolor(3);
	 printf("\5\5 Saisir Date D'Achat : \n");
     p.DA=saisie_date1();
     p.etat='d';

     return p;

}
// inserer une voiture a la tete de la liste
liste_voit insere_tete_voiture(liste_voit l)
{
    liste_voit p; voiture x;
    system("COLOR 70");
    x=saisie_voiture(l);
    p=malloc(sizeof(struct cellule1));
    p->info1=x;
    p->suiv1=l;
    return p;
}
//inserer une voiture au queue de la liste
liste_voit insere_queue_voiture(liste_voit l)
{
    liste_voit p1,p2;voiture x;
    system("COLOR 70");
    x=saisie_voiture(l);
    p1=malloc(sizeof(struct cellule1));
    p1->info1=x;
    if(l==NULL)
    {
        p1->suiv1=l;
        l=p1;
    }
    else
    {
        p2=l;
        while(p2->suiv1)
            p2=p2->suiv1;
        p2->suiv1=p1;
        p1->suiv1=NULL;
    }
    return l;
}
//inserer une voiture dans une position donnée en parametre
void insere_pos_voiture(liste_voit l,int pos)
{
   int i=1;
   liste_voit p1=l,p2;
   while(i<pos-1)
   {
      i++;
      p1=p1->suiv1;
   }
   p2=malloc(sizeof(*p2));
    p2->info1=saisie_voiture(l);
    p2->suiv1=p1->suiv1;
    p1->suiv1=p2;
}
//inserer une voiture dans une position lue dans la fonction
void insere_pos_voiture1(liste_voit l)
{
   	int pos,t;
   	t=taille(l);
        system("COLOR 70");

		do
		{
		    gotoxy(12,4);
		    textcolor(15);
		    t=taille(l);
			printf("\5\5\5 Donnez une Position Entre 1 et %d :          ",t+1);
			gotoxy(49,4);
			fflush(stdin);
			scanf("%d",&pos);
		}while(pos>t+1||pos<1) ;
   int i=1;
   liste_voit p1=l,p2=NULL;
   while(i<pos-1)
   {
      i++;
      p1=p1->suiv1;
   }
   p2=malloc(sizeof(*p2));
    p2->info1=saisie_voiture(l);
    p2->suiv1=p1->suiv1;
    p1->suiv1=p2;
    clrscr();
    textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("AJOUT FAIT AVEC SUCCESS");
}
// creation liste des voitures
liste_voit crea_voit(liste_voit l)
{
	int pos,x,t,rep;
	do
	{
	     clrscr();

                  system("COLOR 70");
		      gotoxy(33,3);
		       textbackground(8);
                    textcolor(1);
                    printf("CREATION LISTE VOITURE");

		do
		{   t=taille(l);
		    gotoxy(12,5);
		    textcolor(15);
			printf("\4 Donnez une Position Entre 1 et %d :          ",t+1);
			gotoxy(49,5);
			fflush(stdin);
			scanf("%d",&pos);
		}while(!(pos<=t+1 && pos>=1)) ;
		if (pos==1)
			l=insere_tete_voiture(l);
		else
			if (pos==t+1)
				l=insere_queue_voiture(l);
			else
				insere_pos_voiture(l,pos);
		do
		{
		    gotoxy(4,22);
		    textcolor(0);
		    printf("Voulez Vous Continuez La Saisie? [ 1:OUI 0:NON ] ");
		    scanf("%d",&rep);
		}while((rep!=1)&&(rep!=0)  ) ;
	}while(rep!=0);
	clrscr();
	return l;
}
//supprimer une voiture de la tete de la liste
liste_voit supp_tete_voit(liste_voit l)
{
     liste_voit p=l;
    l=l->suiv1;
    free(p);
	textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
	 return(l);
}
//supprimer une voiture donnée
liste_voit supp_mat(liste_voit l , char matt[])
{
 liste_voit p,q;
 int ok;
 p=l;
 if(strcmp(p->info1.mat,matt)==0)
{
       l=supp_tete_voit(l);
       gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Suppression Avec Succee");
}

 else
 {
     p=l;
     ok=0;
     while((p->suiv1!=NULL)&&(ok==0))
     {
         if(strcmp(p->suiv1->info1.mat,matt)==0)
            ok=1;
         else
            p=p->suiv1;

     }
     if(ok==1)
     {
        q=p->suiv1;
        p->suiv1=q->suiv1;
        free(q);
         gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Suppression Avec Succee");
     }
     else
       {
           gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("La voiture N'Existe Pas");
       }
 }
 return l;
}
// modifier la couleur d'une voiture donée
liste_voit Modification_couleur(liste_voit l,char m[9])
{
    liste_voit p=l;char c[9];
    p=Rech_voit_mat(l,m);
    if(p==NULL)
        {gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("La voiture N'Existe Pas");}
    else
        {
		 gotoxy(12,5);
		 textcolor(15);
		 printf("\5\5 Donnez La nouvelle couleur  : ");
         gotoxy(50,5);
		 fflush(stdin);
		 textcolor(14);
		 gets(c);
		 strcpy(p->info1.couleur,c);
		 clrscr();
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
         printf("MODIFICATION FAIT AVEC SUCCESS");
		}
    return l;
}
// modifier le prix d'une voiture donée
liste_voit Modification_prix(liste_voit l,char m[9])
{
    liste_voit p=l;int prix;
    p=Rech_voit_mat(l,m);
    if(p==NULL)
        {gotoxy(20,15);
        textcolor(RED);
        textbackground(5);
        printf("La voiture N'Existe Pas");}
    else
        {
		do
        {gotoxy(12,5);
		 textcolor(15);
		 printf("\5\5 Donnez Le nouveau prix  : ");
         gotoxy(50,5);
		 fflush(stdin);
		 textcolor(14);
		 scanf("%d",&prix);
        }while (!(prix>0));
		p->info1.prix_l=prix;
        clrscr();
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
         printf("MODIFICATION FAIT AVEC SUCCESS");
		}


    return l;
}
// afficher la liste des voitures
void affiche_voit(liste_voit l)
{int i=0,j,k=0; liste_voit p;
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
    { clrscr();
    system("COLOR 70");
    textcolor(RED);
	 gotoxy(15,4);
     printf("Liste des voitures");
        for(p=l,j=0;p!=NULL;p=p->suiv1,j++)
        {  textcolor(3);
           gotoxy(5+i,6+k);
            textcolor(WHITE);
           printf ("la voiture N° %d",j+1);
           textcolor(3);
           gotoxy(5+i,8+k);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+i,9+k);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+i,10+k);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+i,11+k);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+i,12+k);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+i,13+k);
           printf("Etat : %c\n",p->info1.etat);
				i=i+25;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}

    }
}
}
// afficher une voiture donnée
void affiche_mat(liste_voit l)
{
    int ok=0; char matt [10];
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
     {  clrscr();gotoxy(12,3);
		 textcolor(15);
		printf("\5\5 Donnez La Matricule de la voiture à chercher    ");
	    fflush(stdin);
		textcolor(14);
		gets(matt);
         liste_voit p=l;
        while(p)
        {
            if  (strcmp(p->info1.mat,matt)==0)
            {
           gotoxy(10,5);
           textcolor(WHITE);
           printf ("la voiture cherchee :");
           textcolor(3);
           gotoxy(10,7);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(10,8);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(10,9);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(10,10);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(10,11);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(10,12);
           printf("Etat : %c\n",p->info1.etat);
				ok=1;
            }
				p=p->suiv1;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Cette voiture n'existe pas");

         }

}

}
// afficher une marque donnée
void affiche_mar(liste_voit l)
{
    int ok=0,k=0,i=0; char mar [10];
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
     {  clrscr();gotoxy(12,3);
		 textcolor(15);
		printf("\5\5 Donnez La Marque des voitures à chercher    ");
	    fflush(stdin);
		textcolor(14);
		gets(mar);
         liste_voit p=l;
        while(p)
        {
            if  (strcmp(p->info1.marque,mar)==0)
            {

           textcolor(3);
           gotoxy(5+i,8+k);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+i,9+k);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+i,10+k);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+i,11+k);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+i,12+k);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+i,13+k);
           printf("Etat : %c\n",p->info1.etat);
				i=i+25;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv1;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Cette voiture n'existe pas");

         }
         else
         {
           gotoxy(10,5);
           textcolor(WHITE);
           printf ("les voitures cherchees :");
         }

}
}
// afficher un couleur donné
void affiche_couleur(liste_voit l)
{
    int ok=0,i=0,k=0; char coi [10];
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
     {  clrscr();gotoxy(12,3);
		 textcolor(15);
		printf("\5\5 Donnez La Marque des voitures à chercher    ");
	    fflush(stdin);
		textcolor(14);
		gets(coi);
         liste_voit p=l;
        while(p)
        {
            if  (strcmp(p->info1.couleur,coi)==0)
            {
           textcolor(3);
           gotoxy(5+i,8+k);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+i,9+k);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+i,10+k);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+i,11+k);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+i,12+k);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+i,13+k);
           printf("Etat : %c\n",p->info1.etat);
				i=i+25;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv1;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Cette voiture n'existe pas");

         }
		 else
		 {
           gotoxy(10,6);
           textcolor(WHITE);
           printf ("les voitures cherchees :");
		   }

}
}
// afficher les voitures louées
void affiche_l(liste_voit l)
{
    int ok=0,i=0,k=0;
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
     {
        liste_voit p=l;
        while(p)
        {
            if  (p->info1.etat=='l')
            {
           textcolor(3);
           gotoxy(5+i,8+k);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+i,9+k);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+i,10+k);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+i,11+k);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+i,12+k);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+i,13+k);
           printf("Etat : %c\n",p->info1.etat);
				i=i+25;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv1;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Toutes les voitures sont disponibles");

         }
		 else
		 {
           gotoxy(10,6);
           textcolor(WHITE);
           printf ("les voitures louees dans la liste :");
		   }

}
}
// trier la liste
void tri1v(liste_voit l)
{
    liste_voit p;
    int ok,j,k=0,t=taille(l),i=((t*9/3)+8);

    voiture aux;
	    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
    { clrscr();
	affiche_voit(l);
    gotoxy(15,4);
    textcolor(RED);
     printf("Liste des voitures avant tri");
    do
    {
        ok=1;
        p=l;
        while(p->suiv1)
        {
            if(p->info1.prix_l<p->suiv1->info1.prix_l)
            {
                aux=p->info1;
                p->info1=p->suiv1->info1;
                p->suiv1->info1=aux;
                ok=0;
            }
            p=p->suiv1;
        }
    }while(ok==0);
    textcolor(RED);
	 gotoxy(15,4+i);
     printf("Liste des voitures apres tri");
        for(p=l,j=0;p!=NULL;p=p->suiv1,j++)
        {  textcolor(3);
           gotoxy(5+k,6+i);
           textcolor(WHITE);
           printf ("la voiture N° %d",j);
           textcolor(3);
           gotoxy(5+k,8+i);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+k,9+i);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+k,10+i);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+k,11+i);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+k,12+i);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+k,13+i);
           printf("Etat : %c\n",p->info1.etat);
				k=k+25;
				if (k>60)
				{
				   i=i+9;
				   k=0;

				}
        }
    }
}
//trier la liste des voitures par echange des voitures
void tri2v(liste_voit l)
{
    liste_voit p ,q,r,prec; int ok1;
        p=l ;
    int ok,j,k=0,t=taille(l),i=((t*9/3)+8);

	    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
    { clrscr();
	affiche_voit(l);
    gotoxy(15,4);
    textcolor(RED);
     printf("Liste des voitures avant tri");
    do
        { ok1=0 ;
            prec=NULL ;
           while(p->suiv1)
            {
                if ((p->suiv1->info1.prix_l)>(p->info1.prix_l) )
                {
                    if(p==l)

                    {

                    q=p->suiv1->suiv1 ;
                            r=p->suiv1 ;
                        p->suiv1->suiv1=p ;
                        l->suiv1=q;

                        l=r ;

                    }
                    else if( p->suiv1->suiv1==NULL)
                    {
                        prec->suiv1=p->suiv1 ;
                        p->suiv1->suiv1=p ;
                        p->suiv1=NULL ;



                    }

                    else {

                        prec->suiv1=p->suiv1  ;
                        q=p->suiv1->suiv1;
                        p->suiv1->suiv1=p;
                        p->suiv1=q ;

                    }
                    ok1=1;
                }

                prec=p ;
                if (p->suiv1 )
                p=p->suiv1 ;

            }
            p=l ;
        }while(ok1) ;
    textcolor(RED);
	 gotoxy(15,4+i);
     printf("Liste des voitures apres tri");
        for(p=l,j=0;p!=NULL;p=p->suiv1,j++)
        {  textcolor(3);
           gotoxy(5+k,6+i);
           textcolor(WHITE);
           printf ("la voiture N° %d",j);
           textcolor(3);
           gotoxy(5+k,8+i);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+k,9+i);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+k,10+i);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+k,11+i);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+k,12+i);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+k,13+i);
           printf("Etat : %c\n",p->info1.etat);
				k=k+25;
				if (k>60)
				{
				   i=i+9;
				   k=0;

				}
        }
    }

}
// afficher les voitures disponibles
 affiche_d(liste_voit l,int *d)
{
    int ok=0,i=0,k=0;
    *d=1;
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    *d=0;
    }
	 else
     {
         liste_voit p=l;
        while(p)
        {
            if  (p->info1.etat=='d')
            {
           system("COLOR 70");
           gotoxy(5+i,8+k);
           printf("Matricule : %s\n",p->info1.mat);
           gotoxy(5+i,9+k);
           printf("Marque : %s\n",p->info1.marque);
           gotoxy(5+i,10+k);
           printf("Couleur : %s\n",p->info1.couleur);
           gotoxy(5+i,11+k);
           printf("Prix: : %d\n",p->info1.prix_l);
           gotoxy(5+i,12+k);
           printf("Date D'Achat: %d/%d/%d\n",p->info1.DA.j,p->info1.DA.m,p->info1.DA.a);
           gotoxy(5+i,13+k);
           printf("Etat : %c\n",p->info1.etat);
				i=i+25;
				if (i>60)
				{
				   k=k+8;
				   i=0;
				}
				ok=1;
            }
				p=p->suiv1;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Toutes les voitures sont louées");
                   *d=0;

         }
		 else
		 {
           gotoxy(10,6);
           textcolor(WHITE);
           printf ("les voitures disponibles :");
		   }

}
}
//supprimer une voiture de la queue de la liste
void supp_queue_voit(liste_voit l)
{   liste_voit p=l;
    while((p->suiv1)->suiv1 != NULL )
        p=p->suiv1;
    free(p->suiv1);
	 p->suiv1=NULL;
	textbackground(3);
        textcolor(RED);
	gotoxy(20,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
}
//supprimer une voiture dans une position lue dans la fonction
void supp_pos_voit(liste_voit l)
{   liste_voit p1=l,p2;
    int i=1;
    int t=taille(l);
    textcolor(0);
		int pos;
		do
		{
		    gotoxy(12,15);
		    textcolor(15);
			printf("\5\5 Donnez La Position Entre 1 et %d :      ",t);
			gotoxy(60,15);
			fflush(stdin);
			scanf("%d",&pos);
		}while(pos>t||pos<1) ;
	if(pos==1)
        l=supp_tete_voit(l);
    else {
        if(pos==t+1)
            supp_queue_voit(l);

    else
    {
    while ( i<pos-1)
	 {   i++;
        p1=p1->suiv1;
    }
    p2=p1->suiv1;
	 p1->suiv1=p2->suiv1;
    free(p2);
    }
    }
    clrscr();
    textbackground(3);
    textcolor(RED);
	gotoxy(25,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
}
//supprimer une voiture dans une position donnée en parametre
void supp_pos_voit1(liste_voit l,int pos)
{   liste_voit p1=l,p2;
    int i=1;
    int t=taille(l);
    textcolor(0);
	if(pos==1)
        l=supp_tete_voit(l);
    else {
        if(pos==t+1)
            supp_queue_voit(l);

    else
    {
    while ( i<pos-1)
	 {   i++;
        p1=p1->suiv1;
    }
    p2=p1->suiv1;
	 p1->suiv1=p2->suiv1;
    free(p2);
    }
    }
}
// enregistrer la liste des voitures dans un fichier
void enregistrement_voiture(liste_voit L)
{
    liste_voit q=L;
    FILE *f;
    f=fopen("Voiture.txt","w");
    while(q!=NULL)
    {
        fprintf(f,"%s %s %s %d %d/%d/%d %c\n\n",
        q->info1.mat,q->info1.marque,q->info1.couleur,q->info1.prix_l,q->info1.DA.a,q->info1.DA.m,q->info1.DA.j,
        q->info1.etat);
        q=q->suiv1;
    }
    fclose(f);
}
liste_voit ajout_queue_voiture_fichier(liste_voit L,voiture v)
{
    liste_voit p,q;
    p=malloc(sizeof(*p));
    p->info1=v;
    p->suiv1=NULL;
    if(L==NULL)
        return p;
    q=L;
    while(q->suiv1!=NULL)
        q=q->suiv1;
    q->suiv1=p;
    return L;
}
// recuperer la liste des voiture de fichier
liste_voit recuperation_voiture()
{
    liste_voit L=NULL;
    voiture v;
    FILE *f;
    int i=1;
    f=fopen("Voiture.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %s %s %d %d/%d/%d %c\n\n",v.mat,v.marque,v.couleur,&v.prix_l,&v.DA.a,&v.DA.m,&v.DA.j,&v.etat);
        L=ajout_queue_voiture_fichier(L,v);
        i++;
    }
    fclose(f);
    return L;
}
liste_voit supp_marque(liste_voit l , char m[20])
{
        int ok=0,s=0;
    liste_voit p,r;
    if(strcmp(l->info1.marque,m)==0)
        ok=1;

        p=l;
        while(p->suiv1)
        {
            if(strcmp((p->suiv1)->info1.marque,m)==0)
            {
                    r=p->suiv1;
                    p->suiv1=r->suiv1;
                    free(r);
                    s=1;
            }
            else
                    p=p->suiv1;
        }

        if (ok)
        {
            r=l;
            l=l->suiv1;
            free(r);
            s=1;
        }
    if (s==1)
    {
        clrscr();
        system("COLOR 70");
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
        printf("SUPPRESSION FAIT AVEC SUCCESS");
    }
    else
    {
        clrscr();
        system("COLOR 70");
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
        printf("MARQUE INTROUVALVLE !!!!");

    }
	    return l;
}
/*******  Gestion des clients ********/
 int taillec(liste_clt l)
{   liste_clt p=l;
	 int x=0;
	 while(p!=NULL)
	 {   x++;
		  p=p->suiv2;
	 }
    return  x;
}
client saisie_client(liste_clt l)
{
  client p;

do
     {
         gotoxy(4,9);
         fflush(stdin);
         textcolor(3);
         printf("\5\5 Saisir N° CIN  ");
         textcolor(2);
         gets(p.cin);
     }while(!(validenum(p.cin)==1 && strlen(p.cin)==8));
	do
	{
    fflush(stdin);
    gotoxy(4,10);
    textcolor(3);
	 printf("\5\5 Saisir le nom : ");
	textcolor(2);
	 gets(p.nom);
	}while(!(validechar(p.nom)==1));
	do
	{
	 fflush(stdin);
	 gotoxy(4,11);
	 textcolor(3);
	 printf("\5\5 Saisir le prenom : ");
	 textcolor(2);
	 gets(p.prenom);
     }while(!(validechar(p.prenom)==1));
	 fflush(stdin);
	 gotoxy(4,12);
	 textcolor(3);
	 printf("\5\5 Saisir l'age : ");
	 textcolor(2);
	 scanf("%d",&p.age);
     fflush(stdin);
	 gotoxy(4,13);
	 textcolor(3);
	 printf("\5\5 Saisir l'adresse :    ");
     textcolor(2);
     gets(p.adr);
         do
     {
         fflush(stdin);
         gotoxy(4,14);
         textcolor(3);
         printf("\5\5 Saisir son numero de telephone :  ");
         textcolor(2);
         gets(p.tel);
     }while(!(validenumt(p.tel)==1));


     return p;

}

liste_clt insere_tete_client(liste_clt l)
{
    liste_clt p; client x;
    system("COLOR 70");
    x=saisie_client(l);
    p=malloc(sizeof(struct cellule2));
    p->info2=x;
    p->suiv2=l;
    return p;
}

liste_clt insere_queue_client(liste_clt l)
{
    liste_clt p1,p2;client x;
    system("COLOR 70");
    x=saisie_client(l);
    p1=malloc(sizeof(struct cellule2));
    p1->info2=x;
    if(l==NULL)
    {
        p1->suiv2=l;
        l=p1;
    }
    else
    {
        p2=l;
        while(p2->suiv2)
            p2=p2->suiv2;
        p2->suiv2=p1;
        p1->suiv2=NULL;
    }
    return l;
}
void affiche_clt(liste_clt l)
{int i=0,j,k=0; liste_clt p;
    if (l==NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des clients Vide");
    }
	 else
    { clrscr();
    system("COLOR 70");
    textcolor(RED);
	 gotoxy(15,4);
     printf("Liste des clients");
        for(p=l,j=0;p!=NULL;p=p->suiv2,j++)
        {  textcolor(3);
           gotoxy(10+i,6+k);
            textcolor(WHITE);
           printf ("le Client  N° %d",j+1);
           textcolor(3);
           gotoxy(10+i,8+k);
           printf("N°CIN: %s\n",p->info2.cin);
           gotoxy(10+i,9+k);
           printf("Nom : %s\n",p->info2.nom);
           gotoxy(10+i,10+k);
           printf("prenom : %s\n",p->info2.prenom);
           gotoxy(10+i,11+k);
           printf("Age: %d\n",p->info2.age);
           gotoxy(10+i,12+k);
           printf("Adresse: %s\n",p->info2.adr);
           gotoxy(10+i,13+k);
           printf("Telephone : %s\n",p->info2.tel);
				i=i+25;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
        }
    }
}
void tri1c(liste_clt l)
{
    liste_clt p;
    int ok,j,i=0,t=taillec(l),k=((t*9/3)+8); char ch1 [30],ch2[30];

    client aux;
	    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des clients Vide");
    }
	 else
    { clrscr();
	affiche_clt(l);
    gotoxy(15,4);
    textcolor(RED);
     printf("Liste des clients avant tri");
    do
    {
        ok=1;
        p=l;
        while(p->suiv2)
        {
             strcpy(ch1,p->info2.nom);
		     strcat(ch1,p->info2.prenom);
             strcpy(ch2,p->suiv2->info2.nom);
		     strcat(ch2,p->suiv2->info2.prenom);
            if(strcmp(ch1,ch2)<0)
            {
                aux=p->info2;
                p->info2=p->suiv2->info2;
                p->suiv2->info2=aux;
                ok=0;
            }
            p=p->suiv2;
        }
    }while(ok==0);
    textcolor(RED);
	 gotoxy(15,4+i);
     printf("Liste des clients apres tri");
        for(p=l,j=0;p!=NULL;p=p->suiv2,j++)
        {  textcolor(3);
           gotoxy(10+i,6+k);
           textcolor(YELLOW);
           printf ("le Client  N° %d",j+1);
           textcolor(3);
           gotoxy(10+i,8+k);
           printf("N°CIN: %s\n",p->info2.cin);
           gotoxy(10+i,9+k);
           printf("Nom : %s\n",p->info2.nom);
           gotoxy(10+i,10+k);
           printf("prenom : %s\n",p->info2.prenom);
           gotoxy(10+i,11+k);
           printf("Age: %d\n",p->info2.age);
           gotoxy(10+i,12+k);
           printf("Adresse: %s\n",p->info2.adr);
           gotoxy(10+i,13+k);
           printf("Telephone : %s\n",p->info2.tel);
				i=i+25;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
        }
    }
}
void insere_pos_client(liste_clt l,int pos)
{
   int i=1;
   liste_clt p1=l,p2;
   while(i<pos-1)
   {
      i++;
      p1=p1->suiv2;
   }
   p2=malloc(sizeof(*p2));
    p2->info2=saisie_client(l);
    p2->suiv2=p1->suiv2;
    p1->suiv2=p2;
}
void insere_pos_client1(liste_clt l)
{
   	int pos,t;
   	t=taillec(l);
        system("COLOR 70");

		do
		{
		    gotoxy(12,4);
		    textcolor(15);
		    t=taillec(l);
			printf("\4 Donnez une Position Entre 1 et %d :          ",t+1);
			gotoxy(49,4);
			fflush(stdin);
			scanf("%d",&pos);
		}while(pos>t+1||pos<1) ;
   int i=1;
   liste_clt p1=l,p2=NULL;
   while(i<pos-1)
   {
      i++;
      p1=p1->suiv2;
   }
   p2=malloc(sizeof(*p2));
    p2->info2=saisie_client(l);
    p2->suiv2=p1->suiv2;
    p1->suiv2=p2;
    clrscr();
    textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("AJOUT FAIT AVEC SUCCESS");
}
liste_clt crea_clt(liste_clt l)
{
	int pos,x,t,rep;
	do
	{
	     clrscr();

                  system("COLOR 70");
		      gotoxy(33,3);
		       textbackground(8);
                    textcolor(1);
                    printf("CREATION LISTE CLIENTS");

		do
		{
		    gotoxy(12,5);
		    textcolor(15);
		    t=taillec(l);
			printf("\5\5\5 Donnez une Position Entre 1 et %d :          ",t+1);
			gotoxy(50,5);
			fflush(stdin);
			scanf("%d",&pos);
		}while(pos>t+1||pos<1) ;
		if (pos==1)
			l=insere_tete_client(l);
		else
			if (pos==t+1)
				l=insere_queue_client(l);
			else
				insere_pos_client(l,pos);
		do
		{
		    gotoxy(4,22);
		    textcolor(0);
		    printf("Voulez Vous Continuez La Saisie? [ 1:OUI 0:NON ] ");
		    scanf("%d",&rep);
		}while((rep!=1)&&(rep!=0)  ) ;
	}while(rep!=0);
	clrscr();
	return l;
}
liste_clt supp_tete_clt(liste_clt l)
{   liste_clt p=l;
    l=l->suiv2;
    free(p);
	textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
	 return(l);
}
void supp_queue_clt(liste_clt l)
{   liste_clt p=l;
    while((p->suiv2)->suiv2 != NULL )
        p=p->suiv2;
    free(p->suiv2);
	 p->suiv2=NULL;
	textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
}
void supp_pos_clt(liste_clt l)
{   liste_clt p1=l,p2;
    int i=1;
    int t=taillec(l);
    textcolor(0);
		int pos;
		do
		{
		    gotoxy(12,15);
		    textcolor(15);
			printf("\5\5 Donnez La Position Entre 1 et %d :      ",t);
			gotoxy(60,15);
			fflush(stdin);
			scanf("%d",&pos);
		}while(pos>t||pos<1) ;
	if(pos==1)
        l=supp_tete_clt(l);
    else {
        if(pos==t+1)
            supp_queue_clt(l);

    else
    {
    while ( i<pos-1)
	 {   i++;
        p1=p1->suiv2;
    }
    p2=p1->suiv2;
	 p1->suiv2=p2->suiv2;
    free(p2);
    }
    }
    clrscr();
    textbackground(3);
    textcolor(RED);
	gotoxy(25,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
}
liste_clt Rech_clt_cin(liste_clt l,char v[])
{
    liste_clt p=l;
    while(p)
    {
        if(strcmp(p->info2.cin,v)==0)
            return p;
        p=p->suiv2;
    }
    fflush(stdin);
    return NULL;
}
liste_clt supp_cin(liste_clt l , char cinn[])
{
 liste_clt p,q;
 int ok;
 p=l;
 if(strcmp(p->info2.cin,cinn)==0)
{
       l=supp_tete_clt(l);
       gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Suppression Avec Succee");
}

 else
 {
     p=l;
     ok=0;
     while((p->suiv2!=NULL)&&(ok==0))
     {
         if(strcmp(p->suiv2->info2.cin,cinn)==0)
            ok=1;
         else
            p=p->suiv2;

     }
     if(ok==1)
     {
        q=p->suiv2;
        p->suiv2=q->suiv2;
        free(q);
         gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Suppression Avec Succee");
     }
     else
       {
           gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Le client N'Existe Pas");
       }
 }
 return l;
}
liste_clt Modification_adresse(liste_clt l,char cin[9])
{
    liste_clt p=l;char c[50];
    p=Rech_clt_cin(l,cin);
    if(p==NULL)
        {gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Le client N'Existe Pas");}
    else
        {
		 gotoxy(12,5);
		 textcolor(15);
		 printf("\5\5 Donnez La nouvelle adresse  : ");
         gotoxy(50,5);
		 fflush(stdin);
		 textcolor(14);
		 gets(c);
		 strcpy(p->info2.adr,c);
		 clrscr();
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
         printf("MODIFICATION FAIT AVEC SUCCESS");
		}
    return l;
}
liste_clt Modification_tele(liste_clt l,char cin[9])
{
    liste_clt p=l;char c[9];
    p=Rech_clt_cin(l,cin);
    if(p==NULL)
        {gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Le client N'Existe Pas");}
    else
        {
		 do {
        gotoxy(12,5);
		 textcolor(15);
		 printf("\5\5 Donnez Le nouveau numero   : ");
         gotoxy(50,5);
		 fflush(stdin);
		 textcolor(14);
		 gets(c);
       } while(!(validenumt(c)==1));
		 strcpy(p->info2.tel,c);
		 clrscr();
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
         printf("MODIFICATION FAIT AVEC SUCCESS");
		}
    return l;
}
void affiche_cin(liste_clt l)
{
    int ok=0,i=0; char cinn [10];
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des clients Vide");
    }
	 else
     {  clrscr();gotoxy(12,3);
        textcolor(15);
		 printf("\5\5 Donnez Le N° CIN  du client à chercher ");
        gotoxy(55,3);
		fflush(stdin);
		textcolor(14);
		gets(cinn);
         liste_clt p=l;
        while(p)
        {
            if  (strcmp(p->info2.cin,cinn)==0)
            {
           textcolor(3);
           gotoxy(10,6);
           textcolor(WHITE);
           printf ("le Client  cherche ");
           textcolor(3);
           gotoxy(10,8);
           printf("N° CIN: %s\n",p->info2.cin);
           gotoxy(10,9);
           printf("Nom : %s\n",p->info2.nom);
           gotoxy(10,10);
           printf("prenom : %s\n",p->info2.prenom);
           gotoxy(10,11);
           printf("Age: %d\n",p->info2.age);
           gotoxy(10,12);
           printf("Adresse: %s\n",p->info2.adr);
           gotoxy(10,13);
           printf("Telephone : %s\n",p->info2.tel);
		   ok=1;
            }
				p=p->suiv2;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Ce client n'existe pas");

         }

}

}
void enregistrement_client(liste_clt L)
{
    liste_clt q=L;
    FILE *f;
    int t;
    f=fopen("Client.txt","w");
    while(q!=NULL)
    {
        fprintf(f,"%s %s %s %d %s %s\n\n",q->info2.cin,
        q->info2.nom,q->info2.prenom,q->info2.age,q->info2.adr,q->info2.tel);
        q=q->suiv2;
    }
    fclose(f);
}
liste_voit ajout_queue_client_fichier(liste_clt L,client v)
{
    liste_clt p,q;
    p=malloc(sizeof(*p));
    p->info2=v;
    p->suiv2=NULL;
    if(L==NULL)
        return p;
    q=L;
    while(q->suiv2!=NULL)
        q=q->suiv2;
    q->suiv2=p;
    return L;
}
liste_clt recuperation_client()
{
    liste_clt L=NULL;
    client c;
    FILE *f;
    int t,i=1;
    f=fopen("Client.txt","r");
    while(!feof(f))
    {
        fscanf(f,"%s %s %s %d %s %s\n\n",c.cin,c.nom,c.prenom,&c.age,c.adr,c.tel);
        L=ajout_queue_client_fichier(L,c);
        i++;
    }
    fclose(f);
    return L;
}
 /*******  Gestion des locations ********/
 int jmax2(date2 d)
{
    switch(d.m)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: return 31;
        case 4:
        case 6:
        case 9:
        case 11:return 30;
        case 2 :
                if(d.a%4==0 && (d.a%100!=0 || d.a%400==0))
                    return 29;
                else
                    return 28;
    }
}
int validedate2(date2 d)
{
    return ((d.a>1900)&& (d.m>=1 && d.m<=12) && (d.j>=1 && d.j<=jmax2(d))&& (d.h>=0 && d.h<=23));
}
liste_loc Rech_loc_num(liste_loc l,int n)
{
    liste_loc p=l;
    while(p)
    {
        if(p->info3.num == n)
            return p;
        p=p->suiv3;
    }
    fflush(stdin);
    return NULL;
}
 date2 saisie_date2()
 {
 date2 d;
     do
     {    textcolor(GREEN);
         fflush(stdin);
         gotoxy(6,10);
         printf("Donner le jour :");
         scanf("%d",&d.j);
         fflush(stdin);
         gotoxy(6,11);
         printf("Donner le mois :");
         scanf("%d",&d.m);
         fflush(stdin);
         gotoxy(6,12);
         printf("Donner l'annee :");
         scanf("%d",&d.a);
         gotoxy(6,13);
		 printf("donner l'heure entre 0 et 23 [0=00:00 et 23= 23:00");
         scanf("%d",&d.h);
     }while(!((validedate2(d)==1 )));
     return d;
 }
int taillel(liste_loc l)
{   liste_loc p=l;
	 int x=0;
	 while(p!=NULL)
	 {   x++;
		  p=p->suiv3 ;
	 }
    return  x;
}
date2 saisiedateretour(date2 dl, int n)
{
date2 dr;int i;
dr=dl;
for(i=1;i<n;i++)
{
if(dr.m!=2)
    {
        if(dr.m==1 || dr.m==3 || dr.m==5 || dr.m==7 || dr.m==8 || dr.m==10 || dr.m==12)
        {
            if(dr.j<31)
                dr.j++;
            else
            {
                dr.j=1;
                if(dr.m<12)
                    dr.m++;
                else
                {
                    dr.m=1;
                    dr.a++;
                }
            }
        }
        else
            if(dr.m==4 || dr.m==6 || dr.m==9 || dr.m==11)
            {
                if(dr.j<31)
                    dr.j++;
                else
                    {
                        dr.j=1;
                        dr.m++;
                    }
            }
            else
                if(dr.m==2)
                {
                    if(dr.a%4==0)
                    {
                        if (dr.j<29)
                            dr.j++;
                        else
                        {
                            dr.j=1;
                            dr.m++;
                        }
                    }
                    else
                    {
                        if (dr.j<28)
                            dr.j++;
                        else
                        {
                            dr.j=1;
                            dr.m++;
                        }
                    }
                }
    }
}
	return dr;
	}
location saisie_location(liste_loc l, liste_voit v, liste_clt c)
{
  location p ; int t=taillel(l);liste_voit rech;int h=0,d=1; char ch[20];
   affiche_d(v,&d);
   if (d==1)

   {
    do
    {   gotoxy(10,((taille(v)/3)+1)*9+4);
        printf("Donner le matricule de la voiture que vous voulez louer  : ");
        gets(p.mat);
		rech=Rech_voit_mat(v,p.mat);
    } while (!(rech!=NULL && rech->info1.etat=='d'));
     clrscr();
     do
     {  gotoxy(10,3);
        textcolor(RED);
        printf("Donner la CIN du client : ");
        textcolor(GREEN);
        gets(p.cin);
     }while(!(validenum(p.cin)==1 && strlen(p.cin)==8));
     if (Rech_clt_cin(c,p.cin)==NULL)
     {
        clrscr();system("COLOR 70");
        gotoxy(2,3);textcolor(RED);
        printf("Ce client n'existe pas dans la liste des clients vous devez l'ajouter d'abord ");
        liste_clt p1,p2;client x;
        p1=malloc(sizeof(struct cellule2));
       strcpy(x.cin,p.cin);
        do
        {
        fflush(stdin);
        gotoxy(4,10);
        textcolor(3);
        printf("\5\5 Saisir le nom : ");
        textcolor(2);
        gets(x.nom);
        }while(!(validechar(x.nom)==1));
        do
        {
        fflush(stdin);
        gotoxy(4,11);
        textcolor(3);
        printf("\5\5 Saisir le prenom : ");
        textcolor(2);
        gets(x.prenom);
        }while(!(validechar(x.prenom)==1));
        fflush(stdin);
        gotoxy(4,12);
        textcolor(3);
        printf("\5\5 Saisir l'age : ");
        textcolor(2);
        scanf("%d",&x.age);
        fflush(stdin);
        gotoxy(4,13);
        textcolor(3);
        printf("\5\5 Saisir l'adresse :    ");
        textcolor(2);
        gets(x.adr);
         do
        {
         fflush(stdin);
         gotoxy(4,14);
         textcolor(3);
         printf("\5\5 Saisir son numero de telephone :  ");
         textcolor(2);
         gets(x.tel);
     }while(!(validenumt(x.tel)==1));
    p1->info2=x;
    if(c==NULL)
    {
        p1->suiv2=c;
        c=p1;
    }
    else
    {
        p2=c;
        while(p2->suiv2)
            p2=p2->suiv2;
        p2->suiv2=p1;
        p1->suiv2=NULL;
    }
     }
     rech->info1.etat='l';
     clrscr();
      gotoxy(10,3);
        textcolor(RED);
        printf("la CIN du client : ");
        textcolor(GREEN);
        puts(p.cin);
     gotoxy(4,4);
    textcolor(RED);
    printf("Donner la duree de la location : ");
    textcolor(GREEN);
    scanf("%d",&p.DureeL);
    gotoxy(4,5);
    textcolor(RED);
    printf("Donner le numéro de la location : ");
    textcolor(GREEN);
    scanf("%ld",&p.num);
    p.mt_p=p.DureeL*rech->info1.prix_l;
    gotoxy(10,8);
    textcolor(RED);
    printf("Saisie date de location ");
     p.DL=saisie_date2();
     p.DR=saisiedateretour(p.DL,p.DureeL);
	}
    return p;

}
liste_loc supp_tete_loc(liste_loc l)
{   liste_loc p=l;
    l=l->suiv3;
    free(p);
	textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
	 return(l);
}
void supp_queue_loc(liste_loc l)
{   liste_loc p=l;
    while((p->suiv3)->suiv3 != NULL )
        p=p->suiv3;
    free(p->suiv3);
	 p->suiv3=NULL;
	textbackground(3);
        textcolor(RED);
	gotoxy(20,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
}
void supp_pos_loc(liste_loc l)
{   liste_loc p1=l,p2;
    int i=1;
    int t=taillel(l);
    textcolor(0);
		int pos;
		do
		{
		    gotoxy(12,15);
		    textcolor(15);
			printf("\5\5 Donnez La Position Entre 1 et %d :      ",t);
			gotoxy(60,15);
			fflush(stdin);
			scanf("%d",&pos);
		}while(pos>t||pos<1) ;
	if(pos==1)
        l=supp_tete_loc(l);
    else {
        if(pos==t+1)
            supp_queue_loc(l);

    else
    {
    while ( i<pos-1)
	 {   i++;
        p1=p1->suiv3;
    }
    p2=p1->suiv3;
	 p1->suiv3=p2->suiv3;
    free(p2);
    }
    }
    clrscr();
    textbackground(3);
    textcolor(RED);
	gotoxy(25,15);
	printf("SUPPRESSION FAIT AVEC SUCCESS");
}
void insere_pos_location(liste_loc l,int pos,liste_voit v, liste_clt c)
{
   int i=1;
   liste_loc p1=l,p2;
   while(i<pos-1)
   {
      i++;
      p1=p1->suiv3;
   }
   p2=malloc(sizeof(*p2));
   p2->info3=saisie_location(l,v,c);
    p2->suiv3=p1->suiv3;
    p1->suiv3=p2;
}
liste_loc insere_tete_location(liste_loc l,liste_voit v, liste_clt c)
{
    liste_loc p; location x;
    system("COLOR 84");
    x=saisie_location(l,v,c);
    p=malloc(sizeof(struct cellule3));
    p->info3=x;
    p->suiv3=l;
    return p;
}
liste_loc insere_queue_location(liste_loc l,liste_voit v, liste_clt c)
{
    liste_loc p1,p2;location x;
    system("COLOR 84");
    x=saisie_location(l,v,c);
    p1=malloc(sizeof(struct cellule3));
    p1->info3=x;
    if(l==NULL)
    {
        p1->suiv3=l;
        l=p1;
    }
    else
    {
        p2=l;
        while(p2->suiv3)
            p2=p2->suiv3;
        p2->suiv3=p1;
        p1->suiv3=NULL;
    }
    return l;
}
void insere_pos_location1(liste_loc l,liste_voit v, liste_clt c)
{
   	int pos,t;
   	t=taillel(l);
        system("COLOR 84");

		do
		{
		    gotoxy(12,5);
		    textcolor(15);
			printf("\4 Donnez une Position Entre 1 et %d :          ",t+1);
			gotoxy(49,5);
			fflush(stdin);
			scanf("%d",&pos);
		}while(!(pos<t+1 && pos>1)) ;
   int i=1;
   liste_loc p1=l,p2;
   while(i<pos-1)
   {
      i++;
      p1=p1->suiv3;
   }
   p2=malloc(sizeof(*p2));
   p2->info3=saisie_location(l,v,c);
    p2->suiv3=p1->suiv3;
    p1->suiv3=p2;
    clrscr();
    textbackground(3);
    textcolor(RED);
	gotoxy(20,15);
	printf("AJOUT FAIT AVEC SUCCESS");
}
void enregistrement_location(liste_loc L)
{
    liste_loc q=L;
    FILE *f;
    int t;
    f=fopen("Location.txt","w");
    while(q!=NULL)
    {
        fprintf(f,"%ld %s %s %d/%d/%d/%d %f %d %d/%d/%d\n\n",
        q->info3.num,q->info3.cin,q->info3.mat,q->info3.DL.h,q->info3.DL.a,q->info3.DL.m,q->info3.DL.j,q->info3.mt_p,q->info3.DureeL,q->info3.DR.a,q->info3.DR.m,q->info3.DR.j);
        q=q->suiv3;
    }
    fclose(f);
}
liste_voit ajout_queue_location_fichier(liste_loc L,location v)
{
    liste_loc p,q;
    p=malloc(sizeof(*p));
    p->info3=v;
    p->suiv3=NULL;
    if(L==NULL)
        return p;
    q=L;
    while(q->suiv3!=NULL)
        q=q->suiv3;
    q->suiv3=p;
    return L;
}
liste_loc recuperation_location()
{
    liste_loc L=NULL;
    location c;
    FILE *f;
    int t,i=1;
    f=fopen("Location.txt","r");
    while(!(feof(f)))
    {
        fscanf(f,"%ld %s %s %d/%d/%d/%d %f %d %d/%d/%d\n\n",&c.num,c.cin,c.mat,&c.DL.h,&c.DL.a,&c.DL.m,&c.DL.j,&c.mt_p,&c.DureeL,&c.DR.a,&c.DR.m,&c.DR.j);
        L=ajout_queue_location_fichier(L,c);
        i++;
    }
    fclose(f);
    return L;
}
liste_loc supp_loc_num(liste_loc l , int nu)
{
 liste_loc p,q;
 int ok;
 p=l;
 if(p->info3.num==nu)
{
       l=supp_tete_loc(l);
       gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Suppression Avec Succee");
}

 else
 {
     p=l;
     ok=0;
     while((p->suiv3!=NULL)&&(ok==0))
     {
         if(p->suiv3->info3.num==nu)
            ok=1;
         else
            p=p->suiv3;

     }
     if(ok==1)
     {
        q=p->suiv3;
        p->suiv3=q->suiv3;
        free(q);
         gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("Suppression Avec Succee");
     }
     else
       {
           gotoxy(20,15);
        textcolor(RED);
        textbackground(3);
        printf("La location n'existe pas");
       }
 }
 return l;
}
liste_loc crea_loc(liste_loc l, liste_voit v, liste_clt c)
{
	int pos,x,t,rep;

	    if (v == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(15,15);
    printf("Liste des voitures Vide");
    }
    else
	do
	{
	     clrscr();

                  system("COLOR 70");
		      gotoxy(33,3);
		       textbackground(8);
                    textcolor(1);
                    printf("CREATION LISTE LOCATION");

		do
		{   t=taillel(l);
		    gotoxy(12,5);
		    textcolor(15);
			printf("\4 Donnez une Position Entre 1 et %d :          ",t+1);
			gotoxy(49,5);
			fflush(stdin);
			scanf("%d",&pos);
		}while(!(pos<=t+1 && pos>=1)) ;
		if (pos==1)
			l=insere_tete_location(l,v,c);
		else
			if (pos==t+1)
				l=insere_queue_location(l,v,c);
			else
				insere_pos_location(l,pos,v,c);
		do
		{
		    gotoxy(4,22);
		    textcolor(0);
		    printf("Voulez Vous Continuez La Saisie? [ 1:OUI 0:NON ] ");
		    scanf("%d",&rep);
		}while((rep!=1)&&(rep!=0)  ) ;
	}while(rep!=0);
	clrscr();
	return l;
}
void affiche_loc(liste_loc l)
{int i=0,j,k=0; liste_loc p;float mp=0;
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des locations Vide");
    }
	 else
    { clrscr();
    system("COLOR 70");
    textcolor(RED);
	 gotoxy(15,4);
     printf("Liste des locations");
        for(p=l;p!=NULL;p=p->suiv3)
        {  textcolor(3);
           gotoxy(2+i,6+k);
           textcolor(WHITE);
           printf ("la location N° %d",p->info3.num);
           textcolor(3);
           gotoxy(2+i,8+k);
           printf("N° Cin client  : %s\n",p->info3.cin);
           gotoxy(2+i,9+k);
           printf("Matricule : %s\n",p->info3.mat);
           gotoxy(2+i,10+k);
           printf("Date location:%d/%d/%dH%d\n",p->info3.DL.j,p->info3.DL.m,p->info3.DL.a,p->info3.DL.h);
           gotoxy(2+i,11+k);
           printf("Duree location : %d\n",p->info3.DureeL);
            gotoxy(2+i,12+k);
           printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
           gotoxy(2+i,13+k);
           printf("Montant à payer=%.2fDT\n",p->info3.mt_p);

				i=i+26;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
           mp+=p->info3.mt_p;

    }
	gotoxy(10,((taillel(l)/3)+1)*9+7);
	textcolor(RED);
	printf ("le montant total des locations = %.2f DT",mp);

}
}
void affiche_loc_cin(liste_loc ll,liste_voit vv ,liste_clt cc)
{
    int ok=0,i=0,k=0; char cinn [10];
	do
     {
         gotoxy(4,9);
         fflush(stdin);
         textcolor(RED);
         printf(" Donner N° CIN de client que vous chercher la location  ");
         textcolor(2);
         gets(cinn);
     }while(!(validenum(cinn)==1 && strlen(cinn)==8));
	 if (Rech_clt_cin(cc,cinn)==NULL)
     {
        clrscr();
        gotoxy(2,3);textcolor(RED);
        printf("Ce client n'existe pas dans la liste des clients");
     }
	 else
     {
         liste_loc p=ll;
         clrscr();
        while(p)
        {

            {
                if  (strcmp(p->info3.cin,cinn)==0)
                 {  textcolor(3);
					gotoxy(7+i,6+k);
					textcolor(3);
					printf ("N° CIN %s",Rech_clt_cin(cc,cinn)->info2.cin);
					gotoxy(7+i,7+k);
					printf("NOM: %s\n",Rech_clt_cin(cc,cinn)->info2.nom);
					gotoxy(7+i,8+k);
					printf("PRENOM : %s\n",Rech_clt_cin(cc,cinn)->info2.prenom);
					gotoxy(7+i,10+k);
					printf("N° TEL : %s\n",Rech_clt_cin(cc,cinn)->info2.tel);
					gotoxy(7+i,8+k);
					printf("Matricule : %s\n",p->info3.mat);
					gotoxy(7+i,9+k);
					printf("Marque : %s\n",Rech_voit_mat(vv,p->info3.mat)->info1.marque);
					gotoxy(7+i,10+k);
					printf("Couleur : %s\n",Rech_voit_mat(vv,p->info3.mat)->info1.couleur);
					gotoxy(7+i,11+k);
					printf("Duree location : %ld\n",p->info3.DureeL);
					gotoxy(2+i,12+k);
                    printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
					gotoxy(7+i,12+k);
					printf("Montant à payer=%.2fDT\n",p->info3.mt_p);
				i=i+25;
				if (i>60)
				{
				   k=k+13;
				   i=0;

				}
				ok=1;
            }

        }
        p=p->suiv3;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Ce client n'a aucun auncune location");

         }


     else
     {
       textcolor(RED);
       gotoxy(20,3);
       printf("Les locations de ce clients ");
     }
     }

}
void affiche_mat_loc(liste_loc l)
{
    int ok=0,i=0,k=0; char matt [10];
    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des locations Vide");
    }
	 else
     {  clrscr();gotoxy(7,3);
		 textcolor(15);
		printf(" Donnez La Matricule de la voiture à chercher les locations   ");
	    fflush(stdin);
		textcolor(14);
		gets(matt);
         liste_loc p=l;
        while(p)
        {
            if  (strcmp(p->info3.mat,matt)==0)
            {
           textcolor(3);
           gotoxy(2+i,6+k);
           textcolor(WHITE);
           printf ("la location N° %d",p->info3.num);
           textcolor(3);
           gotoxy(2+i,8+k);
           printf("N° Cin client  : %s\n",p->info3.cin);
           gotoxy(2+i,9+k);
           printf("Matricule : %s\n",p->info3.mat);
           gotoxy(2+i,10+k);
           printf("Date location:%d/%d/%dH%d\n",p->info3.DL.j,p->info3.DL.m,p->info3.DL.a,p->info3.DL.h);
           gotoxy(2+i,11+k);
           printf("Duree location : %ld\n",p->info3.DureeL);
           gotoxy(2+i,12+k);
           printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
           gotoxy(2+i,12+k);
           printf("Montant à payer=%.2fDT\n",p->info3.mt_p);

				i=i+26;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv3;
        }


     if(ok==0)
  {
                   clrscr();
                   textbackground(3);
                   textcolor(RED);
	               gotoxy(20,15);
                   printf("Cette voiture n'a aucune location");

         }

}

}
void affiche_duree_loc(liste_loc l)
{
    int ok=0,i=0,k=0,d;
    if (l==NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des locations Vide");
    }
	 else
     {  liste_loc p=l;
        clrscr();
        gotoxy(7,3);
        textcolor(15);
		printf(" Donnez La Duree de location que vous cherchez   ");
		textcolor(14);
		scanf("%d",&d);
        while(p)
        {
            clrscr();
            if  (p->info3.DureeL==d)
            {
           textcolor(3);
           gotoxy(2+i,6+k);
           textcolor(WHITE);
           printf ("la location N° %d",p->info3.num);
           textcolor(3);
           gotoxy(2+i,8+k);
           printf("N° Cin client  : %s\n",p->info3.cin);
           gotoxy(2+i,9+k);
           printf("Matricule : %s\n",p->info3.mat);
           gotoxy(2+i,10+k);
           printf("Date location:%d/%d/%dH%d\n",p->info3.DL.j,p->info3.DL.m,p->info3.DL.a,p->info3.DL.h);
           gotoxy(2+i,11+k);
           printf("Duree location : %ld\n",p->info3.DureeL);
           gotoxy(2+i,12+k);
           printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
           gotoxy(2+i,12+k);
           printf("Montant à payer=%.2fDT\n",p->info3.mt_p);

				i=i+26;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv3;
        }


     if(ok==0)
        {
                clrscr();
                textbackground(3);
                textcolor(RED);
                gotoxy(20,15);
                printf("Aucune voiture n'est louée pour cette duree");

         }
		 else
            {
                textcolor(RED);
                gotoxy(20,3);
                printf("Les locations pour %d jours ",d);
            }

}

}
void affiche_date_loc(liste_loc l)
{
    int ok=0,i=0,k=0;date1 d;
    if (l==NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des locations Vide");
    }
	 else
     {  liste_loc p=l;
        clrscr();
        gotoxy(7,3);
        textcolor(15);
		printf(" Saisie la date a chercher   ");
		textcolor(17);
		do
     {
         fflush(stdin);
         gotoxy(6,5);
         printf("Donner le jour :");
         scanf("%d",&d.j);
         fflush(stdin);
         gotoxy(6,6);
         printf("Donner le mois :");
         scanf("%d",&d.m);
         fflush(stdin);
         gotoxy(6,7);
         printf("Donner l'annee :");
         scanf("%d",&d.a);
        clrscr();
        }while(!(validedate(d)==1));
        while(p)
        {
            if  (p->info3.DL.a==d.a && p->info3.DL.m==d.m && p->info3.DL.j==d.j)
            {
           textcolor(3);
           gotoxy(2+i,6+k);
           textcolor(WHITE);
           printf ("la location N° %d",p->info3.num);
           textcolor(3);
           gotoxy(2+i,8+k);
           printf("N° Cin client  : %s\n",p->info3.cin);
           gotoxy(2+i,9+k);
           printf("Matricule : %s\n",p->info3.mat);
           gotoxy(2+i,10+k);
           printf("Date location:%d/%d/%dH%d\n",p->info3.DL.j,p->info3.DL.m,p->info3.DL.a,p->info3.DL.h);
           gotoxy(2+i,11+k);
           printf("Duree location : %ld\n",p->info3.DureeL);
           gotoxy(2+i,12+k);
           printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
           gotoxy(2+i,12+k);
           printf("Montant à payer=%.2fDT\n",p->info3.mt_p);

				i=i+26;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv3;
        }


     if(ok==0)
        {
                clrscr();
                textbackground(3);
                textcolor(RED);
                gotoxy(20,15);
                printf("Aucune voiture n'est louée dans cette date");

         }
		 else
            {
                textcolor(RED);
                gotoxy(20,3);
                printf("Les locations pour %d/%d/%d ",d.j,d.m,d.a);
            }

}

}
void affiche_dateentre_loc(liste_loc l)
{
    int ok=0,i=0,k=0;date1 d1,d2;
    if (l==NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des locations Vide");
    }
	 else
     {  liste_loc p=l;
        clrscr();
        gotoxy(7,3);
        textcolor(15);
		printf(" Saisie la 1ere date");
		textcolor(17);
		do
        {
		do
     {
         gotoxy(7,3);
        textcolor(15);
		printf(" Saisie la 1ere date");
		textcolor(17);
         fflush(stdin);
         gotoxy(6,5);
         printf("Donner le jour :");
         scanf("%d",&d1.j);
         fflush(stdin);
         gotoxy(6,6);
         printf("Donner le mois :");
         scanf("%d",&d1.m);
         fflush(stdin);
         gotoxy(6,7);
         printf("Donner l'annee :");
         scanf("%d",&d1.a);
     }while(!(validedate(d1)==1));
	    gotoxy(7,13);
        textcolor(15);
		printf(" Saisie la 2eme date");
		textcolor(17);
		d2=saisie_date1();
        clrscr();
        }while (!(d1.a<d2.a || (d1.a==d2.a && d1.m<d2.m) || (d1.a==d2.a && d1.m==d2.m && d1.j<d2.j) ));
        while(p)
        {
            if ((p->info3.DL.a>=d1.a && p->info3.DL.a<=d2.a)||((p->info3.DL.a==d1.a==d1.a) && p->info3.DL.m>=d1.m && p->info3.DL.m<=d2.m) || ((p->info3.DL.a==d1.a==d1.a) &&(p->info3.DL.m==d1.m==d1.m )&& p->info3.DL.j>=d1.j && p->info3.DL.j<=d2.j))
            {
           textcolor(3);
           gotoxy(2+i,6+k);
            textcolor(WHITE);
           printf ("la location N° %d",p->info3.num);
           textcolor(3);
           gotoxy(2+i,8+k);
           printf("N° Cin client  : %s\n",p->info3.cin);
           gotoxy(2+i,9+k);
           printf("Matricule : %s\n",p->info3.mat);
           gotoxy(2+i,10+k);
           printf("Date location:%d/%d/%dH%d\n",p->info3.DL.j,p->info3.DL.m,p->info3.DL.a,p->info3.DL.h);
           gotoxy(2+i,11+k);
           printf("Duree location : %ld\n",p->info3.DureeL);
           gotoxy(2+i,12+k);
           printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
           gotoxy(2+i,12+k);
           printf("Montant à payer=%.2fDT\n",p->info3.mt_p);

				i=i+26;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}
				ok=1;
            }
				p=p->suiv3;
        }


     if(ok==0)
        {
                clrscr();
                textbackground(3);
                textcolor(RED);
                gotoxy(20,15);
                printf("Aucune voiture n'est louée entre ces deux dates");

         }
		 else
            {
                textcolor(RED);
                gotoxy(20,3);
                printf("Les locations entre %d/%d/%d et %d/%d/%d",d1.j,d1.m,d1.a,d2.j,d2.m,d2.a);
            }

}

}
liste_loc Modification_duree(liste_loc l,int d)
{
    liste_loc p;
    printf("blablabla");;
    Sleep(60);
    p=Rech_loc_num(l,d);
    if(p==NULL)
        {gotoxy(20,15);
        textcolor(RED);
        textbackground(5);
        printf("La location N'Existe Pas");}
    else
        {
		do
        {gotoxy(12,5);
		 textcolor(15);
		 printf("\5\5 Donnez La nouvelle duree  : ");
         gotoxy(50,5);
		 fflush(stdin);
		 textcolor(14);
		 scanf("%d",&d);
        }while (!(d>0));
		p->info3.DureeL=d;
        clrscr();
        textbackground(3);
        textcolor(RED);
        gotoxy(20,15);
         printf("Modification fait avec succes");
		}


    return l;
}
void tri1l(liste_loc l)
{
    liste_loc p;
    int ok,j,i=0,t=taillel(l),k=((t*9/3)+8);

    location aux;
	    if (l == NULL)
    {
      clrscr();
    textbackground(3);
    textcolor(RED);
	 gotoxy(20,15);
    printf("Liste des voitures Vide");
    }
	 else
    { clrscr();
	affiche_loc(l);
    gotoxy(15,4);
    textcolor(RED);
     printf("Liste des voitures avant tri");
    do
    {
        ok=1;
        p=l;
        while(p->suiv3)
        {
            if(p->info3.mt_p<p->suiv3->info3.mt_p)
            {
                aux=p->info3;
                p->info3=p->suiv3->info3;
                p->suiv3->info3=aux;
                ok=0;
            }
            p=p->suiv3;
        }
    }while(ok==0);
    textcolor(RED);
	 gotoxy(15,4+k);
     printf("Liste des locations apres tri");
        for(p=l;p!=NULL;p=p->suiv3)
        {  textcolor(3);
           gotoxy(2+i,6+k);
           textcolor(WHITE);
           printf ("la location N° %d",p->info3.num);
           textcolor(3);
           gotoxy(2+i,8+k);
           printf("N° Cin client  : %s\n",p->info3.cin);
           gotoxy(2+i,9+k);
           printf("Matricule : %s\n",p->info3.mat);
           gotoxy(2+i,10+k);
           printf("Date location:%d/%d/%dH%d\n",p->info3.DL.j,p->info3.DL.m,p->info3.DL.a,p->info3.DL.h);
           gotoxy(2+i,11+k);
           printf("Duree location : %d\n",p->info3.DureeL);
            gotoxy(2+i,12+k);
           printf("Date de retour:%d/%d/%d\n",p->info3.DR.j,p->info3.DR.m,p->info3.DR.a);
           gotoxy(2+i,13+k);
           printf("Montant à payer=%.2fDT\n",p->info3.mt_p);

				i=i+26;
				if (i>60)
				{
				   k=k+9;
				   i=0;

				}

    }
}
}
#endif // PROGRAMMES_H_INCLUDED
