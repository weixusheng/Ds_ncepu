#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

vector<int> data(500000,1);
int main(){
    /*
    判断一个数由素数组成,首先建立素数表,然后从素数表遍历
    */
    for(int i=2; i*i<500000; i++){
        for(int j=2; i*j<500000; j++){
            data[i*j] = 0;
        }
    }
    long int a;
    scanf("%ld",&a);
    printf("%ld=",a);
    if(a == 1){
        printf("1");
    }
    bool state = false;
    for(int i=2; a >= 2; i++){
        int cnt = 0;
        int flag = 0;
        while(data[i] == 1 && a%i == 0){
            flag = 1;
            a = a/i;
            cnt++;
        }
        if(flag == 1){
            if(state == true){
                printf("*");
            }
            printf("%d",i);
            state = true;
        }
        if(cnt >= 2){
            printf("^%d", cnt);
        }
    }
    return 0;
}