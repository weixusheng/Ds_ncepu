#include<stdio.h>
#include<stdlib.h>

int main(){
    double s1,s2;
    scanf("%lf %lf", &s1, &s2);
    double dvalue = s2-s1;
    long int d;
    d = (int)(dvalue/100+0.5);
    int hour = 0, minutes = 0, second = 0;
    second = d%60;
    d /= 60;
    minutes = d%60;
    hour = d/60;
    printf("%02d:%02d:%02d",hour,minutes,second);
}