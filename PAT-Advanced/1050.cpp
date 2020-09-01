#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    getline(cin, a);
    //getchar();
    getline(cin, b);
    int len = b.size();
    int shit[100000];
    for(int i=0; i<len; i++){
        shit[b[i]] = 1;
    }
    for(int j=0; j<a.size(); j++){
        if(shit[a[j]] != 1){
            printf("%c", a[j]);
        }
    }
    return 0;
}
