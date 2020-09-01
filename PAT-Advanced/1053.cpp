#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int target;

struct node{
    int weight;
    vector<int> child;
};

vector<node> data;
vector<int> path;

void dfs(int index, int sum){
    path.push_back(index);
    if(sum > target){
        path.pop_back();
        return;
    }
    if(sum == target){
        if(data[index].child.size() !=0) {
            path.pop_back();
            return;
        }
        for(int i=0; i<path.size(); i++){
            /*
            if(i != 0){
                printf(" ");
            }
            printf("%d", data[path[i]].weight);
            if(i == path.size()-1){
                printf("\n");
            }
            */
            printf("%d%c", data[path[i]].weight, i != path.size() - 1 ? ' ' : '\n');
        }
        path.pop_back();
        return;
    }
    for(int j=0; j<data[index].child.size(); j++){
        int node = data[index].child[j];
        dfs(node, sum + data[node].weight);
    }
    path.pop_back();
    return;
}

bool cmp(int a, int b){
    return data[a].weight > data[b].weight;
}
int main(int argc, char const *argv[])
{
    int n, m, node, k;
    scanf("%d %d %d", &n, &m, &target);
    data.resize(n);
    //path.resize(n);
    for(int i=0; i<n; i++)
        scanf("%d", &data[i].weight);
    for(int i=0; i<m; i++) {
        scanf("%d %d", &node, &k);
        data[node].child.resize(k);
        for(int j=0; j<k; j++)
            scanf("%d", &data[node].child[j]);
        sort(data[node].child.begin(), data[node].child.end(), cmp);
    }
    //path.push_back(0);
    dfs(0, data[0].weight);
    return 0;
}
