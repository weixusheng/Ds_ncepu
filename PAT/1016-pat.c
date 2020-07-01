#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
long depart(long a, long b){
    long pa;
    for(pa=0; a; a/=10){
        if(a%10 == b){
            pa = pa*10+b;
        }
    }
    return pa;
}
int main(){
    long a,b;
    int pa,pb;
    scanf("%ld %d %ld %d", &a, &pa, &b, &pb);
    printf("%ld", depart(a,pa)+depart(b,pb));
    return 0;
}
*/
int main(){
    char s1[11], s2[11];
    int a,b;
    int res1 = 0, res2 = 0;
    scanf("%s %d %s %d", &s1, &a, &s2, &b);
    int k = strlen(s1);
    for(int i=0; i<strlen(s1); i++){
        if((s1[i]-'0') == a){
            res1 = res1*10+(s1[i]-'0');
        }
    }
    for(int j=0; j<strlen(s2); j++){
        if((s2[j]-'0') == b){
            res2 = res2*10+(s2[j]-'0');
        }
    }
    printf("%d", (res1+res2));
    return 0;
}