#include<string>
#include<cstdio>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    string password;
    int num;
    cin >> password >> num;
    string input;
    getchar();
    //cin >> input;
    getline(cin, input);
    while(input != "#"){
            if(input == password){
                cout << "Welcome in";
                break;
            }
            else{
                cout << "Wrong password: "<< input << endl;
                if(--num == 0){
                    cout << "Account locked";
                    break;
                }
            }
            //cin >> input;
            getline(cin, input);
    }
    return 0;
}