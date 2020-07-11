#include<cstdio>
#include<vector>

using namespace std;

int main(int argc, const char** argv) {
    int pnum, qnum;
    scanf("%d %d", &pnum, &qnum);
    vector<int> score(qnum);
    for(int h=0; h<qnum; h++){
        scanf("%d", &score[h]);
    }
    vector<int> right(qnum);
    for(int w=0; w<qnum; w++){
        scanf("%d", &right[w]);
    }
    int temp_score;
    int temp_choose;
    for(int i=0; i<pnum; i++){
        temp_score = 0;
        for(int k=0; k<qnum; k++){
            scanf("%d", &temp_choose);
            if(temp_choose == right[k]){
                temp_score += score[k];
            }
        }
        printf("%d\n", temp_score);
    }
    return 0;
}