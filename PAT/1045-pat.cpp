#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<map>

using namespace std;

int main()
{
    int N, count = 0;
    int array[100000], lmax[100000], rmin[100000];

    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", array + i);

    /* Find the largest on one's left and the smallest on the right */
    for(int i = 0, max = i; i < N; i++)
        lmax[i] = array[i] >= array[max] ? array[max = i] : array[max];
    for(int i = N - 1, min = i; i >= 0; i--)
        rmin[i] = array[i] <= array[min] ? array[min = i] : array[min];

    /* A element is the largest on its left and the smallest on its right,
     * it is probably a pivot */
    for(int i = 0; i < N; i++)
    {
        if(array[i] == lmax[i] && array[i] == rmin[i])
            count++;
        else
            array[i] = 0;
    }

    printf("%d\n", count);
    for(int i = 0; i < N && count; i++) if(array[i])
        printf("%d%c", array[i], --count ? ' ' : '\0');
    printf("\n");

    return 0;
}
/*
typedef struct {
    string str;
    bool isright; 
}shit,*pointshit;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    map<int, shit> data;
    for(int i=0; i<num; i++){   //add data
        //shit tempshit = (*shit)malloc(sizeof(shit));
        shit tempshit;
        cin >> tempshit.str;
        tempshit.isright = true;
        data[i] = tempshit;
    }
    for(int j=0 ;j<num; j++){
        for(int k=j+1; k<num; k++){
            if(data[k].isright == true && data[j].isright){
                string bigger = data[k].str;
                string smaller = data[j].str;
                if(bigger <= smaller){
                    data[k].isright = false;
                    data[j].isright = false;
                }
            }
        }
    }
    int count = 0;
    int w = 0;
    long int res[10000];
    for(int h=0; h<num; h++){
        if(data[h].isright == true){
            count++;
            res[w] = stoi(data[h].str);
            w++;
        }
    }
    printf("%d\n",count);
    for(int a=0; a<count; a++){
        if(a != count-1){
            printf("%ld ",res[a]);
        }
        else{
            printf("%ld",res[a]);
        }
        
    }
    return 0;
}
*/