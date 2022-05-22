//
//  main.c
//  LePendu
//
//  Created by Ismaël Bresson on 22/05/2022.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool letter_in_word(char* word,char letter)
{
    int length = strlen(word);
    for(int i=0;i<length;i++)
    {
        if(word[i]== letter)
            return true;
    }
    return false;
}

int main()
{
    char* word = "pendu";
    int try = 0;
    char userLetter = 0;
    
    do
    {
        // saisi utilisateur
        printf("votre lettre :");
        scanf(" %c",&userLetter);
        
        if (letter_in_word(word,userLetter))
            printf("ok");
        
    }
    while (try>10);
    
    
    printf("\n");
    return 0;
}
