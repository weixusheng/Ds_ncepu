#include<cstdio>
#include<cstdlib>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    double data[100000];
    double sum[100000];
    for(int i=0; i< num; i++){
        scanf("%lf", &data[i]);
    }
    double temp_sum = 0;
    for(int j=0; j<num; j++){
        temp_sum += data[j];
        sum[j] = temp_sum;
    }
    double res = 0;
    for(int a=0; a < num; a++){
        for(int b = a+1; b < num; b++){
            res += sum[b]-sum[a];
        }
    }
    for(int c=0; c<num; c++){
        res += sum[c];
    }
    printf("%.2f", res);
    return 0;
}
/*
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);        // 数的个数
	double sum = 0, num;    // 和，数
	for (int i = 1; i <= n; ++i) {
		scanf("%lf", &num);
		sum += num * i * (n - i + 1);   // 数×所在片段数
	}
	printf("%.2lf", sum);    // 两位小数
	return 0;
}
*/

/* AC
#include <cstdio>
using namespace std;
#define ll long long

ll n,summ,tmpa;
double tpda;

int main(){
    scanf("%lld",&n);
    for(ll i=0;i<n;++i){
        scanf("%lf",&tpda);
        tmpa = ((ll)(tpda*10000)+5)/10;  //从结果上来看，这么做吧原来的浮点数乘以1000再转为整型
        summ += tmpa * (i+1) * (n-i);  //为什么要先乘以一万再加5除以十？是因为最低位会产生精度误差。
    }                                  //加五除十是为了四舍五入
    printf("%lld.%02lld",summ/1000,((summ%1000)+5)/10);
    return 0;
}
*/