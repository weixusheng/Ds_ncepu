#include<stdio.h>
#include<stdlib.h>

int cmp(const void*a , const void*b){
    /*
    double m = ((double*)a)[1];
    double n = ((double*)b)[1];
    int res = (int)m-(int)n;
    return res;     //递减
    */
    if(((double*)a)[1]>((double*)b)[1])
		return -1;
	else return 1;
}

int main(){
    int n;
    int need;
    double price = 0;
    double data[1000][2];
    scanf("%d %d", &n, &need);
    for(int i=0; i<n; i++){
        scanf("%lf", &data[i][0]);
    }
    for(int j=0; j<n; j++){
        double avg;
        scanf("%lf", &avg);
        data[j][1] = avg/data[j][0];
    }
    qsort(data, n, sizeof(double)*2, cmp); //排序 
    while(need!=0){
        for(int k=0; k<n; k++){
            if(need > data[k][0]){
                need -= data[k][0];
                price+= (data[k][1]*data[k][0]);
            }
            else{
                price+= (data[k][1]*need);
                need = 0;
            }
        }
        break;
    }
    printf("%.2f", price);
}