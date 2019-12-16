#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#define LINE 256
#define WORD 30

int getLine(char s[]){
    int count = 0;
    char ch = getchar();
    s[0]=ch;
    while(ch!='\n' && ch!= EOF){
        count++;
        ch = getchar();
        s[count] = ch;
    }
    s[count] = '\0';
    if(ch == EOF) return EOF;
    else return count;
}

int getWord(char w[]){
    int count = 0;
    char ch = getchar();
    w[0]=ch;
    while(ch!=' ' && ch!='\t' && ch!='\n' && ch!= EOF){
        count++;
        ch = getchar();
        w[count] = ch;
    }
    w[count] = '\0';
    if(ch == EOF) return EOF;
    return count;
}

int subString(char *str1, char *str2){

    int counter = 0;
    int i=0,j=0;
    while(str1[i] != '\0' && str2[j] != '\0'){

        if(str1[i] == str2[j]){
            j++;
            i++;
            counter++;
        }
        else{
            i++;
            j=0;
            counter=0;
        }
    }
    if(counter == 0) return 0;

    else return 1;     
}

int similar(char *s, char *t, int n){

    int i=0,j=0;
    while(s[i] != '\0' || t[j] != '\0' ){

        if(s[i] == t[j]){
            j++;
            i++;
        }
        else{
            i++;
            n--;
        }
    }
    if(n == 0) return 1;
    
    else return 0;
}

void print_lines(char *str){

    char line [LINE];
    int length=0;
    while(length!=EOF){
        length = getLine(line);
 
        if(subString(line,str)){
        printf("%s \n",line);
        }
    }
}
void print_similar_words(char *str){

    char word [WORD];
    int length=0;

    while(length!=EOF){
        length = getWord(word);
 
        if(similar(word,str,1))
        printf("%s \n", word);

        if(similar(word,str,0))
        printf("%s \n", word);
        
    }
    
}


