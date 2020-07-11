#include<cstdlib>
#include<cstdio>
#include<map>
#include<cmath>

using namespace std;

int is_s(int a){
    int i;
    for(int i=2; i<= sqrt(a); i++){
        if(a%i == 0){
            return false;
        }
    }
    return true;
}

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    map<int,int> data;
    int tempid,rank;
    for(int i=0; i<num; i++){
        scanf("%d", &tempid);
        data[tempid] = i+1;
    }
    int search;
    scanf("%d", &search);
    for(int j=0; j<search; j++){
        scanf("%d", &tempid);
        rank = data[tempid];
        if(rank == -1){
            printf("%04d: Checked\n",tempid);
        }
        else if(rank == 1){
            printf("%04d: Mystery Award\n",tempid);
            data[tempid] = -1;
        }
        else if(rank == NULL){
            printf("%04d: Are you kidding?\n",tempid);
        }
        else if(is_s(rank)){
            printf("%04d: Minion\n",tempid);
            data[tempid] = -1;
        }
        else{
            printf("%04d: Chocolate\n",tempid);
            data[tempid] = -1;
        }
    }
    return 0;
}