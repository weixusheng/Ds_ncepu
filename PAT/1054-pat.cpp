#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    char a[50], b[50];
    double temp = 0.0, sum = 0.0;
    bool flag;
    int count = 0;
    for(int i=0; i<num; i++){
        flag = false;
        scanf("%s", &a);
        sscanf(a, "%lf", &temp);
        sprintf(b, "%.2f", temp);
        for(int j=0; j<strlen(a); j++){
            if(a[j] != b[j]){
                flag = true;
            }
        }
        if(flag || temp <-1000 || temp >1000){
            printf("ERROR: %s is not a legal number\n", a);
            continue;
        }
        else{
            count ++;
            sum += temp;
        }
    }
    if(count == 1)
        printf("The average of 1 number is %.2f", sum);
    else if(count > 1)
        printf("The average of %d numbers is %.2f", count, sum / count);
    else
        printf("The average of 0 numbers is Undefined");
    return 0;
}