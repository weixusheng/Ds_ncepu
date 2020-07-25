#include<cstdlib>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int sum = 0;
    string str[10] =  {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    for(int i=0; i<s.length(); i++){
        sum += s[i]-'0';
    }
    string res = to_string(sum);
    for(int j=0; j<res.length(); j++){
        if(j != 0){
            cout << " "; 
        }
        cout << str[res[j]-'0'];
    }
    system("pause");
    return 0;
}
