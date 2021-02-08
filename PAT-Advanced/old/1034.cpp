#include<iostream>
#include<map>

using namespace std;

map<string,int> stoim;
map<int,string> itosm;
int idnum = 1;
int sifunc(string a){
    if(stoim[a] == 0){
        stoim[a] = idnum;
        itosm[idnum] = a;
        return idnum++;
    }
    else{
        return stoim[a];
    }
}
int k;
int g[2010][2010];
int weight[2010];
bool visited[2010];
map<string, int> ans;

void dfs(int v, int &head, int &totalnum, int &totalweight){
    visited[v] = true;
    totalnum++;
    if(weight[v] > weight[head]){
        head = v;
    }
    for(int i=1; i<idnum; i++){
        if(g[v][i] > 0){
            totalweight += g[v][i];
            g[v][i] = g[i][v] = 0;
            if(visited[i] == false){
                dfs(i, head, totalnum, totalweight);
            }
        }
    }
}

void dfstrave(){
    for(int i=1; i<idnum; i++){
        if(visited[i] == false){
            int head = i, totalnum = 0, totalweight = 0;
            dfs(i, head, totalnum, totalweight);
            if(totalnum > 2 && totalweight > k){
                ans[itosm[head]] = totalnum;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int n, w;
    cin >> n >> k;
    string s1, s2;
    for(int i=0; i<n; i++){
        cin >> s1 >> s2 >> w;
        int id1 = sifunc(s1);
        int id2 = sifunc(s2);
        g[id1][id2] += w;
        g[id2][id1] += w;
        weight[id1] += w;
        weight[id2] += w;
    }
    dfstrave();
    cout<< ans.size() << endl;
    for(auto it=ans.begin(); it!=ans.end(); it++)
        cout<< it->first <<" "<< it->second << endl;
    return 0;
}
