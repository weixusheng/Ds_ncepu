#include<iostream>
#include<vector>

using namespace std;

struct node{
    int data;
    node *left, *right;
};

void insert(node* &root, int data){
    if(root == NULL){
        root = new node;
        root->data = data;
        root->left = root->right = NULL;
        return;
    }
    if(data < root->data){
        insert(root->left, data);
    }
    else{
        insert(root->right, data);
    }
}

void preorder(node* root, vector<int> &vi){
    if(root == NULL){
        return;
    }
    vi.push_back(root->data);
    preorder(root->left, vi);
    preorder(root->right, vi);
}

void preorder_mirro(node* root, vector<int> &vi){
    if(root == NULL){
        return;
    }
    vi.push_back(root->data);
    preorder_mirro(root->right, vi);
    preorder_mirro(root->left, vi);
}

/*
首先对于二叉树类型题,首先要建树,这样方便分析.如果单纯分析遍历序列,就会无从下手
本题要求镜像二叉搜索树,因此需要反过来进行左右树访问
*/
void posterorder(node* &root, vector<int> &vi){
    if(root == NULL){
        return;
    }
    posterorder(root->left, vi);
    posterorder(root->right, vi);
    vi.push_back(root->data);
}

void posterorder_mirro(node* &root, vector<int> &vi){
    if(root == NULL){
        return;
    }
    posterorder_mirro(root->right, vi);
    posterorder_mirro(root->left, vi);
    vi.push_back(root->data);
}

vector<int> origin, pre, prem, post, postm;

int main(int argc, char const *argv[])
{
    int n,data;
    node* root = NULL;
    scanf("%d" ,&n);
    for(int i=0; i<n; i++){
        scanf("%d", &data);
        origin.push_back(data);
        insert(root, data);
    }
    preorder(root, pre);
    preorder_mirro(root, pre);
    if(origin == pre){
        printf("YES\n");
        posterorder_mirro(root, post);
        for(int i=0; i<post.size(); i++){
            printf("%d", &post[i]);
        }
    }
    else if(origin == prem){
        printf("YES\n");
        posterorder_mirro(root, postm);
        for(int i=0; i<postm.size(); i++){
            printf("%d", &postm[i]);
        }
    }
    else{
        printf("NO\n");
    }
    return 0;
}

