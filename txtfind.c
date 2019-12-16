#include <stdio.h>
#include "txtfind.h"
#include <string.h>
#define LINE 256
#define WORD 30

//The function gets a string and saves it. The function returns the number of characters per line.
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

//The function gets a string and saves it. The function returns the number of characters in the word.
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

//The function gets two strings and checks if the second string is contained in the first one.
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

//The function gets two strings and a n number. The function will check if the second string is equals to the first string,less the number of characters we have received in n.
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
//The function gets a string, captures the lines of text, and prints the lines in which the desired word appears.

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

//The function gets a string for searching, captures the text words and prints the words similar to the string.

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


