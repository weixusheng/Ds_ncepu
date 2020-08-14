#include<iostream>
#include<vector>
#include<set>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    int num1, num2;
    int tmp1;
    double tmp2;
    vector<double> res(2000,0);
    vector<double> data1(1000,0);
    vector<double> data2(1000,0);
    set<int> s1;
    set<int> s2;
    cin >> num1;
    for(int j=0; j<num1; j++){
        cin >> tmp1 >> tmp2;
        s1.insert(tmp1);
        data1[tmp1] += tmp2;
    }
    cin >> num2;
    for(int j=0; j<num2; j++){
        cin >> tmp1 >> tmp2;
        s2.insert(tmp1);
        data2[tmp1] += tmp2;
    }
    vector<int> res2;
    set<int> nr;
    int sum;
    double sum2;
    for(auto i=s1.begin(); i!=s1.end(); i++){
        for(auto j=s2.begin(); j!=s2.end(); j++){
            sum = *i+*j;
            sum2 = data1[*i] * data2[*j];
            if(nr.find(sum) == nr.end()){
                nr.insert(sum);
                res2.push_back(sum);
            }
            res[sum] += sum2;
        }
    }
    sort(res2.begin(), res2.end(), greater<int>());
    //printf("%d", res2.size());
    for(int w = 0; w < res2.size(); w++){
        if(int(res[res2[w]]) == 0){
            res2.erase(res2.begin()+w);
        }
    }
    cout << res2.size();
    for(int k=0; k<res2.size(); k++){
        printf(" %d %.1f", res2[k], res[res2[k]]);
    }
    return 0;
}
