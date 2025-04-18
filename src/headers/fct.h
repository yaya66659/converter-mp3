#ifndef _FCT_H_
#define _FCT_H_

#define  _SIZE_BUFFER_ 3000

typedef enum{
FAUX,
VRAI
}booleen;

void commandeAudioEnMp3(char*  NomDuFichierAConvertir);

void extractionVideoEnMp3(char * nomFichier);

void compressionVideo(char * nomFichier);

char * retourneNomDeFichierSansExtention(char * nomFichier);

char * returneExtension(char * nomfichier);

void afficheManuel();

void afficheLICENSE();


void clearScreen();

void pause();
booleen returnsiVraiVideaoSinonMusique(char * nomFichier);

#endif //_FCT_H_
