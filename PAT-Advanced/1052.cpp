#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node{
    int ad;
    int key;
    int next;
}origin[1000000];

bool cmp(node a, node b){
    return a.key < b.key;
}

int main(int argc, char const *argv[])
{
    int n, ad, cnt = 0;
    scanf("%d %d", &n, &ad);
    int a, b, c;
    for(int i=0; i<n; i++){
        scanf("%d %d %d", &a, &b, &c);
        origin[a].ad = a;
        origin[a].key = b;
        origin[a].next = c;
    }
    vector<node> data;
    while(ad != -1){
        data.push_back(origin[ad]);
        ad = origin[ad].next;
    }
    sort(data.begin(), data.end(), cmp);
    cnt = data.size();
    printf("%d %d\n", cnt, data[0].ad);
    if(cnt == 0){
        printf("0 -1");
        return 0;
    }
    for(int k=0; k<cnt; k++){
        if(k == 0){
            printf("%05d %d ", data[k].ad, data[k].key);
        }
        else if(k == data.size()-1){
            printf("%05d\n%05d %d -1", data[k].ad, data[k].ad, data[k].key);
        }
        else{
            printf("%05d\n%05d %d ", data[k].ad, data[k].ad, data[k].key);
        }
    }
    return 0;
}
