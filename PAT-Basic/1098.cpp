#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

int converts(char a){
    if(isdigit(a)){
        return a-'0';
    }
    else{
        return a-'a'+10;
    }
}

//vector<char> v = {'a','b',c,d,e,f,g,h,i,j,k}

char cons(int a){
    if(a<10){
        return a+'0';
    }
    else
    {
        return 'a'+(a-10);
    }
}

int main(int argc, char const *argv[])
{
    string a,b;
    cin >> a >> b;
    int sum;
    if(a.size()>b.size()){
        sum = a.size();
        int shit = b.size();
        for(int i=0; i<a.size()-shit; i++){
            b = "0"+b;
        }
    }
    else{
        sum = b.size();
        int shit = a.size();
        for(int i=0; i<b.size()-shit; i++){
            a = "0"+a;
        }
    }
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    char data[1000000];
    int carry = 0;
    int j;
    for(j=0; j<sum; j++){
        int m = converts(a[j]);
        int n = converts(b[j]);
        int shit = (m+n+carry)%30;
        carry = (m+n+carry)/30;
        char shit2 = cons(shit);
        data[j] = shit2;
    }
    if(carry != 0){
        data[j] = carry+'0';
    }
    string res = data;
    // 11feik2ir
    reverse(res.begin(),res.end());
    int cnt = 0;
    for(int i=0; i<res.size(); i++){
        if(res[i] == '0'){
            cnt++;
        }
        else{
            break;
        }
    }
    res = res.substr(cnt,res.size()-cnt);
    //cout << res;
    if(res == ""){
        cout << "0";
    }
    else{
        cout << res;
    }
    system("pause");
    return 0;
}
