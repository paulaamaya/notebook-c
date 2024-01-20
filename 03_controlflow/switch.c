#include <stdio.h>

int main(){
    int a = 10;

    switch (a)
    {
        case 0: case 2: case 14:
            printf("Not a valid id.");
            break;
        case 1: case 3: case 4:
            printf("You do not have clearance.");
            break;
        default:
            printf("Access granted.");
            break;
    }
    return 0;
}