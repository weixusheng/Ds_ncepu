#include<stdlib.h>
#include<stdio.h>
#include<map>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    int  max = 0;
    int maxid;
    scanf("%d", &num);
    map<int,int> map1;
    int first,second;
    for(int i=0; i<num ;i++){
        scanf("%d %d",&first, &second);
        map1[first] += second;
        if(max < map1[first]){
            maxid = first;
            max = map1[first];
        }
    }
    printf("%d %d", maxid, max);
    return 0;
}