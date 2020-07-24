#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            vector<int> lie, a(n + 1, 1);
            a[i] = a[j] = -1;
            for (int k = 1; k <= n; k++)
                if (v[k] * a[abs(v[k])] < 0) lie.push_back(k);
            if (lie.size() == 2 && a[lie[0]] + a[lie[1]] == 0) {
                cout << i << " " << j;
                return 0;
            }
        }
    }
    cout << "No Solution";
    return 0;
}
/*
#include<cstdlib>
#include<vector>
#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char const *argv[])
{
    int num, tmp;
    cin >> num;
    vector<int> data(num);
    for(int i=0; i<num; i++){
        cin >> tmp;
        data[i] = tmp;// insert data
    }
    bool shit_l = false, shit_r = false;
    int shit1,shit2;
    int cnt;
    for(int i=0; i<num; i++){
        for(int j=i+1; j<num; j++){
            shit_r = false;
            shit_l = false;
            cnt = 0;
            for(int k=0; k<num; k++){
                int s = data[k];
                if((abs(s) == i+1 || abs(s) == j+1) && s>0){
                    if(k == i || k == j){
                        shit_l = true;
                        //shit1 = k;
                    }
                    else{
                        shit_r = true;
                        //shit2 = k;
                    }
                    cnt++;
                }
                if(s < 0){
                    if(abs(s) != i+1 && abs(s) != j+1){
                        if(k == i || k == j){
                            shit_l = true;
                            //shit1 = k;
                        }
                        else{
                            shit_r = true;
                            //shit2 = k;
                        }
                        cnt++;
                    }
                }
            }
            // shit2 is shit
            if(shit_l && shit_r && cnt == 2){
                printf("%d %d",i+1,j+1);
                system("pause");
                return 0;
            }
        }
    }
    printf("No Solution");
    system("pause");
    return 0;
}
*/