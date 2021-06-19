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
*  Nom du fichier : cesar.h                                                 *
*                                                                             *
******************************************************************************/
#ifndef CESAR_H
#define CESAR_H

/* Cette fonction permet de chiffrer un tableau de caractères avec le chiffrement de César,
elle prend un tableau de wchar_t et un entier en entrée représentant le message et le décalage (clé), 
le message est modifié et les lettres accentuées seront converties, le message peut contenir des caractères 
accentués ainsi que des espaces. La fonction renvoie 1 en cas de succès, sinon elle renvoie 0 */
int chiffrerCesar(wchar_t message[], int decalage);

/* Cette fonction permet de déchiffrer un tableau de caractères avec le chiffrement de César,
elle prend un tableau de wchar_t et un entier en entrée représentant le message et le décalage (clé), 
le message est modifié et les lettres accentuées seront converties, le message peut contenir des caractères 
accentués ainsi que des espaces. La fonction renvoie 1 en cas de succès, sinon elle renvoie 0 */
int dechiffrerCesar(wchar_t message[], int decalage);

#endif