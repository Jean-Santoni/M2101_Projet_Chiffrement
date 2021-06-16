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
*  Nom du fichier : vigenere.h                                                 *
*                                                                             *
******************************************************************************/
#ifndef VIGENERE_H
#define VIGENERE_H

int chiffrerVigenere(wchar_t message[], wchar_t cle[]);
int dechiffrerVigenere(wchar_t message[], wchar_t cle[]);
int verifierCleVigenere(wchar_t cle[]);

#endif