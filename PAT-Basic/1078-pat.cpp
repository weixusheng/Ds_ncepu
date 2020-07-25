#include<cstdio>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char mode;
    string data;
    scanf("%c", &mode);
    getchar();
    int temp_count;
    int temp_num = 0;
    if(mode == 'C'){
        getline(cin, data);
        temp_count = 1;
        for(int i=0; i<data.size(); i++){
            if(data[i] == data[i+1]){
                temp_count++;
            }
            else{
                if(temp_count!=1){
                    printf("%d",temp_count);
                    temp_count = 1;
                }
                printf("%c",data[i]);
            }
        }
    }
    else if(mode == 'D'){
        getline(cin,data);
        for(int i=0; i<data.size(); i++){
            if(isdigit(data[i])){
                temp_num = temp_num*10 + data[i]-'0';
            }
            else{
                if(temp_num!= 0){
                    for(int a=0 ;a<temp_num-1; a++){
                        printf("%c", data[i]);
                    }
                }
                printf("%c", data[i]);
                temp_num = 0;
            }
        }
    }
    return 0;
}

