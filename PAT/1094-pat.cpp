#include<cstdlib>
#include<iostream>
#include<string>
#include<cmath>

using namespace std;

bool isshit(int a){
    //int s = (int)sqrt(double(a));
    for(int i=2; i*i<=a; i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    int num, k;
    string s;
    cin >> num >> k;
    getchar();
    getline(cin, s);
    int i=0;
    string tmp;
    int shit;
    bool has = false;
    while(i+k <= num){
        tmp = s.substr(i,k);
        shit = stoi(tmp);
        if(isshit(shit)){
            printf("%d",shit);
            //has = true;
            //break;
            return 0;
        }
        i++;
    }
    if(!has){
        printf("404");
    }
    system("pause");
    return 0;
}