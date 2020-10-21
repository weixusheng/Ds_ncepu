/*
根据树的 前序 中序 构造二叉树
*/
#include<vector>
#include<iostream>
#include<queue>

using namespace std;

vector<int> pre;
vector<int> in;

struct treenode{
    treenode* left;
    treenode* right;
    int data;
};

treenode* buildtree(vector<int> pre, vector<int> in, int p1,int p2, int i1, int i2){
    if(p1>p2 || i1>i2){ //越界返回
        return NULL;
    }
    treenode *root = new treenode();    //新建节点
    root->data = pre[p1];   //赋值当前根节点
    int leftlen = 0;    //查找左子树元素数量
    for(int i=i1; i<=i2; i++){
        if(pre[p1] == in[i]){
            leftlen = i-i1; //直到查找到根节点的位置
            break;
        }
    }
    root->left = buildtree(pre, in, p1+1, p1+leftlen, i1, i1+leftlen-1);
    root->right = buildtree(pre, in, p1+leftlen+1, p2, i1+leftlen+1, i2);
    return root;
}

vector<int> shit;

void levelorder(treenode* root){
    queue<treenode*> q;
    if(root == NULL){
        return;
    }
    q.push(root);
    while(!q.empty()){
        treenode* tmp = q.front();
        q.pop();
        shit.push_back(tmp->data);
        if(tmp->left != NULL){
            q.push(tmp->left);
        }
        if(tmp->right != NULL){
            q.push(tmp->right);
        }
    }
}

int main(int argc, char const *argv[])
{
    int n;
    int tmp;
    cin >> n;
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        pre.push_back(tmp);
    }
    for(int i=0; i<n; i++){
        scanf("%d", &tmp);
        in.push_back(tmp);
    }
    treenode* root = new treenode();
    root = buildtree(pre, in, 0, pre.size()-1, 0, in.size()-1);
    levelorder(root);
    for(int i=0; i<shit.size(); i++){
        printf("%d\n", shit[i]);
    }
    return 0;
}
