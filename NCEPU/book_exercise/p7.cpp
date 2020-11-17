#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;

typedef struct tnode{
    struct tnode *left, *right;
    int val;
}TNode;

//题号 6.6
/*
设二叉树采用链式存储结构,试设计一个算法计算一棵给定二叉树中单孩子结点的数量
*/
int num = 0;
int childnum(TNode *root){
    if(root == nullptr){
        return 0;
    }
    if(root->left == nullptr && root->right){
        num++;
    }
    else if(root->right == nullptr && root->left){
        num++;
    }
    childnum(root->left);
    childnum(root->right);
}

//题号 6.7
/*
设t指向二叉树根节点的指针,试求二叉树中某节点p的双亲结点
*/
TNode *get_father(TNode *root, TNode *p){
    if(root == nullptr){
        return nullptr;
    }
    if(root->left ==  p || root->right == p){
        return root;
    }
    else
    {
        TNode *r =  get_father(root->right, p);
        TNode *l = get_father(root->left, p);
        if(r){
            return r;
        }
        if(l){
            return l;
        }
    }
    return nullptr;
}

//图

#define maxsize 1000
//邻接矩阵
typedef struct {
    int edges[maxsize][maxsize];
    int vertex[maxsize];
    int vexnum, arcnum;
}MGraph;

//邻接表
typedef struct arcnode{
    int vertex;
    struct arcnode *next;
}Arcnode;

typedef struct{
    int val;
    Arcnode *first;
}vnode, adjlist[maxsize];

typedef struct{
    adjlist vertices;
    int arcnum, vexnum;
}ALGraph;

//题号 图-2.1
/*
编写一个算法,将一个无环图的邻接矩阵转换为邻接表
*/

void convert_ma(MGraph g1, ALGraph &g2){
    for(int i=0; i<g1.vexnum; i++){
        g2.vertices[i].val = g1.vertex[i];
        g2.vertices[i].first = nullptr;
    }
    for(int i=0; i<g1.vexnum; i++){
        for(int j=0; j<g1.vexnum; j++){
            if(g1.edges[i][j] != 0){    //存在边
                if(g2.vertices[i].first == nullptr){
                    Arcnode *n = new Arcnode();
                    n->vertex = j;
                    n->next = nullptr;
                }
                else{
                    Arcnode *p = g2.vertices[i].first;
                    while(p){
                        p = p->next;
                    }
                    Arcnode *n = new Arcnode();
                    n->vertex = j;
                    p->next = n;
                    n->next = nullptr;
                }
            }
        }
    }
    g2.vexnum = g1.vexnum;
    g2.arcnum = g1.arcnum;
}

//题号 图-2.2
/*
设计一个算法,判断无向图G是否连通,若连同,则返回1,否则返回0,假设途中顶点标号从 0-g.vexnum-1
*/
int bfs_mgraph(MGraph g){
    int visited[g.vexnum] = {0};
    queue<int> q;
    q.push(0);
    while(!q.empty()){
        int tmp = q.front();
        q.pop();
        for(int i=0; i<g.vexnum; i++){
            if(g.edges[tmp][i] != 0){
                if(visited[i] == 0){
                    visited[i] = 1;
                    q.push(i);
                }
            }
        }
    }
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            return 0;
        }
    }
    return 1;
}

//题号 2.3
/*
设计一个算法,输出G中从顶点 vi 到 vj 的长度为L的所有路径
*/
typedef struct{
    vector<int> v;
    int sum;
}path;

void get_path(MGraph g, int vi, int vj, int L){
    path *p = new path();
    p->sum = 0;
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        int tmp = g.edges[vi][i];
        if(tmp != 0){
            dfs_path(g, vj, L, vi, p, visited,tmp);
        }
    }
}

void dfs_path(MGraph g, int vj, int l, int k, path *p, int visited[], int sum){
    visited[k] = 1;
    p->v.push_back(k);
    for(int i=0; i<g.vexnum; i++){
        if(g.edges[k][i] != 0 && visited[i] == 0){
            sum += g.edges[k][i];
            if(sum == l && i == vj){
                for(int i=0; i<p->v.size(); i++){
                    printf("%d", p->v[i]);
                }
            }
            else if(sum < l){
                dfs_path(g,vj,l,i,p,visited,sum);
            }
        }
        sum -= g.edges[k][i];
    }
    p->v.pop_back();
    visited[k] = 0;
}

// 题号 2.4
/*
编写一个实现连通图G的深度优先搜索的非递归函数
*/
//邻接矩阵
void dfs_main(MGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        dfs_non(g, i, visited);
    }
}

void dfs_non(MGraph g, int i, int visited[]){
    if(visited[i] == 1){
        return;
    }
    stack<int> s;
    s.push(i);
    int tmp;
    while(!s.empty()){
        tmp = s.top();
        printf("%d", g.vertex[tmp]);
        visited[tmp] = 1;
        s.pop();
        for(int i=0; i<g.vexnum; i++){
            if(g.edges[tmp][i] != 0 && visited[i] == 0){
                s.push(i);
                break;
            }
            if(i == g.vexnum-1){
                s.pop();
            }
        }
    }
}

//邻接表
void dfs_non_list(ALGraph g, int i, int visited[]){
    stack<int> s;
    s.push(i);
    int tmp;
    while(!s.empty()){
        tmp = s.top();
        printf("%d", g.vertices[tmp].val);
        visited[tmp] = 1;
        Arcnode *p = g.vertices[tmp].first;
        while(p){
            if(visited[p->vertex] == 0){
                s.push(p->vertex);
                break;
            }
            else{
                p = p->next;
            }
            if(p == nullptr){
                s.pop();
            }
        }
    }
}

void dfs_main_list(ALGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            dfs_non_list(g, i, visited);
        }
    }
}