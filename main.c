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
#include <stdlib.h>
#include "utils.h"
#include "cesar.h"
#include "vigenere.h"

#define TAILLE_MAX_TEXTE 200

//Cette procedures évite la réutilisation de ce bout de code
void entreeChiffreUtilisateur(int* inputNumero) { 
	while  ((*inputNumero != 1) && (*inputNumero != 2)) {
		wprintf(L">");
		while ((wscanf(L"%d", inputNumero) != 1)) { //si l'utilisateur n'entre pas un entier
			wprintf(L"Erreur ! Veuillez entrer un chiffre\n");
			while ((getwchar()) != '\n'); //nettoyer le cache
			wprintf(L">");
		}
		if (*inputNumero == 3)
			exit(EXIT_SUCCESS);
		if ((*inputNumero < 1) || (*inputNumero > 2)) {
			wprintf(L"Erreur ! Veuillez entrer un argument valide\n");
		}
	}
}

void main() {
	/// INITIALISATION LOCALE
	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();

	//INITIALISATION VARIABLES
	int quitter = 0;
	int inputNumero = 0;
	wchar_t inputTexte[TAILLE_MAX_TEXTE] = {0};
	wchar_t inputCleVigenere[TAILLE_MAX_TEXTE]= {0}; 
	int inputCleCesar;
	int chiffrerOuDechiffrer; // 1 = chiffrer, 2 = dechiffrer
	int methodeChiffrement; // 1 = cesar, 2 = Vigenere

	//BOUCLE PRINCIPALE
	while (quitter != 1) {
		inputNumero = 0; ///DEBUG ON SAIS JAMAIS HEIN
		wprintf(L"Bienvenue sur la machine à chiffrer !\n\nQue voulez vous faire ?\n-------------------------\n(1) Chiffrer\n(2) Déchiffrer\n(3) ###Quitter###\n");
		entreeChiffreUtilisateur(&inputNumero);
		chiffrerOuDechiffrer = inputNumero;
		inputNumero = 0;
		
		wprintf(L"\nQuelle méthode de chiffrement choisissez vous ?\n----------------------------------------------\n(1) Cesar\n(2) Vigenere\n(3) ###Quitter###\n");
		entreeChiffreUtilisateur(&inputNumero);
		methodeChiffrement = inputNumero;
		
		
		wprintf(L"Entrez votre message\n---------------------\n>");
		fgetws(inputTexte,TAILLE_MAX_TEXTE,stdin);
		fgetws(inputTexte,TAILLE_MAX_TEXTE,stdin);
		inputTexte[wcslen(inputTexte)-1] = L'\0'; // retirer le \n
		wprintf(L"Texte: %ls\n", inputTexte);
		

		if (methodeChiffrement == 1) {
			wprintf(L"Entrez votre clé (César)\n---------------------\n>");
			
			while ((wscanf(L"%d", &inputNumero) != 1)) { //si l'utilisateur n'entre pas un entier
					wprintf(L"Erreur ! Veuillez entrer un chiffre\n");
					while ((getwchar()) != '\n'); //nettoyer le cache
					wprintf(L">");
			}
			inputCleCesar = inputNumero;
			if (chiffrerOuDechiffrer == 1) {
				if (chiffrerCesar(inputTexte, inputCleCesar)) {
						wprintf(L"\n\n	Message chiffré avec le chiffrement de césar (décalage %d) : %ls\n\n\n", inputCleCesar, inputTexte);
				} else {
						fprintf(stderr, "Erreur lors du chiffrement de César: %s \n",get_erreur());
				}
			}  else {
				if (dechiffrerCesar(inputTexte, inputCleCesar)) {
						wprintf(L"\n\n	Message déchiffré avec le chiffrement de césar (décalage %d) : %ls\n\n\n", inputCleCesar, inputTexte);
				} else {
						fprintf(stderr, "Erreur lors du déchiffrement de César: %s \n",get_erreur());
				}								
			}
		} else {
			wprintf(L"Entrez votre clé (Vigenère)\n---------------------\n>");
			fgetws(inputCleVigenere,TAILLE_MAX_TEXTE,stdin);
			inputCleVigenere[wcslen(inputCleVigenere)-1] = L'\0'; // retirer le \n
			wprintf(L"Cle: %ls\n", inputCleVigenere);

			if (chiffrerOuDechiffrer == 1) {
				if (chiffrerVigenere(inputTexte, inputCleVigenere)) {
						wprintf(L"\n\n	Message chiffré avec le chiffrement de Vigenère (clé %ls) : %ls\n\n\n", inputCleVigenere, inputTexte);
				} else {
						fprintf(stderr, "Erreur lors du chiffrement de Vigenère: %s \n",get_erreur());
				} 
				}  else {
				if (dechiffrerVigenere(inputTexte, inputCleVigenere)) {
						wprintf(L"\n\n	Message déchiffré avec le chiffrement de Vigenère (clé %ls) : %ls\n\n\n", inputCleVigenere, inputTexte);
				} else {
						fprintf(stderr, "Erreur lors du déchiffrement de Vigenère: %s \n",get_erreur());
				}								
			}
		}
	}
}
