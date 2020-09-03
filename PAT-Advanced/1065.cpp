/*
因为A、B的⼤大⼩小为[-2^63, 2^63]，用long long 存储A和B的值，以及他们相加的值sum：
如果A > 0, B < 0 或者 A < 0, B > 0，sum是不可能溢出的
如果A > 0, B > 0，sum可能会溢出，sum范围理理应为(0, 2^64 – 2]
溢出得到的结果应该是[-2^63, -2] 是个负数，所以sum < 0时候说明溢出了

如果A < 0, B < 0，sum可能会溢出，同理，sum溢出后结果是大于0的，所以sum > 0 说明溢出了
*/
#include <cstdio>
using namespace std;
int main() {
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        long long sum=a+b;
        if(a>0 && b>0 && sum<0) {
            printf("Case #%d: true\n", i+1);
        } 
        else if(a<0 && b<0 && sum>=0){
            printf("Case #%d: false\n", i+1);
        } 
        else if(sum>c) {
            printf("Case #%d: true\n", i+1);
        } 
        else {
            printf("Case #%d: false\n", i+1);
        }    
    }
    return 0;
}