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
/* Cette fonction permet de chiffrer un tableau de caractères avec le chiffrement de Vigenère,
elle prend deux tableau de wchar_t en entrée représentant le message et la clé, le message est modifié ainsi que
la clé si celle ci contient des accents. La clé ne doit contenir aucun autres caractères que des lettres 
(les lettres accentuées seront converties), le message peut contenir des caractères accentués ainsi que des espaces.
La fonction renvoie 1 en cas de succès, sinon elle renvoie 0 */
int chiffrerVigenere(wchar_t message[], wchar_t cle[]);

/* Cette fonction permet de déchiffrer un tableau de caractères avec le chiffrement de Vigenère,
elle prend deux tableau de wchar_t en entrée représentant le message et la clé, le message est modifié ainsi que
la clé si celle ci contient des accents. La clé ne doit contenir aucun autres caractères que des lettres
 (les lettres accentuées seront converties), le message peut contenir des caractères accentués ainsi que des espaces.
 La fonction renvoie 1 en cas de succès, sinon elle renvoie 0 */
int dechiffrerVigenere(wchar_t message[], wchar_t cle[]);

/* Cette fonction permet de vérifier si une clé (Vigenère) est valide, elle prend en entrée un tableau de wchar_t
représentant la clé et renvoie 1 si la clé est valide, sinon, la fonction renvoie 0. Les caractères accentués de la
clé seront convertis dans tout les cas */
int verifierCleVigenere(wchar_t cle[]);

#endif