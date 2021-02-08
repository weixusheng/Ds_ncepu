#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

const int maxv = 1010;

struct node{
    int id;
    int layer;
};

vector<node> adj[maxv];
bool inq[maxv] = {false};   //全局访问判定数组

int bfs(int s, int L){
    int numforward = 0;
    queue<node> q;
    node start;
    start.id = s;
    start.layer = 0;
    q.push(start);
    inq[start.id] = true;
    while(!q.empty()){
        node topnode = q.front();
        q.pop();
        int u = topnode.id;
        for(int i=0; i<adj[u].size(); i++){
            node next = adj[u][i];
            next.layer = topnode.layer + 1;
            if(inq[next.id] == false && next.layer <= L){   //遍历队头元素
                q.push(next);
                inq[next.id] = true;
                numforward++;
            }
        }
    }
    return numforward;
}

int main(){
    node user;
    int n, L, numfollow, idfollow;
    scanf("%d%d", &n, &L);
    for(int i=1; i<=n; i++){
        user.id = i;
        scanf("%d", &numfollow);
        for(int j=0; j<numfollow; j++){
            scanf("%d", &idfollow);
            adj[idfollow].push_back(user);  //初始化数据
        }
    }
    int numquery, s;
    scanf("%d", &numquery);
    for(int i=0; i<numquery; i++){
        memset(inq, false, sizeof(inq));    //初始化数组
        scanf("%d", &s);
        int numforward = bfs(s, L);
        printf("%d\n", numforward);
    }
    return 0;
}

