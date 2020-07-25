#include<cstdlib>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, k;
    cin >> num >> k;
    int tmp;
    int l,r;
    int max = 0;
    bool comb = false, has = false;
    for(int i=0; i<num; i++){
        cin >> tmp;
        if(tmp > max){
            max = tmp;
        }
        if(comb == false && tmp>k){
            comb = true;
            l = i;
            r = i;
        }
        else if(comb == true && tmp>k){
            r = i;
        }
        else if(tmp <= k){
            if(comb){
                comb = false;
                printf("[%d, %d]\n",l,r);
                has = true;
            }
            else{
                continue;
            }
        }
    }
    if(comb == true){
        printf("[%d, %d]\n",l,r);
        has = true;
    }
    if(!has){
        printf("%d\n", max);
    }
    system("pause");
    return 0;
}
