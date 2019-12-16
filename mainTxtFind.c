#include <stdio.h>
#include "txtfind.h"
#define WORD 30

int main(){

    char str [WORD];
    getWord(str);
    char ch;
    scanf(" %c",&ch);

    if(ch == 'a'){
    print_lines(str);
    }

    if(ch == 'b'){
    print_similar_words(str);
    }
}
