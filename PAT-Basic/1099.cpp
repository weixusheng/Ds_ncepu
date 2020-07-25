#include<string>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>

using namespace std;

bool iss(int a){
    if(a == 1){
        return false;
    }
    int b = (int)sqrt(double(a));
    for(int i=2; i<b; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    bool has = false;
    string s;
    cin >> s;
    for(int i=0; i<s.size(); i++){
        string a = s.substr(i,s.size()-i);
        if(iss(stoi(a))){
            cout << a << " " << "Yes" << endl;
        }
        else
        {
            cout << a << " " << "No" << endl;
            has = true;
        }
    }
    if(!has){
        cout << "All Prime!";
    }
    system("pause");
    return 0;
}
