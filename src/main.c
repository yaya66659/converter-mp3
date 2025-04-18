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
        
                printf("Mode Compression de video activer \n\n");
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
                    printf("\nCommande mp3 Mode debug  par Y.Pichat\n\n");

                    printf("videoSinoMusic : %d\n", returnsiVraiVideaoSinonMusique(argv[1]));

                   if(compression == VRAI)
                   {
                    printf("Mode compression de argv[1] = %s car argv[2] = %s et mopde debug car argv[3] = %s\n", argv[1],  argv[2], argv[3]);
                   }                      
                   else{
                        printf("Mode Compression non activer. pour activer argument [-c]"); 
                   }

                    printf("pour %s , extention du nom de fichier : %s\n nom du fichier sans extention : %s\n",argv[1], extention, sansExtension);
                    
                    free(sansExtension);
                    free(extention);
                    pause();
                }
                else if(compression == VRAI){
                            
                    clearScreen();

                    printf("\nCommande mp3\n Mode Compression Video devlopper par Y.Pichat\n\n");
                    if(returnsiVraiVideaoSinonMusique(argv[1]) == VRAI){
                        compressionVideo(argv[1]);
                    }
                    else if (returnsiVraiVideaoSinonMusique(argv[1]) == FAUX){
                        char * extension = returneExtension(argv[1]);

                        printf("!!Erreure le format de %s n'est pas pris en charge ou n'est pas une video (%s) !!", argv[1], extension);
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
                    printf("\nCommande mp3\n devlopper par Y.Pichat\n\n");

                    if(returnsiVraiVideaoSinonMusique(argv[1]) == VRAI)
                    {
                        extractionVideoEnMp3(argv[1]);
                    }
                    else
                    {
                        char * extension = returneExtension(argv[1]);
                        if(strcmp(extension, ".mp3") == 0)
                        {
                            printf("!!Erreure le format de %s est deja en mp3 (%s) !!", argv[1], extension);
                            free(extension);
                           pause();               
    
                            afficheManuel();
                            afficheLICENSE();
                            clearScreen();
                            exit(EXIT_FAILURE);
    
                        }
                        else{
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