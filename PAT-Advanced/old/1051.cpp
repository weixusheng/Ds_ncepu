#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    int m, n, k;
    // m: maximum stack n:sequence length k:check num
    scanf("%d %d %d", &m, &n, &k);
    for(int i=0; i<k; i++){
        vector<int> data(n);
        stack<int> s;
        for(int j=0; j<n; j++){
            scanf("%d", &data[j]);
        }
        int cur = 0;
        for(int k=1; k<=n; k++){
            s.push(k);
            if(s.size() > m){
                break;
            }
            while(!s.empty() && s.top() == data[cur]){
                s.pop();
                cur++;
            }
        }
        if(cur == n){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
