#include<cstdio>

using namespace std;

int main(int argc, const char** argv) {
    int row, num, shit1, shit2, yeah;
    scanf("%d %d %d %d %d", &row, &num, &shit1, &shit2, &yeah);
    int temp;
    for(int i=0; i<row; i++){
        for(int j=0; j<num; j++){
            scanf("%d", &temp);
            if(j != 0){
                printf(" ");
            }
            if(temp<= shit2 && temp>= shit1){
                printf("%03d", yeah);
            }
            else{
                printf("%03d", temp);
            }
        }
        if(i != row-1){
            printf("\n");
        }
    }
    return 0;
}