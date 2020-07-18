#include<cstdio>
#include<string>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct node{
    string lib;
    double score;
    int pnum;
};

double shitx(double score, string id){
    if(id[0] == 'B'){
        return score/1.5;
    }
    if(id[0] == 'A'){
        return score;
    }
    if(id[0] == 'T'){
        return score*1.5;
    }
}

bool cmp(node a, node b){
    if((int)a.score == (int)b.score){
        if(a.pnum == b.pnum){
            return a.lib < b.lib;
        }
        else{
            return a.pnum < b.pnum;
        }
    }
    else{
        return (int)a.score > (int)b.score;
    }
}

int main(int argc, char const *argv[])
{
    int num,cnt = 0;
    double score;
    string id, lib;
    cin >> num;
    map<string,int> namex;
    vector<node> ans;
    for(int i=0; i<num; i++){
        cin >> id >> score >> lib;
        transform(lib.begin(), lib.end(), lib.begin(), ::tolower);
        if(namex.find(lib) == namex.end()){
            ans.push_back(node{lib,shitx(score,id),1});
            namex[lib] = cnt++;
        }
        else{
            int tmp = namex[lib];
            ans[tmp].pnum++;
            ans[tmp].score = ans[tmp].score + shitx(score,id);
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    int index = 1;
    printf("%d\n", cnt);
    for(int k=0; k<cnt; k++){
        if(k>0 && (int)ans[k-1].score != (int)ans[k].score){
            index = k+1;
        }
        printf("%d %s %d %d\n",index, ans[k].lib.c_str(), (int)ans[k].score, ans[k].pnum);
    }
    return 0;
}
