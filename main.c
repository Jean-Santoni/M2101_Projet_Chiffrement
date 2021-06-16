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
#include <wchar.h>
#include <locale.h>
#include "utils.h"
#include "cesar.h"
#include "vigenere.h"

void main() {
	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();
	wchar_t msg[] = L"noùs sômmés attâqués";
	wchar_t cle[] = L"LÖUISXIV";
	wprintf(L"message: %ls\n", msg);
	if (chiffrerCesar(msg, 3)) {
		wprintf(L"Message chiffré avec le chiffrement de césar (décalage 3) : %ls\n", msg);
	} else {
		fprintf(stderr, "Erreur lors du chiffrement de César: %s \n",get_erreur());
	}
	
	if (dechiffrerCesar(msg, 3)) {
		wprintf(L"Message déchiffré avec le chiffrement de césar: %ls\n", msg);
	} else {
		fprintf(stderr, "Erreur lors du déchiffrement de César : %s\n", get_erreur());
	}
	
	if (chiffrerVigenere(msg, cle)) {
		wprintf(L"Message chiffré avec le chiffrement de Vigenère (clé: %ls) : %ls\n",cle, msg);
	} else {
		fprintf(stderr, "Erreur lors du chiffrement de Vigenère: %s\n", get_erreur());
	}

	if (dechiffrerVigenere(msg, cle)) {
		wprintf(L"Message déchiffré avec le chiffrement de Vigenère (clé: %ls) : %ls\n",cle, msg);
	} else {
		fprintf(stderr, "Erreur lors du déchiffrement de Vigenère: %s\n", get_erreur());
	}
	
}
