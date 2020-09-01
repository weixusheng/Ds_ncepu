#include<set>
#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    set<int> s1;
    vector<int> data(num);
    int shit[100000] = {0};
    int tmp;
    for(int i=0; i<num; i++){
        cin >> tmp;
        data[i] = tmp;
        shit[tmp]++;
    }
    int j;
    for(j=0; j<num; j++){
        if(shit[data[j]] == 1){
            printf("%d", data[j]);
            break;
        }   
    }
    if(j == num){
        printf("None");
    }
    return 0;
}
