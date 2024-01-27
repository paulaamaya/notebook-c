#include <stdio.h>

int max(int a, int b){
    int result;

    result = (a > b) ? a : b;
}

int main(){
    int a, b;
    printf("Enter two integers separated by a space: ");
    scanf("%d %d", &a, &b);
    printf("The larger number is %d\n", max(a,b));
}