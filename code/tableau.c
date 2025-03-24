#include<stdlib.h>
#include<stdio.h>
#include<graph.h>

int tableau(int choix,int taille,int ecartement){
	int x,y,l,h,f1,f2,dim;
	
	l=taille;
	h=taille;
	y=ecartement;
	x=ecartement;

	FermerGraphique();
	dim=(taille*choix)+2*ecartement;
	InitialiserGraphique();
	CreerFenetre(10,10,dim,dim);
	 for(f1=0; f1<choix ; f1++){
	 	for(f2=0; f2<choix ; f2++) {
	 DessinerRectangle(x,y,l,h);
	 	x=x+taille;}
	 	x=ecartement;
	 	y=y+taille;}
	 

    
return dim;}