#include<stdio.h>

int main(int argc, const char** argv) {
    int hashdata[100000] = {0};
    int num;
    scanf("%d",&num);
    int temp;
    for(int i=0; i<num; i++){
        scanf("%d",&temp);
        hashdata[temp]++;
    }
    int query;
    scanf("%d", &query);
    for(int j=0; j<query; j++){
        scanf("%d", &temp);
        if(j != query-1){
            printf("%d ", hashdata[temp]);
        }
        else{
            printf("%d", hashdata[temp]);
        }
    }
    return 0;
}