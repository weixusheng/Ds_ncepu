#include<map>
#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

struct node{
    string name;
    int gp,gm,gf,g;
};

bool cmp(node a, node b){
    return a.g != b.g ? a.g > b.g : a.name < b.name; 
}

int main(int argc, char const *argv[])
{
    int p, m, n, score, cnt = 1;
    string s;
    cin >> p >> m >> n;
    vector<node> v, ans;
    map<string, int> idx;
    for(int i=0; i<p; i++){
        cin >> s >> score;
        if(score >= 200){
            v.push_back(node{s, score, -1, -1, 0});
            idx[s] = cnt++;
        }
    }
    for(int i=0 ;i<m; i++){
        cin >> s >> score;
        if(idx[s] != 0){
            v[idx[s]-1].gm = score;
        }
    }
    for(int i=0; i<n; i++){
        cin >> s >> score;
        int temp = idx[s]-1;
        if(idx[s] != 0){
            v[temp].gf = v[temp].g = score;
            if(v[temp].gm > v[temp].gf){
                v[temp].g = (int)(v[temp].gm*0.4 + v[temp].gf*0.6 + 0.5);
            }
        }
    }
    for(int i=0; i<v.size(); i++){
        if(v[i].g >= 60){
            ans.push_back(v[i]);
        }
    }
    sort(ans.begin(), ans.end(),cmp);
    for(int i=0; i<ans.size(); i++){
        printf("%s %d %d %d %d\n", ans[i].name.c_str(), ans[i].gp, ans[i].gm, ans[i].gf, ans[i].g);
    }
    return 0;
}
