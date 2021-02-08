#include<iostream>
#include<cstdlib>
#include<queue>
#include<stack>

using namespace std;

typedef struct node //单链表
{
    struct node *next;
    int val;
}link_list;

typedef struct {    //线性表
    int *data;
    int length;
}list;

//单链表逆置
void reverse_link(link_list *l){
    link_list *p = l, *q = l->next;
    link_list *r = nullptr;
    while(q){
        q->next = r;
        q = q->next;
        r = p;
        p = q;
    }
    l->next = q;
}

//删除链表中特定的元素
void delete_link(link_list *l, int val){
    link_list *p = l->next;
    link_list *pre = l;
    link_list *tmp;
    while (p)
    {
        if(p->val == val){
            pre->next = p->next;
            tmp = p;
            p = p->next;
            free(tmp);
        }
        else{
            pre = p;
            p = p->next;
        }
    }
}

//逆转线性表
void reverse_list(list *l){
    int len = l->length;
    int tmp;
    for(int i=0; i<len/2; i++){
        tmp = l->data[i];
        l->data[i] = l->data[len-i-1];
        l->data[len-i-1] = tmp;
    }
}

//非空递增单链表合并
link_list *merge(link_list *a, link_list *b){
    link_list *p1 = a;
    link_list *l1 = a->next;
    link_list *l2 = b->next;
    link_list *tmp;
    while (l1 && l2)
    {
        if(l1->val < l2->val){
            tmp = l2;
            l2 = l2->next;
            p1->next = tmp;
            tmp->next = l1;
            p1 = l1;
            l1 = l1->next;
        }
        else{
            l2 = l2->next;
        }
    }
    if(l2){
        l1->next = l2;
    }
    return a;
}

//二叉树
typedef struct node{
    struct node *left;
    struct node *right;
    int val;
}btnode;

//前序遍历-递归
void preorder(btnode *root){
    if(!root) return;
    printf("%d", root->val);
    preorder(root->left);
    preorder(root->right);
}

//前序遍历-非递归
void preotder_non(btnode *root){
    if(!root) return;
    stack<btnode*> s;
    s.push(root);
    while(!s.empty())
    {
        while(root)
        {
            printf("%d", root->val);
            root = root->left;
            s.push(root);
        }
        root = s.top();
        s.pop();
        root = root->right;        
    }
}

//中序遍历-非递归
void inorder_non(btnode *root){
    if(!root) return;
    stack<btnode*> s;
    while (!s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        printf("%d", root->val);
        s.pop();
        root = root->right;
    }
}

//后序遍历-非递归
void postorder_non(btnode *root){
    if(!root) return;
    stack<btnode*> s;
    btnode *pre = root;
    while (!s.empty())
    {
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(root->right == pre || root->right == nullptr){
            printf("%d", root->val);
            pre = root;
            s.pop();
            root = nullptr;
        }
        else{
            root = root->right;
        }
    }
}

//层序遍历
void level_order(btnode *root){
    if(!root) return;
    queue<btnode*> q;
    btnode *tmp;
    q.push(root);
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        printf("%d", tmp->val);
        if(tmp->left) q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
}

//求树的深度
int getdeep(btnode *root){
    if(!root) return 0;
    int l = getdeep(root->left);
    int r = getdeep(root->right);
    return max(l,r)+1;
}
int getdeep_main(btnode *root){
    int  res = getdeep(root);
    return res;
}

//求结点所在的层数
int getlevel(btnode *root, int x, int level){
    if(!root) return -1;
    int l,r;
    if(root->val != x){
        l = getlevel(root->left, x, level+1);
        r = getlevel(root->right, x, level+1);
    }
    else{
        return level;
    }
    if(l || r){
        if(l != -1) return l;
        else{
            return r;
        }
    }
    else{
        return -1;
    }
}

int getlevel_main(btnode *root, int x){
    int res = getlevel(root, x, 0);
    return res;
}

//交换左右子树
void swap_tree(btnode *root){
    if(!root) return;
    swap_tree(root->left);
    swap_tree(root->right);
    btnode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}

//二叉树删除一个节点开始的二叉树
void des(btnode *root){
    if(!root) return;
    des(root->left);
    des(root->right);
    free(root);
}
void delete_tree(btnode *root, int x){
    if(!root) return;
    if(root->left->val == x){
        des(root->left);
    }
    if(root->right->val == x){
        des(root->right);
    }
    delete_tree(root->left, x);
    delete_tree(root->right, x);
}

//邻接矩阵
#define maxsize 1000
typedef struct{
    int edges[maxsize][maxsize];
    int arcnum;
    int vexnum;
    int vex[maxsize];
}MGraph;

//邻接表
typedef struct arcnode{
    struct arcnode *next;
    int adjvex;
}arcnode;

typedef struct {
    int val;
    arcnode *first;
}vnode, adjlist[maxsize];

typedef struct {
    adjlist vertices;
    int arcnum;
    int vexnum;
}ALGraph;

//深度优先dfs- 邻接矩阵
void dfs(MGraph g, int v, int visited[]){
    visited[v] = 1;
    printf("%d", g.vex[v]);
    for(int i=0; i<g.vexnum; i++){
        if(g.edges[v][i] != 0 && visited[i] == 0){
            dfs(g, i, visited);
        }
    }
}

//dfs-邻接矩阵-非递归
void dfs_non(MGraph g, int v){
    int visited[g.vexnum] = {0};
    stack<int> s;
    s.push(v);
    while(!s.empty()){
        for(int i=0; i<g.vexnum; i++){
            if(visited[i] != 0 && g.edges[v][i] != 0){
                s.push(i);
                printf("%d", i);
                break;
            }
            if(i == g.vexnum-1){
                s.pop();
            }
        }
    }
}

//bfs-邻接矩阵
void bfs(MGraph g, int v){
    int visited[g.vexnum] = {0};
    queue<int> q;
    q.push(v);
    int tmp;
    while(!q.empty()){
        tmp = q.front();
        q.pop();
        printf("%d", tmp);
        visited[tmp] = 1;
        for(int i=0; i<g.vexnum; i++){
            if(g.edges[v][i] != 0 && visited[i] == 0){
                q.push(tmp);
            }
        }
    }
}

//dfs-邻接表-递归
void dfs2(ALGraph g, int v, int visited[]){
    visited[v] = 1;
    printf("%d", v);
    arcnode *p = g.vertices[v].first;
    while(p){
        if(visited[p->adjvex] == 0){
            dfs2(g, p->adjvex, visited);
        }
        p = p->next;
    }
}

//dfs-邻接表-非递归
void dfs2_non(ALGraph g, int v){
    int visited[maxsize] = {0};
    stack<int> s;
    s.push(v);
    arcnode *p;
    while (!s.empty())
    {
        p = g.vertices[s.top()].first;
        if(visited[p->adjvex] == 0){
            s.push(p->adjvex);
            printf("%d", g.vertices[p->adjvex].val);
            break;
        }
        p = p->next;
        if(p == nullptr){
            s.pop();
        }
    }
}

//bfs-邻接表
void bfs2(ALGraph g, int v){
    int visited[g.vexnum] = {0};
    queue<int> q;
    int tmp;
    q.push(v);
    visited[v] = 1;
    while (!q.empty())
    {
        tmp = q.front();
        q.pop();
        printf("%d", tmp);
        arcnode *p = g.vertices[tmp].first;
        while(p){
            q.push(p->adjvex);
        }
    }
}

