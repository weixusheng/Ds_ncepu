#include<vector>
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    vector<int> data(num);
    for(int i=0; i<num; i++){
        cin >> data[i];
    }
    int tmp = 0, tmpindex = 0, left = 0, right = num-1, max = -1;
    for(int i=0; i<num; i++){
        tmp += data[i];
        if(tmp < 0){
            tmp = 0;
            tmpindex = i+1;
        }
        else{
            if(tmp > max){
                left = tmpindex;
                right = i;
                max = tmp;
            }
        }
    }
    if(max < 0){
        max = 0;
    }
    cout << max << " " << data[left] << " " << data[right];
    return 0;
}
