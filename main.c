#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif

#include <tchar.h>
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <stdlib.h>
#include "programmes.h"
liste_voit v=NULL;
liste_clt c=NULL;
liste_loc l=NULL;
char matt[10];
char cin[10];
char mar[20];
int msgboxID;
int d=1,nu;


/*  Declare Windows procedure  */

LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
HWND button;
HWND Txt;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = (HICON)LoadImage(GetModuleHandle(NULL),
                     MAKEINTRESOURCE(1),"C:\\Users" ,
                    16,16,0);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */

    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND+2+1;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
         hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Rent_Car"),       /* Title Text */
           WS_OVERLAPPEDWINDOW | WS_SYSMENU, /* default window */
           710,       /* Windows decides the position */
           100,       /* where the window ends up on the screen */
           610,                 /* The programs width */
           300,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );


    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}

/*  This function is called by the Windows function DispatchMessage()  */


LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    int a;
    char s;
    switch (message)                  /* handle the messages */
    {

     case WM_CREATE:{


         //  creation boutton exit
            button = CreateWindow("BUTTON","Exit",
            WS_VISIBLE | WS_CHILD | WS_BORDER,
            410,150,80,30,
            hwnd,(HMENU) 101,NULL,NULL);
            //  creation boutton recup
            button = CreateWindow("BUTTON","RECUPERATION TOUT",
            WS_VISIBLE | WS_CHILD | WS_BORDER,
            230,150,160,30,
            hwnd,(HMENU) 102,NULL,NULL);
             //  creation boutton ENRE
            button = CreateWindow("BUTTON","ENREGISTREMENT TOUT",
            WS_VISIBLE | WS_CHILD | WS_BORDER,
            5,150,190,30,
            hwnd,(HMENU) 103,NULL,NULL);
             //  creation boutton test
            Txt = CreateWindow("STATIC","PROJET REALISE PAR RIABI ARIJ",
            WS_VISIBLE | WS_CHILD |  WS_BORDER |BS_DEFPUSHBUTTON ,
            300,200,230,25,
            hwnd,103,NULL,NULL);

          //  creation menu
               HMENU menuprincipale=CreateMenu();
               HMENU menug1=CreateMenu();
               HMENU menug2=CreateMenu();
               HMENU menug3=CreateMenu();
               HMENU help=CreateMenu();
               HMENU mise1=CreateMenu();
               HMENU rech1=CreateMenu();
               HMENU mise2=CreateMenu();
               HMENU rech2=CreateMenu();
               HMENU mise3=CreateMenu();
               HMENU rech3=CreateMenu();
               HMENU ajout1=CreateMenu();
               HMENU supp1=CreateMenu();
               HMENU modif1=CreateMenu();
               HMENU ajout2=CreateMenu();
               HMENU supp2=CreateMenu();
               HMENU modif2=CreateMenu();
               HMENU ajout3=CreateMenu();
               HMENU supp3=CreateMenu();
               HMENU modif3=CreateMenu();
               HMENU enre=CreateMenu();
               AppendMenu(menuprincipale,MF_POPUP ,(UINT_PTR)menug1,"  Gestion de parc automobile");
               AppendMenu(menuprincipale,MF_POPUP ,(UINT_PTR)menug2,"    Gestion des clients");
               AppendMenu(menuprincipale,MF_POPUP ,(UINT_PTR)menug3,"    Gestion des locations");
               AppendMenu(menuprincipale,MF_POPUP ,(UINT_PTR)enre,"   ENR/RECU FIC");
               AppendMenu(menuprincipale,MF_POPUP ,(UINT_PTR)help,"   HELP");
               AppendMenu(help,MF_STRING,(UINT_PTR)200,"ENONCEE");
               AppendMenu(help,MF_STRING,(UINT_PTR)200,"RAPPORT");
               AppendMenu(menug1,MF_STRING,(UINT_PTR)2,"Création des voitures");
               AppendMenu(menug1,MF_POPUP,(UINT_PTR)mise1,"Mise à jour de la liste des voitures");
               AppendMenu(menug1,MF_POPUP,(UINT_PTR)rech1,"Recherche, affichage et Tri");
               AppendMenu(mise1,MF_POPUP,(UINT_PTR)ajout1,"Ajouter une nouvelle voiture");
               AppendMenu(mise1,MF_POPUP,(UINT_PTR)supp1,"Supprimer une voiture");
               AppendMenu(mise1,MF_POPUP,(UINT_PTR)modif1,"Modifier les données d'une voiture");
               AppendMenu(ajout1,MF_STRING,(UINT_PTR) 3,"Ajout en tête");
               AppendMenu(ajout1,MF_STRING,(UINT_PTR) 4,"Ajout en queue");
               AppendMenu(ajout1,MF_STRING,(UINT_PTR) 5,"Ajout dans une position");
               AppendMenu(supp1,MF_STRING,(UINT_PTR) 6,"Suppresion en tête");
               AppendMenu(supp1,MF_STRING,(UINT_PTR) 7,"Suppresion en queue");
               AppendMenu(supp1,MF_STRING,(UINT_PTR) 8,"Suppresion à partir d'une position");
               AppendMenu(supp1,MF_STRING,(UINT_PTR) 9,"Suppresion d'une voiture donnée");
               AppendMenu(supp1,MF_STRING,(UINT_PTR) 10,"Suppresion des voitures d'une marque donnée");
               AppendMenu(modif1,MF_STRING,(UINT_PTR) 11,"Couleur");
               AppendMenu(modif1,MF_STRING,(UINT_PTR) 12," Prix");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 13,"Contenu de la liste des voitures");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 14,"Recherche par matricule");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 15,"Recherche par marque");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 16,"Recherche par couleur");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 17,"Recherche des voitures disponibles");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 18,"Recherche des voitures louées");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 19,"Tri 1");
               AppendMenu(rech1,MF_STRING,(UINT_PTR) 20,"Tri 2");
               AppendMenu(menug2,MF_STRING ,(UINT_PTR) 21,"Création des clients");
               AppendMenu(menug2,MF_POPUP ,(UINT_PTR) mise2,"Mise à jour de liste des clients");
               AppendMenu(menug2,MF_POPUP ,(UINT_PTR) rech2,"Recherche , Affichage et Tri");
               AppendMenu(mise2,MF_POPUP,(UINT_PTR)ajout2,"Ajouter un nouvel client");
               AppendMenu(mise2,MF_POPUP,(UINT_PTR)supp2,"Supprimer un client");
               AppendMenu(mise2,MF_POPUP,(UINT_PTR)modif2,"Modifier les données d'un client ");
               AppendMenu(ajout2,MF_STRING,(UINT_PTR) 22,"Ajout en tête");
               AppendMenu(ajout2,MF_STRING,(UINT_PTR) 23,"Ajout en queue");
               AppendMenu(ajout2,MF_STRING,(UINT_PTR) 24,"Ajout dans une position");
               AppendMenu(supp2,MF_STRING,(UINT_PTR) 25,"Suppresion en tête");
               AppendMenu(supp2,MF_STRING,(UINT_PTR) 26,"Suppresion en queue");
               AppendMenu(supp2,MF_STRING,(UINT_PTR) 27,"Suppresion à partir d'une position");
               AppendMenu(supp2,MF_STRING,(UINT_PTR) 28,"Suppresion d'une client donnée");
               AppendMenu(modif2,MF_STRING,(UINT_PTR) 29,"Adresse");
               AppendMenu(modif2,MF_STRING,(UINT_PTR) 30," téléphne");
               AppendMenu(rech2,MF_STRING,(UINT_PTR) 31,"Contenu de la liste des clients");
               AppendMenu(rech2,MF_STRING,(UINT_PTR) 32,"Recherche par CIN");
               AppendMenu(rech2,MF_STRING,(UINT_PTR) 33,"Tri ");
               AppendMenu(menug3,MF_STRING ,(UINT_PTR) 77,"Création des locations");
               AppendMenu(menug3,MF_POPUP,(UINT_PTR)mise3,"Mise à jour de la liste des locations");
               AppendMenu(menug3,MF_POPUP,(UINT_PTR)rech3,"Recherche, affichage et Tri");
               AppendMenu(mise3,MF_POPUP,(UINT_PTR)ajout3,"Ajouter une nouvelle location");
               AppendMenu(mise3,MF_POPUP,(UINT_PTR)supp3,"Supprimer une location");
               AppendMenu(mise3,MF_POPUP,(UINT_PTR)modif3,"Modifier les données d'une location");
               AppendMenu(ajout3,MF_STRING,(UINT_PTR) 34,"Ajout en tête");
               AppendMenu(ajout3,MF_STRING,(UINT_PTR) 35,"Ajout en queue");
               AppendMenu(ajout3,MF_STRING,(UINT_PTR) 36,"Ajout dans une position");
               AppendMenu(supp3,MF_STRING,(UINT_PTR) 37,"Suppresion en tête");
               AppendMenu(supp3,MF_STRING,(UINT_PTR) 38,"Suppresion en queue");
               AppendMenu(supp3,MF_STRING,(UINT_PTR) 39,"Suppresion à partir d'une position");
               AppendMenu(supp3,MF_STRING,(UINT_PTR) 41,"Suppresion d'une location donnée");
               AppendMenu(modif3,MF_STRING,(UINT_PTR) 42,"date de location");
               AppendMenu(modif3,MF_STRING,(UINT_PTR) 43," Duree");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 44,"Contenu de la liste des locations");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 45,"Recherche par CIN");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 46,"Recherche par mat");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 47,"Recherche par date donnée");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 48,"Recherche par durée de location");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 49,"Recherche des locations entre 2 dates données");
               AppendMenu(rech3,MF_STRING,(UINT_PTR) 50,"Tri");
                AppendMenu(enre,MF_STRING,(UINT_PTR) 51,"Enregistrement fichier VOITURES ");
               AppendMenu(enre,MF_STRING,(UINT_PTR) 52,"Récupération fichier VOITURES");
               AppendMenu(enre,MF_STRING,(UINT_PTR) 53,"Enregistrement fichier CLIENTS");
               AppendMenu(enre,MF_STRING,(UINT_PTR) 54,"Récupération fichier CLIENTS");
               AppendMenu(enre,MF_STRING,(UINT_PTR) 55,"Enregistrement fichier LOCATIONS");
               AppendMenu(enre,MF_STRING,(UINT_PTR) 56,"Récupération fichier LOCATIONS");

               SetMenu(hwnd,menuprincipale);

                break;}


        case WM_COMMAND:

                    switch(LOWORD(wParam))
                    {
                        case 2 :clrscr();
                                v=crea_voit(v);
                                clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(5,9);
	                            printf("PENSEZ A ENREGISYTRER LA LISTE DANS LE FICHIER AVANT DE QUITTER LE PROGRAMME");
                                 break;
                        case 3: clrscr();
                                textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT EN TETE");
                                v=insere_tete_voiture(v);
                                clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("AJOUT FAIT AVEC SUCCESS");
                                break;
                        case 4: clrscr();
                                textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT EN QUEUE");
                                v=insere_queue_voiture(v);
                                 clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("AJOUT FAIT AVEC SUCCESS");
                                break;
                                 break;
                        case 5: clrscr();
                               textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT DANS UNE POSITION DONNEE");
                                insere_pos_voiture1(v);
                                break;
                        case 6: clrscr();
                                textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION EN TETE");
                                v=supp_tete_voit(v);
                                break;
                        case 7: clrscr();
                               textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION EN QUEUE");
                               supp_queue_voit(v);
                               break;
                        case 8:clrscr();
                               textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION DANS UNE POSITION");
                               supp_pos_voit(v);
                               break;
                        case 9: clrscr();
                              system("COLOR 70");
                              do
                                {
                                    gotoxy(12,3);
                                    textcolor(RED);
                                    fflush(stdin);
                                    printf("\5\5 Donnez La Matricule de la voiture à supprimer : (...TN....)");
                                    gotoxy(64,3);
                                    fflush(stdin);
                                    textcolor(14);
                                    gets(matt);;
                                } while(!(validemat(matt)==1));
			                  clrscr;
			                  v=supp_mat(v,matt);
                              break;
                    case 10:clrscr();
                              system("COLOR 70");
                              gotoxy(12,3);
		                      textcolor(RED);
			                  printf("\5\5 Donnez La Marque de la voiture à supprimer : ");
                              gotoxy(64,3);
			                  fflush(stdin);
			                  textcolor(14);
			                  gets(mar);
			                  v=supp_marque(v,mar);
                            break;
                    case 11:clrscr();
                              system("COLOR 70");
                              do
                                {
                                    gotoxy(12,3);
                                    textcolor(RED);
                                    fflush(stdin);
                                    printf("\5\5 Donnez La Matricule de la voiture à modifier  : (...TN....)");
                                    gotoxy(64,3);
                                    fflush(stdin);
                                    textcolor(14);
                                    gets(matt);;
                                } while(!(validemat(matt)==1));
			                  v=Modification_couleur(v,matt);

                            break;
                   case 12:clrscr();
                              system("COLOR 70");
                              do
                                {
                                    gotoxy(12,3);
                                    textcolor(RED);
                                    fflush(stdin);
                                    printf("\5\5 Donnez La Matricule de la voiture à modifier  : (...TN....)");
                                    gotoxy(64,3);
                                    fflush(stdin);
                                    textcolor(14);
                                    gets(matt);;
                                } while(!(validemat(matt)==1));
			                  v=Modification_prix(v,matt);
                            break;
                  case 13: clrscr();affiche_voit(v);
                                    break;
                            break;
                  case 14: clrscr();affiche_mat(v);
                            break;
                  case 15: clrscr();affiche_mar(v);
                            break;
                  case 16:clrscr();affiche_couleur(v);
                            break;
                  case 17: clrscr();affiche_d(v,&d);
                            break;
                  case 18:clrscr();affiche_l(v);
                            break;
                 case 19: clrscr();
                          system("COLOR 70");
                          tri1v(v);
                            break;
                case 20:clrscr();
                          system("COLOR 70");
                          tri2v(v);
                            break;
                case 21 :clrscr();
                                c=crea_clt(c);
                                clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(5,9);
	                            printf("PENSEZ A ENREGISYTRER LA LISTE DANS LE FICHIER AVANT DE QUITTER LE PROGRAMME");
                                 break;
                case 22: clrscr();
                textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT EN TETE");
                                c=insere_tete_client(c);
                                clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("AJOUT FAIT AVEC SUCCESS");
                                break;
                case 23: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT EN QUEUE");
                                 c=insere_queue_client(c);
                                 clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("AJOUT FAIT AVEC SUCCESS");
                                break;
                case 24: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT DANS UNE POSITION DONNEE");
                                insere_pos_client1(c);
                                break;
               case 25: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION EN TETE");
                                v=supp_tete_clt(c);
                                break;
               case 26: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION EN QUEUE");
                               supp_queue_clt(c);
                               	textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("SUPPRESSION FAIT AVEC SUCCESS");
                               break;
              case 27:clrscr();
                               supp_pos_clt(c);
                               break;
              case 28: clrscr();
                              gotoxy(12,15);
		                      textcolor(RED);
			                  printf("\5\5 Donnez Le N° CIN  du client à supprimer ");
                              gotoxy(55,15);
			                  fflush(stdin);
			                  textcolor(14);
			                  gets(cin);
			                  c=supp_cin(c,cin);
                        break;
              case 29:
                              clrscr();
                              system("COLOR 70");
                              gotoxy(12,3);
		                      textcolor(RED);
			                  printf("\5\5 Donnez Le N° CIN du client  à modifier : ");
                              gotoxy(64,3);
			                  fflush(stdin);
			                  textcolor(14);
			                  gets(cin);
			                  c=Modification_adresse(c,cin);
                            break;
              case 30:clrscr();
                              system("COLOR 70");
                              gotoxy(12,3);
		                      textcolor(RED);
			                  printf("\5\5 Donnez Le N° CIN du client  à modifier : ");
                              gotoxy(64,3);
			                  fflush(stdin);
			                  textcolor(14);
			                  gets(cin);
			                  c=Modification_tele(c,cin);
                            break;
            case 31: affiche_clt(c);
                            break;
            case 32:affiche_cin(c);
                            break;
            case 33:clrscr();
                    system("COLOR 70");
                    tri1c(c);
                    break;
            case 34: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT EN TETE");
                                l=insere_tete_location(l,v,c);
                                clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("AJOUT FAIT AVEC SUCCESS");
                                break;
            case 35: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT EN QUEUE");
                                l=insere_queue_location(l,v,c);
                                 clrscr();
                                textbackground(3);
                                textcolor(RED);
	                            gotoxy(20,15);
	                            printf("AJOUT FAIT AVEC SUCCESS");
                                 break;
            case 36: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("AJOUT DANS UNE POSITION DONNEE");
                                insere_pos_location1(l,v,c);
                                break;
            case 37: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION EN TETE");
                                l=supp_tete_loc(l);

                        break;
            case 38: clrscr();textcolor(BLUE);
	                            gotoxy(20,4);
	                            printf("SUPPRESION EN QUEUE");
                               supp_queue_loc(l);
                               break;
            case 39:clrscr();
                               supp_pos_loc(l);
                               break;
            case 41:clrscr();
                     system("COLOR 70");
                     gotoxy(12,3);
                     textcolor(RED);
                     printf("\5\5 Donnez Le numero de la location à modifier : ");
                     gotoxy(63,3);
                     fflush(stdin);
                     textcolor(14);
                     scanf("%d",&nu);
                     l=supp_loc_num(l,nu);
                     break;

            case 43 :clrscr();
                              system("COLOR 70");
                              gotoxy(12,3);
		                      textcolor(RED);
			                  printf("\5\5 Donnez Le numero de la location à modifier : ");
                              gotoxy(63,3);
			                  fflush(stdin);
			                  textcolor(14);
			                  scanf("%d",&nu);
			                  l=Modification_duree(l,nu);break;
            case 44:clrscr;
                    system("COLOR 70");
                    affiche_loc(l);
                    break;
            case 45:clrscr();system("COLOR 70");
                    affiche_loc_cin(l,v,c);
                    break;
            case 46:clrscr();system("COLOR 70");
                    affiche_mat_loc(l);break;
            case 47:clrscr();system("COLOR 70");
                    affiche_date_loc(l);break;
             case 48:clrscr();system("COLOR 70");
                    affiche_duree_loc(l);break;
             case 49:clrscr();system("COLOR 70");
                    affiche_dateentre_loc(l);break;
             case 50:clrscr();
                    system("COLOR 70");
                    tri1l(l);
                    break;
            case 51: clrscr();
                                     enregistrement_voiture(v);
                                     system("COLOR 70");
                                     textbackground(3);
                                     textcolor(RED);
	                                 gotoxy(20,15);
                                     printf("ENREGISTREMENT FAIT AVEC SUCCESS");
                                     break;
                            case 52: clrscr();
                                v=recuperation_voiture();
                                     system("COLOR 70");
                                     textbackground(3);
                                     textcolor(RED);
	                                 gotoxy(20,15);
                                    printf("RECUPERATION FAIT AVEC SUCCESS");
                                     break;
                            case 53: clrscr();
                                     enregistrement_client(c);
                                     system("COLOR 70");
                                     textbackground(3);
                                     textcolor(RED);
	                                 gotoxy(20,15);
                                     printf("ENREGISTREMENT FAIT AVEC SUCCESS");
                                     break;
                            case 54: clrscr();
                                     c=recuperation_client();
                                     system("COLOR 70");
                                     textbackground(3);
                                     textcolor(RED);
	                                 gotoxy(20,15);
                                    printf("RECUPERATION FAIT AVEC SUCCESS");
                                     break;
                            case 55: clrscr();
                                     enregistrement_location(l);
                                     system("COLOR 70");
                                     textbackground(3);
                                     textcolor(RED);
	                                 gotoxy(20,15);
                                     printf("ENREGISTREMENT FAIT AVEC SUCCESS");
                                     break;
                            case 56: clrscr();
                                     l=recuperation_location();
                                     system("COLOR 70");
                                     textbackground(3);
                                     textcolor(RED);
	                                 gotoxy(20,15);
                                     printf("RECUPERATION FAIT AVEC SUCCESS");
                                     break;
                            case 77:
                                l=crea_loc(l,v,c); break;
                    case 102:
                                l=recuperation_location();
                                v=recuperation_voiture();
                                c=recuperation_client();
                                clrscr();
                                system("COLOR 70");
                                textbackground(3);
                                textcolor(RED);
                                gotoxy(20,15);
                                printf("RECUPERATION FAIT AVEC SUCCESS");
                                break;
                    case 103:
                                enregistrement_voiture(v);
                                enregistrement_location(l);
                                enregistrement_client(c);
                                clrscr();
                                system("COLOR 70");
                                textbackground(3);
                                textcolor(RED);
                                gotoxy(20,15);
                                printf("ENREGISTREMENT FAIT AVEC SUCCESS");
                                break;

                    case 101:
                        MessageBeep(MB_ICONERROR);
                        msgboxID=MessageBox(hwnd," Vous avez enregistrez les modifications dans les fichiers avant de quitter  ?        ","AU REVOIR ",MB_ICONWARNING | MB_YESNO);
                        switch (msgboxID)
                        {


                            case IDYES:
                                 PostQuitMessage (0);
                               break;
                            case IDNO:

                               break;
                        }
                    break;



                    }

                    break;

        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
