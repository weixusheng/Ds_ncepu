#include<stdlib.h>
#include<stdio.h>

int main(){
    int j,num;
    scanf("%d", &num);
    int i = 0;
    int res[3] = {0};
    while(num != 0){
        res[i++] = num%10;
        num = num/10;
    }
    for(j=0; j<res[2]; j++){
        printf("%s", "B");
    }
    for(j=0; j<res[1]; j++){
        printf("%s", "S");
    }
    for(j=0; j<res[0]; j++){
        printf("%d", j+1);
    }
    return 0;
}