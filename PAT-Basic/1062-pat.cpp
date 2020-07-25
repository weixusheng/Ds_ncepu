#include<cstdio>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int main(int argc, const char** argv) {
    int s1,s2,s3,s4,shit;
    scanf("%d/%d %d/%d %d", &s1,&s2,&s3,&s4,&shit);
    double shit1 = (double)s1/s2;
    double shit2 = (double)s3/s4;
    double temp;
    if(shit1 > shit2){
        temp = shit2;
        shit2 = shit1;
        shit1 = temp;
    }
    int flag = 0;
    for(int i=0; i<shit; i++){
        double temp_shit = (double)i/shit;
        if(temp_shit<shit2 && temp_shit>shit1 && gcd(i,shit) == 1){
            if(flag == 0){
                flag = 1;
            }
            else{
                printf(" ");
            }
            printf("%d/%d", i,shit);
        }
    }
    return 0;
}