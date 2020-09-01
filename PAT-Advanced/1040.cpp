#include<iostream>
#include<vector>
#include<string>

using namespace std;

int data[1010][1010];

int main(int argc, char const *argv[])
{
    string s;
    getline(cin, s);
    int len = s.size(), ans = 1;
    for(int i=0; i<len; i++){
        data[i][i] = 1;
        if(s[i] == s[i+1]){
            data[i][i+1] = 1;
            ans = 2;
        }
    }
    for(int shit = 3; shit <= len; shit++){
        for(int i=0; i<len; i++){
            int j = i+shit-1;
            if(s[i] == s[j] && data[i+1][j-1] == 1){
                data[i][j] = 1;
                ans = shit;
            }
        }
    }
    printf("%d", ans);
    return 0;
}
