#include <stdio.h>

void squeeze(char s1[], char s2[]);
int isCharInString(char c, char s[]);

main(){

    char s1[30], s2[30];
    
    printf("Enter two strings separated by a space: ");
    scanf("%s %s", &s1, &s2);

    squeeze(s1, s2);

    printf("The result is: \"%s\"\n", s1);

}

void squeeze(char s1[], char s2[]){
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
        if(!isCharInString(s1[i], s2))
            s1[j++] = s1[i];
    
    s1[j] = '\0';
}

int isCharInString(char c, char s[]){

    for (int i = 0; s[i] != '\0'; i++)
        if(s[i] == c)
            return 1;
    return 0;
}