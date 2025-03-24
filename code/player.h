#ifndef PLAYER_H
#define PLAYER_H

void affiche_J1(int tab[9][9],int ecartement,int taille,int sprite); // affiche le srpite du joueur 1
void affiche_J2(int tab[9][9],int ecartement,int taille,int sprite); // affiche le srpite du joueur 2
int possibilite(int tab[9][9],int x,int y); // vérifie si les joueur peuvent se déplacé ou non
void suppJ(int x,int y,int taille,int ecartement); // supprime le sprite du joueur
void affichecroix_J1(int tab[9][9],int ecartement,int taille,int sprite);// affiche le srpite due la croix du joueur 1
void affichecroix_J2(int tab[9][9],int ecartement,int taille,int sprite);// affiche le srpite due la croix du joueur 2
#endif /*PLAYER_H*/