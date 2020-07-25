#include<cstdio>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    string s;
    cin >> num;
    getchar();
    bool hasa,hasd,shit;
    for(int i=0; i<num; i++){
        hasa = false;
        hasd = false;
        shit = false;
        s = "";
        getline(cin, s);
        if(s.size() < 6){
            cout << "Your password is tai duan le."<< endl;
            continue;
        }
        for(int j=0; j<s.size(); j++){
            if(isdigit(s[j])){
                hasd = true;
            }
            else if(isalpha(s[j])){
                hasa = true;
            }
            else if(s[j] != '.'){
                shit = true;
            }
        }
        if(shit){
            cout << "Your password is tai luan le." << endl;
            continue;
        }
        if(hasa == false){
            cout << "Your password needs zi mu."<< endl;
            continue;
        }
        if(hasd == false){
            cout << "Your password needs shu zi."<< endl;
            continue;
        }
        cout << "Your password is wan mei."<< endl;
    }
    return 0;
}
