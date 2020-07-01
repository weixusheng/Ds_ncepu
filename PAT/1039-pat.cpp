#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    int data[1000] = {0};
    bool shit = false;
    string s1,s2;
    getline(cin, s1);
    getline(cin, s2);
    int sum = s1.size();
    int count = 0;
    for(int j=0 ; j<s1.size(); j++){
        data[s1[j]]++;
    }
    for(int i=0; i<s2.size(); i++){
        if(data[s2[i]] == 0){   //没有找到
            shit = true;
            count++;
        }
        else{
            data[s2[i]]--;
            sum--;
        }
    }
    if(shit){
        printf("No %d", count);
    }
    else{
        printf("Yes %d", sum);
    }
    return 0;
}