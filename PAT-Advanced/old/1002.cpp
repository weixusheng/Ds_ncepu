#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int cnt = 0;
    double data[1001] = {0};
    int num1, num2;
    int tmp;
    double tmp2;
    cin >> num1;
    for(int i=0; i<num1; i++){
        cin >> tmp >> tmp2;
        if(data[tmp] == 0){
            cnt++;
        }
        data[tmp] += tmp2;
    }
    cin >> num2;
    for(int i=0; i<num2; i++){
        cin >> tmp >> tmp2;
        if(data[tmp] == 0){
            cnt++;
        }
        data[tmp] += tmp2;
    }
    cout << cnt;
    for(int j=1000; j>=0; j--){
        if(data[j]!=0){
            cout << " " << j << " " << data[j];
        }
    }
    system("pause");
    return 0;
}
