#include<cstdio>
#include<map>
#include<vector>

using namespace std;

struct node {
    int data, next;
}list[100000];

vector<int> v[3];
int main() {
    int start, n, k, a;
    scanf("%d%d%d", &start, &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        scanf("%d%d", &list[a].data, &list[a].next);
    }
    int p = start;
    while(p != -1) {
        int data = list[p].data;
        if (data < 0)
            v[0].push_back(p);
        else if (data >= 0 && data <= k)
            v[1].push_back(p);
        else
            v[2].push_back(p);
        p = list[p].next;
    }
    int flag = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (flag == 0) {
                printf("%05d %d ", v[i][j], list[v[i][j]].data);
                flag = 1;
            } else {
                printf("%05d\n%05d %d ", v[i][j], v[i][j], list[v[i][j]].data);
            }
        }
    }
    printf("-1");
    return 0;
}
/*
int main(int argc, const char** argv) {
    int start, num, K;
    scanf("%d %d %d", &start, &num, &K);
    map<int, int> map_ad;
    map<int, int> map_to;
    map<int, int> map_res;
    int temp_ad, temp_id, temp_to;
    for(int i=0; i<num; i++){
        scanf("%d %d %d",&temp_ad, &temp_id, &temp_to);
        map_ad[temp_ad] = temp_id;
        map_to[temp_id] = temp_to;
        map_res[temp_id] = temp_ad;
    }
    vector<int> data(100001);
    int k = 0;
    int shit = start;
    while(shit != -1){
        data[k] = map_ad[shit];
        shit = map_to[data[k]];
        k++;
    }
    vector<int> res(100001);
    int index = 0;
    for(int h=0; h<num; h++){
        if(data[h]<0){
            res[index] = data[h];
            index++;
        }
    }
    for(int h=0; h<num; h++){
        if(data[h]>=0 && data[h]<=K){
            res[index] = data[h];
            index++;
        }
    }
    for(int h=0; h<num; h++){
        if(data[h]>K){
            res[index] = data[h];
            index++;
        }
    }
    int tempto;
    for(int w=0; w<num; w++){
        if(w != num-1){
            printf("%05d %d %05d\n", map_res[res[w]], res[w], map_res[res[w+1]]);
        }
        else{
            printf("%05d %d -1", map_res[res[w]], res[w]);
        }
    }
    return 0;
}
*/