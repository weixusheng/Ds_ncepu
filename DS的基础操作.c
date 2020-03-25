//线性表 顺序存储
typedef int ElemType;

#define MAX 100
typedef struct //数组实现
{
    ElemType data[MAX];
    int listSize;
    int length;
}SqList_basic;

typedef struct //保存线性表的头指针（没有define定义长度）
{
    ElemType * data;
    int listSize;
    int length;
}SqList_basic2;

//基于线性表的基本操作实现
typedef struct{
    char name[20];
    float score;
}STD;

typedef struct{
    STD *data;
    int listSize;
    int length;
}SqList;
//线性表初始化操作
int initSqList(SqList *L, int max){
    L->data = (STD *)malloc(max*sizeof(STD));
    if(STD->data == NULL){
        printf("空间申请失败")；return 0;
    }
    L->listSize = max;
    L->length = 0;
    return 1;
}
//线性表插入操作
int insertSqList(SqList *l, int i; STD x){
    int k;
    if(i<1 || i>l->length+1){
        printf("插入位置有问题")；
        return 0;
    }
    if(l->length >= l->listSize){
        printf("空间不够")；
        return 0;
    }
    for(k=l->length;k>i;k--){
        l->data[k] = l->data[k-1];
    }
    l->data[i-1] = x;
    l->length = l->length + 1;
    return 1; 
}
//删除操作
int deleteSqList(SqList *l, int i, STD *x){
    int k;
    if(l->length == 0){
        printf("线性表没有数据")；return 0；
    }
    if(i<= 0 || i>SqList->length){
        printf("删除位置有问题")；return 0；
    };
    *x = l->data[i-1];
    for(k=i; k<l->length; k++){
        l->data[k-1] = l->data[k];
    }
    l->length = l->length-1;
    return 1;
}
//更新操作
int updateSqList(SqList l, int i, STD x){
    if(l.length == 0){
        printf("线性表没有数据")；return 0；
    }
    if(i<=0 || i>l.length){
        printf("更新位置有问题");return 0;
    }
    l.data[i-1] = x;
    return 1;
}
//获取操作
int getSqList(SqList l, int i, STD *x){
    if(l.length == 0){
        printf("线性表没有数据")；return 0；
    }
    if(i<=0 || i>l.length){
        printf("位置有问题")；return 0；
    }
    *x = l.data[i-1];
    return 1;
}
//定位操作
int locationSqList(SqList l, char *x){
    int i;
    if(l.length == 0){
        printf("没有数据")；return 0；
    }
    for(i = 0; i<l,length, i++){
        if(strcmp(l.data[i]).name, x){
            return i+1
        }
    }
    return 0;
}
//遍历操作
int dispSqList(SqList l){
    int i;
    if(l.length == 0){
        printf("没有数据")；return 0；
    }
    for(i=0; i<l.length; i++){
        printf("%10s &7.2f",l.data[i].name,l.data[i].score);
    }
    return 1;
}

//链式存储
typedef struct node{
    ElemType data;
    struct node *next;
}LNode_basic, *LinkList_basic;

typedef struct Lnode{
    STD data;
    struct Lnode *next;
}LNode, *LinkList;

//初始化单链表
int initLinkList(LinkList *l){
    *l = (LinkList)malloc(sizeof(LinkList));
    if(*l == 0)return 0;
    (*l->next) = NULL;
    return 1;
}

//插入操作
int insertLinkList(LinkList l, int i, STD x){
    LinkList p =l,s;
    int pos = 0;
    while(p!=NULL && pos<i-1){
        p = p->next;
        pos++;
    }
    if(p == null || pos > i-1){
        printf("插入位置有问题")；return 0；
    }
    s = (LinkList)malloc(sizeof(LNode));
    s->data = x;
    s->next = p->next;
    p->next = s;
    return 1;
}

//删除操作
deleteLinkList(LinkList l, int i, STD *x){
    LinkList p = l,q;
    int pos = 0;
    while(p->next != NULL && pos < i-1){
        p = p->next;
        pos++;
    }
    if(p->next == NULL || i-1 < pos){
        printf("删除位置有问题")；return 0；
    }
    q = p->next;
    p->next = q->next;
    x = q->data;
    free(q);
    return 1;
}

//更新操作
int updateLinkList(LinkList l, int i, STD x){
    int pos = 1;
    LinkList p = l->next;
    while(p->next != NULL && pos < i){
        p = p->next;
        pos++;
    }
    if(p->next == NULL || i > pos){
        printf("更新位置有问题")；return 0；
    }
    p->data = x;
    return 1;
}

//获取操作
int getLinkList(LinkList l, int i, STD *x){
    LinkList p = l->next;
    int pos = 1;
    while(p->next != NULL && pos < i){
        p = p->next;
        pos++;
    }
    if(p->next == NULL || i < pos){
        printf("位置有问题")；return 0；
    }
    *x = p->data;
    return 1;
}

