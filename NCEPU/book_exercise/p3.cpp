#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;
#define Elemtype int
#define maxsize 10000

typedef struct listnode{
    struct listnode *next;
    Elemtype val;
}ListNode;

//题号 3.1
/*
有一个带头结点的单链表(不同节点的值域可能相同)其头指针为head,编写一个函数来计算数据域为x的节点个数
(默认链表都带头结点)
*/
int list_count(ListNode *head, int x){
    ListNode *p = head->next;
    int num = 0;
    while(p){
        if(head->val == x){
            num++;
        }
        p = p->next;
    }
    return num;;
}

//题号 3.2
/*IMPORTANT: 链表的原地逆置
有一个单链表l(至少有一个节点)的头指针为head,编写一个函数将l逆置
*/
void reverse_list(ListNode *head){
    ListNode *p = head, *q = head->next;
    while(q){
        ListNode *r = p->next;
        q->next = p;
        p = q;
        q = r;
    }
    head->next = nullptr;
    head = p;
}

// 题号 3.3
/*
已知一个带头结点的单链表中的元素按元素非递减有序排列,编写一个函数删除链表中多余的值相同的元素
*/
void delete_same(ListNode* head){
    ListNode *p = head->next, *q = p->next;
    if(!p){
        return;
    }
    while(q){
        if(p->val == q->val){
            p->next = q->next;
            free(q);    //注意释放空间
        }
        else{
            p = p->next;
        }
        q = p->next;
    }
}

//题号 3.4
/*
设计一个算法判断链表的元素是否递增有序
*/
bool isbigger(ListNode *head){
    ListNode *p = head->next, *q = p->next;
    if(!p){
        return true;
    }
    while(q){
        if(q->val <= p->val){
            return false;
        }
        p = p->next;
        q = p->next;
    }
    return true;
}

//题号 3.5
/*
已知两个不带头结点单链表A和B,其头指针分别为heada和headb
编写一个函数,从链表a自i起的len个节点,然后将他们插入到链表b第j个节点前
*/

void switchnode(ListNode *heada, ListNode *headb, int i, int len, int j){
    ListNode *a = new ListNode();
    a->next = heada;
    ListNode *b = new ListNode();
    b->next = headb;
    //查找a中第i个节点前驱
    for(int k=0; k<i-1; k++){
        if(!a){
            printf("i越界");
            return;
        }
        a = a->next;
    }
    ListNode *s = a->next;
    //查找b中第j个节点的前驱
    for(int h=0; h<j-1; h++){
        if(!b){
            printf("j越界");
            return;
        }
        b = b->next;
    }
    //移动节点
    for(int m=0; m<len; m++){
        if(!s){
            printf("a链表越界");
            return;
        }
        a->next = s->next;
        b->next = s;
        b = b->next;
        s = s->next;
    }
    b->next = nullptr;
}

// 题号 3.6
/*
已知递增有序的两个链表a,b分别存储了一个集合,设计算法实现求两个集合交集,并且用a表示
*/
void mergesame(ListNode *a, ListNode *b){
    ListNode *p = a;
    ListNode *q = b;
    ListNode *tmp;
    while(p->next && q->next){
        if(p->next->val < q->next->val){
            tmp = p->next;
            p->next = tmp->next;
            free(tmp);
        }
        else if(p->next->val > q->next->val){
            q = q->next;
        }
        else{
            p = p->next;
            q = q->next;
        }
    }
    while(p->next){
        tmp = p->next;
        p->next = tmp->next;
        free(tmp);
    }
}

/*
int m[] = {1,2,3,4,5,6};
int n[] = {2,3,4};

ListNode *makelist(int a[], int n){
    ListNode *p = new ListNode();
    ListNode *pre = p;
    for(int i=0; i<n; i++){
        ListNode *shit = new ListNode();
        shit->val = a[i];
        pre->next = shit;
        pre = shit;
    }
    pre->next = nullptr;
    return p;
}

int main(){
    ListNode *a = makelist(m,6);
    ListNode *b = makelist(n,3);
    mergesame(a, b);
    ListNode *s = a->next;
    while(s){
        printf("%d", s->val);
        s = s->next;
    }
    system("pause");
}
*/

// 题号 3.7
/*
有两个单循环链表,链表头指针分别为heada和headb,编写一个函数将链表a连接到headb后仍然保持循环状态
*/
void link(ListNode *heada, ListNode *headb){
    ListNode *p = heada;
    while(p->next != heada){
        p = p->next;
    }
    ListNode *q = headb;
    while(q->next != headb){
        q = q->next;
    }
    p->next = headb;
    q->next = heada;
}


// 题号 3.8
/*
编写算法,将一个用循环链表表示的稀疏多项式分解为两个多项式
使这两个多项式中仅含有奇次项和偶数项,并要求利用原链表的空间构成这两个链表
*/
typedef struct node{
    double c;
    int exp;
    struct node *next;
}*polynom;

void splitpoly(polynom &l, polynom &l1, polynom &l2){
    polynom p = l->next;
    polynom q = l1;
    polynom r = l2;
    while(p){
        if(p->exp %2 == 0){
            q->next = p;
            q = p;
        }
        else{
            r->next = p;
            r = p;
        }
        p = p->next;
    }
    q->next = nullptr;
    r->next = nullptr;
}

