#include<iostream>
#include<queue>
#include<vector>

using namespace std;

struct treenode
{
    int val;
    treenode *left;
    treenode *right;
};

int main(int argc, char const *argv[])
{
    treenode* node = new treenode(); //输入的二叉树根节点
    vector<int> res;
    res = dfs_avg(node);  //深度优先
    res = bfs_avg(node);  //广度优先
    return 0;
}

// TODO:深度优先遍历,计算平均值
vector<int> dfs_avg(treenode *root){
    vector<double> res;
    vector<int> sizes;
    vector<double> sum;
    dfs(root, sum, 0, sizes);
    int s = sizes.size();
    for(int i=0; i<s; i++){
        res.push_back(sum[i]/sizes[i]);
    }
    return res;
}

void dfs(treenode *root, vector<double> &sum, int level, vector<int> &sizes){
    if(root == nullptr){
        return;
    }
    if(level < sizes.size()){
        sizes[level]++;
        sum[level] += root->val;
    }
    else{
        sizes.push_back(1);
        sum.push_back(1.0 * root->val);
    }
    dfs(root->left, sum, level+1, sizes);
    dfs(root->right, sum, level+1, sizes);
}

// TODO: 广度优先遍历
vector<int> bfs_avg(treenode *root){
    vector<double> res;
    queue<treenode*> data;
    data.push(root);
    while(!data.empty()){
        int sum = 0;
        int size = data.size();
        for(int i=0; i<size; i++){
            treenode* tmp = data.front();
            data.pop();
            sum += tmp->val;
            if(tmp->left != nullptr){
                data.push(tmp->left);
            }
            if(tmp->right != nullptr){
                data.push(tmp->right);
            }
        }
        res.push_back(sum/size);
    }
    return res;
}