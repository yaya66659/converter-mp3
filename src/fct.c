#include <stdio.h>
#include <stdlib.h>
#include<string.h>


#include "headers/fct.h"

/*ffmpeg -i video.avi -q:a 0 -map a audio.mp3*/
/*ffmpeg -i video.avi -vn -acodec libmp3lame -ab 192k*/
/*ffmpeg -i video.mp4 -vcodec libx264 -crf 28 -preset slow -acodec aac video.mp4*/
/*ffmpeg -i input.ext -ac 1 -ar 22050 -b:a 64k output.mp3*/
/*ffmpeg -i input.mp3 -ac 2 -ar 44100 -b:a 128k output_clean.mp3*/
/*ffmpeg -i input.wav -c:a adpcm_ima_wav output_compressed.wav*/

void commandeAudioEnMp3(char*  NomDuFichierAConvertir){

    char * fichierSansExtention =  retourneNomDeFichierSansExtention(NomDuFichierAConvertir);
    char cmdFfmpeg[_SIZE_BUFFER_] ="ffmpeg -i \"";

    strcat(cmdFfmpeg, NomDuFichierAConvertir );
    strcat(cmdFfmpeg, "\" \"");
    strcat(cmdFfmpeg, fichierSansExtention);
    strcat(cmdFfmpeg, ".mp3\"");

    printf("Conversion de %s en MP3 avec la commande:  %s\n", NomDuFichierAConvertir, cmdFfmpeg );

    pause();

    system(cmdFfmpeg);

    free(fichierSansExtention);

    clearScreen();
    printf("Conversion de %s en MP3 avec la commande:  %s\n", NomDuFichierAConvertir, cmdFfmpeg );
    printf("Conversion reussi!\n");

    pause();

}

void extractionVideoEnMp3(char * nomFichier){
    char * fichierSansExtention =  retourneNomDeFichierSansExtention(nomFichier);

    char cmdFfmpeg[_SIZE_BUFFER_] ="ffmpeg -i \"";

    strcat(cmdFfmpeg, nomFichier );
    strcat(cmdFfmpeg, "\" -q:a 0 -map a \"");
    strcat(cmdFfmpeg, fichierSansExtention);
    strcat(cmdFfmpeg, ".mp3\"");

    printf("Conversion de \"%s\" en MP3 avec la commande:  [%s]\n vers > \"%s.mp3\"", nomFichier, cmdFfmpeg, fichierSansExtention );

    pause();

    system(cmdFfmpeg);

  
    clearScreen();
    printf("!!SUCESSE!! Conversion de \"%s\" en MP3 avec la commande:  [%s]\n vers > \"%s.mp3\" FINI!",nomFichier, cmdFfmpeg, fichierSansExtention);
    free(fichierSansExtention);

    pause();

}

void compressionAudioWave(char * nomFichier){
    char * nomFichierSansExtention = retourneNomDeFichierSansExtention(nomFichier);

    char cmdFfmpegCopressionAudio[_SIZE_BUFFER_] ="ffmpeg -i \"";
    strcat(cmdFfmpegCopressionAudio, nomFichier);
    strcat(cmdFfmpegCopressionAudio, "\" -c:a adpcm_ima_wav \"");
    strcat(cmdFfmpegCopressionAudio, nomFichierSansExtention);
    strcat(cmdFfmpegCopressionAudio, "_Compresse.wav\"");
    
    printf("\nCompression de \"%s\" en WAVE avec la commande:  [%s]\n vers > \"%s_Compresse.wav\"\n", nomFichier, cmdFfmpegCopressionAudio, nomFichierSansExtention);
    pause();

    system(cmdFfmpegCopressionAudio);
   
    clearScreen();
    printf("!!SUCESSE!! Compression de \"%s\" en gardant le format WAVE avec la commande:  [%s]\n vers > \"%s_Compresse.wav\" FINI!",nomFichier, cmdFfmpegCopressionAudio, nomFichierSansExtention);
    free(nomFichierSansExtention);

    pause();


}

