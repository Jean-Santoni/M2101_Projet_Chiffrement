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
#include <wchar.h>
#include "utils.h"
#include "vigenere.h"

int chiffrerVigenere(wchar_t message[], wchar_t cle[]) {
	if(!verifierAlphanumerique(message) || !verifierCleVigenere(cle)) 
		return 0;
	int y = 0;
	for (int i = 0; i<wcslen(message); i++) {
		if (message[i] != ' ') { //ne pas chiffrer les espaces 
			if (y / wcslen(cle) == 1) //si on atteint la fin de la clé, on la répète
				y = 0;
			message[i] = rotation(message[i], indiceAlphabet(cle[y]));
			y++;
		}
	}
	return 1;
}
	
int dechiffrerVigenere(wchar_t message[], wchar_t cle[]) {
	if(!verifierAlphanumerique(message) || !verifierCleVigenere(cle))
		return 0;
	int y = 0;
	for (int i = 0; i<wcslen(message); i++) {
		if (message[i] != ' ') { //ne pas dechiffrer les espaces 
			if (y / wcslen(cle) == 1) //si on atteint la fin de la clé, on la répète
				y = 0;
			message[i] = rotation(message[i], -indiceAlphabet(cle[y]));
			y++;
		}
	}
	return 1;
};

int verifierCleVigenere(wchar_t cle[]) {
	if(!verifierAlphanumerique(cle)){
		set_erreur("La clé contient des caractères qui ne sont pas des lettres");
		return 0;
	}
	for (int i = 0; i<wcslen(cle); i++) { //vérifier la clé 
		if (cle[i] == ' ') {
	    	set_erreur("La cle ne doit pas contenir d'espaces"); 
			return 0;
		}
	}
	return 1;
}

