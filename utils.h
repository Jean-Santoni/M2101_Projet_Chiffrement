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
*  Nom du fichier : utils.h                                                 *
*                                                                             *
******************************************************************************/
#ifndef UTILS_H
#define UTILS_H

#define TAILLE_STATUS_ERREUR 300

wchar_t rotation(wchar_t lettre, int decalage);
wchar_t indiceAlphabet(wchar_t lettre);
void set_erreur(char message[]);
char* get_erreur();
int verifierAlphanumerique(wchar_t chaine[]);
void convertirAccent(wchar_t chaine[]);


#endif
