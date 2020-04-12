typedef int ElemType;
#define MAX 100

#pragma region 线性表-数组
//线性表 顺序存储
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

#pragma endregion

#pragma region 单链表-链式存储
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

//插入操作-单链表
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

//删除操作-单链表
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
    *x = q->data;
    free(q);
    return 1;
}

//更新操作-单链表
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

//获取操作-单链表
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

//定位操作-单链表
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

//遍历操作-单链表
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

//头插法-单链表
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

//尾插法-单链表
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
#pragma endregion

#pragma region 静态链表
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
#pragma endregion

#pragma region 顺序栈
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

//下列实现方式使用第二种表示方法
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
        *e = s.data[s.top];
        return 1;
    }
}

//求栈的长度
int SqStackLength(SqStack s){
    return s->top + 1;
}

//进栈-顺序栈
int SqStackPush(SqStack *s, int e){
    if(s->StackSize == s->top+1){
        return 0;
    }
    s->tpp++;
    s->data[s->top] = e;
    return 1;
}

//出栈-顺序栈
int SqStackPop(SqStack *s, int *e){
    if(s->top == -1){
        return 0;
    }
    else{
        *e = s->data[s->top];
        s->top--;
    }
    return 1;
}

//遍历-顺序栈
void SqStackTraverse(SqStack s){
    int x;
    if(s.top == -1){
        printf("栈空");
        return 0;
    }
    else{
        for(k = s.top; k>=0; k--){
            printf("%d", s.data[k]);
        }
        return 1;
    }
}

#pragma endregion

#pragma region 链栈
//链栈
typedef struct snode{
    Elemdata data;
    struct snode *next;
}Snode, *LinkStack;

//初始化-链栈
LinkStack initLinkStack(LinkStack *s){
    *s = NULL;
}

//判断栈空-链栈
int IsEmptyLinkStack(LinkStack s){
    if(s == NULL){
        return 1;
    }
    else{
        return 0;
    }

}

//得到栈顶-链栈
int LinkStackGetTop(LinkStack s, Elemdata *x){
    if(s == NULL) return 0;
    else{
        *x = s->data;
        return 1;
    }
}

//求栈的长度-链栈
int LinkStackLength(LinkStack s){
    int count = 0;
    while(s){
        s = s->next;
        count++;
    }
    return count;
}

//进栈-链栈
int LinkStackPush(LinkStack *s, Elemdata x){
    LinkStack p = (LinkStack)malloc(sizeof(Snode));
    if(!p){
        return 0;
    }
    p->data = x;
    p->next = *s;
    *s = p;
    return 1;
}

//出栈-链栈
int LinkStackPop(LinkStack *s, Elemdata *x){
    LinkStack p = *s;
    if(*s == null){
        return 0;
    }
    else{
        *x = *s->data;
        *s = (*s)->next;
        free(p);
        return 1;
    }
}

//遍历-链栈
int LinkStackTraverse(LinkStack s){
    LinkStack p = s;
    if(s == NULL) return 0;
    while(p){
        printf("%d", p->data);
        p = p->next;
    }
    return 1;
}

#pragma endregion

#pragma region 顺序队列
//顺序队列-数组
typedef struct{
    ElemType data[MAX];
    int front;
    int rear;
    int queueSize;
}SqQueue;

//初始化-顺序队列
int initQueue(SqQueue &q){
    q->front = q->rear = 0;
    q->queueSize = MAX;
    return 1;
}

//判断队空-顺序队列
int QueueEmpty(SqQueue q){
    if(q.rear == q.front){
        return 1;
    }
    else{
        return 0;
    }
}

//求队列长度-顺序队列
int QueueLength(SqQueue q){
    return(q.rear-q.front + q.queueSize)%q.queueSize;       //这里使用的是循环队列(牺牲一个位置)的通用求法
}

//得到队头-顺序队列
int GetFront(SqQueue q, ElemType *x){
    if(q.rear == q.front){
        printf("为空队列");
        return 0;
    }
    else{
        *x = q.data[q.front];
        return 1;
    }
}

//进队列-顺序队列
int EnQueue(SqQueue &q, ElemType x){
    if((q->rear + 1) % q->queueSize == q->front) return 0;     //判断循环队列(牺牲一个位置)满
    else{
        q->data[rear] = x;
        l->rear = (l->rear+1) % q->queueSize;
        return 1;
    }
}

