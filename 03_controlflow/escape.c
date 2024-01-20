#include <stdio.h>

void escape(char s[], char t[]);

int main(){

    char s[30];
    char t[30] = "Name:\t Paula Amaya\nAge:\t22";

    s[0] = '\0';

    escape(s, t);
    printf("%s", s);

    return 0;
}

void escape(char s[], char t[]){
    int i, j;
    for (i = j = 0; i != '\0'; i++)
    {
        switch (s[i]){
        case '\t':
            s[i] = '';
            break; 
        case '\n': 
            s[i] = '';
            break;
        case '\b':
            s[i] = '';
            break;
        default:
            break;
        }
    }
}