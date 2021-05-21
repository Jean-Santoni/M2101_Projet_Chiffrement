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
*  Nom du fichier : vigenere.c                                                 *
*                                                                             *
******************************************************************************/

#include <string.h>
#include <stdio.h> //DEBUG
#include "utils.h"
#include "vigenere.h"

int chiffrerVigenere(char message[], char cle[]) {
	//vérifier avec fonction verifierAlphanumerique() et retourner 0 si pas bon
	for (int i = 0; i<strlen(cle); i++) { //vérifier la clé
		if (cle[i] == ' ') {
			set_erreur("La cle ne doit pas contenir d'espaces");
			return 0;
		}
	}
	int y = 0;
	for (int i = 0; i<strlen(message); i++) {
		if (message[i] != ' ') { //ne pas chiffrer les espaces 
			if (y / strlen(cle) == 1) //si on atteint la fin de la clé, on la répète
				y = 0;
			message[i] = rotation(message[i], indiceAlphabet(cle[y]));
			y++;
		}
	}
	return 1;
}
	
int dechiffrerVigenere(char message[], char cle[]) {
	for (int i = 0; i<strlen(cle); i++) { //vérifier la clé 
		if (cle[i] == ' ') {
			set_erreur("La cle ne doit pas contenir d'espaces");
			return 0;
		}
	}
	int y = 0;
	for (int i = 0; i<strlen(message); i++) {
		if (message[i] != ' ') { //ne pas dechiffrer les espaces 
			if (y / strlen(cle) == 1) //si on atteint la fin de la clé, on la répète
				y = 0;
			message[i] = rotation(message[i], -indiceAlphabet(cle[y]));
			y++;
		}
	}
	return 1;
};


