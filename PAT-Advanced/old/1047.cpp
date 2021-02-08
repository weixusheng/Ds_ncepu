#include <vector>
#include<iostream>
#include <algorithm>
#include <string.h>
using namespace std;
char name[40010][5];
vector<int> course[2510];
bool cmp1(int a, int b) {
    return strcmp(name[a], name[b]) < 0;
}
int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
        int cnt, temp;
        scanf("%s %d", name[i], &cnt);
        for(int j=0; j<cnt; j++) {
            scanf("%d", &temp);
            course[temp].push_back(i);        
        }    
    }
    for(int i=1; i<=k; i++) {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp1);
        for(int j=0; j<course[i].size(); j++)
            printf("%s\n", name[course[i][j]]);
    }
    return 0;
}

/*
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

bool cmp(string a, string b){
    return a < b;
}

int main(int argc, char const *argv[])
{
    map<int, vector<string> > data;
    int stnum, cnum;
    scanf("%d %d", &stnum, &cnum);
    string id;
    id.resize(30);
    int shit, tmp;
    for(int i=0; i<stnum; i++){
        scanf("%s %d", &id[0], &shit);
        for(int j=0; j<shit; j++){
            scanf("%d", &tmp);
            data[tmp].push_back(id);
        }
    }
    for(int k=1; k<=cnum; k++){
        sort(data[k].begin(), data[k].end(), cmp);
        printf("%d %d\n", k, data[k].size());
        for(int w=0; w<data[k].size(); w++){
            printf("%s\n", data[k][w].c_str());
        }
    }
    return 0;
}
*/