//定位操作
int getlocationLinkList(LinkList l, char *name){
    LinkList p = l->next;
    int j = 1;
    while(p){
        if(strcmp(p->data.name,name)){
            p = p->next;
            j++;
        }
        else{
            return j;
        }
    }
    if(p == NULL){
        return 0;
    }
}

//得到单链表长度
int linklistlength(LinkList l){
    int len = 0;
    LinkList p = l->next;
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

//遍历操作
int disLinkList(linklist l){
    LinkList p = l->next;
    if(p == NULL){
        printf("没有数据");
        return 0;
    }
    while(p){
        printf("%10s, %7.2f\n");
        p = p->next;
    }
    return 1;
}

//头插法
void frontcreateLinkList(LinkList *l){
    int n = 0;
    STD x;
    LinkList p;
    char yn;
    initLinkList(l);
    do{
        printf("请输入第%d个学生的姓名和分数，用空格隔开："，++n);
        scanf("%s%f",&x.name,&x.score);
        getchar();
        p = (LinkList)malloc(sizeof(LNode));
        p->data = x;
        p->next = (*l)->next;
        (*l)->next = p;
        printf("请继续输入？ Y/N:");
        yn = getchar();
    }while(yn == 'Y' || yn == 'y');
}

void rearcreateLinkList(LinkList *l){
    int n = 0;
    STD x;
    LinkList p,R;
    char yn;
    initLinkList(l);
    R = *l;
    do{
        printf("请输入第%d个学生的信息"，++n);
        scanf("%s%d",&x.name,&x.score);
        getchar();
        p = (LinkList)malloc(sizeof(LNode));
        p->data = x;
        p->next = NULL;
        R->next = p;
        R = p;
        printf("还要继续输入吗？ Y/N:");
        yn = getchar();
    }while(yn == 'Y' || yn == 'y');
}

//静态链表
#define MAXSIZE 100

typedef struct{
    ElemType data;
    int next;
}SNode;

typedef struct{
    SNode sd[MAXSIZE];
    int SL,AV;
    int SLinkSize;
}StaticLink;

//初始化静态链表
int initSLink(StaticLink *l){
    l->SL = 0;
    l->SLinkSize = MAXSIZE;
    l->sd[0].next = -1;
    l->AV = 1;
    for(int i = 1; i < l->SLinkSize-1; i++){
        l->sd[i].next = i+1;
    }
    l->sd[i].next = -1;
    return 1;
}

//插入操作
int insertSList(StaticLink *l, int i, ElemType x){
    int p,t,j;
    p = l->SL;
    j = 0;
    while(l->sd[p].next != -1 && j<i-1){
        p = l->sd[p].next;
        j++;
    }
    if(j == i-1){
        if(l->AV != -1){  //检查空余位置
            t = l->AV;
            l->AV = l->sd[t].next;
            l->sd[t].data = x;
            l->sd[t].next = l->sd[p].next;
            l->sd[p].next = t;
            return 1;
        }
        else{
            printf("没有空余的位置")；return 0；
        }
    }
    else{
        printf("插入的位置有问题")；return 0；
    }
}

//删除操作
int deleteSList(StaticLink *l, int i, ElemType *x){
    int p,t,s,j;
    p = l->SL;
    j = 0;
    while(l->sd[p]->next != -1 && j < i-1){
        p = l->sd[p]->next;
        j++;
    }
    if(j == i-1){
        t = l->sd[p].next;
        if(t == -1){
            printf("删除位置不存在")；return 0;
        }
        else{
            l->sd[p].next = l->sd[t].next;
            *x = l->sd[t].data;
        }
        p = l->AV;
        if(t < p){
            l->sd[t].next = l->AV;
            l->AV = t;
        }
        else{
            while(l->sd[p].next != -1 && l->sd[p].next < t){
                p = p->sd[p].next;
            }
            s = l->sd[p].next;
            l->sd[t]->next = s;
            l->sd[p]->next = t;
            return 1;
        }
    }
    else{
        printf("删除位置有问题")；return 0;
    }
    return 1;
}

//顺序栈

typedef struct stack{  //第一种使用数组实现
    ElemType data[MAX];
    int top;
    int StackSize;
}SqStack;

typedef struct stack{  //第二种使用指向数组的指针表示
    ElemType *data;
    int top;
    int StackSize;
}SqStack;

//初始化栈
int initStack(SqStack *s, int max){
    s->data = (SqStack*)malloc(max*sizeof(ElemType));
    if(s->data == NULL){
        printf("空间申请失败")；return 0；
    }
    s->top = 0;
    s->StackSize = max;
    return 1;
}

//判断栈空
int SqStackEmpty(SqStack s){
    if(s.top == -1)return 1;
    else return 0;
}

//得到栈顶
int getSqStack(SqStack s, ElemType *e){
    if(SqStackEmpty(s)){
        printf("栈为空")；return 0；
    }
    else{
        *e = s->data[s.top];
        return 1;
    }
}

//求栈的长度
int SqStackLength(SqStack s){
    return s->top + 1;
}