#include <cstdio>
#include <vector>

using namespace std;

/*
typedef struct {
	int shit;
	int score;
	int right_num;
	char choice[5];
}question;

main(){
	int stdnum,qnum;
	scanf("%d %d", &stdnum, &qnum);
	int score, right_num, useless;
	vector<question> data(qnum);
	for(int i=0; i<qnum; i++){
		question newqus;
		scanf("%d %d %d", &newqus.score, &useless, &newqus.right_num);
		newqus.shit = 0;
		for(int j=0; j<right_num; j++){
			scanf(" %c", &newqus.choice[j]);
		}
		data[i] = newqus;
	}
	vector<int> getscore(stdnum,0);
	int choose_num, shit_max = 0;
	bool is_shit = false;
	char temp_chos;
	for(int k=0; k<stdnum; k++){
		for(int w=0; w<qnum; w++){
			scanf("%d", &choose_num);
			if(choose_num == data[w].right_num){
				for(int a=0; a<choose_num; a++){
					scanf("%c", &temp_chos);
					if(temp_chos != data[w].choice[a]){
						is_shit = true;
					}
				}
			}
			else{
				is_shit = true;
			}
			if(!is_shit){
				getscore[k] += data[w].score;
			}
			else{
				++data[w].shit;
				if(shit_max < data[w].shit){
					shit_max = data[w].shit;
				}
			}
		}
	}
	printf("hello"); 
	system("pause");
	getchar();
	return 0;
}
*/

#include <set>

using namespace std;
int main() {
    int n, m, temp, k;
    scanf("%d%d", &n, &m);
    vector<set<char> > right(m);
    vector<int> total(m), wrongCnt(m);
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &total[i], &temp, &k);
        for(int j = 0; j < k; j++) {
            char c;
            scanf(" %c", &c);
            right[i].insert(c);
        }
    }
    for(int i = 0; i < n; i++) {
        int score = 0;
        scanf("\n");
        for(int j = 0; j < m; j++) {
            if(j != 0) scanf(" ");
            scanf("(%d", &k);
            set<char> st;
            char c;
            for(int l = 0; l < k; l++) {
                scanf(" %c", &c);
                st.insert(c);
            }
            scanf(")");
            if(st == right[j]) {
                score += total[j];
            } else {
                wrongCnt[j]++;
            }
        }
        printf("%d\n", score);
    }
    int maxWrongCnt = 0;
    for(int i = 0; i < m; i++) {
        if(wrongCnt[i] > maxWrongCnt) {
            maxWrongCnt = wrongCnt[i];
        }
    }
    if(maxWrongCnt == 0)
        printf("Too simple");
    else {
        printf("%d", maxWrongCnt);
        for(int i = 0; i < m; i++) {
            if(wrongCnt[i] == maxWrongCnt) {
                printf(" %d", i + 1);
            }
        }
    }
    fflush(stdin);
    getchar();
    return 0;
}

