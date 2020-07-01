#include<stdio.h>
#include<map>

using namespace std;

int main(int argc, const char** argv) {
    long int data[3];
    int s1,s2,s3,k1,k2,k3;
    scanf("%d.%d.%d %d.%d.%d", &s1,&s2,&s3,&k1,&k2,&k3);
    long int sum1,sum2;
    int cache = 17*29;
    sum1 = s1*cache + s2*29 + s3;
    sum2 = k1*cache + k2*29 + k3;
    int change = sum2-sum1;
    bool shit = false;
    if(change < 0){
        shit = true;
        change = abs(change);
    }
    data[0] = change/cache;
    change %= cache;
    data[1] = change/29;
    change %= 29;
    data[2] = change;
    if(shit){
        printf("-");
    }
    printf("%d.%d.%d", data[0], data[1], data[2]);
    return 0;
}