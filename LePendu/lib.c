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
    printf("\npas de : %s \n",list);
    printf("il vous reste : %d tentative \n",tryA - try);
    printf("%s \n\n",board);
    
}

void printResult (bool win,char* word) //anoncé les resulta
{
    if (win)
        printf("\nvous avez gagner !!\n");
    else
        printf("\nvous avez perdu !!\n");
    
    printf("le mots etais : %s\n\n",word);
}

void config (char *word,int *tryA,bool *rndp) //configuration de la partie
{
    char ans = 'n';
    printf("\nvoulez-vous de l'aleatoire ? (o/n)");
    scanf(" %c[o,n]",&ans);
    if (ans == 'o' )
    {
        *rndp = true;
    }
    else //if (ans == 'n')
    {
        printf("\nvotre mot : ");
        scanf(" %s",word);
        *rndp = false;
    }
    printf("\nnombre d'essaie : ");
    scanf("%d",tryA);
}

void rndWord (char* word) //generateur de mots aléatoire
{
    {
        int rng = rand()%30;
        FILE* dico = NULL;
        dico = fopen("dico.txt", "r");
        if (dico != NULL)
        {
            while (rng-- > 0)
            {
            fgets(word,MAX_WL,dico);
            word[strlen(word)-1] = '\0';//fgets lit aussi le retour a la ligne de fin donc on le retire
            for(int i=0;i<strlen(word);i++)
                word[i] = tolower(word[i]);
            }
            fclose(dico);
        }
        else
        {
        printf("\nprobleme avec le fichier dictionaire \n");
        }
    }
        return ;
}
