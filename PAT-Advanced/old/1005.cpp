#include<cstdio>
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    int shit, sum = 0, tmp;
    string shit2;
    cin >> shit2;
    /* 不能这样用,因为给的测试数据太大了
    while(shit != 0){
        tmp = shit%10;
        sum += tmp;
        shit = shit/10;
    }
    */
    for(int i=0; i<shit2.length(); i++){
        sum += shit2[i]-'0';
    }
    string tb[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    string ans = to_string(sum);
    cout << tb[ans[0]-'0'];
    for(int i=1; i<ans.length(); i++){
        cout << " " << tb[ans[i]-'0'];
    }
    return 0;
}