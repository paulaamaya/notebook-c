#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

main(){
    printf("Range of signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of unsigned int: 0 to %u\n", UINT_MAX);

    printf("Range of signed short int: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of unsigned short int: 0 to %u\n", USHRT_MAX);

    printf("Range of signed long int: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of unsigned long int: 0 to %lu\n", ULONG_MAX);

    printf("Range of signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range of unsigned char: 0 to %u\n", UCHAR_MAX);

}