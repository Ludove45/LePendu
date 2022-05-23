//
//  lib.c
//  LePendu
//
//  Created by Ismaël Bresson on 23/05/2022.
//

#include "lib.h"

bool letter_in_word(char* word,char letter) // la lettre est elle dans le mots
{
    int length = strlen(word);
    for(int i=0;i<length;i++)
    {
        if(word[i]== letter)
            return true;
    }
    return false;
}

void letter_replace0 (char* word,char letter,char* board) // remplacé le tiret
{
    int length = strlen(word);
    for(int i=0;i<length;i++)
    {
        if(word[i] == letter)
            board[i] = letter;
    }
}
bool word_complet (char* board) // verifié si l'on a gagnié
{
    int length = strlen(board);
    for(int i=0;i<length;i++)
        if (board[i]== '_')
            return false;
    return true;
}

void printall (char* board, char* list,int try,int tryA) //desinné l'interface
{
    printf("pas de : %s \n",list);
    printf("il vous reste : %d tentative \n",tryA - try);
    printf("%s \n\n",board);
    
}

void printResult (bool win) //anoncé les resulta
{
    if (win)
        printf("vous avez gagner !!");
    else
        printf("vous avez perdu !!");
}

void config (char *word,int *tryA) //configuration de la partie
{
    printf("\nvotre mot : ");
    scanf(" %s",word);
    printf ("nombre d'essai : ");
    scanf("%d",tryA);
    
}
