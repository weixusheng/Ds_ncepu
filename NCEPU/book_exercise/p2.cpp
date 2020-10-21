#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

using namespace std;
#define Elemtype int
#define maxsize 10000

int max_val = 0, min_val = 1000;
int a[] = {1,2,3,4,5};
int len = sizeof(a)/sizeof(a[0]);

/*
测试数组的引用
*/
void modify_list(int a[], int x){
    a[x] = 99;
    for(int i=0; i<len; i++){
        printf("%d ",a[i]);
    }
}
/*
int main(){
    modify_list(a, 2);
    system("pause");
}
*/


//题号 2.2
/*
线性表中的元素存在向量A中,元素是整型数,试写出递归算法求出A中的最大最小元素
*/
void get_val(int A[], int n, int &max_val, int &min_val){
    if(n == 1){
        max_val = A[0];
        min_val = A[0];
    }
    else{
        get_val(A, n-1, max_val, min_val);
        if(A[n] > max_val){
            max_val = A[n];
        }
        if(A[n] < min_val){
            min_val = A[n];
        }
    }
}
/*
int main(){
    get_val(a, len-1, max_val, min_val);
    printf("max=%d min=%d", max_val, min_val);
    system("pause");
}
*/

//题号 2.3
/*
删除线性表A中第i个元素开始的,连续K个元素
*/
void delete_list(int *a[], int i, int k, int *n){
    if(i>(*n-1) || (i+k) > (*n-1) || k<0){
        printf("没有元素可以删除");
    }
    for(int j=i; j<i+k; ++j){
        a[j] = a[j+k];
    }
    *n -= k;
}

//题号 2.4
/*
将元素x插入到递增有序的表a中
*/
void insert_list(int a[], int x, int &n){
    if(n >= maxsize){
        printf("空间不足");
    }
    for(int i=n; i>=0; i--){
        if(a[i-1] >= x){
            a[i] = a[i];
        }
        else{
            a[i] = x;
            break;
        }
    }
    /* 冗余方法
    int k = 0;
    for(int i=0; i<*n; i++){
        if(x > *a[i]){
            k = i;
            break;
        }
    }
    for(int j=*n-1; j>=k; j++){
        *a[j+1] = *a[j];
    }
    *a[k] = x;
    *n++;
    */
}

//题号 2.5
/*  IMPORTANT:
已知在一维数组A[1,..m+n]中依次存放着两个向量(a1,a2...am)和(b1,b2...bn)
编写一个函数将两个向量位置互换
*/
// 思路: 三次逆置*/
void reverse_list(int a[], int f, int n){
    int tmp;
    for(int i=f; i<(n)/2; i++){
        tmp = a[i];
        a[i] = a[n-i-1];
        a[n-i-1] = tmp;
    }
}

void reverse(int a[], int m, int n){
    reverse_list(a, 0, m+n-1);
    reverse_list(a, 0, n-1);
    reverse_list(a, n, m+n-1);
}
/*
int main(){
    reverse_list(a,5);
    for(int i=0; i<5; i++){
        printf("%d ", a[i]);
    }
    system("pause");
}
*/

//题号 2.6
/*
假定以"I"和"O"分别表示入栈和出栈,栈的初始态和终态均为空
判断所给序列是否合法,若合法返回1,若不合法返回0
*/ 
int isvalid(char a[], int n){
    int num = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 'I'){
            ++num;
        }
        else if(a[i] == 'O'){
            --num;
        }
        if(num < 0 || num>n-1){
            return 0;
        }
    }
    if(num != 0){
        return 0;
    }
    return 1;
}

int main(){
    char test[] = {'I','O','I','I','O','O'};
    int res = isvalid(test, 6);
    printf("%d", res);
    system("pause");
}

//题号 2.7
/*
编写一个函数来求逆波兰表达式,其中逆波兰表达式是在该函数中输入的
*/
void nibolan(char a[]){
    stack<float> s;
    char data[maxsize];
    int i=0;
    while(data[i] != '#' && i<maxsize){ //输入元素
        scanf("%c", &data[i]);
        i++;
    }
    int n = i;
    char tmp;
    float m, n, res;
    for(int j=0; j<n; j++){
        tmp = data[i];
        if('0' < tmp && tmp < '9'){
            //数字
            s.push(tmp-'0');
        }
        else{
            m = s.top();
            s.pop();
            n = s.top();
            s.pop();
            switch (tmp)
            {
            case '+':
                res = m+n;
                s.push(res);
                break;
            case '-':
                res = m-n;
                s.push(res);
                break;
            case '*':
                res = m*n;
                s.push(res);
                break;
            case '/':
                if(n == 0.0){
                    printf("当前除零错误");
                }
                else{
                    res = m/n;
                    s.push(res);
                }
                break;
            }
        }
    }
    int ress = s.top();
    printf("%f", ress);
}

//题号 2.10
/*
假设循环队列中 rear,len 表示队尾元素的位置,和队中元素的个数
试着求出判别该循环队列队满的条件,并写出相应的入队和出队算法,要求出队时返回队头元素
*/
typedef struct{
    int rear;
    int len;
    Elemtype data[maxsize];
}xh_queue;

bool isfull(xh_queue a){
    if(a.len == maxsize){
        return false;
    }
    else{
        return true;
    }
}

void enqueue_xh(xh_queue &a, int x){
    if(isfull(a)){
        printf("队列已经满啦");
    }
    else{
        a.len++;
        a.rear = (a.rear+1)%maxsize;
        a.data[a.rear] = x;
    }
}

Elemtype dequeue_xh(xh_queue &a){
    int front;
    if(a.len == 0){
        printf("队列中没有元素");
        return 0;
    }
    else{
        a.len--;
        front = (maxsize + a.rear - a.len + 1)%maxsize;
    }
    return a.data[front];
}