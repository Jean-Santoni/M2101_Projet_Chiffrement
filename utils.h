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

/* Cette fonction permet de décaler un caractère de x caractères dans l'alphabet, 
elle prend en entrée un caractère wchar_t ainsi qu'un entier représentant la taille
du décalage, elle renvoie le caractère décalé, cette fonction supporte les majuscules
et les minuscules mais pas les lettres accentués */
wchar_t rotation(wchar_t lettre, int decalage);

/* Cette fonction renvoie la position dans l'alphabet d'un caractère, elle prend en
entrée un caractère wchar_t et renvoie un entier représentant sa position dans 
l'alphabet entre 0 et 25, cette fonction supporte les majuscules et les minuscules
mais pas les lettres accentués */
int indiceAlphabet(wchar_t lettre);

/* Cette fonction permet de modifier la variable globale contenant le message d'erreur,
elle prend en entrée une chaine de caractères sous la forme d'un tableau de char */
void set_erreur(char message[]);

/* Cette fonction renvoie un pointeur vers la chaine de caractère contenant le message
d'erreur */
char* get_erreur();

/* Cette fonction permet de vérifier si une chaine de caractère contient des caractères autres
que des lettres. Elle prend en entrée un tableau de wchar_t.
 Les lettres majuscules, minuscules sont acceptés et les accents seront convertis 
La fonction renvoie 1 en cas de succès, sinon celle ci renvoie 0 */
int verifierAlphanumerique(wchar_t chaine[]);

/* Cette fonction permet de convertir les lettres accentués d'une chaine de caractère, elle prend en
entrée un tableau de wchar_t. Les accents pouvant être convertis sont les suivants :
"ÀÁÂÃÄÅàáâãäåÇçÈÉÊËèéêëÌÍÎÏìíîïÑñÒÓÔÕÖòóôõöÙÚÛÜùúûüÝýÿ"*/
void convertirAccent(wchar_t chaine[]);

#endif
