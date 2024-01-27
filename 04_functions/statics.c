#include <stdio.h>

void print_int(int num) {
    static int counter = 0;
    printf("Printing....%d\n", num);
    counter++;
    printf("For the %dth time.\n", counter);
}

int main(){
    for (int i = 0; i < 10; i++)
    {
        print_int(5);
    }
}