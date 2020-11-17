#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;
// 图-拔高题
// 题号 1.1
/*
对于一个使用邻接表存储的带权有向图G,试用dfs对所有顶点进行拓扑排序
如果拓扑排序成功,返回1,如果图中存在环,则返回0

这个题好像有点问题,他只能判定是否成环,而不能输出拓扑排序序列
拓扑排序序列是 深度优先遍历的 逆后序
*/
#define maxsize 1000

typedef struct arcnode{
    struct arcnode *next;
    int vertex;
}Arcnode;

typedef struct {
    int val;
    Arcnode *first;
}vnode, adjlist[maxsize];

typedef struct{
    adjlist vertices;
    int vexnum, arcnum;
}ALGraph;

void dfs_t(ALGraph g, int flag, int v, int visited[], int finished[]){
    Arcnode *p = g.vertices[v].first;
    printf("%d", g.vertices[v].val);
    finished[v] = 0;
    visited[v] = 1;
    while(p){
        if(visited[p->vertex] == 1 && finished[p->vertex] == 0){
            flag = 0;   //阻断(成环)标志
        }
        else if(visited[p->vertex] == 0){
            dfs_t(g, flag, p->vertex, visited, finished);
            finished[p->vertex] = 1;
        }
        p = p->next;
    }
}

int dfs_t_main(ALGraph g){
    int flag = 1;
    int visited[g.vexnum] = {0};
    int finished[g.vexnum] = {1};
    int i = 0;
    while(flag == 1 && i < g.vexnum){
        if(visited[i] == 0){
            dfs_t(g, flag, i, visited, finished);
        }
        else{
            i++;
        }
        finished[i] = 1;
    }
    return flag;
}

//题号 1.2
/*
设计一个算法,求出无向图G的连通分量个数,假设题中顶点标号为 1-g.vexnum-1
*/
typedef struct{
    int arcnum, vexnum;
    int edge[maxsize][maxsize];
}MGraph;

int count_num(MGraph g){
    int visited[g.vexnum] = {0};
    int num = 0;
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            dfs_mgraph(g, i, visited);
            num++;
        }
    }
    return num;
}

void dfs_mgraph(MGraph g, int v, int visited[]){
    visited[v] = 1;
    for(int i=0; i<g.vexnum; i++){
        if(g.edge[v][i] != 0 && visited[i] == 0){
            dfs_mgraph(g, i, visited);
        }
    }
}

//题号 1.4
/*
设计一个算法,从入口"0"到出口"6"必须经过食品和财宝的地方,不得经过强盗的点
*/
bool verify_valid(vector<int> v, int a, int b){
    bool v1 = false, v2 = false;
    for(int i=0; i<v.size(); i++){
        if(v[i] == a){
            v1 = true;
        }
        if(v[i] == b){
            v2 = true;
        }
    }
    if(v1 && v2){
        return true;
    }
    return false;
}

void print_path(ALGraph g, int i, int vj, int visited[], vector<int> v, int a, int b, int c){
    if(i == c){
        return;
    }
    else if(i == vj){
        v.push_back(vj);
        if(verify_valid(v, a, b)){
            for(int i=0; i<v.size(); i++){
                printf("%d ", v[i]);
            }
        }
    }
    else{
        v.push_back(i);
        visited[i] = true;
        Arcnode *p = g.vertices[i].first;
        while(p){
            if(visited[p->vertex] = 0){
                print_path(g, p->vertex, vj, visited, v, a, b, c);
            }
        }
        v.pop_back();
        visited[i] = 0;
    }
}

void print_path_main(ALGraph g, int vi, int vj, int a, int b, int c){
    int visited[g.vexnum] = {0};
    vector<int> path;
    print_path(g, vi, vj, visited, path, a, b, c);
}

//题号 1.5
/*
设计一个算法,输出图G中经过某个顶点vi,长度为L的所有环
*/
void print_cycle(ALGraph g, int i, int vi, int l, int visited[], vector<int> v){
    if(i == vi && v.size() == l){
        v.push_back(vi);
        for(int i=0; i<v.size(); i++){
            printf("%d", v[i]);
        }
    }
    else{
        visited[i] = 1;
        v.push_back(i);
        Arcnode *p = g.vertices[i].first;
        while(p){
            if(v.size() > l){
                return;
            }
            if(visited[p->vertex] == 0 || p->vertex == vi){
                print_cycle(g, p->vertex, vi, l, visited, v);
            }
            p = p->next;
        }
        v.pop_back();
        visited[i] = 0;
    }
}

void cycle(ALGraph g, int vi, int vj, int l){
    int visited[g.vexnum] = {0};
    vector<int> v;
    print_cycle(g, vi, vj, l, visited, v);
}

//题号 1.6
/*
假设图采用邻接表存储,编写一个算法,利用深度优先求出无向图中通过给定结点v的所有简单回路
*/

/*
和上一题相同,只是不需要路径长度判定
*/

//题号1.7
/*
设计一个算法创建一个带权的无向图,要求被创建的图由用户输入
输出从v0到其他各点的最短路径长度和路径
*/

MGraph *create_graph(){
    int n;
    cout << "输入节点个数";
    cin >> n;
    MGraph *g = new MGraph();
    if(g == nullptr){
        return nullptr;
    }
    g->vexnum = n;
    int a, b, weight;
    for(int i=0; i<g->vexnum; i++){
        cout << "输入边";
        cin >> a >> b >> weight;
        g->edge[a][b] = g->edge[b][a] = weight;
    }
    return g;
}

void dji(MGraph g, int vi, int visited[], int pre[]){
    int lowcost[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){  //初始化lowcost
        if(g.edge[vi][i] != 0){
            lowcost[i] = g.edge[vi][i];
            pre[i] = vi;
        }
    }
    for(int i=0; i<g.vexnum; i++){
        int min = INT_MAX;
        int index;
        for(int j=0; j<g.vexnum; j++){
            if(visited[j] == 0 && lowcost[j] < min){
                index = j;
                min = lowcost[j];
            }
        }
        visited[index] = 1;
        for(int i=0; i<g.vexnum; i++){
            int dis = lowcost[index] + g.edge[index][i];
            if(dis < lowcost[i]){
                pre[i] = index;
            }
        }
    }
}

void dji_main(int vi){
    MGraph *g = create_graph();
    int visited[g->vexnum] = {0};
    int pre[g->vexnum];
    dji(*g, vi, visited, pre);
    for(int i=0; i<g->vexnum; i++){
        if(i != vi){
            printf("当前节点为: %d", i);
            int k = pre[i];
            while(k != vi){
                printf("%d ",k);
                k = pre[k];
            }
        }
    }
}
