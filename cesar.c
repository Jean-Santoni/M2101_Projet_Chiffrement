
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
*  Nom du fichier : cesar.c                                                 *
*                                                                             *
******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "cesar.h"
#include "utils.h"

void chiffrerCesar(char message[], size_t tailleMessage, size_t decalage) {
	for (int i = 0; i<tailleMessage; i++) {
			if (isupper(message[i])) {
				message[i]-= 65; //mettre la lettre entre 0 et 25 pour coller à l'index de la table (majuscule)
				message[i] = table_alphabet[((message[i] + decalage) % 26)];
			} else if (islower(message[i])) {
				message[i]-= 97; //mettre la lettre entre 0 et 25 pour coller à l'index de la table (minuscule)
				message[i] = tolower(table_alphabet[((message[i] + decalage) % 26)]);
			}	
	}
}
