#include <stdio.h>
#include <math.h>

int maxMemory(int bits);

main(){
    int inputBits;

    printf("How many bits of storage do you have? ");
    scanf("%d", &inputBits);

    printf("The maximum unsigned integer you can store is %d", maxMemory(inputBits));
}

int maxMemory(int bits){
    int sum = 0;

    for (int i = 0; i < bits; i++)
        sum += pow(2, i);

    return sum;

}