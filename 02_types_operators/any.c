#include <stdio.h>

int any(char s1[], char s2[]);
int isCharInString(char c, char s[]);

int main(){
    char s1[30], s2[30];
    
    printf("Enter two strings separated by a space: ");
    scanf("%s %s", &s1, &s2);

    printf("The first location where S1 contains a char from S2 is: %d\n", any(s1, s2));
}

int any(char s1[], char s2[]){
    for (int i = 0; s1[i] != '\0'; i++)
        if(isCharInString(s1[i], s2))
            return i;
    return -1;
}


int isCharInString(char c, char s[]){

    for (int i = 0; s[i] != '\0'; i++)
        if(s[i] == c)
            return 1;
    return 0;
}