void compressionVideo(char * nomFichier){

    char * nomFichierSansExtension = retourneNomDeFichierSansExtention(nomFichier);
    char cmdFfmpegCompressionVideo[_SIZE_BUFFER_] = "ffmpeg -i \"";

    strcat(cmdFfmpegCompressionVideo, nomFichier);
    strcat(cmdFfmpegCompressionVideo, "\" -vcodec libx264 -crf 28 -preset slow -acodec aac \"");
    strcat(cmdFfmpegCompressionVideo, nomFichierSansExtension);
    strcat(cmdFfmpegCompressionVideo, "_Compressee.mp4\"");

    printf("Compression de : \"%s\" avec la commande [%s]\n Vers > \"%sCompressee.mp4\"", nomFichier, cmdFfmpegCompressionVideo, nomFichierSansExtension);
    pause();

   system(cmdFfmpegCompressionVideo);

   clearScreen();
   printf("!!SUCESSE!! Compression de : %s avec la commande %s\n Vers > %s_Compressee.mp4\n!!FINI!!", nomFichier, cmdFfmpegCompressionVideo, nomFichierSansExtension);

   free(nomFichierSansExtension);

   pause();
   

}
char * retourneNomDeFichierSansExtention(char * nomFichier){
    char *  nomFichierSansExtention = NULL;
    int posFinDeChaine = 0;

    nomFichierSansExtention = malloc((sizeof(char)*_SIZE_BUFFER_));
    if(nomFichierSansExtention == NULL)
    {
        printf("Erreur maloc ficSansExtension!!!!!");
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
        printf("Erreur maloc extension!!!");
        pause();
        clearScreen();
        exit(EXIT_FAILURE);

    }
 

    for(int i = 0, x = 0; i < strlen(nomfichier); i++){
            if(nomfichier[i] == '.')
            {
                               
                strcpy(extention, "");
                x=0;
            }
            

            
                if(i+1 < strlen(nomfichier) && nomfichier[i+1] == '.' )
                {
                    strcpy(extention, "");
                    x=0;
                    
                }
                else{
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

    printf("Ce programme utilise ffmpeg (https://ffmpeg.org), distribué sous licence LGPL/GPL.\n");
    printf("Consultez https://ffmpeg.org/legal.html pour plus d'informations sur la licence.\n\n");

    printf("Cette outil est concu pour faciliter l'utilisation de le commande ffmepg et convertir des musiques en MP3 ou extraire l'audio d'une video vers un MP3 ainsi que Compresser une video en ma_video_Compressee.mp4 ainsi que Compresser un Audio .wav ou .WAV en mon_audio_compresse.wav\n\n");

    printf("!!A ajouter le chemin vers l'executuble \"mp3.exe\" au variable d'environement Systeme PATH!!(mp3Setup.bat le fait automatiquement!)\n\n");

    printf("Exemple :\n\t\"mp3 [Chemin vers le fichier audio ou video a convertir en mp3]\"\nMode compression d'une video:\n\t\"mp3 [Chemin vers le fichier video ou audio WAVE a compresser ] -c\t -compresssee en .mp4 ou en .wav pour les audio.wav ou .WAV\"\n Mode debug:\n\tmp3 [Chemin vers le fichier audio ou video a convertir en mp3] -debug \nou :\n\t\"mp3 [Chemin vers le fichier video a compresser] -c -debug\"\n");
    
    printf("Commande console developpe par Y.Pichat\n");

    pause();

   
   


}
void clearScreen(){
    system("cls");
}


formatExtension returnVideaoMusiqueOuIncorrectFormat(char * nomFichier){
    formatExtension videoSinoMusic = FORMAT_INCORRECT;
    
        char * extention =  returneExtension(nomFichier);

       
    /*Test format VIDEO*/
        if(strcmp(extention, ".mp4") == 0 ){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".avi") == 0 ){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".mkv") == 0 ){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".mov")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".webm")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".flv")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".mpg") == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".mpeg")  == 0){
             videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".wmv")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".3gp")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".ogv")  == 0){
            videoSinoMusic = VIDEO;
        } else if(strcmp(extention, ".ts")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".m2ts")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".asf")  == 0){
            videoSinoMusic = VIDEO;
        }
        else if(strcmp(extention, ".m4v")  == 0){
            videoSinoMusic = VIDEO;
        }/*Test format AUDIO*/
        else if(strcmp(extention, ".mp3") == 0 ){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".wma") == 0 ){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".aac") == 0 ){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".wav") == 0 ){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".WAV") == 0 ){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".flac")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".ogg")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".opus")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".m4a") == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".dts")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".aiff")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".au")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".mp2")  == 0){
            videoSinoMusic = AUDIO;
        } else if(strcmp(extention, ".caf")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".voc")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".ra")  == 0){
            videoSinoMusic = AUDIO;
        }
        else if(strcmp(extention, ".snd")  == 0){
            videoSinoMusic = AUDIO;
        }/*Test sinon  faormat incorrecte*/
        else{
            videoSinoMusic = FORMAT_INCORRECT;
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

    printf("\tLicence\n\nCe projet est open-source, mais il est interdit de l'utiliser a des fins commerciales.\n\nVous etes libre de :\n\n\tl'utiliser,\n\tle modifier,\n\tle partager,\n\tl'etudier,\n\nTant que cela reste dans un cadre personnel, educatif ou non commercial.\n\nToute utilisation commerciale est INTERDITE!.\n\n");
    printf("Merci d'avoir utiliser l'outil en ligne de commade mp3 (simplification de ffmpeg)\n\n");

    printf("Ce programme utilise ffmpeg (https://ffmpeg.org), distribué sous licence LGPL/GPL.\n");
    printf("Consultez https://ffmpeg.org/legal.html pour plus d'informations sur la licence.\n\n");

    printf("\tYann Pichat - 2025\n\n");

    pause();
}