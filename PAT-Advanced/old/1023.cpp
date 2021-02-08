#include <cstdio>
#include <string>
#include<iostream>
using namespace std;

int book[10];
int main() {
    //char num[22];
    //scanf("%s", num);
    string s;
    getline(cin,s);
    int flag=0, len = s.size();
    for(int i=len-1; i>=0; i--) {
        int temp = s[i] -'0';
        book[temp]++;
        temp = temp*2+flag;
        flag=0;
        if(temp>=10) {
            temp=temp-10;
            flag=1;        
        }
        s[i] = (temp+'0');
        book[temp]--;    
    }
    int flag1=0;
    for(int i=0; i<10; i++) {
        if(book[i] !=0)
            flag1=1;    
    }
    printf("%s", (flag==1||flag1==1) ?"No\n" : "Yes\n");
    if(flag==1) 
        printf("1");
    cout << s;
    return 0;
}