//出队列-顺序队列
int DeQueue(SqQueue *q, ElemType *x){
    if(q->rear == q->front){
        printf("队列为空");
        return 0;
    }
    else{
        *x = q->data[q->front];
        q->front = (q->front-1) % q->queueSize;
        return 1;
    }
}

//遍历队列-顺序队列
int QueueTraverse(SqQueue q){
    ElemType p = q.front;
    while(p!= (q->rear +1) % q.queueSize){
        
    }
}

//循环队列
typedef struct{
    Elemdata data[MAX];
    int rear;
    int front;
    int length;
    int size;
}
//进队列时q.rear = (q.rear+1) % q.size;
#pragma endregion

#pragma region 链队列
//结点-链队列
typedef struct qnode{
    Elemdata data;
    struct qnode *next;
}QNode, *QueueLink;
//栈队列类型-链队列
typedef struct{
    QueueLink front;
    QueueLink rear;
}Qlink;

//初始化-链队列
int initQueueLink(Qlink *q){
    q->rear = q->front = (Qlink)malloc(sizeof(QNode));
    if(q->front == NULL) return 0;
    q->front->next = NULL;
    return 1;
}

//判断队空-链队列
int QueueLinkEmpty(Qlink q){
    if(q->rear == front) return 1;
    else return 0;
}

//求队列长度-链队列
int QueueLinkLength(Qlink q){
    QueueLink p;
    int n = 0;
    if(q->front == q->rear) return 0;
    p = q->rear->next;
    while(p){
        n++;
        p = p->next;
    }
    return n;
}

//得到队头-链队列
int QueueLinkGetHead(Qlink q, Elemdata *x){
    if(q->front == q.rear) return 0;
    *x = q->front->next;
    return 1;
}

//进队列-链队列
int EnQueueLink(Qlink *q, Elemdata x){
    Qlink p = (QueueLink)malloc(sizeof(QNode));
    if(p == NULL) return 0;
    p->data = x;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
    return 1;
}

//出队列-链队列
int DeQueueLink(Qlink *q, Elemdata *x){
    Qlink p;
    if(q->rear = q->front) return 0;
    *x = q->front->next->data;
    p = q->front->next;
    q->front->next = p->next;
    if(q->rear == p){
        q->rear = q->front;     //保证空队列时都指向头结点
    }
    free(p);
    return 1;
}

//遍历队列-链队列
void QueueLinkTraverse(Qlink q){        //不需要返回int,直接void
    Qlink p = q-front->next;
    while(p){
        printf("%s", p->data);
        p = p->next;
    }
}

#pragma endregion

#pragma region 多维矩阵
//问题描述:二维矩阵中的元素aij 为第i行最小值，且为j列的最大值，称该元素为鞍点，求出A(m*n)矩阵中的所有鞍点
//解题思路：根据二维数组的结构特点，将二维数组看作一维数组处理
void saddle(int A[], int m, int n){
    int i,j,k,min,col;
    for(i = 0; i<m; i++){
        min = *(A+i*n);
        col = 0;
        for(j = 1; j<n; j++){
            if(*(A+i*n+j) < min){
                min = *(A+i*n+j);
                col = j;
            }
        }
        for(k = 0; k<m; k++){
            if(*(A+ m*k + col)>min){
                break;
            }
        }
        if(k == m){
            printf("%d,%d,%d",i, col, min); //打印鞍点
        }
    }
}

//问题描述：三维矩阵求出最大值
//解题思路：讲三维数组看作一维数组求解
int jsmax(int A[], int m, int n, int p){
    int i, j, k, max = *A;
    for(i = 0; i<m; i++){
        for(j = 0; j<n, j++){
            for(k = 0; k<p; k++){  //三维数组转一维数组地址为 i*n*p+j*p+k
                if(*(A+i*n*p+j*p+k)>max){
                    max = *(A+i*n*p+j*p+k);
                }
            }
        }
    }
    return max;
}

#pragma endregion

#pragma region 二叉树
//二叉树-顺序存储
#define MAXNODE 100
typedef ElemType SqBiTree[MAXNODE+1];

//二叉树-链式存储
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild;
    struct BiTNode *rchild;
}BiTNode, *BiTree;

