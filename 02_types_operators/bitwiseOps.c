#include <stdio.h>

unsigned getBits(unsigned x, int p, int n);
unsigned setBits(unsigned x, int p, int n, unsigned y);
unsigned invert(unsigned x, int p, int n);
unsigned rightRot(unsigned x, int n);

int main(){

    // 47 == 101111 => |101|111 => 101 == 5
    unsigned x = 47;
    int p = 5;
    int n = 3;
    printf("%d\n", getBits(x, p, n));

    return 0;
}

unsigned getBits(unsigned x, int p, int n){
    // shift bits right by p - n + 1
    // mask with something that will cancel out the stuff after p
    return x >> (p - n + 1) & ~(~0 << n);
}