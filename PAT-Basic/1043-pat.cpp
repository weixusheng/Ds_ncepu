#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    map<char,int>mp;
    mp['P'] = 0,mp['A'] = 0,mp['T'] = 0;
    mp['e'] = 0,mp['s'] = 0,mp['t'] = 0;
    string s;
    getline(cin, s);
    int count = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'P'){ //PATest
            mp['P']++;
            count++;
            continue;
        }
        if(s[i] == 'A'){ //PATest
            mp['A']++;
            count++;
            continue;
        }
        if(s[i] == 'T'){ //PATest
            mp['T']++;
            count++;
            continue;
        }
        if(s[i] == 'e'){ //PATest
            mp['e']++;
            count++;
            continue;
        }
        if(s[i] == 's'){ //PATest
            mp['s']++;
            count++;
            continue;
        }
        if(s[i] == 't'){ //PATest
            mp['t']++;
            count++;
            continue;
        }
    }
    int j = 0;
    while(j < count){
        if(mp['P']){
            printf("P");
            mp['P']--;
            j++;
        }
        if(mp['A']){
            printf("A");
            mp['A']--;
            j++;
        }
        if(mp['T']){
            printf("T");
            mp['T']--;
            j++;
        }
        if(mp['e']){
            printf("e");
            mp['e']--;
            j++;
        }
        if(mp['s']){
            printf("s");
            mp['s']--;
            j++;
        }
        if(mp['t']){
            printf("t");
            mp['t']--;
            j++;
        }
    }
    return 0;
}