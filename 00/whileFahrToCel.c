#include <stdio.h>

main(){
    // variable declarations
    float fahr, celsius;
    int lower, upper, step;

    //assignment statements
    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    printf("Fahrenheit\tCelsius");
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.2f\n", fahr, celsius);
        fahr = fahr + step;
    }
}