#include<cstdio>

using namespace std;

int main(int argc, const char** argv) {
    int shit, num;
    scanf("%d %d",&shit, &num);
    int data1, data2, guss, gushit;
    for(int i=0; i<num; i++){
        scanf("%d %d %d %d", &data1, &guss, &gushit, &data2);
        if(gushit > shit){
            printf("Not enough tokens.  Total = %d.\n",shit);
        }
        else{
            if((data1 < data2 && guss == 1) || (data1 > data2 && guss == 0)){
                shit += gushit;
                printf("Win %d!  Total = %d.\n", gushit,shit);
            }
            else{
                shit -= gushit;
                printf("Lose %d.  Total = %d.\n", gushit,shit);
                if(shit == 0){
                    printf("Game Over.");
                    break;
                }
            }
        }
    }
    return 0;
}