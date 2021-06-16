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
#include <wchar.h>
#include "utils.h"

char status_erreur[TAILLE_STATUS_ERREUR]; //variable globale servant à l'affichage des message d'erreurs.

wchar_t rotation(wchar_t lettre, int decalage) {
	const wchar_t table_alphabet[26] = L"ABCDEFGHIJKLMNOPQRSTUVWXYZ"; 
	if (!isalpha(lettre))  //ne décaler QUE les lettres
		return lettre;

	int indice, lettreDecale = lettre;
	lettreDecale = indiceAlphabet(lettreDecale); //indice entre 0 et 25
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

wchar_t indiceAlphabet(wchar_t lettre) {
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

int verifierAlphanumerique(wchar_t chaine[]) {
	convertirAccent(chaine);
	for(int i= 0; i<wcslen(chaine); i++){
		if( !isalpha(chaine[i]) ){
			if (chaine[i] != ' ') {//Ignorer les espaces
				set_erreur("La chaine de caractères contient des caractères qui ne sont pas des lettres");
				return 0;
		 	 }
		}
	}
	return 1;
}

void convertirAccent(wchar_t chaine[]) {
	const wchar_t table[54][3] = {L"ÀA",L"ÁA",L"ÂA",L"ÃA",L"ÄA",L"ÅA",L"àa",L"áa",L"âa",L"ãa",L"äa",L"åa",L"ÇC",L"çc",L"ÈE",L"ÉE",L"ÊE",L"ËE",L"èe",L"ée",L"êe",L"ëe",L"ÌI",L"ÍI",L"ÎI",L"ÏI",L"ìi",L"íi",L"îi",L"ïi",L"ÑN",L"ñn",L"ÒO",L"ÓO",L"ÔO",L"ÕO",L"ÖO",L"òo",L"óo",L"ôo",L"õo",L"öo",L"ÙU",L"ÚU",L"ÛU",L"ÜU",L"ùu",L"úu",L"ûu",L"üu",L"ÝY",L"ýy",L"ÿy"};
	for (int i = 0; i < wcslen(chaine); i++) {
		for (int y = 0; y < 54; y++) {
			if (chaine[i] == table[y][0]) {
				chaine[i] = table[y][1]; //on remplace l'accent par la lettre correspondante
			}
		}
	}
}
