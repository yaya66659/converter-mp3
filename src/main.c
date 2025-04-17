#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"headers/fct.h"
int main(int argc, char *argv[])
{
        
        booleen debug = FAUX;
      
       
if(argv[1]){
        if(argv[2])
        {
            if(strcmp(argv[2], "-debug") == 0){
                printf("Mode debug activer \n\n");
                debug = VRAI;
            }   
            
            
            
         
        
        }
        

                if(debug == VRAI)
                {

                    char  * sansExtension = retourneNomDeFichierSansExtention(argv[1]) ;
            char *  extention = returneExtension(argv[1]);
                    
            clearScreen();
            printf("\nConverter Mp3 Mode debug  par Y.Pichat\n\n");

                    printf("videoSinoMusic : %d\n", returnsiVraiVideaoSinonMusique(argv[1]));
                    printf("pour %s , extention du nom de fichier : %s\n nom du fichier sans extention : %s\n",argv[1], extention, sansExtension);

                    free(sansExtension);
                    free(extention);
                }
                else
                {           
                    
            clearScreen();
            printf("\nConverter Mp3\n devlopper par Y.Pichat\n\n");

                    if(returnsiVraiVideaoSinonMusique(argv[1]) == VRAI)
                    {
                        extractionVideoEnMp3(argv[1]);
                    }
                    else
                    {
                        commandeAudioEnMp3(argv[1]);
                    }
                }        
               
            
 
            }
            else
            {
                afficheManuel();
            }

          printf("Saisir ENTER pour quitter!\n");
           getchar();

return 0;
}