#include <cstdlib>
#include <iostream>
#include <stack>
#include <queue>
#define EelemType int

using namespace std;

/*
教材应用例题
*/

//线性表的应用
//两个线性表的合并
typedef struct linknode{
    EelemType val;
    struct linknode *next;
}linknode, *linklist;

linklist mergelink(linklist a, linklist b){
    linklist res = new linknode();
    linklist tmp = res;
    linklist p = a->next;
    linklist q = b->next;
    while(p && q){
        if(p->val > q->val){
            tmp->next = p;
            tmp = p;
            p = p->next;
        }
        else{
            tmp->next = q;
            tmp = q;
            q = q->next;
        }
    }
    if(p != nullptr){
        tmp->next = p;
    }
    if(q != nullptr){
        tmp->next = q;
    }
    return res;
}

//共用(共享)栈
//数据类型
#define max 100
typedef struct{
    EelemType val[max];
    int top1, top2;
    int stacksize;
}sharestack;

//进栈操作
int enstack(sharestack *s, EelemType x, int stacknum){  //stacknum区分是对哪个栈进行操作
    if(s->top1+1 == s->top2){
        return 0;
    }
    if(stacknum == 1){
        s->val[++s->top1] = x;
    }
    else if(stacknum == 2){
        s->val[++s->top2] = x;
    }
    else{
        return 0;
    }
    return 1;
}

//出栈操作
int destack(sharestack *s, EelemType &x, int stacknum){
    if(stacknum == 1){
        if(s->top1 == -1){
            return 0;
        }
        else{
            x = s->val[s->top1--];
        }
    }
    else if(stacknum == 2){
        if(s->top2 == -1){
            return 0;
        }
        else{
            x = s->val[s->top2--];
        }
    }
    else{
        return 0;
    }
    return 1;
}