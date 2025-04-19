#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/fct.h"
int main(int argc, char *argv[])
{
        
        booleen debug = FAUX;
        booleen compression = FAUX;
      
       
if(argv[1]){
        if(argv[2])
        {
            if(strcmp(argv[2], "-debug") == 0){
                printf("Mode debug activer \n\n");
                debug = VRAI;
            }   
            else if(strcmp(argv[2], "-c") == 0){
        
                printf("Mode Compression de video ou audio activer \n\n");
                compression = VRAI;
                if(argv[3]){
                    if(strcmp(argv[3], "-debug" ) == 0){
                        printf("Mode debug activer \n\n");
                        debug = VRAI;
                    }
                    else{
                        afficheManuel();
                    }
                }

            }
           
            
            
         
        
        }
        
        

                if(debug == VRAI)
                {

                    char  * sansExtension = retourneNomDeFichierSansExtention(argv[1]) ;
                    char *  extention = returneExtension(argv[1]);
                            
                    clearScreen();
                    printf("\n\tCommande mp3 Mode debug  par Y.Pichat\n\n");

                    printf("videoSinoMusic : %d\n", returnVideaoMusiqueOuIncorrectFormat(argv[1]));

                   if(compression == VRAI)
                   {
                    printf("Mode compression de argv[1] = %s car argv[2] = %s et mopde debug car argv[3] = %s\n", argv[1],  argv[2], argv[3]);
                   }                      
                   else{
                        printf("Mode Compression non activer. pour activer argument [-c]\n"); 
                   }

                    printf("pour %s , extension du nom de fichier : %s\n nom du fichier sans extension : %s\n",argv[1], extention, sansExtension);
                    
                    free(sansExtension);
                    free(extention);
                    pause();
                }
                else if(compression == VRAI){
                            
                    clearScreen();

                    
                    if(returnVideaoMusiqueOuIncorrectFormat(argv[1]) == VIDEO){
                        printf("\n\tCommande mp3\n Mode Compression Video developpe par Y.Pichat\n\n");
                        compressionVideo(argv[1]);
                    }
                    else if(returnVideaoMusiqueOuIncorrectFormat(argv[1]) == AUDIO){
                        char *  extension = returneExtension(argv[1]);

                        printf("\n\tCommande mp3\n Mode Compression Audio devlopper par Y.Pichat\n\n");
                        if(strcmp(extension, ".wav") == 0 || strcmp(extension, ".WAV") == 0)
                        {
                            free(extension);
                            printf("AVERTISSEMENT : Votre fichier a une extension .wav une compression bon compromis qualite/taille sera aplliquee en gardant le format WAVE.\n");
                            compressionAudioWave(argv[1]);
                            
                            

                        }
                        else
                        {
                           
                            printf("AVERTISSEMENT : Votre fichier a une extension  autre que .wave (%s) une conversion en .mp3 sera appliquer!\n", extension);
                        
                            free(extension);
                            

                            commandeAudioEnMp3(argv[1]);
                        }
                       
                        
                      

                    }
                    else if (returnVideaoMusiqueOuIncorrectFormat(argv[1]) == FORMAT_INCORRECT){
                        char * extension = returneExtension(argv[1]);
                        printf("\n\tCommande mp3\n Mode Compression Video ou Audio developpe par Y.Pichat\n\n");
                        printf("!!Erreur le format de \"%s\" n'est pas pris en charge (%s) !!\n", argv[1], extension);
                        free(extension);
                       pause();               

                        afficheManuel();
                        afficheLICENSE();
                        clearScreen();
                        exit(EXIT_FAILURE);

                    }
                }
                else
                {           
                    
                    clearScreen();
                    printf("\n\tCommande mp3\n developpe par Y.Pichat\n\n");

                    if(returnVideaoMusiqueOuIncorrectFormat(argv[1]) == VIDEO)
                    {
                        printf("\n\tCommande mp3\n Mode Extraction Audio en mp3 de la video \"%s\" developpe par Y.Pichat\n\n", argv[1]);
                        extractionVideoEnMp3(argv[1]);
                    }
                    else if (returnVideaoMusiqueOuIncorrectFormat(argv[1]) == AUDIO)
                    {
                        char * extension = returneExtension(argv[1]);
                        if(strcmp(extension, ".mp3") == 0)
                        {
                            printf("!!Erreur le format de \"%s\" est deja en mp3 (%s) !!\n", argv[1], extension);
                            free(extension);
                           pause();               
    
                            afficheManuel();
                            afficheLICENSE();
                            clearScreen();
                            exit(EXIT_FAILURE);
    
                        }
                        else{
                            printf("\n\tCommande mp3\n Mode Conversion Audio en mp3 devlopper par Y.Pichat\n\n");
                            commandeAudioEnMp3(argv[1]);
                        }
                        
                    }
                }        
               
            
 
            }
            else
            {
                afficheManuel();
               
            }

            afficheLICENSE();
            clearScreen();
           
           




return 0;
}