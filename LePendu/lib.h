//
//  lib.h
//  LePendu
//
//  Created by Ismaël Bresson on 23/05/2022.
//

#ifndef lib_h
#define lib_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool letter_in_word(char*,char);
void letter_replace0 (char*,char,char*);
bool word_complet (char*);
void printall (char*, char*,int,int);
void printResult (bool);
void config (char*,int*);

#endif /* lib_h */
