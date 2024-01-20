#include <stdio.h>

enum day {MON = 1, TUE, WED, THU, FRI, SAT, SUN};

int main(){
    enum day launch_date = MON;
    printf("%d", launch_date);
}