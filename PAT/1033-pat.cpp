#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    bool has = false;
    string s1;
    getline(cin,s1);
    string s2;
    getline(cin,s2);
    bool shitup = false;
    if(s1.find('+') != string::npos){
        shitup = true;
    }
    for(int j=0; j<s2.size(); j++){
        char a = s2[j];
        if(a>='A' && a<='Z' && shitup){
            continue;
        }
        if(s1.find(a) == string::npos){
            if(a>='a' && a<='z'){
                if(s1.find(a-32) != string::npos){
                    continue;
                }
            }
            printf("%c",a);
            has = true;
        }
    }
    if(has == false){
        printf("\n");
    }
    return 0;
}

/*
int main()
{
    string s1,s2;
    int flag = 0 ;
    int sum = 0;
    getline(cin,s1);
    getline(cin,s2);
    int len = s2.length();
    if(s1.find('+') != string::npos)       //判断是否能打出大写字母
        flag = 1;
    for(int i = 0; i < len ; i++)
    {
        if(s2[i] >= 'a' && s2[i] <= 'z') //英文小写
        {
            if(s1.find(s2[i] - 32) == string::npos) //英文大写
            {
                 cout<<s2[i];
                 sum = 1;
            }
        }
        else if(s1.find(s2[i]) == string::npos) 
        {
            if(s2[i] >= 'A' && s2[i] <= 'Z' && flag == 1)   //英文大写
                continue;
            else
            {
                cout<<s2[i];
                sum = 1;
            }
        }
    }
    if(sum  == 0)
        cout<<endl;
    return 0;
}
*/
