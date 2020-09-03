/*
二叉搜索树的中序遍历,转层序遍历
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 1100;
//num存储有序数，即是完全二叉树的中序排列
//CBT存放完全二叉树的层次遍历 

int n,num[maxn],CBT[maxn],index = 0;

void inOrder(int root){
    if(root > n) return;
    inOrder(root*2);
    CBT[root] = num[index++];
    inOrder(root*2+1);
}

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++){
        scanf("%d",&num[i]);
    }
    sort(num,num+n);
    inOrder(1);
    for(int i = 1; i <= n; i++){
        printf("%d",CBT[i]);
        if(i < n) printf(" ");
    }
    return 0;
}