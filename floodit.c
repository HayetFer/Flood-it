//code maison a ajouter a tp6
#include <stdlib.h>
#include <stdio.h>

// "constantes"
#define TAILLE 12
#define NB_COLORS 6
#define NB_ESSAIS 22

#define FG_SHIFT 30
#define BG_SHIFT 40
char c;


// type de donnees
typedef enum {BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, MAX_COLORS} ColorCode;

// prototypes
ColorCode ** creeGrille (int hayet){
	//aloue M = 4 pointeurs de ligne
	ColorCode **M;

	M=malloc(hayet*sizeof(int*));

	//alocation de ligne
	for(int i=0; i<hayet; ++i){
		M[i] = malloc (hayet*sizeof(int));
	}

	//initialisation
	for(int l = 0; l<hayet; ++l){
		for(int c=0; c<hayet; ++c){
			M[l][c]=0;

		}
	}
	return M;

}


                                          // A FAIRE
void detruitGrille (ColorCode ***pM, int pl){

for(int i=0;i<pl;++i){
	free((*pM)[i]);
	//M[i]=NULL NE SERS A RIEN !
}
free (*pM);
*pM=NULL;
}                                // A FAIRE

void afficheGrille (ColorCode **M, int pl){
	
		for(int j=0;j<pl; ++j){
			afficheCouleur (M[1][j], M[1][j], ' ');
			//printf("%d  ",M[i][j] );


		}
		printf("\n");
	}
                             // A FAIRE
void randomGrille (ColorCode **G, int T, int A){
	for(int i = 0; i<T; ++i){
		for(int j=0;j<A; ++j){
			/*if(i%2==0){G[i][j]=0;}
			else{
				G[i][j]=1;
			}*/
			G[i][j]=rand()%10;
		}
	}

}                             // A FAIRE
int isFlooded (ColorCode **G, int T){
	for(int i = 0; i<T; ++i){
		for(int j=0;j<T; ++j){
			if(G[i][j]!=G[i+1][j+1]){
				return 1;
			}
		}

	}

	return 0;
}


void propagate_rec (ColorCode ** G, int t, ColorCode avant, ColorCode apres, int lo, int la){

	afficheGrille(G, TAILLE);



	if(G[lo][la] == NULL){
		return;
	}

	if(G[lo][la]!=avant){
		return;
	}
	else {
		G[lo][la] = apres;
	}

	propagate_rec (G,  t,  avant, apres,  lo+1, la);
	propagate_rec (G,  t,  avant, apres,  lo-1,  la);
	propagate_rec (G,  t,  avant, apres,  lo,  la-1);
	propagate_rec (G,  t,  avant,  apres,  lo, la-1);

}


void propagate (ColorCode **G, int T, ColorCode X){
	int lar = 0;
	int lon = 0;
	int num;

	propagate_rec (G, T, G[lon][lar], num, lar, lon);

	
	
	
}



// A FAIRE
void play (int, int, int);                                              // A TERMINER


// implementations
void afficheCouleur (int fg, int bg, char c)
{
  printf("\033[%d;%dm %c\033[m", FG_SHIFT + fg, BG_SHIFT + bg, c);
}


void play (int t, int nb_col, int n)
{
  ColorCode ** G;
  int res = -1;

  // initialisation
  G = creeGrille (t);
  randomGrille (G, t, nb_col);
  afficheGrille (G, t);

  // boucle principale
  for (int i = 0; i < n; ++i)
  	printf("HEYYY");

    scanf( "%d", &res);
    printf( "%d",res);
  {




    /*while(isFlooded){
    	scanf( "%d", &res);
    	propagate(G, n, res );
    	afficheGrille (G, t);
    //}*/
  }


  // resultats
  if (res == -1)
    printf("Bye!\n");
  else if (isFlooded(G,t))
    printf("GAGNE!\n");
  else
    printf("PERDU!\n");

  // desallocation memoire
  detruitGrille(&G, t);
}


int main ()
{

	//ColorCode ** G = creeGrille (TAILLE);
	play (TAILLE, TAILLE, TAILLE);
	//randomGrille (G, TAILLE, TAILLE);
	//isFlooded (G, TAILLE);
	//afficheGrille(G, TAILLE);
	//propagate (G, TAILLE, GREEN);
	//detruitGrille(&G, TAILLE);
	//play(TAILLE, NB_COLORS, NB_ESSAIS);

  return EXIT_SUCCESS;
}