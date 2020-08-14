#include <iostream>
#include <cctype>
#include <algorithm>
#include <cmath>
using namespace std;

long long convert(string n, long long radix) {
    long long sum = 0;
    int index = 0, temp = 0;
    for (auto it=n.rbegin(); it!=n.rend(); it++) {  //反向迭代器
        temp = isdigit(*it) ? *it-'0' : *it-'a'+10;
        sum += temp * pow(radix, index++);    //pow函数,指数运算
    }
    return sum;
}
long long find_radix(string n, long long num) {
    char it = *max_element(n.begin(), n.end()); //max_element : 返回容器中最大值的第一个位置
    long long low= (isdigit(it) ?it-'0': it-'a'+10) +1;     //二分法确定边界
    long long high=max(num, low);
    while (low<=high) {
        long long mid= (low+high) /2;
        long long t = convert(n, mid);  //转换为 mid 进制
        if (t<0||t>num){    //判断是否满足条件
            high=mid-1; //前半部分二分
        } 
        else if(t==num){
            return mid;
        }  
        else {
            low=mid+1;  //后半部分二分
        }
    }
    return -1;
}
int main() {
    string n1, n2;
    long long tag=0, radix=0, result_radix;
    cin >> n1 >> n2 >> tag >> radix;
    result_radix = tag==1 ?find_radix(n2, convert(n1, radix)) :find_radix(n1, convert(n2, radix));
    if (result_radix!=-1) {
        printf("%lld", result_radix);    
    } 
    else {
        printf("Impossible");    
    }  
    return 0;
}