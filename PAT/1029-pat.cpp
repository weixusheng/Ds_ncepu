#include<stdio.h>
#include<stdlib.h>
#include<unordered_set>
#include<string>
#include<iostream>

using namespace std;

int main(){
    string s1, s2,ans;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++){
        if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos){
            ans += toupper(s1[i]);
        }
    }
    cout << ans;
    system("pause");
}
/*
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    unordered_set<char> set1;
    string::iterator it1 = s1.begin(), it2 = s2.begin();
    while(it1 != s1.end()){
        if(*it1 != *it2){
            if(*it1<'z' && *it1>'a'){
                *it1-=32;
            }
            set1.insert(*it1);
            it1++;
        }
        else{
            it1++;
            it2++;
        }
    }
    for(unordered_set<char>::iterator it = set1.begin(); it!=set1.end(); it++){
        printf("%c", *it);
    }
    return 0;
}
*/