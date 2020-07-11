#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iterator>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    vector<int> data(num);
    for(int h=0; h<num; h++){
        scanf("%d", &data[h]);
    }
    sort(data.begin(), data.end(), greater<int>());
    /*
    int next = 0, max = 0;
    bool ok = true;
    for(int i=0; i<num; i++){
        for(int j=0; j<i; j++){
            if(data[j] < i+1){
                ok = false;
                break;
            }
        }
        if(ok){
            max = i;
        }
        else{
            break;
        }
    }
    */
    int k;
    for(k=0; k<num && k+1 < data[k]; k++);
    printf("%d", k);
    return 0;
}