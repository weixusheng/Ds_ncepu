#include<cstdlib>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, tmp;
    cin >> num;
    set<int> set1;
    vector<int> data;
    for(int i=0; i<num; i++){
        cin >> tmp;
        data.push_back(tmp);
        while(tmp != 1){
            if(tmp % 2 == 1){
                tmp = (3*tmp+1)/2;
            }
            else{
                tmp = tmp/2;
            }
            if(set1.find(tmp) != set1.end()){
                break;
            }
            set1.insert(tmp);
        }
    }
    vector<int> res;
    for(int i=0; i<num; i++){
        if(set1.find(data[i]) == set1.end()){
            res.push_back(data[i]);
        }
    }
    sort(res.begin(),res.end(),greater<int>());
    for(int j=0; j<res.size(); j++){
        if(j != 0){
            cout << " "; 
        }
        cout << res[j];
    }
    system("pause");
    return 0;
}
