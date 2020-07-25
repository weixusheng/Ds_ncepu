#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    string s;
    int max = 0;
    int maxid;
    int tempid;
    getline(cin, s);
    int hashmap[500] = {0};
    for(int i=0; i<s.size(); i++){
        if(s[i]>= 'A' && s[i]<= 'Z'){    //大写字母
            tempid = s[i]+32-'0';
            hashmap[tempid]++;
            if(max < hashmap[tempid]){
                max = hashmap[tempid];
                maxid = tempid;
            }
            if(max == hashmap[tempid]){
                maxid = maxid < tempid ? maxid:tempid;
            }
        }
        else if(s[i]>='a' && s[i]<='z'){
            tempid = s[i]-'0';
            hashmap[tempid]++;
            if(max < hashmap[tempid]){
                max = hashmap[tempid];
                maxid = tempid;
            }
            if(max == hashmap[tempid]){
                maxid = maxid < tempid ? maxid:tempid;
            }
        }
    }
    printf("%c %d",(char)(maxid+'0'), max);
    return 0;
}