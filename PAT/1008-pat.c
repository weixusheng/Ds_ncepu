#include<stdlib.h>
#include<stdio.h>

int cmp_int(const void* a , const void* b)
{
    return ( *(int*)a - *(int*)b );
}

int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    int data[N];
    M = M%N;
    for(int i = 0; i< N; i++){
        scanf("%d", &data[i]);
    }
    int a = N-M;
    int temp;
    for(int i=0; i<M; i++){
        temp = data[i];
        data[i] = data[a];
        data[a] = temp;
        a++;
    }
    qsort(&data[M], N-M, sizeof(int),cmp_int);
    for(int k = 0; k< N; k++){
        printf("%d", data[k]);
    }
}

/*
int main(){
    int N,M;
    scanf("%d %d", &N, &M);
    int data[300];
    M = M%N;
    for(int i = 0; i< N; i++){
        scanf("%d", &data[i]);
    }
    int a = N;
    int b = N-M;
    for(int j=0; j<b; j++){
        data[a] = data[j];
        a++;
    }
    for(int k=0; k< N; k++){
        if(k != 0){
            printf(" ");
        }
        printf("%d", data[b]);
        b++;
    }
    return 0;
}
*/
