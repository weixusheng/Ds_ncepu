#include<set>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    int s1,s2;
    //scanf("%d %d",&s1,&s2);
    cin >> s1 >> s2;
    int n, m;
    cin >> n >> m;
    //scanf("%d %d",&n,&m);
    vector<bool> shit(n,false);
    set<int> data1; //输入的
    set<int> data2; //差值 
    data2.insert(abs(s1-s2));
    data1.insert(s1);
    data1.insert(s2);
    vector<vector<int>> res;
    res.resize(n,vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int tmp;
            cin >> tmp;
            res[i][j] = tmp;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(!shit[j]){
                int tmp = res[j][i];
                if(data1.find(tmp) == data1.end() && data2.find(tmp) != data2.end()){
                    for(auto k=data1.begin(); k!= data1.end(); k++){
                        data2.insert(abs(*k-tmp));
                        data1.insert(tmp);
                    }
                }
                else{
                    printf("Round #%d: %d is out.\n",i+1,j+1);
                    shit[j] = true;
                }
            }
        }
    }
    bool has = false;
    for(int h=0; h<n; h++){
        if(shit[h] == false){
            has = true;
        }
    }
    if(has){
        printf("Winner(s):");
        for(int w=0; w<n; w++){
            if(!shit[w]){
                printf(" %d",w+1);
                //cout << " " << w+1;
            }
        }
    }
    else{
        printf("No winner.");
    }
    system("pause");
    return 0;
}
