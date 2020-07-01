#include<cstdio>
#include<algorithm>
using namespace std;
 
int main(){
	int n;
	scanf("%d",&n);
	int a[n];
	int b[n];
	for(int i=0 ;i<n ;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0 ;i<n ;i++){
		scanf("%d",&b[i]);
	}
	int i,j;
	for(i=0 ;i<n-1 && b[i+1]>=b[i] ;i++); //i记录了第一个相同元素的位置 
	for(j=i+1 ;j<n && a[j]==b[j];j++);	//j记录了最后一个相同元素的位置+1 
	
	if(j==n){	//如果最后一个相同的位置是n-1 那么说明是插入排序 
		printf("Insertion Sort\n");
		sort(a,a+i+2);	
	}else{
		printf("Merge Sort\n");
		int k = 1;	//下一次进行排序的子序列长度是2*k 
        int flag = 1;
       	//设置flag变量后，模拟归并过程。直到达到给出的状态，然后再进行一次归并，将结果输出即可。 
	    while(flag) {
            flag = 0;
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }    
			k = k * 2;
            for (i = 0; i < n / k; i++){
            	sort(a + i * k, a + (i + 1) * k);
			}
			sort(a + n / k * k, a + n);
        }
		
	}
	for(int i=0 ;i<n-1 ;i++){
		printf("%d ",a[i]);
	}
	printf("%d\n",a[n-1]);
	return 0;
}