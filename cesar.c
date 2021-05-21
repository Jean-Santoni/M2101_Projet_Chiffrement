
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

#include <string.h>
#include "cesar.h"
#include "utils.h"

int chiffrerCesar(char message[], int decalage) {
	//vérifier avec fonction verifierAlphanumerique() et retourner 0 si pas bon
	for (int i = 0; i<strlen(message); i++) {
			message[i] = rotation(message[i], decalage);
	}
	return 1;
}

int dechiffrerCesar(char message[], int decalage) {
	//vérifier avec fonction verifierAlphanumerique() et retourner 0 si pas bon
	chiffrerCesar(message, -decalage);
	return 1;
}
