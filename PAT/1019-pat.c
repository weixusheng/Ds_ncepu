#include<stdio.h>
#include<stdlib.h>

/*
int cmp_small(const void* a, const void*b){
    char* m = (char*)a;
    char* n = (char*)b;
    return strcmp(a,b);
}

int cmp_big(const void* a, const void*b){
    char* m = (char*)a;
    char* n = (char*)b;
    return strcmp(b,a);
}

int toint(char* a){
    int res1 = 0;
    for(int j=0; j< 4; j++){
        res1 = (a[j]-'0') + res1*10;
    }
    return res1;
}

main(){
    char init_data[5];
    char small[5];
    char big[5];
    int m;
    int n;
    int res = 0;
    int flag = 0;
    scanf("%s", &init_data); //读入初始数到char数组
    //判断是否全部相同
    if((init_data[0] == init_data[1]) && (init_data[0] == init_data[2]) && (init_data[0]== init_data[3])){
        printf("%s - %s = 0 0 0 0",init_data,init_data);
        return 0;
    }
    while(res!=6174){
        strcpy(small,init_data);
        strcpy(big,init_data);
        //非递减排序(递增)
        qsort(big,4,sizeof(init_data[0]),cmp_big);
        m = toint(big); //char 转为 int
        //递减
        qsort(small,4,sizeof(init_data[0]),cmp_small);
        n = toint(small);
        printf("%04d - %04d",m,n);
        res = m-n;
        sprintf(init_data, "%d", res);  //int 转为 char数组
        if(res == 6174){
            printf(" = %04d",res);
        }
        else{
            printf(" = %04d\n",res);
        }
    }
    return 0;
}
*/

int cmp(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int sort(int n)
{
    int digits[4] = {n/1000, n%1000/100, n%100/10, n%10};
    qsort(digits, 4, sizeof(int), cmp);
    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

int reverse(int n)
{
    return n/1000 + n%1000/100 * 10 + n%100/10 * 100 + n%10 * 1000;
}

int main()
{
    int N;
    scanf("%d", &N);
    do
    {
        N = sort(N);
        printf("%04d - %04d = %04d\n", N, reverse(N), N - reverse(N));
        N = N - reverse(N);
    }while(N != 0 && N != 6174) ;
    return 0;
}