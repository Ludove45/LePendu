//
//  main.c
//  LePendu
//
//  Created by Ismaël Bresson on 22/05/2022.
//

#include "lib.h"
#include <unistd.h>

int main(int argc, char * argv[])
{
    //Sur MacOS, l'execution du programme dans le terminal tente d'ouvrir les fichiers dans HOME
    char * p = strrchr(argv[0],'/');
    if(p != NULL) //On trouve le dossier d'execution
    {
        *p = '\0';//on retire le nom de l'executable a la fin
        chdir(argv[0]);//L'ouverture des fichiers se fera dans le dossier d'exec
        /*char * buf = malloc(500*sizeof(char));
        getcwd(buf, 500);
        printf("%s\n",buf);
        free(buf);*/
    }
    
    srand(time(0));
    char word[MAX_WL] = "ats";
    int tryAllowed = 10;
    bool rnd = false;
    config(word, &tryAllowed, &rnd);
    
    while (1)
    {
        if (rnd)
            rndWord(word);
        
        int try = 0;
        char userLetter = 0;
        char usedLetters[tryAllowed];
        memset(usedLetters, 0,tryAllowed * sizeof(char));//initialisation de la memoire
        char drawnWord[strlen(word)];
        memset(drawnWord,'_',strlen(word));//initialisation par les tiret
    
        printall(drawnWord, usedLetters, try, tryAllowed);
        
    do
    {
        // saisi utilisateur
        printf("votre lettre :");
        scanf(" %c",&userLetter);
        userLetter = tolower(userLetter); // pour pouvoire joué en majusucule
        
        if (letter_in_word(word,userLetter))
            letter_replace0 (word,userLetter,drawnWord);
        else
            if (!letter_in_word(usedLetters, userLetter))
        {
            usedLetters[try] = userLetter;
            try++;
        }
        
        if (userLetter == '#')// recomancé la partie
        {
            config(word, &tryAllowed, &rnd);
            break;
        }
        
        printall(drawnWord, usedLetters, try, tryAllowed);
        
        if (word_complet(drawnWord))
            break;
    }
    while (try<tryAllowed);
    
    printResult(word_complet(drawnWord),word);
 
}
    printf("\n");
    return 0;
}
