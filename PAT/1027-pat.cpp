#include<stdio.h>
#include<stdlib.h>


int main(){
    int s;
    char signal;
    scanf("%d %c", &s, &signal);
    int sum = s;
    s = (s+1)/2;
    int minus;
    int shit = 0;
    int left = 0;
    int count = 0;
    minus = 1;
    for(int i=1; s >= minus; i++){
        s = s-minus;
        minus = 2*i +1;
        count++;
    }
    left = 2*s;
    int k;
    int w;
    int j;
    for(k=0; k < count; k++){
        for(j=0; j< k; j++){
            printf(" ");
        }
        for(w=0; w<((count-k)*2-1); w++){
            printf("%c",signal);
            shit++;
        }
        printf("\n");
    }
    for(k=count-2; k>=0; k--){
        for(j=k; j>0; j--){
            printf(" ");
        }
        for(w=((count-k)*2-1); w>0; w--){
            printf("%c",signal);
            shit++;
        }
        printf("\n");
    }
    /*
    if(left != 0){
        printf("%d", left);
    }
    */
    printf("%d", sum-shit);
    return 0;
}


/*
#include <stdio.h>

#define ABS(X) ((X) >= 0 ? (X) : -(X))

int main()
{
    char c;
    int N, M;
    scanf("%d %c", &N, &c);

    for(M = 1; 2 * M * M - 1 <= N; M++) ;
    M--;   

    for(int i = 0; i < 2 * M - 1; i ++)
    {
        for(int j = 0; j < M - 1 - ABS(M - 1 - i); j++)
            putchar(' ');
        for(int j = 0; j < 2 * ABS(M - 1 - i) + 1; j++)
            putchar(c);
        putchar('\n');
    }
    printf("%d", N - 2 * M * M + 1);

    return 0;
}
*/