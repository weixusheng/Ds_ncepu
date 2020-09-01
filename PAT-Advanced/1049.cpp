#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    int shit;
    scanf("%d", &shit);
    string data;
    int cnt = 0;
    for(int i=1; i<=shit; i++){
        data += to_string(i);
    }
    for(int j=0; j<data.size(); j++){
        if(data[j] == '1'){
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
