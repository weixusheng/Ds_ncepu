#include<stdio.h>
#include<stdlib.h>

char ** buildArray(int* target, int targetSize, int n){
    int res_len = target[targetSize-1]+(target[targetSize-1]-targetSize);
    char** res = (char**)malloc(sizeof(char*)*res_len);
    for(int j=0; j<res_len; j++){
        res[j] = (char*)malloc(sizeof(char)*5);
    }
    int count = 0;
    int step1 = 0;
    int step2 = 0;
    for(int i=0; i<res_len; i++){
        int temp = target[i];
        if(target[step1] != step2+1){
            res[count] = "Push";
            res[++count] = "Pop";
            ++count;
            step2++;
            printf("%d", count);
        }
        else{
            res[count] = "Push";
            ++count;
            step1++;
            step2++;
            printf("%d", count);
        }
    }
    return res;
}

int main(){
    int target[] = {1,3};
    char** result = buildArray(target,2,3);
    printf("hello");
    return 0;
}