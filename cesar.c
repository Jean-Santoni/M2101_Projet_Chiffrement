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
#include <stdio.h>
#include <wchar.h>
#include "cesar.h"
#include "utils.h"

int chiffrerCesar(wchar_t message[], int decalage) {
	if (!verifierAlphanumerique(message))
		return 0;
	
	for (int i = 0; i<wcslen(message); i++) 
			message[i] = rotation(message[i], decalage);
	return 1;
}

int dechiffrerCesar(wchar_t message[], int decalage) {
	if (!verifierAlphanumerique(message))
		return 0;
		
	chiffrerCesar(message, -decalage);
	return 1;
}
