#include<stdlib.h>
#include<stdio.h>
#include<graph.h>
#include<string.h>
#define cycle 100000L

void menu_presentation(void){
	char text[]="BLOCUS \0",text1[]="Par eliot maxime et pot lucas\0";
	int go_on=1,temp=0;
	unsigned long suivant;
	suivant=Microsecondes()+cycle;
	while(go_on){
		if(suivant<Microsecondes()){
			EcrireTexte(250,100,text,2);
			suivant=Microsecondes()+cycle;
			temp=1;
		}
		if(suivant<Microsecondes() && temp==1){
				EcrireTexte(100,150,text1,2);
				suivant=Microsecondes()+cycle*20;
				temp=2;
			}
		if(suivant<Microsecondes() && temp==2){
			go_on=0;
		}
	}
}

int menu_taille(taille){
int choix=0,f1,x=50,y=200;
int go_on=1;
char text[]={"choisi la taille entre 3 et 9 : "};
char text2[7]={'3','4','5','6','7','8','9'};
char temp[2]={'0','\0'};
EffacerEcran(CouleurParNom("white"));
EcrireTexte(100,100,text,2);
printf("[log] le menu s'est correctement exécuté\n");

for (f1 = 0; f1 < 7; f1++)
{
	temp[0]=text2[f1];
	DessinerRectangle(x,y,taille,taille);
	EcrireTexte(x+(taille/2),y+(taille-20),temp,2);
	x=x+taille+10;
}

while(go_on) {	
	if (choix!=0) {
		go_on=0;
		}
	else{
		SourisCliquee();
		x=50;
		y=200;
	for(f1=0;f1<7;f1++){
		if (x<=_X && _X<=x+taille && y<=_Y && _Y<=y+taille)
		{
			choix=f1+3;
		}
		x=x+taille+10;
	}
	}

}


return choix ;}

int menu_player(int taille){
int f1,x=50,y=500,go_on=1,choixJoueur=0;
char text[]={"choisi le nombre de joueur : "};
char text2[2]={'1','2'};
char temp[2]={'0','\0'};
EcrireTexte(100,400,text,2);


for (f1 = 0; f1 < 2; f1++)
{
	temp[0]=text2[f1];
	DessinerRectangle(x,y,taille,taille);
	EcrireTexte(x+(taille/2),y+(taille-20),temp,2);
	x=x+taille+100;
}

while(go_on) {	
	if (choixJoueur!=0) {
		go_on=0;
		}
	else{
		SourisCliquee();
		x=50;
		y=500;
	for(f1=0;f1<2;f1++){
		if (x<=_X && _X<=x+taille && y<=_Y && _Y<=y+taille)
		{
			choixJoueur=f1+1;
		}
		x=x+taille+100;
	}
	}}

return choixJoueur;
}

int menu_fin(int dim,int res){
int choix=0,x=20,y=100,go_on=1,f1;
char text[]="rejouer",text1[]="terminer",text2[]="Egalite",text3[]="Le joueur 1 remporte la partie",text4[]="Le joueur 2 remporte la partie";
FermerGraphique();
InitialiserGraphique();
CreerFenetre(10,10,dim-100,dim/2);

EffacerEcran(CouleurParNom("white"));
 if(res==0){
   EcrireTexte(x,(dim/10)-3,text2,2);
 }
 if(res==1){
   EcrireTexte(x,(dim/10)-3,text3,2);
 }
 if(res==2){
   EcrireTexte(x,(dim/10)-3,text4,2);
 }
x=dim/3;
DessinerRectangle(x,y,dim/4,dim/15);
EcrireTexte(x,y+(dim/15)-3,text,2);
y=y+100;
DessinerRectangle(x,y,dim/4,dim/15);
EcrireTexte(x,y+(dim/15)-3,text1,2);

while(go_on) {	
	if (choix!=0) {
		go_on=0;
		}
	else{
		SourisCliquee();
		x=dim/3;
		y=100;
	for(f1=0;f1<2;f1++){
		if (x<=_X && _X<=(x+dim/4) && y<=_Y && _Y<=y+(dim/15))
		{
			choix=f1+1;
		}
		y=y+100;
	}
	}}

return choix;}
