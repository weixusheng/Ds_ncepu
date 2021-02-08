#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;

#define maxsize 1000

typedef struct{
    int vexnum, arcnum;
    int edge[maxsize][maxsize];
    int vex[maxsize];
}MGraph;

typedef struct arcnode{
    struct arcnode *next;
    int adjvex;
    int weight;
}Arcnode;

typedef struct {
    arcnode *first;
    int val;
}vnode, adjlist[maxsize];

typedef struct{
    adjlist vertices;
    int arcnum;
    int vexnum;
}ALGraph;

//题号 1
/*
已知一具有n个顶点的无向图G采用邻接表存储,写一个算法,删除图中数据信息为item的结点
*/
void delete_node(ALGraph &g, int x){
    //循环删除结点数组
    int k = -1;
    for(int i=0; i<g.vexnum; i++){  //找到删除节点位置
        if(g.vertices[i].val == x){
            k = i;
        }
    }
    if(k == -1){
        return;
    }
    arcnode *p = g.vertices[k].first, *q;
    for(int i=k; i<g.vexnum-1; i++){    //移动 vertices 中的元素
        g.vertices[i].val = g.vertices[i+1].val;
        g.vertices[i].first = g.vertices[i+1].first;
    }
    g.vexnum -= 1;
    while(p){   //删除结点对应的链队
        q = p;
        p = p->next;
        delete(q);
    }
    arcnode *r;
    for(int i=0; i<g.vexnum; i++){
        p = g.vertices[i].first;
        if(p->adjvex == k){
            if(g.vertices[i].first == p){
                g.vertices[i].first = p->next;
            }
            else{
                q->next = p->next;
            }
            //统一删除
            r = p;
            p = p->next;
            delete(r);
        }
        else{
            q = p;
            if(p->adjvex > k){  //只移动 k 之后的结点
                p->adjvex -= 1;
            }
            p = p->next;
        }
    }
}

//题号 2
/*
设图采用邻接矩阵,写出图的深度优先和广度优先
*/
void dfs_mgraph(MGraph g, int v, int visited[]){
    visited[v] = 1;
    printf("%d",g.vex[v]);
    for(int i=0; i<g.vexnum; i++){
        if(g.edge[v][i] != 0 && visited[i] == 0){
            dfs_mgraph(g, i, visited);
        }
    }
}

void dfs_mgraph_non(MGraph g, int v, int visited[]){
    stack<int> s;
    s.push(v);
    int tmp;
    while(!s.empty()){
        tmp = s.top();
        printf("%d", g.vex[tmp]);
        visited[tmp] = 1;
        for(int i=0; i<g.vexnum; i++){
            if(g.edge[tmp][i] != 0 && visited[i] == 0){
                s.push(i);
                break;
            }
            if(i == g.vexnum-1){
                s.pop();
            }
        }
    }
}

void dfs_main(MGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            dfs_mgraph(g, i, visited);
        }
    }
}

void bfs_mgraph(MGraph g, int v, int visited[]){
    queue<int> q;
    q.push(v);
    int tmp;
    while(!q.empty()){
        tmp = q.front();
        printf("%d", g.vex[tmp]);
        visited[tmp] = 1;
        q.pop();
        for(int i=0; i<g.vexnum; i++){
            if(g.edge[tmp][i] != 0 && visited[i] == 0){
                q.push(i);
            }
        }
    }
}

//题号 3
/*
编写一个算法,找出在邻接表方式存储的图G中,顶点i到顶点j的不含回路的长度为m的路径数,并输出各个路径
*/
vector<int> path;
int sum = 0;
void find_path(ALGraph g, int v, int j, int m, int visited[]){
    path.push_back(v);
    visited[v] = 1;
    if(v == j && path.size() == m){
        ++sum;
        for(int i=0; i<path.size(); i++){
            printf("%d", path[i]);
        }
    }
    else if(path.size() < m){
        arcnode *p = g.vertices[v].first;
        while(p){
            if(visited[p->adjvex] == 0){
                find_path(g, v, j, m, visited);
            }
            else{
                p = p->next;
            }
        }
    }
    path.pop_back();
    visited[v] = 0;
}

//题号 4
/*
以邻接表为存储结构,实现从源点vo到其余各点的最短距离
*/
void dijkstra_algraph(ALGraph g, int v0){
    int visited[g.vexnum] = {0};
    int lowcost[g.vexnum];
    for(int i=0; i<g.vexnum; i++){
        lowcost[i] = INT_MAX;
    }
    arcnode *p = g.vertices[v0].first;
    visited[v0] = 1;
    while(p){
        lowcost[p->adjvex] = p->weight;
        p = p->next;
    }
    int k;
    int maxl;
    for(int i=0; i<g.vexnum; i++){  //n次迭代
        k = -1;
        maxl = INT_MAX;
        for(int i=0; i<g.vexnum; i++){
            if(lowcost[i] < maxl && visited[i] == 0){
                maxl = i;
                k = lowcost[i];
            }
        }
        if(k == -1){
            return;
        }
        visited[k] = 1;
        p = g.vertices[k].first;
        int tmp;
        while(p){
            tmp = p->weight + lowcost[k];
            if(lowcost[p->adjvex] < tmp){
                lowcost[p->adjvex] = tmp;
            }
            p = p->next;
        }
    }
}