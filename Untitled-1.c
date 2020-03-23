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
    if(l.length==0){    
        printf("线性表没有数据")；return 0;
    }    
}
typedef hello{
    h
}




