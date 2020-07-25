#include<cstdio>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    int n[5];
    char c;
    char data[3][10][5] = {'\0'};
    for(int i=0; i<3; i++){
        for(int index=0; (c = getchar())!='\n';){
            if(c == '['){
                scanf("%[^]]", data[i][index++]);
            }
        }
    }
    scanf("%d", &num);
    for(int j=0; j<num; j++){
        for(int k=0; k<5; k++){
            scanf("%d", n+k);
            --n[k];
        }
        if(n[0] < 0 || n[0] > 9 || !(*data[0][n[0]])
        || n[1] < 0 || n[1] > 9 || !(*data[1][n[1]])
        || n[2] < 0 || n[2] > 9 || !(*data[2][n[2]])
        || n[3] < 0 || n[3] > 9 || !(*data[1][n[3]])
        || n[4] < 0 || n[4] > 9 || !(*data[0][n[4]]))
            puts("Are you kidding me? @\\/@");
        else{
            printf("%s(%s%s%s)%s\n", data[0][n[0]], data[1][n[1]],data[2][n[2]], data[1][n[3]], data[0][n[4]]);
        }
    }
    return 0;
}