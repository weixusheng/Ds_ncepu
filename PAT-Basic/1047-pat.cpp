#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    int id, pid, score;
    int maxid, maxscore = 0;
    int hash[10000] = {0};
    for(int i=0; i<num; i++){
        scanf("%d-%d %d", &id, &pid, &score);
        hash[id] += score;
        if(hash[id] > maxscore){
            maxid = id;
            maxscore = hash[id];
        }
    }
    printf("%d %d", maxid, maxscore);
    return 0;
}