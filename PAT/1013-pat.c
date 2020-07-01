#include<stdio.h>
#include<stdlib.h>
#include <math.h>

int main(){
    int a, b;   //输入
    scanf("%d %d", &a, &b);
    int count = 0;  //计数
    int m; //平方跟
    int i; //循环计数
    int s=2; //当前判断的数
    int flag;   //判断素数
    while(count < b){
        flag = 0;
        m=(int)sqrt((double)s);
        for(i=2;i<=m;i++)
        if(s%i==0)
            break;
        if(i>m){
            flag = 0;
            ++count;
        } 
        else{
            flag = 1;
        }
        if(flag == 0){ // is single
            if(count >= a){
                printf("%d", s);
                if((count-a+1)%10 == 0 && count!= b){
                    printf("\n");
                }
                else if(count != b)
                {
                    printf(" ");
                }
            }
        }
        s++;
    }
    return 0;
}