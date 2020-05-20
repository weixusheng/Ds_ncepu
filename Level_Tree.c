#include<stdlib.h>
#include<stdio.h>

/*bool变量*/
#ifndef __cplusplus
typedef char bool;
#define false 0
#define true  1
#endif

/*树节点 start*/
struct node {
    int val; 
    struct node *left, *right; 
};
/*树节点 end*/

# pragma region
/*层序遍历构造二叉树*/
void insert(struct node *p, int *a,int t, int num){
    //int length = sizeof(a)/sizeof(int);
    //printf("this is the length:%d",length);
    if(t>=num)return;
    p->val = a[t];
    if((2 * (t+1)) <= num){
        if(a[2 * (t+1) -1]!=0){
            struct node *l;
            l = (struct node*)malloc(sizeof(struct node));
            l->left = NULL;
            l->right = NULL;
            p->left = l;
            insert(p->left, a, 2 * (t+1) -1,num);
            //printf("建立节点");
        }
        if((2 * (t+1) +1) <= num){
            if(a[2 * (t+1)]!=0){
                struct node *r;
                r = (struct node*)malloc(sizeof(struct node));
                r->left = NULL;
                r->right = NULL;
                p->right = r;
                insert(p->right, a, 2 * (t+1),num);
                //printf("建立节点");
            }
        }
    }
}
     
struct node* createFromArray(int* a, int num){
    struct node *p;
    p = (struct node*)malloc(sizeof(struct node));
    p->left = NULL;
    p->right = NULL;
    insert(p,a,0,num);
    return p;
}

// 一个数组，数组长度不低于二叉树的高度，为了简便起见，这里假设是一百,
// 自己使用得时候可以改成动态数组(或链表)
int vec_left[100] = {0};
// 显示二叉树的函数，只要调用Display(root, 0)即可
void Display(struct node* root, int ident)
{
    if(ident > 0)
    {
        for(int i = 0; i < ident - 1; ++i)
        {
            printf(vec_left[i] ? "│   " : "    ");
        }
        printf(vec_left[ident-1] ? "├── " : "└── ");
    }

    if(! root)
    {
        return;
    }
    printf("%d\n", root->val);
    if(!root->left && !root->right)
    {
        return;
    }
    vec_left[ident] = 1;
    Display(root->left, ident + 1);
    vec_left[ident] = 0;
    Display(root->right, ident + 1);
}
# pragma endregion