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
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <locale.h>
#include <time.h>
#include "utils.h"
#include "cesar.h"
#include "vigenere.h"

#define TAILLE_MAX_TEXTE 1000

//Ces procedure évite la réutilisation de bout de code
void entreeChiffreUtilisateur(int* choix) { 
	*choix = 0;
	while (*choix == 0) {
		if (wscanf(L"%d", choix) != 1) {
			wprintf(L"Erreur, veuillez entrer un chiffre\n");
			while ((getwchar()) != '\n'); //nettoyer le cache
			*choix = 0;
		}
	}
	//while ((getwchar()) != '\n'); //nettoyer (encore) le cache (éviter les dépassements)
}

void entreeTexteUtilisateur(wchar_t inputTexte[TAILLE_MAX_TEXTE]) { 
	fgetws(inputTexte,TAILLE_MAX_TEXTE,stdin);
	inputTexte[wcslen(inputTexte)-1] = L'\0'; // retirer le \n
}

void main() {
	/// INITIALISATION LOCALE
	struct lconv *loc;
	setlocale (LC_ALL, "");
	loc=localeconv();

	//INITIALISATION VARIABLES
	FILE *fp;
	char asciiNomFichier[TAILLE_MAX_TEXTE];
	wchar_t nomFichier[TAILLE_MAX_TEXTE] = {0};
	wchar_t inputTexte[TAILLE_MAX_TEXTE] = {0};
	wchar_t inputCleVigenere[TAILLE_MAX_TEXTE]= {0}; 
	int nombreActions= 0;
	int enregistrerDansFichier = 0;
	int choix;
	int inputCleCesar;
	int etatChoix = 0;
	
	//BOUCLE PRINCIPALE (INFINIE)
	while (1) {
		wprintf(L"Bienvenue sur la machine à chiffrer !\n\nQue voulez vous faire ?\n-------------------------\n(1) Chiffrer Cesar\n(2) Déchiffrer Cesar\n(3) Chiffrer Vigenère\n(4) Déchiffrer Vigenère\n");
		if (enregistrerDansFichier == 1) {
			wprintf(L"(5) Enregistrer dans fichier ? (ACTIVÉ)\n");
		} else {
			wprintf(L"(5) Enregistrer dans fichier ? (DÉSACTIVÉ)\n");
		}
		wprintf(L"(6) Quitter\n");
		
		while (etatChoix == 0) {
			entreeChiffreUtilisateur(&choix);
			if (choix > 0 && choix < 7) {
				etatChoix = 1;
			} else {
				wprintf(L"Erreur, veuillez entrer un argument valide\n");
			}
		}
		while ((getwchar()) != '\n'); //nettoyer le cache (sinon un depassement à lieu)

		if (choix == 6) 
			exit(EXIT_SUCCESS);

		if (choix == 5) { //activer/désactiver l'enregistrement du fichier
			if (enregistrerDansFichier) {
				enregistrerDansFichier = 0;
			} else {
				enregistrerDansFichier = 1;
				wprintf(L"Entrez le nom du fichier (Attention ! Le contenue d'un fichier déjà existant seras écrasé)\n");
				entreeTexteUtilisateur(nomFichier);
				wcstombs(asciiNomFichier, nomFichier, sizeof(asciiNomFichier)); //convertir le nom du fichier en code ascii
			    if ((fp = fopen(asciiNomFichier, "w")) == NULL) {
			   	     wprintf(L"Erreur lors de la création du fichier, assurez vous d'avoir les droits suffisants ou d'avoir entré un nom valide\n");
				} else {
					///RECUPERER LE TEMPS ACTUEL
					time_t t = time(NULL);
					struct tm *tm = localtime(&t);
					char temps_actuel[64];
					strftime(temps_actuel, sizeof(temps_actuel), "%c", tm);
					///
					fwprintf(fp, L"------RAPPORT DU %s------\n", temps_actuel);
				}
				
				
			}
		}
			
		if (choix == 1 || choix == 2) {
				wprintf(L"Entrez votre message (CESAR)\n---------------------\n");
				entreeTexteUtilisateur(inputTexte);
				wprintf(L"Entrez votre clé (CESAR)\n---------------------\n");
				entreeChiffreUtilisateur(&inputCleCesar);
				if (enregistrerDansFichier) {
					fwprintf(fp, L"###### ACTION %d ######\nchiffrement: CESAR\n", nombreActions);
					nombreActions++;
				}
				if (choix == 1) {
					
					if (chiffrerCesar(inputTexte, inputCleCesar)) {
						wprintf(L"\n\n	Message chiffré avec le chiffrement de césar (décalage %d) : %ls\n\n\n", inputCleCesar, inputTexte);
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Message chiffré avec le chiffrement de césar (décalage %d) : %ls\n", inputCleCesar, inputTexte);
						}
					} else {
						fprintf(stderr, "Erreur lors du chiffrement de César: %s \n",get_erreur());
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Erreur lors du chiffrement de César: %s \n",get_erreur());
						}
					}
				} else {
					if (dechiffrerCesar(inputTexte, inputCleCesar)) {
						wprintf(L"\n\n	Message déchiffré avec le chiffrement de césar (décalage %d) : %ls\n\n\n", inputCleCesar, inputTexte);
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Message déchiffré avec le chiffrement de césar (décalage %d) : %ls\n", inputCleCesar, inputTexte);
						}
					} else {
						fprintf(stderr, "Erreur lors du déchiffrement de César: %s \n",get_erreur());
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Erreur lors du déchiffrement de César: %s \n",get_erreur());
						}
					}
				}
		}
		if (choix == 3 || choix == 4) {
				wprintf(L"Entrez votre message (VIGENERE)\n---------------------\n");
				entreeTexteUtilisateur(inputTexte);
				wprintf(L"Entrez votre clé (VIGENERE)\n---------------------\n");
				entreeTexteUtilisateur(inputCleVigenere);
				if (enregistrerDansFichier) {
					fwprintf(fp, L"###### ACTION %d ######\nchiffrement: VIGENERE\n", nombreActions);
					nombreActions++;
				}
				if (choix == 3) {
					if (chiffrerVigenere(inputTexte, inputCleVigenere)) {
						wprintf(L"\n\n	Message chiffré avec le chiffrement de Vigenère (clé %ls) : %ls\n\n\n", inputCleVigenere, inputTexte);
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Message chiffré avec le chiffrement de Vigenère (clé %ls) : %ls\n\n\n", inputCleVigenere, inputTexte);
						}
					} else {
						fprintf(stderr, "Erreur lors du chiffrement de Vigenère: %s \n",get_erreur());
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Erreur lors du chiffrement de Vigenère: %s \n",get_erreur());
						}
					} 
				} else {
					if (dechiffrerVigenere(inputTexte, inputCleVigenere)) {
						wprintf(L"\n\n	Message déchiffré avec le chiffrement de Vigenère (clé %ls) : %ls\n\n\n", inputCleVigenere, inputTexte);
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Message déchiffré avec le chiffrement de Vigenère (clé %ls) : %ls\n\n\n", inputCleVigenere, inputTexte);
						}
					} else {
						fprintf(stderr, "Erreur lors du déchiffrement de Vigenère: %s \n",get_erreur());
						if (enregistrerDansFichier) {
							fwprintf(fp, L"Erreur lors du déchiffrement de Vigenère: %s \n",get_erreur());
						}
					} 
					
				}
			
			
		}
		
		etatChoix = 0; //Pour éviter une répétition infinie
	}
}