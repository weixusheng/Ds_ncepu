#include<cstdio>
#include<vector>
#include<algorithm>
#include<iterator>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    double temp;
    double sum = 0;
    vector<double> data(num);
    for(int i=0; i<num; i++){
        scanf("%lf", &temp);
        data[i] = temp;
    }
    sort(data.begin(), data.end(), less<double>());
    /*
    if(data.size() == 1){
        printf("%d", (int)data[0]);
        return 0;
    }
    */
    sum = data[0];
    for(int k=1; k<data.size(); k++){
        sum += data[k];
        sum = sum/2;
    }
    int res = (int)sum;
    printf("%d", res);
    return 0;
}