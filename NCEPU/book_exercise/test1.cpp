#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;
#define Elemtype int
#define maxsize 10000

/* 11.3 */

typedef struct treenode{
    struct treenode *left;
    struct treenode *right;
    Elemtype val;
}TreeNode;

// 先序遍历
void pre_order(TreeNode *root){
    if(!root){
        return;
    }
    pre_order(root->left);
    pre_order(root->right);
}

//先序非递归
void pre_order_non(TreeNode *root){
    stack<TreeNode*> s;
    TreeNode *tmp;
    while(!s.empty() || root){
        while(root){
            printf("%d", root->val);
            s.push(root);
            root = root->left;
        }
        tmp = s.top();
        s.pop();
        root = tmp->right;
    }
}

//中序非递归
void inorder_non(TreeNode *root){
    stack<TreeNode*> s;
    TreeNode *tmp;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }
        tmp = s.top();
        printf("%d", tmp->val);
        s.pop();
        root = tmp->right;
    }
}

//后序非递归
void postorder_non(TreeNode *root){
    stack<TreeNode*> s;
    TreeNode *pre = root;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(pre == root->right || root->right == nullptr){
            printf("%d", root->val);
            s.pop();
            pre = root;
            root = nullptr;
        }
        else{
            root = root->right;
        }
    }
}

//层序遍历
void levelorder(TreeNode *root){
    if(!root){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        root = q.front();
        printf("%d", root->val);
        if(root->left){
            q.push(root->left);
        }
        if(root->right){
            q.push(root->right);
        }
        q.pop();
    }
}

//交换子树
void swap_tree(TreeNode *root){
    if(!root){
        return;
    }
    TreeNode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    swap_tree(root->left);
    swap_tree(root->right);
}

//叶子节点的路径
vector<TreeNode*> v;
void print_road(TreeNode *root){
    if(!root){
        return;
    }
    v.push_back(root);
    if(root->left){
        print_road(root->left);
    }
    else if(root->right){
        print_road(root->right);
    }
    else{
        for(int i=0; i<v.size(); i++){
            printf("%d", v[i]->val);
        }
    }
    v.pop_back();
}

//中序递归遍历交换二叉树
TreeNode *swap_tree_inorder(TreeNode *root){
    if(!root){
        return;
    }
    else{
        TreeNode *p, *q;
        p = swap_tree_inorder(root->left);
        q = root->right;
        root->right = p;
        root->left = q;
        q = swap_tree_inorder(root->right);
    }
}

//三叉链表
typedef struct triplenode{
    struct triplenode *parents;
    struct triplenode *left;
    struct triplenode *right;
    Elemtype val;
}Triplenode;

//三叉链表打印路径
void print_triple_road(Triplenode *root){
    if(root){
        printf("%d", root->val);
        root = root->parents;
    }
    else{
        return;
    }
}

void dfs_triple(Triplenode *root){
    if(!root){
        return;
    }
    if(!root->left && !root->right){
        print_triple_road(root);
    }
    if(root->left){
        root->left->parents = root;
    }
    if(root->right){
        root->right->parents = root;
    }
}

void main_triple(Triplenode *root){
    if(!root){
        return;
    }
    root->parents = nullptr;
    dfs_triple(root);
}

//线索二叉树
typedef struct btnode{
    Elemtype val;
    struct btnode *left, *right;
    int ltag, rtag;
}BTNode, *BTTree;

//中序线索化
BTNode *pre = nullptr;
void inorder_thread(BTNode *root){
    if(!root){
        return;
    }
    inorder_thread(root->left);
    //首先链接前驱结点
    if(pre && pre->rtag == 1){
        pre->right = root;
    }
    if(!root->left){
        root->ltag = 1;
        root->left = pre;
    }
    else{
        root->ltag = 0;
    }
    if(!root->right){
        root->rtag = 1;
    }
    else{
        root->rtag = 0;
    }
    pre = root;
    inorder_thread(root->right);
}

//中序线索二叉树遍历
void bttree_iorder(BTTree root){
    BTNode *p = root;
    while(p){
        while(p->ltag == 0){
            p = p->left;
        }
        printf("%d", p->val);
        while(p->rtag == 1){
            p = p->right;
            printf("%d", p->val);
        }
        p = p->right;
    }
}

//前序线索化
void pre_thread(BTTree root){
    if(!root){
        return;
    }
    BTNode *pre = nullptr;
    if(pre && pre->rtag == 1){
        pre->right = root;
    }
    if(root->left){
        root->ltag = 1;
        root->left = pre;
    }
    else{
        root->ltag = 0;
    }
    if(root->right){
        root->rtag = 0;
    }
    else{
        root->rtag = 1;
    }
    pre_thread(root->right);
    pre_thread(root->left);
}

//前序线索遍历
void pre_thread_order(BTTree root){
    if(!root){
        return;
    }
    BTNode *p = root;
    while(p){
        while(p->ltag == 0){
            printf("%d", p->val);
            p = p->left;
        }
        printf("%d", p->val);
        p = p->right;
    }
}

//图算法
//邻接矩阵结构
typedef struct MGraph{
    int edge[maxsize][maxsize];
    Elemtype vex[maxsize];
    int vexnum, arcnum;
};

//邻接表
typedef struct arcnode{
    int vertex;
    struct arcnode *next;
};
typedef struct vnode{
    Elemtype val;
    arcnode *first;
}vnode, adjlist[maxsize];
typedef struct{
    int vexnum,arcnum;
    adjlist vertices;
}ALGraph;

