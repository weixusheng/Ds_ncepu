#include<cstdio>
#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

string rev(string data){
    reverse(data.begin(), data.end());
    return data;
}

string add(string data1, string data2){
    string s = data1;
    int carry = 0;
    for(int i=s.size()-1; i>=0 ; i++){
        s[i] = (data1[i]-'0'+data2[i]-'0'+carry+carry)%10 + '0';
        carry =  (data1[i]-'0'+data2[i]-'0'+ carry)/10;
    }
    return s;
}

int main(int argc, char const *argv[])
{
    string origin, s;
    cin >> origin;
    int n = 10;
    if(origin == rev(origin)){
        cout << origin << " is a palindromic number.\n";
    }
    while(n--){
        s = add(origin, rev(origin));
        cout << origin << " + " << rev(origin) << " = " << s << endl;
        if(s == rev(s)){
            cout << s << " is a palindromic number.\n";
            return 0;
        }
        origin = s;
    }
    cout << "Not found in 10 iterations.\n";
    return 0;
}

