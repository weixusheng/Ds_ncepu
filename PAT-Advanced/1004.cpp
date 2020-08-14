#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v[100];
int book[100], maxdepth = -1;   //记录层数对应的叶子节点数目数组 和 树的最大深度

void dfs(int index, int depth) {
    if(v[index].size() ==0) {   //当前为叶子节点
        book[depth]++;  //当前层数叶子节点 +1
        maxdepth = max(maxdepth, depth);    //更新最大层数
        return; //递归边界    
    }
    for(int i=0; i<v[index].size(); i++)    //递归当前节点对应的所有子节点
        dfs(v[index][i], depth+1);
}
int main() {
    int n, m, k, node, c;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d %d",&node, &k);
        for(int j=0; j<k; j++) {
            scanf("%d", &c);
            v[node].push_back(c);   //构建当前树  
        }    
    }
    dfs(1, 0);
    printf("%d", book[0]);  //分开,符合格式化打印要求
    for(int i=1; i<=maxdepth; i++)
        printf(" %d", book[i]);
    return 0;
}