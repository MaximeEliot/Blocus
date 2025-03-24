#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include"tableau.h"
#include"menu.h"
#include"player.h"
#include<time.h>

#define taille 75
#define ecartement 50
#define dimFenetre 700
#define CYCLE 1000000L 



int main(void){
  int choix, choixJoueur, dim,choix_fin=1,go_on=1,possijoueur1=1,possijoueur2=1,x,y,X,Y,f1,f2,choixP=0,sprite1,sprite2,sprite3,sprite4,temp=0,xJ1,yJ1,xJ2,yJ2,res;
	char text[]="joueur :",text1[]="1",text2[]="2";
	unsigned long suivant;
	int game[9][9]={{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0},
									{0,0,0,0,0,0,0,0,0}};


srand(time(NULL));
while(choix_fin==1){
	InitialiserGraphique();

	CreerFenetre(10,10,dimFenetre,dimFenetre);
	menu_presentation();
	choix=menu_taille(taille);
	choixJoueur=menu_player(taille);
	for(x=0;x<9;x++){
		for(y=0;y<9;y++){
			if(x>=choix || y>=choix){
				game[x][y]=-1;

			}
			if(x<choix && y<choix){
				game[x][y]=0;
			}
		}

	}

	dim=tableau(choix,taille,ecartement);
	printf("[log] un tableaux de %d s'est ouvert\n",choix );



/*initialisation du jeux*/
	sprite1=ChargerSprite("code/image/joueur_1.png");
	if(sprite1 == -1){
		printf("erreur lors du chargement d'un sprite.\n");
		FermerGraphique();
		return;
	}
	sprite2=ChargerSprite("code/image/joueur_2.png");
	if(sprite2 == -1){
		printf("erreur lors du chargement d'un sprite.\n");
		FermerGraphique();
		return;
	}
	sprite3=ChargerSprite("code/image/croix_1.png");
	if(sprite2 == -1){
		printf("erreur lors du chargement d'un sprite.\n");
		FermerGraphique();
		return;
	}
	sprite4=ChargerSprite("code/image/croix_2.png");
	if(sprite2 == -1){
		printf("erreur lors du chargement d'un sprite.\n");
		FermerGraphique();
		return;
	}
	EcrireTexte(dim/3,25,text,2);
	EcrireTexte(dim/3+110,25,text1,2);
	_X=0;
	_Y=0;
	 X=0;
	 Y=0;
	go_on=1,possijoueur1=1,possijoueur2=1,temp=0,choixP=0;
	while(go_on){
	
		if(choixP==1 ){
		  affiche_J1(game,ecartement,taille,sprite1);
			if(choixJoueur==2){
	  		choixP++;}
			if(choixJoueur==1){
			  X=(rand()%(choix));
				Y=(rand()%(choix));
	  		if(game[X][Y]==0){
	  			game[X][Y]=2;
					choixP=3;
					xJ2=X;
					yJ2=Y;}
		}
		ChoisirCouleurDessin(CouleurParNom("white"));
		RemplirRectangle(dim/3+110,0,ecartement,ecartement);
		ChoisirCouleurDessin(CouleurParNom("black"));
		EcrireTexte(dim/3+110,25,text2,2);
		}
		if (choixP==3) {
			affiche_J2(game,ecartement,taille,sprite2);
			go_on=0;
		}
		else{
			SourisCliquee();
			x=ecartement;
			y=ecartement;
			for(f1=0;f1<choix;f1++){
				for(f2=0;f2<choix;f2++){
			
					if (x<=_X && _X<=(x+taille) && y<=_Y && _Y<=(y+taille) && game[f2][f1]==0)
					{
						choixP++;
						temp++;
						game[f2][f1]=temp;
						if(temp==1){
							xJ1=f2;
							yJ1=f1;
						}
						if(temp==2){
							xJ2=f2;
							yJ2=f1;
						}
					_X=0;
					_Y=0;
					}
			
				x+=taille;}
	 		x=ecartement;
	 		y+=taille;}
		}

	}


	/*JEU*/
	temp=0;
	for(;possijoueur1!=0 && possijoueur2!=0;){
		temp=-1;
		if(temp==-1){ChoisirCouleurDessin(CouleurParNom("white"));
		RemplirRectangle(dim/3+110,0,ecartement,ecartement);
		ChoisirCouleurDessin(CouleurParNom("black"));
		EcrireTexte(dim/3+110,25,text1,2);
		temp=0;}
	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;}
	go_on=1;
	if(temp==0){
	while(go_on){
		
		if(temp==1){
			go_on=0;
		}
		else{
			SourisCliquee();
			x=ecartement+(xJ1-1)*taille;
			y=ecartement+(yJ1-1)*taille;
			for(f1=0;f1<3;f1++){
			for(f2=0;f2<3;f2++){

			
			if (x<=_X && _X<=(x+taille) && y<=_Y && _Y<=(y+taille) && game[xJ1-1+f2][yJ1-1+f1]==0 && (xJ1-1+f2)>=0 && (yJ1-1+f1)>=0 && (xJ1-1+f2)<9 && (yJ1-1+f1)<9)
			{
				suppJ(xJ1,yJ1,taille,ecartement);
				game[xJ1][yJ1]=0;
					xJ1=xJ1-1+f2;
					yJ1=yJ1-1+f1;
				game[xJ1][yJ1]=1;
				affiche_J1(game,ecartement,taille,sprite1);

				temp=1;
				
				_X=0;
				_Y=0;
			}
			
			x+=taille;}
	 	x=ecartement+(xJ1-1)*taille;
	 	y+=taille;}

		}
	}}
	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;}
	if(temp==1){
	go_on=1;
	while(go_on){
		if(temp==2){
			go_on=0;
		}
		else{
			SourisCliquee();
			x=ecartement;
			y=ecartement;
			for(f1=0;f1<choix;f1++){
			for(f2=0;f2<choix;f2++){
			
			if (x<=_X && _X<=(x+taille) && y<=_Y && _Y<=(y+taille)&& game[f2][f1]==0 )
			{
				game[f2][f1]=3;
				temp=2;
				affichecroix_J1(game,ecartement,taille,sprite3);
				_X=0;
				_Y=0;
			}
			
			x+=taille;}
	 	x=ecartement;
	 	y+=taille;}

		}
	}}

	/*joueur 2*/
	if(choixJoueur==2){
		if(temp==2){ChoisirCouleurDessin(CouleurParNom("white"));
		RemplirRectangle(dim/3+110,0,ecartement,ecartement);
		ChoisirCouleurDessin(CouleurParNom("black"));
		EcrireTexte(dim/3+110,25,text2,2);
		temp=3;}
	
	go_on=1;
	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;}
	if(temp==3){
	while(go_on){
		
		if(temp==4){
			go_on=0;
		}
		else{
			SourisCliquee();
			x=ecartement+(xJ2-1)*taille;
			y=ecartement+(yJ2-1)*taille;
			for(f1=0;f1<3;f1++){
			for(f2=0;f2<3;f2++){

			
			if (x<=_X && _X<=(x+taille) && y<=_Y && _Y<=(y+taille) && game[xJ2-1+f2][yJ2-1+f1]==0 && (xJ2-1+f2)>=0 && (yJ2-1+f1)>=0 && (xJ2-1+f2)<9 && (yJ2-1+f1)<9)
			{
				suppJ(xJ2,yJ2,taille,ecartement);
				game[xJ2][yJ2]=0;
					xJ2=xJ2-1+f2;
					yJ2=yJ2-1+f1;
				game[xJ2][yJ2]=2;
				affiche_J2(game,ecartement,taille,sprite2);

				temp=4;
				
				_X=0;
				_Y=0;
			}
			
			x+=taille;}
	 	x=ecartement+(xJ2-1)*taille;
	 	y+=taille;}

		}
	}}
	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;}
	if(temp==4){
	go_on=1;
	while(go_on){
		if(temp==5){
			go_on=0;
		}
		else{
			SourisCliquee();
			x=ecartement;
			y=ecartement;
			for(f1=0;f1<choix;f1++){
			for(f2=0;f2<choix;f2++){
			
			if (x<=_X && _X<=(x+taille) && y<=_Y && _Y<=(y+taille) && game[f2][f1]==0)
			{
				game[f2][f1]=4;
				temp=5;
				affichecroix_J2(game,ecartement,taille,sprite4);
				_X=0;
				_Y=0;
			}
			
			x+=taille;}
	 	x=ecartement;
	 	y+=taille;}

		}
	}}}

	/*Bot*/
	
	if(choixJoueur==1){
		if(temp==2){ChoisirCouleurDessin(CouleurParNom("white"));
		RemplirRectangle(dim/3+110,0,ecartement,ecartement);
		ChoisirCouleurDessin(CouleurParNom("black"));
		EcrireTexte(dim/3+110,25,text2,2);
		temp=3;}
	
	go_on=1;
	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;}
	if(temp==3){
	  while(go_on){
		
			if(temp==4 && suivant<Microsecondes()){
				go_on=0;
			}
			if(temp==3){
			  X=(rand()%(dim)+1);
			  Y=(rand()%(dim)+1);
		   	x=ecartement+(xJ2-1)*taille;
				y=ecartement+(yJ2-1)*taille;
				for(f1=0;f1<3;f1++){
					for(f2=0;f2<3;f2++){

			
						if (x<=X && X<=(x+taille) && y<=Y && Y<=(y+taille) && game[xJ2-1+f2][yJ2-1+f1]==0 && (xJ2-1+f2)>=0 && (yJ2-1+f1)>=0 && (xJ2-1+f2)<9 && (yJ2-1+f1)<9)
						{
							suppJ(xJ2,yJ2,taille,ecartement);
							game[xJ2][yJ2]=0;
							xJ2=xJ2-1+f2;
							yJ2=yJ2-1+f1;
							game[xJ2][yJ2]=2;
							affiche_J2(game,ecartement,taille,sprite2);
							suivant=Microsecondes()+CYCLE;
							temp=4;
				
							X=0;
							Y=0;
						}
			
					x+=taille;}
	 			x=ecartement+(xJ2-1)*taille;
	 			y+=taille;}

			}
		}
	}
	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;}
		if(temp==4){
			go_on=1;
			while(go_on){
				if(temp==5 && suivant<Microsecondes()){
					go_on=0;
				}
				if(temp==4){
		     
					X=(rand()%(dim + 1));
					Y=(rand()%(dim + 1));
					x=ecartement;
					y=ecartement;
					for(f1=0;f1<choix;f1++){
						for(f2=0;f2<choix;f2++){
			
							if (x<=X && X<=(x+taille) && y<=Y && Y<=(y+taille) && game[f2][f1]==0)
							{
								game[f2][f1]=4;
								temp=5;
								affichecroix_J2(game,ecartement,taille,sprite4);
								X=0;
								Y=0;
								suivant=Microsecondes()+CYCLE;
							}
			
							x+=taille;
						}
	 					x=ecartement;
	 					y+=taille;
	 				}
				}
			}
		}
	}

	possijoueur1=possibilite(game,xJ1,yJ1);
	possijoueur2=possibilite(game,xJ2,yJ2);
	if(possijoueur1==0 || possijoueur2==0){temp=100;

		if(possijoueur1==0){
  		if(possijoueur2==0){
  	  	res=0;
   		}
   		else{
    		res=2;
   		}
 		}
 		else{
  		res=1;
		}
	}
}



/*FENETRE DE FIN*/
 choix_fin=menu_fin(dimFenetre,res);
FermerGraphique();}
if(choix_fin==1){
	go_on=1,possijoueur1=1,possijoueur2=1,temp=0,xJ1=0,yJ1=0,xJ2=0,yJ2=0;
}
if(choix_fin==2){

printf("[log] fin\n");
return;}
}
