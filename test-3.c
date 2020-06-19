#include<stdio.h>
#include<stdlib.h>

int* dailyTemperatures(int* T, int TSize){
    int i = TSize;
    //*returnSize = TSize;
    int count;
    int* res_array = (int*)malloc(i* sizeof(int)); //init return_list
    int* stack = (int*)malloc(sizeof(int)*i);
    int top = -1;
    while(i>-1){
        if(top == -1){
            stack[++top] = T[i];
            //printf("T[i]:%d",T[i]);
            res_array[i--] = 0;
        }
        else{
            count = 0;
            while(top>-1 && stack[top] < T[i]){
                //printf("T[i]:%d",T[i]);
                //printf("stack[top]:%d",stack[top]);
                --top;
                ++count;
            }
            if(top == -1){
                stack[++top] = T[i];
                res_array[i--] = 0;
            }
            else{
                stack[++top] = T[i];
                res_array[i--] = ++count;
            }
        }
    }
    return res_array;
}

int main(){
    int a[] = {73,74,75,71,69,72,76,73};
    int* res = NULL;
    res = dailyTemperatures(a,7);
    for(int j = 0; j<= 7; j++){
        printf("\n%d",res[j]);
    }
    return 1;
}