//三叉链表
typedef struct TriTNode{
    ElemType data;
    struct TriTNode *lchild;
    struct TriTNode *rchild;
    struct TriTNode *parent;
}TriTNode, *TriTree

//先序遍历-递归
void preorder(BiTree t){
    if(t){
        printf(t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}
//中序遍历
void inorder(BiTree t){
    if(t){
        inorder(t->lchild);
        printf(t->data);
        inorder(t->rchild);
    }
}
//后序遍历
void postorder(BiTree t){
    if(t){
        postorder(t->lchild);
        postorder(t->rchild);
        printf(t->data);
    }
}

//树的遍历非递归--王道--前序遍历
void tree_preorder(BiTree t){
    BiTNode p = t;
    initStack(S);
    while(!SqStackEmpty(S) || p){
        if(p){
            push(S,p);
            visit(p);   //前进到最左侧节点，先序中途一直访问
            p = p->lchild;
        }
        else{
            pop(S,p);   //当左侧无节点时，转向右节点
            p = p->rchild;
        }
    }
}

//王道中序
void tree_inorder(BiTree t){
    BiTNode p = t;
    initStack(S);
    while(!SqStackEmpty(S) || p){
        if(p){
            push(S,p);
            p = p->lchild;
        }
        else{
            pop(S,p);
            visit(p);
            p= = p->rchild;
        }
    }
}

//后序遍历--使用 lastnode 标记上一个访问的节点
void tree_postorder(BiTree t){
    BiTNode p = t;
    BiTNode lastnode = NULL;
    initStack(S);
    while(!SqStackEmpty(S) || p){
        while(p){
            push(S,p);
            p = p->lchild;
        }
        pop(S,p);
        if(p->rchild == NULL || p->rchild == lastnode){
            visit(p);
            lastnode = p;
        }
        else{
            p = p->rchild;
            while(p){
                push(S,p);
                p = p->lchild;
            }
        }
    }
}

//华北电力--任务分析法
//分析方法:改装stack结构，使其具有task属性,根据每个节点的task来区分对于节点的操作
typedef struct{
    BiTree ptr;
    int task;   //task = 1表示遍历，task = 0表示访问
}Elemdata;

typedef struct{
    Elemdata data[MAX];
    int top;
}SqStack;

//非递归中序遍历
void task_inorder(BiTree t){
    initStack(S);
    Elemdata e;
    e.ptr = t;
    e.task = 1;
    BiTree p;
    if(t) push(S,e);
    while(!SqStackEmpty(S)){
        pop(S,e);
        if(e.task == 0){
            visit(e.ptr);
        }
        else{
            p = e.ptr;
            e.ptr = p->rchild;
            if(e.ptr){
                push(S,e);
            }
            e.ptr = p;
            e.task = 0;
            push(S,e);
            e.ptr = p->rchild;
            e.task = 1;
            if(e.ptr){
                push(S,e);
            }
        }
    }
}
//非递归前序遍历
void task_preorder(BiTree t){
    initStack(S);
    Elemdata e;
    e.task = 1;
    e.ptr = t;
    BiTree p;
    if(t) push(S,e);
    while(!SqStackEmpty(S)){
        pop(S,e);
        if(e.task == 0){
            visit(e.ptr);
        }
        else{
            p = e.ptr;
            e.task = 1;
            push(S,e);
            e.ptr = p->rchild;
            e.task = 0;
            if(e.ptr){
                push(S,e);
            }
        }
    }
}
//非递归后序遍历
void task_postorder(BiTree t){
    initStack(S);
    Elemdata e;
    e.ptr = t;
    e.task = 1;
    BiTree p;
    if(t) push(S,e);
    while(!SqStackEmpty(S)){
        pop(S,e);
        if(e.task == 0){
            visit(e.ptr);
        }
        else{
            p = e.ptr;
            e.ptr = p->rchild;
            e.task = 1;
            if(e.ptr){
                push(S,e);
            }
            e.ptr = p->lchild;
            e.task = 1;
            if(e.ptr){
                push(S,e);
            }
            e.ptr = p;
            e.task = 0;
            push(S,e);
        }
    }
}

//华北电力-基于搜索路径的分析法
//分析方法：对于一个一个节点,如果没有访问则为空,若左子树访问完成,则为"L",如果右子树访问完成则为"R"

BiTree Goleft(BiTree t, SqStack *s, char c[]){  //左子树一直进栈
    if(!t) return NULL;
    while(t){
        push(s,t);
        c[s->top] = 'L';
        if(t->lchild == NULL) break;
        t = t->lchild;
    }
    return t;                   //返回最左侧结点
}
void NR_postorder(BiTree t){
    initStack(S);
    char lrtag[MAX];            //创建标记数组
    BiTree p;
    t = Goleft(t,S,lrtag);      //左子树进栈,p为最左侧结点
    while(t){
        lrtag[S.top] = 'R';     //第二次访问,改变为"R",紧接着访问"rchild"
        if(t->rchild){
            t = Goleft(t->rchild,S,lrtag);
        }
        else{
            while(!SqStackEmpty(S) && lrtag[S.top] == 'R'){
                pop(S,p);
                visit(p);
            }
        }
        if(!SqStackEmpty(S)) gettop(S,t);
        else{
            t = NULL;
        }
    }
}
//非递归先序
void NR_preorder(BiTree t){
    BiTree p;
    char lrtag[MAX];
    initStack(S);
    if(t == NULL) return;       //空树返回
    p = t;
    while(p!= NULL || !SqStackEmpty(S)){
        while(p!= NULL){        //进栈访问到最左侧结点
            visit(p);
            push(S,p);
            p = p->lchild;
        }
        if(SqStackEmpty(S)) return;
        else{                   //当前不为空栈,出栈当前元素,转向右子树
            pop(S,p);
            p = p->rchild;
        }
    }
    printf("\n");
}

//层序遍历
void layer_traversal(BiTree t){
    BiTree p;
    initQueue(q);
    if(b){
        EnQueue(q, b);
    }
    while(!QueueEmpty(q)){
        p = DeQueue(q);
        visit(p);
        if(p->lchild){
            EnQueue(q, p->lchild);
        }
        if(p->rchild){
            EnQueue(q, p->rchild);
        }
    }
}

//字符串根左子树右子树创造一棵树
void rlr_CreateTree(BiTree *t){
    scanf("%c", &ch);
    if(ch == '#') *t = NULL;        //"#"表示空结点
    else{
        *t = (BiTree)malloc(sizeof(BiTNode));
        (*t)->data = ch;
        rlr_CreateTree(&(*t)->lchild);      //访问指针结点时 &(*t) 重点
        rlr_CreateTree(&(*t)->rchild);
    }
}

//读入边创造二叉链表非递归方法
void CreateTree(BiTree *t){
    initQueue(q);
    *t = NULL;
    scanf(fa, ch, lrflag);
    while(ch!= '#'){
        p = (BiTree)malloc(sizeof(BiTNode));
        p->data = ch;
        p->lchild = p->rchild = NULL;       //首先创建结点
        EnQueue(q,p);       //结点进队列,为写一个结点寻找父节点做准备
        if(fa == '#'){
            *t = p;
        }
        else{
            s = QueueLinkGetHead(q);        //寻找父节点
            while(s->data != s){
                DeQueue(q);
                s = QueueLinkGetHead(q);
            }
            if(lrtag == 0) s->lchild = p;       //链接父节点
            else s->rchild = p;
        }
        scanf(fa, ch, lrtag);
    }
}

//先序和中序确定一个二叉树
void CrtBT(BiTree *t, char pre[], char ino[], int ps, int is, int n){
    if(n == 0){     //pre[]为先序遍历, ino[]为中序遍历, ps为先序遍历第一个元素, is为中序遍历第一个元素
        *t == NULL;
    }
    else{
        k = search(ino, pre[ps]);       //从中序得到树的中间节点
        if(k == -1) *t = NULL;
        else{
            if(!(*t = (BiTree)malloc(sizeof(BiTNode)))) exit(0);        //申请位置
            (*t)->data = pre[ps];       //(*t)为此时树的根节点
            if(k == is) (*t)->lchild = NULL;
            else{
                CrtBT(&(*t)->lchild, pre, ino, ps+1, is, k-is);     //存在左子树,递归建立左子树
            }
            if(k == is+n-1) (*t)->rchild = NULL;
            else{
                CrtBT(&(*t)->rchild, pre, ino, ps+1+k-is, k+1, n-(k-is)-1);
            }
        }
    }
}

//二叉树遍历算法的应用-求二叉树的深度
int depth(BiTree t){
    if(t == NULL){
        return 0;
    }
    else{
        depl = depth(t->lchild);
        depr = depth(t->rchild);
        if(depl>depr) return(depl + 1);
        else return (depr + 1);
    }
}

//二叉树叶子节点的数量
int leafcount(BiTree t, int *count){
    if(t == NULL){
        return 0;
    }
    else{
        leafcount(t->lchild, count);
        if(t->lchild == NULL && t->rchild == NULL) (*count)++;
        leafcount(t->rchild, count);
    }
}

//求任意结点的祖先
void search_priorder(BiTree t, Elemdata x){     //基于路径分析法实现-后序遍历
    SqStack s;
    initStack(&s);
    char lrtag[MAX] = "";
    BiTree t;
    t = priGoleft(t, &s, lrtag);
    while(t && t->data != x){
        lrtag[s.top] = 'R';
        if(t->rchild) t = priGoleft(t->rchild, &s, lrtag);
        else{
            while(!SqStackEmpty(s) && lrtag[s.top] == 'R'){
                gettop(s, &t);
                if(t->data == x){
                    printstack(s);
                    return;
                }
            }
            if(!SqStackEmpty(s)) gettop(s, &t);
            else t = NULL;
        }
    }
}

BiTree priGoleft(BiTree t, SqStack *s, char c[]){
    if(!t){
        return NULL;
    }
    else{
        while(t){
            push(s, t);
            c[s->top] = 'L';
            if(t == NULL){
                break;
            }
            t = t->lchild;
        }
    }
    return t;
}

#pragma endregion

#pragma region 线索二叉树
//线索二叉树
typedef struct BiThrNode{
    int ltag;
    struct BiThrNode *lchild;
    Elemdata data;
    int rtag;
    struct BiThrNode *rchild;
}BiThrNodeType, *BiThrTree;

//基于中序遍历的二叉树-线索化
void InThreading(BiThrTree p, BiThrTree *pre){
    if(p){
        InThreading(p->lchild, pre);
        if(!p->lchild){     //如果p的左子树为空,则链接到pre,向上建立线索
            p->ltag = 1;
            p->lchild = *pre;
        }
        else{
            p->ltag = 0;        //左子树非空,无法建立线索
        }
        if(!(*pre)->rchild){        //pre的右子树为空,向下建立线索
            (*pre)->rtag = 1;
            (*pre)->rchild = p;
        }
        else{
            (*pre)->rtag = 0;       //pre的右子树非空,无法建立线索
        }
        *pre = p;
        InThreading(p->rchild, pre);
    }
}

//创建一个带头结点的中序线索二叉树
//头结点左指针指向t,右指针指向最后一个结点,二叉树的第一个结点和最后一个结点指向头结点
int orderThr(BiThrTree *head, BiThrTree t){
    if(!(*head = (BiThrTree)malloc(sizeof(BiThrNode)))) return 0;   //申请结点失败
    (*head)->ltag = 0;          //左指针暂时为空
    (*head)->rtag = 1;
    (*head)->rchild = *head;            //右指针指向自己(暂时初始化)
    BiThrTree pre;          //定义pre指针,进行链接线索
    if(!t){
        (*head)->rtag = 0;          //空树
    }
    else{
        (*head)->lchild = t;            //左指针指向t
        pre = *head;            //将头结点变为pre,从而第一个结点与pre链接线索
        InThreading(BiThrTree t, pre);          //中序线索化t
        pre->rchild = *head;            //最后链接,
        pre->rtag = 1;
        (*head)->rchild = pre;
    }
}

//中序线索二叉树上寻找结点p的中序前驱结点
BiThrTree InPreNode(BiThrTree p){
    BiThrTree pre;
    pre = p->lchild;
    if(p->ltag != 1){
        while(pre->rtag == 0){          //如果结点有左子树,则前驱结点应该是左子树的最右端结点
            pre = pre->rchild;
        }
    }
    return pre;         //如果没有左子树,则直接是 lchild
}

//中序线索二叉树寻找结点p的中序后继结点
BiThrTree InPostNode(BiThrTree p){
    BiThrTree post = p->rchild;
    if(p->rtag != 1){
        while(post->ltag == 0){         //如果结点有右子树,则后驱结点应该是右子树的最左端结点
            post = post->lchild;
        }
    }
    return post;            //如果没有右子树,则直接是 rchild
}

//中序线索二叉树寻找结点p的后序前驱结点
//思想与中序寻找先序后继结点很像,画图即可
BiThrNode IPostPreNode(BiThrTree p){
    BiThrNode pre;
    if(p->rtag == 0) pre = pre->rchild;
    else{
        pre = p;
        while(pre->ltag == 1 && pre->lchild != head) pre = pre->lchild;
        pre = pre->lchild
    }
    return pre;
}

//中序线索二叉树寻找结点p的先序后继结点--很棒(迷)的算法
/*思想:
p为非叶子结点:
    1.如果结点p->ltag = 0,则先序遍历的后继结点即p->lchild
    2.如果p->ltag = 1,先序后继结点为p->rchild
p为叶子节点:
    1.如果p->rchild = *head,则p->rchild为后继结点,因为先序遍历和中序遍历最后一个结点相同,后继也相同
    2.如果p->rchild != *head,若p->rchild有右子树,直接p = p->rchild->rchild,若p->rchild有右线索,进入循环
*/
BiThrNode IPrePostNode(BiThrTree p){
    BiThrNode post;
    if(p->ltag == 0;) post = p->lchild;
    else{
        post = p;
        while(post->rtag == 1 && post->rchild != head) post = post->rchild;
        post = post->rchild;
    }
    return post;
}

//在中序线索上查找值为x的结点
//直接到达第一个结点,或最后一个结点,然后前驱或后继一次访问所有结点
BiThrNode Search(BiThrTree head, Elemdata x){
    BiThrNode p = head->lchild;
    while(p->rtag != 1 && p != head){
        p = p->lchild;
    }
    while(p != head && p->data != x){
        p = InPostNode(p);      //依次访问后继结点,直到p->data = x
    }
    if(p == head){
        printf("没有找到");
        return NULL;
    }
    else{
        return p;
    }
}

//在中序线索二叉树上更新结点-中序线索二叉树插入右孩子
void InsertThrRight(BiThrTree t, BiThrTree p){
    BiThrTree w;
    p->rchild = t->rchild;
    p->rtag = t->rtag;
    p->lchild = s;
    p->ltag = 1;
    t->rchild = p;
    t->rtag = 0;
    if(p->rtag == 0){           //如果t的右子树为空,则找到t的后继,使其前驱指针指向p;
        w = InPostNode(t);
        w->lchild = p;
    }
}

#pragma endregion

#pragma region 树和森林
//双亲表示法
typedef struct tnode{
    Elemdata data;
    int parent;         //父节点的位置
}PNode;

typedef struct PNode{
    PNode tree[MAX];            //存放结点的数组
    int n;          //存放树结点的数量
    int r;          //存放根结点的位置
}PTree;

//链式存储-孩子链表
typedef struct CTNode{          //孩子链表上的结点类型
    struct CTNode *next;            //下一个孩子的位置
    int child;          //第一个孩子结点所在的位置
}CTNode, *ChildPtr;

typedef struct{         //头结点的类型
    Elemdata data;
    ChildPtr link;          //孩子链表的头指针
}CTbox;

typedef struct{         //孩子链表的数据类型
    CTbox nodes[MAX];
    int n,r;            //结点数目和根结点的位置
}ChildList;

//创建孩子链表的方法
void createPTree(ChildList *t){
    int i, j, k;
    ChildPtr p, s;
    char father, child;
    printf("请输入节点数:");
    scanf("%d", &t->n);
    getchar();
    printf("请依次输入%d个结点的值",t->n);
    for(i = 0; i<t->n; i++){            //初始化结点序列 nodes
        scanf(&t->nodes[i]->data);
        t->nodes[i].link = NULL;
    }
    getchar();
    t->r = 0;
    printf("格式{双亲,孩子}输入%d个分支{从左至右,从上至下}",t->n-1);
    for(i = 1; i < t->n-1; i++){
        scanf(&father, &child);
        getchar();
        for(j=0; j<t->n; j++){
            if(father == t->nodes[j].data) break;           //找到父结点的位置
        }
        if(j > t->n) return;
        for(k=0; k<t->n; k++){
            if(child == t->nodes[k].data) break;            //找到孩子结点的位置
        }
        if(k > t->n) return;
        p = t->nodes[j].link;           //建立链接
        if(p == null){              //当前头结点还没有孩子结点,申请结点,链接
            s = (ChildPtr)malloc(sizeof(CTNode));
            s->child = k;
            s->next = NULL;
            t->nodes[j].link = s;
        }
        else{               //有孩子节点,找到最后一个位置建立兄弟链接
            while(p->next) p = p->next;
            s = (ChildPtr)malloc(sizeof(CTNode));
            s->next = NULL;
            s->child = k;
            p->next = s;
        }
    }
}


//孩子兄弟链表表示法
typedef struct CSNode{
    Elemdata data;
    struct CSNode *fch, *nsib;
}CSNode, *CStree;

//创建孩子兄弟树
void createCSTree(CStree *t){
    initQueue(q);
    CStree r;
    *t = NULL;
    scanf(fa, ch);
    while(ch != '#'){
        p = (CStree)malloc(sizeof(CSNode));         //初始化结点
        p->data = ch;
        p->fch = p->nsib = NULL;
        EnQueue(Q, p);
        if(fa == '#') *t = p;           //此时为根节点
        else{
            s = LinkStackGetTop(Q);
            while(s->data != fa){           //找到父节点位置
                DeQueue(Q);
                s = LinkStackGetTop(Q);
                if(s->fch == NULL){         //如果没有孩子结点,直接链接为第一个孩子
                    s->fch = p;
                    r = p;          //r存储当前孩子结点位置
                }
                else{           //有孩子结点,找到链接孩子节点,并赋值r为当前兄弟结点
                    r->nsib = p;
                    r = p;
                }
            }
        }
        scanf(fa, ch);
    }
}

//树的遍历-先根遍历
void preorderTree(CStree t){
    if(t){
        printf(t->data);
        preorderTree(t->fch);
        preorderTree(t->nsib);
    }
    else{
        return;
    }
}

//树的遍历-后根遍历
void postorderTree(CStree t){
    if(t){
        postorderTree(t->fch);
        postorderTree(t->nsib);
        printf(t->data);
    }
    else{
        return;
    }
}

//树的结点查找
void findTree(CStree t, char kval, CStree *p){          //寻找值为 kval 的结点
    if(t){
        if(strcmp(kval, t->data) == 0){
            *p = t;
            return;
        }
        else{
            findTree(t->fch, kval, p);
            findTree(t->nsib, kval, p);
        }
    }
}

//树的结点的插入
int insertTree(CStree *t, char father, char child){         //父结点的值为 father,需要插入的孩子结点值为 child
    CStree p = NULL, q, s;
    findTree(t, father, &p);            //找父节点,其值为father
    if(p){
        s = (CStree)malloc(sizeof(CSNode));         //初始化结点
        strcpy(s->data, child);
        s->fch = s->nsib = NULL;
        if(!p->fch){            //如果没有孩子结点
            p->fch = s;
        }
        else{           //有孩子节点
            q = p->fch;
            while(q->nsib){         //找到最后一个兄弟节点
                q = q->nsib;
            }
            q->nsib = s;
        }
        return 1;
    }
    else{
        return 0;
    }
}

//树的结点的删除
int deleteTree(CStree *t, char fa, char ch){
    CStree pfa = NULL, pch = NULL;
    if(strcmp(fa, "#") == 0){           //如果此时删除的结点为根结点
        postdelete(*t);         //递归删除树(根结点为 t )
        *t = NULL;
        return;
    }
    else{
        findTree(*t, fa, &pfa);         //得到父结点,赋值指针 pfa
        findTree(*t, ch, &pch);         //得到孩子结点,赋值指针 pch
        if(pfa == NULL || pch == NULL){
            return;         //指针不存在,数据有误
        }
        else{
            if(pfa->fch != pch){            //不是直接孩子,需要查找 father's child's sibling
                pfa = pfa-> fch;            
                while(pfa){
                    if(pfa->nsib == pch) break;
                    pfa = pfa->nsib;            //这里得到 pfa 为 pch 的前驱结点
                }
            }
            delete(pch, pfa);           //在删除 pch 的子树时需要 pch 的前驱,用来重新链接其他子树
        }          
    }
}

void delete(CStree p, CStree f){            //删除单个结点,重新连接后序子树
    if(f->fch == p){
        f->fch = p->nsib;
        p->nsib = NULL;
        postdelete(p);
    }
    if(f->nsib == p){
        f->nsib = f->nsib;
        p->nisb = NULL;
        postdelete(p);
    }
}

void postdelete(CStree t){          //递归删除整个树
    if(t){
        postdelete(t->fch);
        postdelete(t->nsib);
        free(p);
    }
}


//树的深度
int depthTree(BiThrTree t){
    if(t == NULL){
        return 0;
    }
    else{
        d1 = depthTree(t->fch);           //递归求深度
        d2 = depthTree(t->nsib);
        return d1+1 > d2 ? d1+1:d2; 
    }
}

//求二叉树中的所有叶子节点的路径
void AllBitreePath(BiTree t, stack *s){
    while(t){
        SqStackPush(s, t->data);
        if(!t-> lchild && !t->rchild){          //叶子节点此时输出栈
            SqStackTraverse(*s);
        }
        else{
            AllBitreePath(t->lchild, *s);       //非叶子结点进栈
            AllBitreePath(t->rchild, *s);
        }
        SqStackPop(s);          //此时已经输出栈,出栈当前叶子结点
    }
}

//求树中的所有叶子节点的路径
void AllTreePath(CStree t, SqStack *s){
    while(t){
        SqStackPush(s, t->data);
        if(!t->fch){            //没有子结点,输出栈
            SqStackTraverse(s);
        }
        else{           //一直递归直到遇到叶子结点输出栈
            AllTreePath(t->fch, *s);
        }
        SqStackPop(s);          //叶子结点出栈
        t = t->nsib;            //上一层开始寻找兄弟结点
    }
}

#pragma endregion

#pragma region 哈夫曼树
//类型定义 
typedef struct{
    char data;
    int weight;
    int parent, lch, rch;
}NodeType;
typedef NodeType HufTree[M+1];
typedef char **HufCode;

//已知n个字符,生成一棵哈夫曼树
void huff_tree(int w[], int n, HufTree ht){
    int i, s1, s2;
    fot(i = 1; i<2*n; i++){         //首先初始化,一共2n-1个结点
        if(i>=1; && i<=n){
            ht[i].weight = w[i-1];          //将所给字符,赋值到初始结点中
        }
        else{
            ht[i].weight = 0;
        }
        ht[i].parent = 0;           //初始化结点
        ht[i].lch = 0;
        ht[i],rch = 0;
    }
    for(i = n+1; i<2*n, i++){
        select(ht, n, &s1, &s2);            //从结点中挑选两个最小权值结点
        ht[i].weight = ht[s1].weight + ht[s2].weight;           //结点合并
        ht[i].lch = s1;         //合并结点建立父子链接
        ht[i].rch = s2;
        ht[s1].parent = i;
        ht[s2].parent = i;
    }
}

void select(HufTree ht, int n, int *s1, int *s2){           //从结点中挑选最小的两个结点
    int i, min;
    for(min = 100, i = 1; i<2*n; i++){          //最小结点1
        if(ht[i].parent == 0 && ht[i].weight != 0 && ht[i].weight <= min){
            min = ht[i].weight;
            *s1 = i;
        }
    }
    for(min = 100, i = 1; i<2*n; i++){          //最小结点2
        if(ht[i],parent == 0 && ht[i].weight != 0 && i != s1 && ht[i].weight <=min){
            min = ht[i].weight;
            *s2 = i
        }
    }
}

//求叶子结点的哈夫曼编码
void hufcode(HufCode *hcd, HufTree ht, int n){
    char *cd;
    int i, start, c, f;
    *hcd = (HufCode)malloc((n+1)*sizeof(*char));
    cd = (char *)malloc(n*sizeof(char));            //申请存放编码的数组
    for(i = 1; i<=n; i++){
        cd[n-1] = '\0';
        start = n-1;
        c = i;
        f = ht[c].parent;              //从下向上获得编码
        while(f){
            if(ht[f].lch == c){
                cd[--start] = '0';
            }
            else{           //根据左右子树状态确定编码0或1
                cd[--start] = '1';
            }
            c = f;
            f = ht[f].parent;
        }
        (*hcd)[i] = (char *)malloc((n-start)*sizeof(char));
        strcpy((*hcd)[i], &cd[start]);      //使用char数组指针,一直到'\0'结束
    }
}

#pragma endregion