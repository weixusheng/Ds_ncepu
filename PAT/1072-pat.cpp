#include<cstdio>
#include<set>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {
    int pnum, shitnum;
    set<int> shit;
    scanf("%d %d", &pnum, &shitnum);
    int tempshit;
    for(int i=0; i<shitnum; i++){
        scanf("%d", &tempshit);
        shit.insert(tempshit);
    }
    char name[10];
    int tempnum,tempshit2;
    int count = 0, tempcount, pcount = 0;
    vector<int> data(6);
    for(int k=0; k<pnum; k++){
        tempcount = 0;
        scanf("%s %d", &name, &tempnum);
        for(int h=0; h<tempnum; h++){
            scanf("%d", &tempshit2);
            if(shit.find(tempshit2) != shit.end()){
                count++;
                data[tempcount] = tempshit2;
                tempcount++;
            }
        }
        if(tempcount != 0){
            printf("%s: ",name);
            for(int w=0; w<tempcount; w++){
                if(w != 0){
                    printf(" ");
                }
                printf("%04d",data[w]);
            }
            printf("\n");
            pcount++;
        }
    }
    printf("%d %d",pcount, count);
    return 0;
}