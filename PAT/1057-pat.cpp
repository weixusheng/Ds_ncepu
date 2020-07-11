#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    string s;
    getline(cin,s);
    int sum=0;
    for(int i=0; i<s.size(); i++){
        if(isalpha(s[i])){
            if(s[i]<='Z' && s[i]>='A'){
                sum += s[i]-'A'+1;
            }
            else{
                sum += s[i]-32-'A'+1;
            }
        }
    }
    int count1 = 0, count0 = 0;
    while(sum != 0){
        if(sum%2 == 1){
            count1++;
            printf("1");
        }
        else{
            count0++;
            printf("0");
        }
        sum = sum/2;
    }
    printf("%d %d", count0, count1);
    return 0;
}