//单源最短路径-dijkstra
void dijkstra(MGraph g, int v){
    bool visited[maxsize] = {false};
    int dis[g.vexnum] = {0};
    int mins;
    for(int i=0; i<g.vexnum; i++){
        dis[i] = g.edge[v][i];
    }
    for(int i=0; i<g.vexnum; i++){  //i层迭代
        mins = INT_MAX;
        int k;
        for(int j=0; j<g.vexnum; j++){
            if(dis[j] < mins){
                mins = dis[j];
                k = j;
            }
        }
        visited[k] = true;
        for(int j=0; j<g.vexnum; j++){
            if(!visited[j] && g.edge[k][j] != INT_MAX){
                dis[j] = min(dis[k] + g.edge[k][j], dis[j]);
            }
        }
    }
}

//多源最短路径floyd
void floyd(MGraph g){
    for(int i=0; i<g.vexnum; i++){
        for(int j=0; j<g.vexnum; j++){
            for(int k=0; k<g.vexnum; k++){
                g.edge[i][j] = min(g.edge[i][k] + g.edge[k][j], g.edge[i][j]);
            }
        }
    }
}

//最小生成树
typedef struct {
    int vi, vj;
    int weight;
}lowcost;

void prim(MGraph g){
    lowcost *lowest = new lowcost[g.vexnum];
    for(int i=0; i<g.vexnum; i++){
        lowest[i].weight = g.edge[0][i];
        lowest[i].vi = 0;
        lowest[i].vj - i;
    }
    lowest[0].weight = 0;
    int mins;
    int k;
    for(int i=0; i<g.vexnum; i++){
        mins = INT_MAX;
        for(int j=0; j<g.vexnum; j++){
            if(lowest[j].weight < mins){
                mins = lowest[j].weight;
                k = j;
            }
        }
        lowest[k].weight = 0;
        for(int j=0; j<g.vexnum; j++){
            if(lowest[j].weight > g.edge[k][j]){
                lowest[j].weight = g.edge[k][j];
                lowest[j].vi = k;
            }
        }
    }
}

//邻接矩阵的dfs递归
void MGraph_dfs(MGraph g, int v, int visited[]){
    visited[v] = 1;
    printf("%d", g.vex[v]);
    for(int i=0; i<g.vexnum; i++){
        if(g.edge[v][i] != 0 && visited[i] == 0){
            MGraph_dfs(g, i, visited);
        }
    }
}

void MGraph_dfs_main(MGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            MGraph_dfs(g, i, visited);
        }
    }
}

//邻接表dfs递归
void ALGraph_dfs(ALGraph g, int v, int visited[]){
    visited[v] = 1;
    printf("%d", g.vertices[v].val);
    arcnode *p = g.vertices[v].first;
    while(p){
        if(visited[p->vertex] == 0){
            ALGraph_dfs(g, g.vertices[p->vertex].val, visited);
        }
    }
}

void ALGraph_dfs_main(ALGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            ALGraph_dfs(g, i, visited);
        }
    }
}

//邻接矩阵dfs-非递归
void MGraph_dfs_non(MGraph g, int v, int visited[]){
    printf("%d", g.vex[v]);
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int p = s.top();
        for(int i=0; i<g.vexnum; i++){
            if(g.edge[v][i] !=0 && visited[i] == 0){
                printf("%d", g.vex[i]);
                s.push(i);
                visited[i] = 1;
                break;
            }
            if(i == g.vexnum-1){
                s.pop();
            }
        }
    }
}

void MGraph_dfs_non_main(MGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            MGraph_dfs_non(g, i, visited);
        }
    }
}

//邻接表-dfs-非递归
void ALGraph_dfs_non(ALGraph g, int v, int visited[]){
    stack<int> s;
    s.push(v);
    printf("%d", g.vertices[v].val);
    visited[v] = 1;
    while(!s.empty()){
        arcnode *p = g.vertices[v].first;
        while(p){
            if(visited[p->vertex] == 0){
                visited[p->vertex] = 1;
                s.push(p->vertex);
                printf("%d", g.vertices[p->vertex].val);
                p = g.vertices[p->vertex].first;
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

void ALGraph_dfs_non_main(ALGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            ALGraph_dfs_non(g, i, visited);
        }
    }
}

//bfs_邻接矩阵
void bfs_MGraph(MGraph g, int v, int visited[]){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int p = q.front();
        printf("%d", g.vex[p]);
        q.pop();
        visited[v] = 1;
        for(int i=0; i<g.vexnum; i++){
            if(visited[i] == 0 && g.edge[v][i]!=0){
                q.push(i);
            }
        }
    }
}

void bfs_MGraph_main(MGraph g){
    int visited[g.vexnum] = {0};
    for(int i=0; i<g.vexnum; i++){
        if(visited[i] == 0){
            bfs_MGraph(g, i, visited);
        }
    }
}

//bfs_邻接表
void bfs_ALGraph(ALGraph g, int v, int visited[]){
    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int t = q.front();
        printf("%d", g.vertices[t].val);
        q.pop();
        visited[t] = 1;
        arcnode *p = g.vertices[t].first;
        while(p){
            if(visited[p->vertex] == 0){
                q.push(p->vertex);
            }
            p = p->next;
        }
    }
}

/* 11.4 */