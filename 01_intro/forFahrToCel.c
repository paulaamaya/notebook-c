#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20  

main(){
    float fahr;

    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%3.0f\t%6.2f\n", fahr, (5.0/9.0) * (fahr - 32));
    }
}