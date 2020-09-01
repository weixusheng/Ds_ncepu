#include<string>
#include<algorithm>
#include<iostream>

using namespace std;

bool isshit(string s){
    /*
    int len = s.size();
    for(int i=0; i<len/2; i++){
        if(s[i] != s[len-i-1]){
            return false;
        }
    }
    */
    string s2  = s;
    reverse(s.begin(),s.end());
    if(s == s2){
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string s,s2;
    int num, carry;
    cin >> s >> num;
    bool shit;
    shit = isshit(s);
    if(shit){
        cout << s << endl;
        cout << "0";
        return 0;
    }
    for(int j=1; j<=num; j++){
        s2 = s;
        reverse(s2.begin(), s2.end());
        int tmp;
        carry = 0;
        for(int i=s.size()-1; i>=0; i--){
            tmp = (s[i]-'0')+(s2[i]-'0');
            tmp += carry;
            carry = 0;
            if(tmp >10){
                carry = 1;
            }
            tmp = tmp%10;
            s[i] = tmp+'0';
        }
        if(carry == 1){
            s = "1"+s;
        }
        shit = isshit(s);
        if(shit || j == num){
            cout << s << endl;
            cout << j;
            break;
        }
    }
    return 0;
}
