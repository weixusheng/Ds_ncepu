#include<stdio.h>
#include<stdlib.h>

/*20分*/

int cmp(const void *a, const void *b){
    int* m = (int*)a;
    int* n = (int*)b;
    return *m-*n;
}

int main(int argc, const char** argv) {
    int data[100000];
    int N,p;
    scanf("%d %d", &N, &p);
    for(int i=0; i<N; i++){
        scanf("%d", &data[i]);
    }
    qsort(data, N, sizeof(int), cmp);
    int max_count = 0;
    /*
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(data[j] <= 1L*p*data[i]){
                if(max_count < (j-i+1)){
                    max_count = (j-i+1);
                }
            }
        }
    }
    */
    for(int first=0,last=0; last<N && max_count< N-first; first++){
        while(last<N && data[last] <= 1L*data[first]*p){
            last++;
        }
        if(max_count< last-first){
            max_count = last-first;
        }
    }
    printf("%d", max_count);
    return 0;
}