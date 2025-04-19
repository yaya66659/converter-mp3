#ifndef _FCT_H_
#define _FCT_H_

#define  _SIZE_BUFFER_ 3000

typedef enum{
FAUX,
VRAI
}booleen;

typedef enum{
    FORMAT_INCORRECT,
    AUDIO,
    VIDEO
}formatExtension;

/*Convertie Audio en mp3*/
void commandeAudioEnMp3(char*  NomDuFichierAConvertir);

/*extrait Audio en mp3 d'une video*/
void extractionVideoEnMp3(char * nomFichier);

/*compresse une video en mp4 en gardant une qualiter suffisante*/
void compressionVideo(char * nomFichier);

/*compresse un audio wave en gardant l'extention .wav en gardant une qualiter suffisante*/
void compressionAudioWave(char * nomFichier);



/*return nom du fichier  en argument sans extention*/
char * retourneNomDeFichierSansExtention(char * nomFichier);

/*return extention (.mp3, .mp4 ...) du fichier en argument*/
char * returneExtension(char * nomfichier);

/*affiche le manuel d'utilisation*/
void afficheManuel();

/*affiche la licence*/

void afficheLICENSE();

/*efface l'ecran de la console*/
void clearScreen();

/* demande de saisir ENTER pour continuer...*/
void pause();

/*return AUDIO , VIDEO ou FORMAT_INCORRECT du genre du fichier */
formatExtension returnVideaoMusiqueOuIncorrectFormat(char * nomFichier);

#endif //_FCT_H_
