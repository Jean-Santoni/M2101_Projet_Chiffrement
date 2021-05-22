/******************************************************************************
*  ASR => M2101                                                               *
*******************************************************************************
*                                                                             *
*  N° de Sujet : 3                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Intitulé : Chiffrement                                                            *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom-prénom1 : Lacoste Pierre                                                     *
*                                                                             *
*  Nom-prénom2 : Santoni Jean                                               *
*                                                                             *
*******************************************************************************
*                                                                             *
*  Nom du fichier : utils.c                                                 *
*                                                                             *
******************************************************************************/
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

static char table_alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
char status_erreur[TAILLE_STATUS_ERREUR]; //variable globale servant à l'affichage des message d'erreurs.

char rotation(char lettre, int decalage) {
	if (!isalpha(lettre)) { //ne décaler QUE les lettres
		return lettre;
	}
	int indice, lettreDecale = lettre;
	lettreDecale = indiceAlphabet(lettreDecale);
	if (decalage < 0) {
		indice = (lettreDecale - abs(decalage)) % 26;
		if (indice < 0)
			 indice += 26; 
	} else {
		indice = (lettreDecale + abs(decalage)) % 26;
	}
	if (islower(lettre)) //support des lettres minuscles
		return tolower(table_alphabet[indice]);
	return table_alphabet[indice];
}

char indiceAlphabet(char lettre) {
	if (isupper(lettre))
		return lettre - 65; //mettre la lettre entre 0 et 25 pour coller à l'index de la table (majuscule)
	if (islower(lettre))
		return lettre - 97; //idem pour la lettre minuscule
}

void set_erreur(char message[]) {
	strncpy(status_erreur, message, TAILLE_STATUS_ERREUR);
}

char* get_erreur() {
	return status_erreur;
}
int verifierAlphanumerique(char chaine[]){
	for(int i= 0; i<strlen(chaine); i++){
		if( !isalpha(chaine[i])){
			if(chaine[i]!=' '){//Ignorer les espaces
				set_erreur("La chaine de caractères contient des caractères qui ne sont pas des lettres");
				return 0;
		 	 }
		}
	}
	return 1;
}
