#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;
#define Elemtype int
#define maxsize 10000

//树的结构
typedef struct tnode{
    struct tnode *left;
    struct tnode *right;
    Elemtype val;
}Treenode;

//先序访问(递归)
void preorder(Treenode *root){
    if(!root){
        return;
    }
    printf("%d", root->val);
    preorder(root->left);
    preorder(root->right);
}

//先序遍历非递归
void nonrecursive_preorder(Treenode *root){
    stack<Treenode*> s;
    Treenode *tmp;
    while(!s.empty() || root){
        while(root){
            printf("%d", root->val);    //在节点左移过程中输出
            s.push(root);
            root = root->left;
        }
        tmp = s.top();
        s.pop();
        root = tmp->right;
    }
}

//中序递归
void inorder(Treenode *root){
    if(!root){
        return;
    }
    inorder(root->left);
    printf("%d", root->val);
    inorder(root->right);
}

//中序非递归
void nonrecursive_inorder(Treenode *root){
    stack<Treenode*> s;
    Treenode *tmp;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }
        tmp = s.top();  //while后输出
        printf("%d", tmp->val);
        s.pop();
        root = tmp->right;
    }
}

//后序递归
void postorder(Treenode *root){
    if(!root){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d",root->val);
}

//后序非递归
void nonrecursive_postorder(Treenode *root){
    Treenode *pre = root;
    stack<Treenode*> s;
    while(!s.empty() || root){
        while(root){
            s.push(root);
            root = root->left;
        }
        root = s.top();
        if(root->right == nullptr || root->right == pre){
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
void levleorder(Treenode *root){
    if(!root){
        return;
    }
    queue<Treenode*> q;
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

//设计一个算法,交换二叉树的所有节点的左右子树
//前序递归和后序递归不需要多考虑,但是中序递归需要注意
void swap_child(Treenode *root){
    if(!root){
        return;
    }
    swap_child(root->left);
    Treenode *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    swap_child(root->right);
}

/*
交换二叉树的左右子树可采用先序遍历，中序遍历，后序遍历完成。先序与后序不需要考虑太多，简单交换即可。
中序遍历要考虑到，若左子树已经交换过了，那么左右一交换
原来的左变为右了，原来的右子树变为左子树，而新的左子树是没有进行交换过的。
*/
//中序递归交换左右子树
Treenode* exchange_rootMiddle(Treenode* T)
{
    if(!T){
        return nullptr;
    }
    if(T->left!=NULL||T->right!=NULL)
    {
        Treenode *p,*q;
        p = exchange_rootMiddle(T->left);
        q = T->right;
        T->right = p;
        T->left = q;
        q = exchange_rootMiddle(T->right);
    }
    return T;
}

//二叉树采用三叉链表存储结构,设计一个算法输出二叉树从根节点到所有叶子节点的路径
typedef struct triple_tree{
    struct triple_tree *parent;
    struct triple_tree *left;
    struct triple_tree *right;
    Elemtype val;
}triple_tree;

void print_road(triple_tree *root){
    if(!root){
        return;
    }
    printf("%d", root->val);
    print_road(root->parent);
}

void dfs_road(triple_tree *root){
    if(!root){
        return;
    }
    if(root->left == nullptr && root->right == nullptr){
        print_road(root);
    }
    if(root->left){
        root->left->parent = root;
        dfs_road(root->left);
    }
    if(root->right){
        root->right->parent = root;
        dfs_road(root->right);
    }
}

void recursive_road(triple_tree *root){
    if(!root){
        return;
    }
    root->parent = nullptr;
    dfs_road(root);
}

//三叉树链表打印路径 非递归
void dfs_nonrecursive(triple_tree *root){
    stack<triple_tree*> s;
    triple_tree *tmp;
    while(root || !s.empty()){
        while(root){
            s.push(root);
            if(root->left == nullptr && root->right == nullptr){
                print_road(root);
            }
            else if(root->left){
                root->left->parent = root;
            }
            else if(root->right){
                root->right->parent = root;
            }
            root == root->left;
        }
        tmp = s.top();
        s.pop();
        root = tmp->right;
    }
}

//线索二叉树
typedef struct BTNode{
    Elemtype val;
    struct BTNode *left, *right;
    int ltag, rtag;
}BTNode, *BTTree;

//二叉树的中序线索化
BTNode *pre = nullptr;
void inorder_thread(BTTree t){
    if(!t){
        return;
    }
    inorder_thread(t->left);
    //前驱结点-线索
    if(pre && pre->rtag == 1){
        pre->right = t;
    }
    //当前结点-线索
    //左
    if(!t->left){
        t->left = pre;
        t->ltag = 1;
    }
    else{
        t->ltag = 0;
    }
    //右
    if(!t->right){
        t->rtag = 1;
    }
    else{
        t->rtag = 0;
    }
    pre = t;
    inorder_thread(t->right);
}

//中序线索二叉树的遍历-新款
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

//中序线索二叉树的遍历-老款复杂
void bttree_inorder2(BTTree t){
    if(!t){
        return;
    }
    BTNode *p = t;
    while(p->ltag == 0){
        p = p->left;
    }
    while(p){
        printf("%d", p->val);
        if(p->rtag == 1){
            p = p->right;
        }
        else{
            p = p->right;
            while(p->ltag == 0){
                p = p->left;
            }
        }
    }
}

//线索二叉树前序线索化
BTTree pre = nullptr;
void preorder_thread(BTTree t){
    if(!t){
        return;
    }
    if(pre && pre->rtag == 1){
        pre->left = t;
    }
    if(!t->left){
        t->left = pre;
        t->ltag = 1;
    }
    else{
        t->ltag = 0;
    }
    if(!t->right){
        t->rtag = 1;
    }
    else{
        t->rtag = 0;
    }
    pre = t;
    preorder_thread(t->left);
    preorder_thread(t->right);
}


//前序线索遍历-新版
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

//前序线索二叉树-旧版复杂
void bttree_preorder(BTTree t){
    if(!t){
        return;
    }
    BTNode *p = t;
    while(p){
        printf("%d", p->val);
        if(p->rtag == 1){
            p = p->right;
        }
        else{
            if(p->ltag == 0){
                p = p->left;
            }
            else{
                p = p->right;
            }
        }
    }
}