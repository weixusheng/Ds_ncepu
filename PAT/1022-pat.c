#include<stdio.h>
#include<stdlib.h>

/*
int main(){
    long int a,b,c;
    int res[100000];
    int i = 0;
    int d;
    scanf("%ld %ld %d", &a, &b ,&d);
    c = a+b;
    int temp;
    while(c > d){
        temp = c%d;
        c = c/d;
        res[i] = temp;
        i++;
    }
    res[i] = c;
    for(int k=i; k>=0; k--){
        printf("%d", res[k]);
    }
    return 0;
}
*/

int main()
{
    int A, B, D, Sum;
    scanf("%d %d %d", &A, &B, &D);
    Sum = A + B;

    /* calculate the bits of Sum */
    int power = 1;
    /* use Sum / D >= power to avoid using long int */
    while(Sum / D >= power) power *= D;

    /* calculate D-base number. print them on-the-fly */
    for(; power > 0; Sum %= power, power /= D)
        printf("%d", Sum / power);

    return 0;
}