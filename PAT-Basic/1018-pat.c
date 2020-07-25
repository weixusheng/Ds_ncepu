#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int win_j;
    int win_s;
    int win_b;
    int lose;
    int balance;
    char win_max;
}play,*player;

void charge_func(char aplay, char bplay, player a, player b){
    if(aplay == bplay){
        (a->balance)++;
        (b->balance)++;
    }
    else if(aplay == 'C' && bplay == 'J'){
        (a->win_s)++;
        (b->lose)++;
    }
    else if(aplay == 'J' && bplay == 'B'){
        (a->win_j)++;
        (b->lose)++;
    }
    else if(aplay == 'B' && bplay == 'C'){
        (a->win_b)++;
        (b->lose)++;
    }
    else if(bplay == 'C' && aplay == 'J'){
        (b->win_s)++;
        (a->lose)++;
    }
    else if(bplay == 'J' && aplay == 'B'){
        (b->win_j)++;
        (a->lose)++;
    }
    else if(bplay == 'B' && aplay == 'C'){
        (b->win_b)++;
        (a->lose)++;
    }
}
char max(int B, int C, int J)
{
    if(B >= C && B >= J) return 'B';
    if(C >  B && C >= J) return 'C';
    /* J > B && J > C */ return 'J';
}

void find_max(player k){
    int max = k->win_b;
    k->win_max = 'B';
    if(k->win_s > max){
        max = k->win_s;
        k->win_max = 'C';
    }
    if(k->win_j > max){
        k->win_max = 'J';
    }
}

int main(){
    player a = (player)malloc(sizeof(play));
    player b = (player)malloc(sizeof(play));
    a->win_b = a->win_j = a->win_s = a->balance = a->lose = 0;
    b->win_b = b->win_j = b->win_s = b->balance = b->lose = 0;
    int n;
    scanf("%d", &n);
    char aplay,bplay; //两个玩家出的东西
    for(int i=0; i<n; i++){
        scanf(" %c %c", &aplay, &bplay);
        charge_func(aplay, bplay, a, b);
    }
    int win_a = (a->win_b) + (a->win_s) + (a->win_j);
    int win_b = (b->win_b) + (b->win_s) + (b->win_j);
    printf("%d %d %d\n", win_a, a->balance, a->lose);
    printf("%d %d %d\n", win_b, b->balance, b->lose);
    find_max(a);
    find_max(b);
    //char max1,max2;
    //max1 = max(a->win_b, a->win_s, a->win_j);
    //max2 = max(b->win_b, b->win_s, b->win_j);
    printf("%c %c",a->win_max, b->win_max);
    //printf("%c %c",max1, max2);
}