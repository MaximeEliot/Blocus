#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include<string.h>

void affiche_J1(int tab[9][9],int ecartement,int taille,int sprite){
int x,y;


for(x=0;x<9;x++){
	for(y=0;y<9;y++){
		if(tab[x][y]==1){
			
			AfficherSprite(sprite,(x*taille+ecartement+1),((y)*taille+ecartement+1));
		}
	}
}

} 

void affiche_J2(int tab[9][9],int ecartement,int taille,int sprite){
int x,y;

for(x=0;x<9;x++){
	for(y=0;y<9;y++){
		if(tab[x][y]==2){
			
			AfficherSprite(sprite,(x*taille+ecartement+1),((y)*taille+ecartement+1));
		}
	}
}

} 

int possibilite(int tab[9][9],int x,int y){
int possi=0,f1,f2;
x=x-1;
y=y-1;
for(f1=0;f1<3;f1++){
	for(f2=0;f2<3;f2++){
		if(tab[x+f2][y+f1]==0 && 0<=(x+f2) && 9>(x+f2) && 0<=(y+f1) && 9>(y+f1)){
			possi++;
		}
	}
}
return possi;}

void suppJ(int x,int y,int taille,int ecartement){
	ChoisirCouleurDessin(CouleurParNom("white"));
	RemplirRectangle((x*taille+ecartement+1),((y)*taille+ecartement+1),taille-2,taille-2);
	ChoisirCouleurDessin(CouleurParNom("black"));
}

void affichecroix_J1(int tab[9][9],int ecartement,int taille,int sprite){
int x,y;

for(x=0;x<9;x++){
	for(y=0;y<9;y++){
		if(tab[x][y]==3){
			
			AfficherSprite(sprite,(x*taille+ecartement+1),((y)*taille+ecartement+1));
		}
	}
}

} 

void affichecroix_J2(int tab[9][9],int ecartement,int taille,int sprite){
int x,y;

for(x=0;x<9;x++){
	for(y=0;y<9;y++){
		if(tab[x][y]==4){
			
			AfficherSprite(sprite,(x*taille+ecartement+1),((y)*taille+ecartement+1));
		}
	}
}

} 