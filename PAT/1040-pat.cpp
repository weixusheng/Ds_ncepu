#include<stdio.h>
#include<string>
#include<iostream>

using namespace std;

/*
int main(int argc, const char** argv) {
    string s;
    getline(cin, s);
    int p_pos=0, a_pos=0, t_pos=0;  
    int count = 0;
    bool shit = false;
    int sum = s.size();
    for(int i=0 ;i < s.size();){
        if(p_pos == 0 && t_pos == 0 && t_pos == 0){ //第一次寻找
            while(s[i] != 'P' && i<sum){
                i++;
            }
            while(s[i] != 'A' && i<sum){
                i++;
            }
            while(s[i]!= 'T' && i<sum){
                i++;
            }
            if(i > sum){
                shit = true;
                break;
            }
            count++;
        }
        else{
            i = p_pos+1;
            while (s[i] != 'P' && i<sum)
            {
                i++;
            }
            if(i<sum){
                p_pos = i;
            }
            else{
                 break;
            }
            if(i > a_pos){
                i = a_pos+1;
                while(s[i] != 'A' && i<sum){
                    i++;
                }
                if(i<sum){
                    a_pos = i;
                }
                else{
                    break;
                }
            }
            if(i>t_pos){
                i = t_pos+1;
                while(s[i] != 'T' && i<sum){
                    i++;
                }
                if(i<sum){
                    t_pos = i;
                }
                else{
                    break;
                }
            }
            count++;
        } 
    }
    if(shit){
        printf("0");
    }
    else{
        printf("%d", count%1000000007);
    }
    return 0;
}
*/

#include <stdio.h>

#define LIM 1000000007

int main()
{
    int P = 0, PA = 0, PAT = 0;
    char c;

    while((c = getchar()) != '\n')
    {
        if(c == 'P')   P++;
        if(c == 'A')   PA = (PA + P) % LIM;
        if(c == 'T')   PAT = (PAT + PA) % LIM;
    }
    printf("%d", PAT);

    return 0;
}