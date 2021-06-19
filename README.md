# Chiffrement de Messages
Le But de ce projet est de créer un programme permettant de chiffrer et déchiffrer des messages avec les chiffrements de Vigenère et de César.

##Construction du projet
Le projet utilise l'utilitaire make, pour constuire le projet, il suffit donc d'entrer la commande suivante dans votre terminal :

```bash
make all
```
Pour exécuter le programme de démonstration, vous pouvez ensuite taper

```bash
./main
```

##Interface du programme de démonstration
Le programme est sous la forme d'un menu demandant à l'utilisateur de faire des choix.

Le premier écran est sous cette forme:

```bash
Bienvenue sur la machine à chiffrer !

Que voulez vous faire ?
-------------------------
(1) Chiffrer Cesar
(2) Déchiffrer Cesar
(3) Chiffrer Vigenère
(4) Déchiffrer Vigenère
(5) Enregistrer dans fichier ? (DÉSACTIVÉ)
(6) Quitter

```

Si vous choisissez de chiffrer ou déchiffrer un programme (par exemple avec le chiffrement de Vigenère), l'écran seras sous cette forme :

```bash
Entrez votre message (VIGENERE)
---------------------
HELLO WORLD
```
Entrez votre message puis la clé:

```bash
Entrez votre clé (VIGENERE)
---------------------
WORLD
```
Le programme afficheras le résultat de la façon suivante:

```
Message chiffré avec le chiffrement de Vigenère (clé WORLD) : DSCWR SCIWG
```

Vous avez la possibilité d'enregistrer le résultats de vos actions dans un fichier en selectionnant l'option **(5)** du menu principal. Le programme vous demanderas alors le nom du fichier, celui ci seras créer dans le même répertoire que l'exècutable du programme (dans l'exemple le programme va créer un fichier nommé resultats.txt):

```
Entrez le nom du fichier (Attention ! Le contenue d'un fichier déjà existant seras écrasé)
resultats.txt
```

Si le nom du fichier est invalide, le programme vous le feras savoir.

Une fois le fichier créer, le programme retourne au menu principal et, à partir de ce moment là, tout vos chiffrements, déchiffrement seront enregistrés. Vous pouvez le désactiver en entrant à nouveau 5 dans le menu.

Voici un exemple de rapport:
> 
> ------RAPPORT DU sam. 19 juin 2021 13:10:32------
> 
> ###### ACTION 0 ######
> chiffrement: CESAR
> Message chiffré avec le chiffrement de césar (décalage 6) : GBK IKYGX
> 
> ###### ACTION 1 ######
> chiffrement: VIGENERE
> Message chiffré avec le chiffrement de Vigenère (clé louisxiv) : ycoa kluhpg ublxyppg
> 
> ###### ACTION 2 ######
> chiffrement: VIGENERE
> Erreur lors du déchiffrement de Vigenère: La cle ne doit pas contenir d'espaces 
> 

##Signature des fonctions
###cesar.h
```C
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
```
###vigenere.h
```C
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
```

###utils.h

```C
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
```

##Créateurs

###Lacoste pierre

###Santoni Jean
