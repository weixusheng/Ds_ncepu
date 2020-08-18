#include<iostream>
using namespace std;

int k[200005];

int main(int argc, char const *argv[])
{
    int n,m, tmp, count = 0;
    cin >> n;
    for(int i=1; i<=n; i++){
        scanf("%d", &k[i]);
    }
    k[n+1] = 0x7fffffff; // int 's max value = 0x7fffffff
    cin >> m;
    int midpos = (n+m+1)/2, i=1;
    for(int j=1; j<=m; j++){
        scanf("%d", &tmp);
        while(k[i] < tmp){
            count++;
            if(count == midpos){
                cout << k[i];
            }
            i++;
        }
        count++;
        if(count == midpos){
            cout << tmp;
        }
    }
    while(i <= n){
        count++;
        if(count == midpos){
            cout << k[i];
        }
        i++;
    }
    return 0;
}
