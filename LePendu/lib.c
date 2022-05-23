//
//  lib.c
//  LePendu
//
//  Created by Ismaël Bresson on 23/05/2022.
//

#include "lib.h"

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

void letter_replace0 (char* word,char letter,char* board)
{
    int length = strlen(word);
    for(int i=0;i<length;i++)
    {
        if(word[i] == letter)
            board[i] = letter;
    }
}
