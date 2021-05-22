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
*  Nom du fichier : main.c                                                 *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include "utils.h"
#include "cesar.h"
#include "vigenere.h"

void main() {

	
	char msg[] = "NOUS SOMMES ATTAQUES";
	char cle[] = "LOUISXIV";
	
	if (chiffrerCesar(msg, 3)) {
		printf("Message chiffré avec le chiffrement de césar (décalage 3) : %s\n", msg);
	} else {
		fprintf(stderr, "Erreur lors du chiffrement de César: %s \n",get_erreur());
	}
		
	if (dechiffrerCesar(msg, 3)) {
		printf("Message déchiffré avec le chiffrement de césar: %s\n", msg);
	} else {
		fprintf(stderr, "Erreur lors du déchiffrement de César : %s\n", get_erreur());
	}

	if (chiffrerVigenere(msg, cle)) {
		printf("Message chiffré avec le chiffrement de Vigenère (clé: %s) : %s\n",cle, msg);
	} else {
		fprintf(stderr, "Erreur lors du chiffrement de Vigenère: %s\n", get_erreur());
	}

	if (dechiffrerVigenere(msg, cle)) {
		printf("Message déchiffré avec le chiffrement de Vigenère (clé: %s) : %s\n",cle, msg);
	} else {
		fprintf(stderr, "Erreur lors du déchiffrement de Vigenère: %s\n", get_erreur());
	}
	
}
