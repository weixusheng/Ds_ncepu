#include <iostream>
using namespace std;
int a[1001];
int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%d", &temp);
        a[temp]++;    
    }
    for(int i=0; i<1001; i++) {
        if(a[i]) {
            a[i]--;
            if(m>i && a[m-i]) {
                printf("%d %d", i, m-i);
                return 0;       
            }
            a[i]++;
        }    
    }
    printf("No Solution");
    return 0;
}
/*
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

bool cmp(int a, int b){
    return a < b; 
}

int main(int argc, char const *argv[])
{
    int num, shit;
    int hs[100000] = {0};
    scanf("%d %d", &num, &shit);
    vector<int> data(num);
    for(int i=1; i<=num; i++){
        scanf("%d", &data[i]);
        hs[data[i]] = i;
    }
    sort(data.begin(), data.end(), cmp);
    int mid;
    int left, right, sum = 0;
    for(int j=1; j<=data.size(); j++){
        left = j+1;
        right = data.size()-1;
        while(left <= right){
            mid = (left + right)/2;
            sum = data[j] + data[mid];
            if(sum == shit){
                if(hs[data[j]] > hs[data[mid]]){
                    break;
                }
                printf("%d %d", data[j], data[mid]);
                return 0;
            }
            else if(sum > shit){
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
    }
    printf("No Solution");
    return 0;
}
*/

