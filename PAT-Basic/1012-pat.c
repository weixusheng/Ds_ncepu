/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int a1=0, a2=0, a3=0, a5=0, cur, temp, flag=0,count=0;
    int useless;
    scanf("%d", &useless);
    double a4=0;
    char ch;
    while(1){
        ch = getchar();
        if(ch == '\n'){
            break;
        }
        scanf("%d", &cur);
        temp = cur%5;
        if(temp == 0 && cur%2 == 0){
            a1 += cur;
        }
        else if(temp == 1){
            if(flag == 0){
                a2 += cur;
            }
            else{
                a2 -= cur;
            }
            flag = !flag;
        }
        else if(temp == 2){
            a3++;
        }
        else if(temp == 3)
        {
            a4 += cur;
            ++count;
        }
        else if(temp = 4)
        {
            if(cur > a5){
                a5 = cur;
            }
        }
    }
    if(a1 == 0){
        printf("N");
    }
    else
    {
        printf("%d", a1);
    }
    if(a2 == 0){
        printf(" N");
    }
    else
    {
        printf(" %d", a2);
    }
    if(a3 == 0){
        printf(" N");
    }
    else
    {
        printf(" %d", a3);
    }
    if(a4 == 0){
        printf(" N");
    }
    else
    {
        a4 = a4/count;
        printf(" %.1f", a4);
    }
    if(a5 == 0){
        printf(" N");
    }
    else
    {
        printf(" %d", a5);
    }
    return 0;
}
*/
#include<stdio.h>

#define MAXN 1000

int n[MAXN];
int n5[MAXN];//配合a5，存储所有被 5 除后余 4 的数字
int k = 0;

int main()
{
    int a1 = 0, a2 = 0, a3 = 0, a5 = 0, count4 = 0;
    int flag1 = 0, flag2 = 0, flag3 = 0, flag4 = 0, flag5 = 0;
    double a4, sum4 = 0;
    int N, i;
    int flag = 1;//配合a2，用来* -1
    scanf("%d",&N);
    for (i = 0; i < N; i++)
    {
        scanf("%d",&n[i]);
    }
    for (i = 0; i < N; i++)
    {
        if (n[i] % 5 == 0 && n[i] % 2 == 0)
        {
            a1 += n[i];
            flag1 = 1;
        }
        if (n[i] % 5 == 1)
        {
            a2 = a2 + flag * n[i];
            flag *= (-1);
            flag2 = 1;
        }
        if (n[i] % 5 == 2)
        {
            a3++;
            flag3 = 1;
        }
        if (n[i] % 5 == 3)
        {
            sum4 = sum4 + n[i];
            count4++;
            flag4 = 1;
        }
        if (n[i] % 5 == 4)
        {
            n5[k++] = n[i];
            flag5 = 1;
        }
    }
    a4 = sum4 / count4;
    a5 = n5[0];
    for (i = 1; i < k; i++)
    {
        if (n5[i] > a5)
        {
            a5 = n5[i];
        }
    }
    if (flag1)
    {
        printf("%d",a1);
    }
    else
    {
        printf("N");
    }
    printf(" ");
    if (flag2)
    {
        printf("%d", a2);
    }
    else
    {
        printf("N");
    }
    printf(" ");
    if (flag3)
    {
        printf("%d", a3);
    }
    else
    {
        printf("N");
    }
    printf(" ");
    if (flag4)
    {
        printf("%.1lf", a4);
    }
    else
    {
        printf("N");
    }
    printf(" ");
    if (flag5)
    {
        printf("%d", a5);
    }
    else
    {
        printf("N");
    }
    return 0;
}

