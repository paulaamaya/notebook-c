#include <stdio.h>

void squeeze(char s[], char c);

main(){
    char input[30], c;

    printf("Enter a string with no spaces and a character you wish to remove: ");
    scanf("%s %c", &input, &c);

    squeeze(input, c);

    printf("The result is: \"%s\"\n", input);

}

void squeeze(char s[], char c){
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if(s[i] != c)
            s[j++] = s[i];

    s[j] = '\0';
}