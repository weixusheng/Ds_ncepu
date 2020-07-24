#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct bing{
    int id;
    int cnt;
};

bool cmp(bing a, bing b){
    if(a.cnt == b.cnt){
        return a.id < b.id;
    }
    else{
        return a.cnt > b.cnt;
    }
}

int main(int argc, char const *argv[])
{
    int m, c, tmp;
    cin >> m >> c;
    vector<bing> data(m);
    for(int i=0; i<m; i++){
        data[i].id = i;
        data[i].cnt = 0;
    }
    for(int k=0; k<c; k++){
        for(int j=0; j<m; j++){
            cin >> tmp;
            data[j].cnt += tmp;
        }
    }
    sort(data.begin(), data.end(), cmp);
    int max = data[0].cnt;
    printf("%d\n", max);
    for(int i=0; i<m; i++){
        if(data[i].cnt == max){
            if(i != 0){
                printf(" ");
            }
            printf("%d", data[i].id+1);
        }
        else{
            break;
        }
    }
    system("pause");
    return 0;
}
