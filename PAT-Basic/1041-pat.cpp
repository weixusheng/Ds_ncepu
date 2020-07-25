#include<stdio.h>
#include<stdlib.h>
#include<map>
#include<string.h>

using namespace std;

typedef struct{
    char ida[17];
    int sitid;
}*person,node;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    map<int,node>mp1;
    char tempid[17];
    int tryid,sitid;
    for(int i=0; i<num; i++){
        scanf("%s %d %d", &tempid, &tryid, &sitid);
        person person_temp = (person)malloc(sizeof(node));
        person_temp->sitid = sitid;
        strcpy(person_temp->ida, tempid);
        mp1[tryid] = *person_temp;
    }
    int query,queryid;
    scanf("%d", &query);
    for(int k=0; k<query; k++){
        scanf("%d", &queryid);
        printf("%s %d\n", mp1[queryid].ida, mp1[queryid].sitid);
    }
    return 0;
}