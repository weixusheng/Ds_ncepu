#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;

typedef struct {
    int isleaf;
    int weight;
    int index;
    int child;
    vector<int> childs;
}node;
vector<node> data;

bool cmp1(int a, int b){
    return data[a].weight > data[b].weight;
}

void print_path(vector<node> v, int w, int cost, int k, vector<int> path){
    if(cost == w && v[k].isleaf == 1){
        for(int i=0; i<path.size(); i++){
            printf("%d", path[i]);
            if(i == path.size()-1){
                printf("\n");
            }
            else{
                printf(" ");
            }
        }
    }
    if(cost > w){
        return;
    }
    int tmp;
    if(v[k].isleaf == 0){
        for(int i=0; i<v[k].child; i++){
            tmp = v[k].childs[i];
            cost += v[tmp].weight;
            path.push_back(v[tmp].weight);
            print_path(v,w,cost,tmp,path);
            path.pop_back();
            cost -= v[tmp].weight;
        }
    }
    return;
}

int main(){
    int sum, non_leaf, wei;
    cin >> sum >> non_leaf >> wei;
    int tmp;
    for(int i=0 ;i<sum; i++){   //initial isleaf and weight
        scanf("%d", &tmp);
        node p;
        p.weight = tmp;
        p.isleaf = 1;
        data.push_back(p);
    }
    int tmp_index;
    int tmp_num;
    for(int j=0; j<non_leaf; j++){
        cin >> tmp_index >> tmp_num;
        for(int i=0 ; i<tmp_num; i++){
            scanf("%d", &tmp);
            data[tmp_index].childs.push_back(tmp);
            sort(data[tmp_index].childs.begin(),data[tmp_index].childs.end(),cmp1);
            data[tmp_index].isleaf = 0;
        }
        data[tmp_index].child = tmp_num;
    }
    vector<int> path;
    path.push_back(data[0].weight);
    int cost = data[0].weight;
    print_path(data,wei,cost,0,path);
    system("pause");
}