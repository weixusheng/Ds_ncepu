#include <iostream>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>

using namespace std;

#define maxsize 1000

//线性表
typedef struct{
    int length;
    int data[maxsize];
}sqlist;

//链表结构
typedef struct node{
    struct node *next;
    int val;
}list;

/*测试free*/

list *makelist(vector<int> v){
    list *res = new list();
    list *p = nullptr;
    for(auto i = v.begin(); i!=v.end(); i++){
        list *n = new list();
        n->val = *i;
        if(p == nullptr){
            p = n;
            res->next = p;
        }
        else{
            p->next = n;
            p = n;
        }
    }
    p->next = nullptr;
    return res->next;
}

int main(){
    vector<int> v = {1,2,3,4,5,4,6};
    list *a = makelist(v);
    list *ft,*q,*p = a;
    q = p->next;
    while (q)
    {
        if(q->val == 4){
            p->next = q->next;
            ft = q;
            q = q->next;
            free(ft);
        }
        else{
            p = q;
            q = q->next;
        }
    }
    p = a;
    while(p){
        printf("%d ",p->val);
        p = p->next;
    }
    system("pause");
}

//逆转链表
void reverse_list(list *l){
    if(l->next == nullptr) return;
    list *r = nullptr;
    list *p = l->next;
    list *q = l;
    while(p){
        q = p;
        p = p->next;
        q->next = r;
        r = q;
    }
    l->next = q;
}

//删除链表中的特定元素(没有头结点)
void delete_node(list *l, int x){
    list *q,*p = l;
    list *tmp;
    q = p->next;
    while(q){
        if(q->val == x){
            p->next = q->next;
            tmp = q;
            q = q->next;
            free(tmp);
        }
        else{
            q = p;
            p = p->next;
        }
    }
    if(l->val == x){
        tmp = l;
        l = l->next;
        free(tmp);
    }
}

//逆转顺序表
void reverse(int a[], int n){
    int mid = n/2;
    int tmp;
    for(int i=0; i<mid; i++){
        tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }
}

//复制链表(递归)
list *copy(list *l){
    list *res;
    if(l == nullptr) return nullptr;
    res = new list();
    res->val = l->val;
    res->next = copy(l->next);
    return res;
}

//两个递增链表合并
list *merge_list(list *a, list *b){
    list *res = new list();
    list *tmp = res;
    while(a && b){
        if(a->val <= b->val){
            tmp->next = a;
            a = a->next;
        }
        else{
            tmp->next = b;
            b = b->next;
        }
    }
    if(a){
        tmp->next = a;
    }
    else{
        tmp->next = b;
    }
    tmp->next = nullptr;
    return res->next;
}

//二叉树
typedef struct BTnode{
    struct BTnode *left;
    struct BTnode *right;
    int val;
}btnode;

//中序遍历
void inorder(btnode *root){
    if(!root) return;
    inorder(root->left);
    printf("%d", root->val);
    inorder(root->right);
}

//前序非递归
void non_preorder(btnode *root){
    if(!root) return;
    stack<btnode*> s;
    btnode *tmp;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            printf("%d", root->val);
            root = root->left;
        }
        tmp = s.top();
        s.pop();
        root = tmp->right;
    }
}

//中序非递归
void non_inorder(btnode *root){
    if(!root) return;
    stack<btnode*> s;
    btnode *tmp;
    while(!s.empty() || root){
        while(root){
            root = root->left;
            s.push(root);
        }
        tmp = s.top();
        printf("%d", tmp->val);
        s.pop();
        root = tmp->right;
    }
}

//后序非递归
void non_postorder(btnode *root){
    stack<btnode*> s;
    btnode *tmp;
    btnode *pre = nullptr;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(root->right == pre || root->right == nullptr){
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

//二叉树线索化
typedef struct node{
    int ratg, ltag;
    struct node *left;
    struct node *right;
    int val;
}bttree;

bttree *pre = nullptr;
void makebtt(bttree *root){
    if(!root) return;
    if(pre && pre->ratg == 1){
        pre->right = root;
    }
    if(!root->left){
        root->ratg = 1;
        root->left = pre;
    }
    else{
        root->ltag = 0;
    }
    if(!root->right){
        root->ratg = 1;
    }
    else{
        root->ratg = 0;
    }
    pre = root;
    makebtt(root->left);
    makebtt(root->right);
}

//前序遍历线索二叉
void preorder_thread(bttree *root){
    if(!root) return;
    while(root){
        while(root->ltag == 0){
            printf("%d", root->val);
            root = root->left;
        }
        printf("%d", root->val);
        root = root->right;
    }
}

//中序遍历线索二叉
void inorder_thread(bttree *root){
    if(!root) return;
    while(root){
        while(root->ltag == 0){
            root = root->left;
        }
        printf("%d", root->val);
        while(root->ratg == 1){
            root = root->right;
            printf("%d", root->val);
        }
        root = root->right;
    }
}