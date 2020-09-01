#include<iostream>
#include<vector>

using namespace std;
/*
这都能二分吗...我傻了
*/
vector<int> ans, sum;
int n, m, tmpsum;

int func(int i, int &j){
    int left = i;
    int right = n;
    while(left < right){
        int mid = (left+right)/2;
        if(sum[mid]-sum[i-1] >= m){
            right = mid;
        }
        else{
            left = mid+1;
        }
    }
    j = right;
    int tsum = sum[j]-sum[i-1];
    return tsum;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    sum.resize(n+1);
    for(int i=0; i<n; i++){
        scanf("%d", &sum[i]);
        sum[i] += sum[i-1];
    }
    int maxshit = sum[n];
    for(int i=1; i<=n; i++){
        int j;
        tmpsum = func(i, j);
        if(tmpsum > maxshit){
            continue;
        }
        else if(tmpsum >= m){
            if(tmpsum < maxshit){
                ans.clear();
                maxshit = tmpsum;
            }
            ans.push_back(i);
            ans.push_back(j);
        }
    }
    for(int j=0; j<ans.size(); j+=2){
        printf("%d-%d\n", ans[j],ans[j+1]);
    }
    return 0;
}


