#include<iostream>
#include<cstdlib>
#include<stack>
#include<queue>
#include<set>

//顺序查找
typedef struct{
    int *data;
    int length;
}stable;

int find(stable t, int x){
    int len = t.length;
    for(int i=0; i<len; i++){
        if(t.data[i] == x){
            return i;
        }
    }
}

//折半查找
int find(stable t, int x){
    int len = t.length;
    int low = 0, high = len-1;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(t.data[mid] == x){
            return mid;
        }
        else if(t.data[mid] < x){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

//插入排序-直接插入排序
int insert_sort(stable t){
    int i, j;
    int tmp;
    for(i=1; i<t.length; i++){
        if(t.data[i] < t.data[i-1]){
            tmp = t.data[i];
            for(j = i-1; tmp < t.data[j]; --j){
                t.data[j+1] = t.data[j];
            }
            t.data[j+1] = tmp;
        }
    }
}

//折半插入
void insert_sort_half(stable t){
    int i, j, tmp;
    int low, high, mid;
    for(i=1; i<t.length; i++){
        tmp = t.data[i];    //其中 [1, i]为有序序列
        low = 1;
        high = i-1; 
        while(low <= high){
            mid = (high+low)/2;
            if(t.data[mid] > tmp){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        //折半查找到位置 low = high
        for(j=i-1; j >= high+1; --j){   //统一后移
            t.data[j+1] = t.data[j];
        }
        t.data[j+1] = tmp;
    }
}

//希尔排序
void shell_sort(stable t){
    int dk,i,j;
    int tmp;
    for(dk = t.length/2; dk >= 1; dk = dk/2){
        for(i=dk+1; i<t.length; i++){
            if(t.data[i] < t.data[i-dk]){
                tmp = t.data[i];
                for(j=i-dk; j>0 && tmp<t.data[j]; j-=dk){
                     t.data[j+dk] = t.data[j];
                }
                t.data[j+dk] = tmp;
            }
        }
    }
}

//快速排序
int partition(stable t, int low, int high){
    int pivot = t.data[0];
    while(low < high){
        while(low < high && t.data[high] >= pivot){
            --high;
        }
        t.data[low] = t.data[high];
        while(low < high && t.data[low] <= pivot){
            ++low;
        }
        t.data[high] = t.data[low];
    }
    t.data[low] = pivot;
    return low;
}

void quick_sort(stable t, int low, int high){
    if(low < high){
        int pivot = partition(t, low, high);
        quick_sort(t, low, pivot-1);
        quick_sort(t, pivot+1, high);
    }
}

//简单选择排序
void swap(stable t, int i, int j){
    int tmp = t.data[i];
    t.data[i] = t.data[j];
    t.data[j] = tmp;
}

void selectsort(stable t){
    for(int i=0; i<t.length-1; i++){
        int min = i;
        for(int j = i+1; j<t.length; j++){
            if(t.data[j] < t.data[min]){
                min = j;
            }
        }
        if(min != i){
            swap(t, t.data[min], t.data[i]);
        }
    }
}

//堆排序
//建堆
void adjust_heap_down(int a[], int index, int len){
    int tmp = a[index];
    for(int i=2*index; i<=len; i*=2){
        if(i<len && a[i] < a[i+1]){
            i++;
        }
        if(tmp > a[i]){
            break;
        }
        else{
            a[index] = a[i];
            index = i;
        }
    }
    a[index] = tmp;
}

void adjust_heap_up(int a[], int index, int len){
    int tmp = a[index];
    int i = index/2;
    while(i>0 && a[i]<a[index]){
        a[index] = a[i];
        index = i;
        i = i/2;
    }
    a[index] = tmp;
}

void build_heap_maxtree(stable t){
    for(int i=t.length/2; i>0; i--){
        adjust_heap_down(t.data, i, t.length);
    }
}

//堆排序
void heap_sort(stable t){
    build_heap_maxtree(t);  //初始建堆
    for(int i=t.length-1; i>0; i--){
        swap(t, i, 0);
        adjust_heap_down(t.data, i-1, i);
    }
}

//归并排序
stable *t = new stable();
int n = t->length;
int *tmp = (int*)malloc(sizeof(int)*(n+1));     //申请辅助空间

void merge(stable t, int low, int mid, int high){   //两端各自有序,合并为一段有序
    int i, j, k;
    for(k = low; k<=high; k++){
        tmp[k] = t.data[k];
    }
    for(i=low, j=mid+1, k=i; i<=mid && j<=high; k++){
        if(tmp[i] <= tmp[j]){
            t.data[k++] = tmp[i++];
        }
        else{
            t.data[k++] = tmp[j++];
        }
    }
    while(i <= mid){
        t.data[k++] = tmp[i++];
    }
    while(j <= high){
        t.data[k++] = tmp[j++];
    }
}

void merge_sort(stable t, int low, int high){
    if(low < high){
        int mid = (low+high)/2;
        merge_sort(t, low, mid-1);
        merge_sort(t, mid+1, high);
        merge(t, low, mid, high);
    }
}