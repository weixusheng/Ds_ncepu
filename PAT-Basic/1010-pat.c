#include<stdlib.h>
#include<stdio.h>

/*int main(){
    char data[1000];
    gets(data);
    int p=0;
    int num_1;
    int num_2;
    int res;
    while(data[p] != '\0'){
        num_1 = data[p]-'0';
        p = p+2;
        num_2 = data[p]-'0';
        if(num_2 == 1){
            printf("%d", num_1);
        }
        else if(num_2 == 0){
            printf("0");
        }
        else{
            res = num_1*(num_2);
            printf("%d %d", res, num_2-1);
        }
        ++p;
        if(data[p] != '\0'){
            printf(" ");
            ++p;
        }
    }
    return 0;
}*/
int main(){
    int a,b;//a代表系数，b代表指数
    int flag=0;
    while(scanf("%d%d",&a,&b)!=EOF){//每次读两个字符，这种输入方式挺常用的
        if(b!=0){
            if(flag==0) printf("%d",a*b);
            else printf(" %d",a*b);
            printf(" %d",b-1);
            flag=1;
        }
    }
    if(flag==0) printf("0 0");//flag为0代表，所有的输入指数都为0，如果不为0的话
    return 0;//就置1了。
}