#include<stdio.h>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    char signal;
    scanf("%d %c", &num, &signal);
    int row = (num+1)/2;
    int j;
    for(j=0; j<num; j++){
        printf("%c", signal);
    }
    printf("\n");
    for(int i=0; (i < row-2); i++){
            printf("%c", signal);
            for(int k=0; k<(num-2); k++){
                printf(" ");
            } 
            printf("%c\n", signal);
    }
    for(j=0; j<num; j++){
        printf("%c", signal);
    }
    return 0;
}