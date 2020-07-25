#include<stdio.h>
#include<stdlib.h>

int main(){
    int data[10];
    for(int k=0; k<10; k++){
        scanf("%d", &data[k]);
    }
    // find first
    int first = 0;
    for(int i=1; i<10; i++){
        if(data[i]!= 0){
            first = i;
            (data[i])--;
            break;
        }
    }
    printf("%d",first);
    int n;
    for(int j=0; j<10; j++){
        if(data[j]!=0){
            n = data[j];
            for(int h=0; h<n; h++){
                printf("%d", j);
            }
        }
    }
    return 0;
}