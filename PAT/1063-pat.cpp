#include<cstdio>
#include<cstdlib>
#include<cmath>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    int data1,data2;
    double sum, min = 0;
    for(int i=0; i<num; i++){
        sum = 0;
        scanf("%d %d", &data1, &data2);
        sum = data1*data1 + data2*data2;
        sum = sqrt(sum);
        if(min < sum){
            min = sum;
        }
    }
    printf("%.2f",min);
    return 0;
}