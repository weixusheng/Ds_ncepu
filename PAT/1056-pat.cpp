#include<cstdio>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    int sum = 0;
    int temp;
    for(int i=0; i<num; i++){
        scanf("%d", &temp);
        sum += (temp*10+temp)*(num-1);
    }
    printf("%d", sum);
    return 0;
}