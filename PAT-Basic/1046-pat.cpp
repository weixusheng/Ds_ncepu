#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, const char** argv) {
    int num, acount = 0, bcount = 0;
    int sum;
    scanf("%d", &num);
    int temp1, temp2, temp3, temp4;
    for(int i=0; i<num; i++){
        scanf("%d %d %d %d", &temp1, &temp2, &temp3, &temp4);
        sum = temp1+temp3;
        if(temp2 == sum){
            if(temp2 == temp4){
                continue;
            }
            else{
                acount++;
            }
        }
        if(temp4 == sum){
            bcount++;
        }
    }
    printf("%d %d", bcount, acount);
    return 0;
}
