//
//  main.c
//  LePendu
//
//  Created by Ismaël Bresson on 22/05/2022.
//

#include "lib.h"

int main()
{
    char* word = "pendu";
    int try = 0;
    int tryAllowed = 10;
    char userLetter = 0;
    char usedLetters[tryAllowed];
    memset(usedLetters, 0,tryAllowed * sizeof(char));//initialisation de la memoire
    char drawnWord[strlen(word)];
    memset(drawnWord,'_',strlen(word));//initialisation par les tiret
    
    do
    {
        // saisi utilisateur
        printf("votre lettre :");
        scanf(" %c",&userLetter);
         
        
        if (letter_in_word(word,userLetter))
            letter_replace0 (word,userLetter,drawnWord);
        else
            if (!letter_in_word(usedLetters, userLetter))
        {
            usedLetters[try] = userLetter;
            try++;
        }
        printf("%s \n",usedLetters);
        printf("%s \n\n",drawnWord);
        
    }
    while (try<10);
    
    
    printf("\n");
    return 0;
}
