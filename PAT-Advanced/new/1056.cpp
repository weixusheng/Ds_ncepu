#include<cstdio>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstdlib>

using namespace std;
/*
11 3
25 18 0 46 37 3 19 22 57 56 10
6 0 8 7 10 5 9 1 4 2 3
*/

typedef struct {
    int weight;
    int rank;
    int index;
    int index0;
}node;

bool cmp1(node n1, node n2){
    return n1.index0 < n2.index0;
}

int main(){
    int p,g;
    scanf("%d%d", &p, &g);
    vector<node> v(p);
    vector<int> v2(p);
    int tmp;
    for(int i=0; i<p; i++){
        scanf("%d", &tmp);
        v2[i] = tmp;
    }
    for(int i=0; i<p; i++){
        scanf("%d", &tmp);
        v[i].weight = v2[tmp];
        v[i].index = i;
        v[i].index0 = tmp;
    }
    queue<node> q;
    for(int i=0; i<p; i++){
        q.push(v[i]);
    }
    while(!q.empty()){
        int r;
        int ranks;
        int level = q.size();
        if(level == 1){
            r = q.front().index;
            v[r].rank = 1;
            break;
        }
        else{
            ranks = level/g;
            if(level%g != 0){
                ranks += 1;
            }
            node maxnode;
            int cnt = 0,maxn = -1;
            for(int i=0; i<level; i++){
                node ntmp = q.front();
                v[ntmp.index].rank = ranks+1;
                q.pop();
                if(ntmp.weight > maxn){
                    maxnode = ntmp;
                    maxn = ntmp.weight;
                }
                cnt++;
                if(cnt == g || i == level-1){
                    q.push(maxnode);
                    cnt = 0;
                    maxn = -1;
                }
            }
        }
    }
    sort(v.begin(),v.end(),cmp1);
    for(int i=0; i<p; i++){
        if(i!=0){
            printf(" ");
        }
        printf("%d",v[i].rank);
    }
    system("pause");
    return 0;
}