#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#include "headers/fct.h"

/*ffmpeg -i video.avi -q:a 0 -map a audio.mp3*/
/*ffmpeg -i video.avi -vn -acodec libmp3lame -ab 192k*/
/*ffmpeg -i video.mp4 -vcodec libx264 -crf 28 -preset slow -acodec aac video.mp4*/

void commandeAudioEnMp3(char*  NomDuFichierAConvertir){

    char * fichierSansExtention =  retourneNomDeFichierSansExtention(NomDuFichierAConvertir);
    char cmdFfmpeg[_SIZE_BUFFER_] ="ffmpeg -i \"";

    strcat(cmdFfmpeg, NomDuFichierAConvertir );
    strcat(cmdFfmpeg, "\" \"");
    strcat(cmdFfmpeg, fichierSansExtention);
    strcat(cmdFfmpeg, ".mp3\"");

    printf("Conversion de %s en MP3 avec la command:  %s\n", NomDuFichierAConvertir, cmdFfmpeg );

    pause();

    system(cmdFfmpeg);

    free(fichierSansExtention);

    clearScreen();
    printf("Conversion de %s en MP3 avec la command:  %s\n", NomDuFichierAConvertir, cmdFfmpeg );
    printf("Converstion reussi!\n");

    pause();

}

void extractionVideoEnMp3(char * nomFichier){
    char * fichierSansExtention =  retourneNomDeFichierSansExtention(nomFichier);

    char cmdFfmpeg[_SIZE_BUFFER_] ="ffmpeg -i \"";

    strcat(cmdFfmpeg, nomFichier );
    strcat(cmdFfmpeg, "\" -q:a 0 -map a \"");
    strcat(cmdFfmpeg, fichierSansExtention);
    strcat(cmdFfmpeg, ".mp3\"");

    printf("Conversion de \"%s\" en MP3 avec la command:  [%s]\n vers > \"%s.mp3\"", nomFichier, cmdFfmpeg, fichierSansExtention );

    pause();

    system(cmdFfmpeg);

  
    clearScreen();
    printf("!!SUCESSE!! Converstion de \"%s\" en MP3 avec la command:  [%s]\n vers > \"%s.mp3\" FINI!",nomFichier, cmdFfmpeg, fichierSansExtention);
    free(fichierSansExtention);

    pause();

}


void compressionVideo(char * nomFichier){

    char * nomFichierSansExtension = retourneNomDeFichierSansExtention(nomFichier);
    char cmdFfmpegCompressionVideo[_SIZE_BUFFER_] = "ffmpeg -i \"";

    strcat(cmdFfmpegCompressionVideo, nomFichier);
    strcat(cmdFfmpegCompressionVideo, "\" -vcodec libx264 -crf 28 -preset slow -acodec aac \"");
    strcat(cmdFfmpegCompressionVideo, nomFichierSansExtension);
    strcat(cmdFfmpegCompressionVideo, "_Compressee.mp4\"");

    printf("Compression de : \"%s\" avec la commmande [%s]\n Vers > \"%sCompressee.mp4\"", nomFichier, cmdFfmpegCompressionVideo, nomFichierSansExtension);
    pause();

   system(cmdFfmpegCompressionVideo);

   clearScreen();
   printf("!!SUCESSE!! Compression de : %s avec la commmande %s\n Vers > %s_Compressee.mp4\n!!FINI!!");

   free(nomFichierSansExtension);

   pause();
   

}
char * retourneNomDeFichierSansExtention(char * nomFichier){
    char *  nomFichierSansExtention = NULL;
    int posFinDeChaine = 0;

    nomFichierSansExtention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(nomFichierSansExtention == NULL)
    {
        printf("Erreure maloc ficSansExtention!!!!!");
        pause();
        clearScreen();
        exit(EXIT_FAILURE);
    }

    for(int i =0, x = 0; i< strlen(nomFichier); i++){
        if(nomFichier[i] == '.')
        {
          
            break;
            
        }
      
  
     nomFichierSansExtention[x++] = nomFichier[i];
     posFinDeChaine = x;
    
    }
   
    nomFichierSansExtention[posFinDeChaine] = '\0';

   
return nomFichierSansExtention;
}


char * returneExtension(char * nomfichier){
    char * extention = NULL;
    int posFinDeChaine = 0 ;

    extention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(extention == NULL)
    {
        printf("Erreure maloc extension!!!");
        pause();
        clearScreen();
        exit(EXIT_FAILURE);

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
                
            posFinDeChaine = x;
           
            
    }

    extention[posFinDeChaine] = '\0';

           

    
 return  extention;
}

void afficheManuel(){

    clearScreen();

    printf("\n\t MANUEL de la commande bash \'mp3\'.\n\n");

    printf("Cette outil est concu pour faciliter l'utilisation de le commade ffmepg et convertire des musiques en MP3 ou extraire l'audio d'une video vers un MP3 ainsi que Compresser une video ves ma_video_Compressee.mp4\n\n");

    printf("!!A ajouter le chemin vers l'executuble \"mp3.exe\" au variable d'environement Systeme PATH!!(mp3Setup.bat le fait automatiquement!)\n\n");

    printf("Exemple :\n\t\"mp3 [Chemin vers le fichier audio ou video a convertir en mp3]\"\nMode compression d'une video:\n\t\"mp3 [Chemin vers le fichier video a compresser] -c\"\n Mode debug:\n\tmp3 [Chemin vers le fichier audio ou video a convertir en mp3] -debug \nou :\n\t\"mp3 [Chemin vers le fichier video a compresser] -c -debug\"\n");
    
    printf("Commande console devlopper par Y.Pichat\n");

    pause();

   
   


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


void pause(){

    printf("\nSaisir ENTER pour continuer...\n");

    getchar();
}

void afficheLICENSE(){

    clearScreen();

    printf("\tLicence\n\nCe projet est open-source, mais il est interdit de l'utiliser a des fins commerciales.\n\nVous etes libre de :\n\n\tl'utiliser,\n\tle modifier,\n\tle partager,\n\tl'etudier,\n\nTant que cela reste dans un cadre personnel, educatif ou non commercial.\n\nPour toute utilisation commerciale, une autorisation ecrite de l'auteur est requise.\n\n");
    printf("Merci d'avoir utiliser l'outil en ligne de commade mp3 (simplification de ffmpeg)\n\n");
    printf("\tYann Pichat - 2025\n\n");

    pause();
}