#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#include "headers/fct.h"

void commandeAudioEnMp3(char*  NomDuFichierAConvertir){

    char * fichierSansExtention =  retourneNomDeFichierSansExtention(NomDuFichierAConvertir);

    char cmdFfmpeg[_SIZE_BUFFER_] ="ffmpeg -i \"";
    strcat(cmdFfmpeg, NomDuFichierAConvertir );
    strcat(cmdFfmpeg, "\" \"");
    strcat(cmdFfmpeg, fichierSansExtention);
    strcat(cmdFfmpeg, ".mp3\"");
    printf("Conversion de %s en MP3 avec la command:  %s\n", NomDuFichierAConvertir, cmdFfmpeg );
    system(cmdFfmpeg);
    free(fichierSansExtention);
    printf("Converstion reussi!");

}
/*ffmpeg -i video.avi -q:a 0 -map a audio.mp3*/
/*ffmpeg -i video.avi -vn -acodec libmp3lame -ab 192k*/
void extractionVideoEnMp3(char * nomFichier){
    char * fichierSansExtention =  retourneNomDeFichierSansExtention(nomFichier);

    char cmdFfmpeg[_SIZE_BUFFER_] ="ffmpeg -i \"";
    strcat(cmdFfmpeg, nomFichier );
    strcat(cmdFfmpeg, "\" -q:a 0 -map a \"");
    strcat(cmdFfmpeg, fichierSansExtention);
    strcat(cmdFfmpeg, ".mp3\"");
    printf("Conversion de %s en MP3 avec la command:  %s\n", nomFichier, cmdFfmpeg );
    system(cmdFfmpeg);
    free(fichierSansExtention);
    printf("Converstion reussi!");
}

char * retourneNomDeFichierSansExtention(char * nomFichier){
    char *  nomFichierSansExtention = NULL;

    nomFichierSansExtention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(nomFichierSansExtention == NULL)
    {
        printf("Erreure maloc ficSansExtention!!!!!");
        exit(EXIT_SUCCESS);
    }

    for(int i =0, x = 0; i< strlen(nomFichier); i++){
        if(nomFichier[i] == '.')
        {
          
            break;
            
        }
      
  
     nomFichierSansExtention[x++] = nomFichier[i];
     nomFichierSansExtention[x] = '\0';
    }
   
   

   
return nomFichierSansExtention;
}


char * returneExtension(char * nomfichier){
    char * extention = NULL;

    extention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(extention == NULL)
    {
        printf("Erreure maloc extension!!!");
        exit(EXIT_SUCCESS);

    }
    booleen apresLePiont = FAUX;

    for(int i = 0, x = 0; i < strlen(nomfichier); i++){
            if(nomfichier[i] == '.')
            {
                apresLePiont = VRAI;
            }
            

            if(apresLePiont == VRAI)
            {
                extention[x++] = nomfichier[i];
            }
                
            
            extention[x] = '\0';
            
    }

           

    
 return   extention;
}

void afficheManuel(){
    clearScreen();
    printf("\n\t MANULEL de la commande bash \'mp3\'.\n\n");
    printf("Cette outil est concu pour faciliter l'utilisation de le commade ffmepg et convertire des musiques en MP3 ou extraire l'audio en MP3\n\n");
    printf("!!A ajouter le chemin vers l'executuble \"mp3.exe\" au variable d'environement Systeme PATH!!\n\n");
    printf("Exemple :\n\t\"mp3 [Chemin vers le fichier a convertir]\"\n Mode debug:\n\tmp3 [Chemin vers le fichier a convertir] -debug \n\n");
    
    printf("Commande console devlopper par Y.Pichat\n");

   
   


}
void clearScreen(){
    system("cls");
}


booleen returnsiVraiVideaoSinonMusique(char * nomFichier){
    booleen videoSinoMusic = FAUX;
    
        char * extention =  returneExtension(nomFichier);

       

    if(strcmp(extention, ".mp4") == 0 ){
        videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".avi") == 0 ){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".mkv") == 0 ){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".mov")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".webm")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".flv")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".mpg") == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".mpeg")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".wmv")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".3gp")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".ogv")  == 0){
videoSinoMusic = VRAI;
} else if(strcmp(extention, ".ts")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".m2ts")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".asf")  == 0){
videoSinoMusic = VRAI;
}
else if(strcmp(extention, ".m4v")  == 0){
videoSinoMusic = VRAI;
}
else{
videoSinoMusic = FAUX;
}

free(extention);


return videoSinoMusic;
}