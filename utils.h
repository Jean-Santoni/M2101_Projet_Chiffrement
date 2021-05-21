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

#define TAILLE_STATUS_ERREUR 100

char rotation(char lettre, int decalage);
char indiceAlphabet(char lettre);
void set_erreur(char message[]);
char* get_erreur();
#endif