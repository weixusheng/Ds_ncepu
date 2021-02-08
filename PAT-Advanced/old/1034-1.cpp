#include<iostream>
#include<string>
#include<map>

using namespace std;

const int maxn = 2010;
const int INF = 999999999;

map<int, string> intTostring;
map<string, int> stringToint;
map<string, int> gang;
int G[maxn][maxn] = {0};
int weight[maxn] = {0};

int n, k, numperson = 0;
bool vis[maxn] = {false};

void dfs(int nowvisit, int &head, int &num, int &totalvalue){
    num++;
    vis[nowvisit] = true;
    if(weight[nowvisit] > weight[head]){
        head = nowvisit;
    }
    for(int i=0; i<num; i++){
        if(G[nowvisit][i] > 0){
            totalvalue += G[nowvisit][i];
            G[nowvisit][i] = G[i][nowvisit] = 0; 
        }
        if(vis[i] == false){
            dfs(i, head, num, totalvalue); //递归访问
        }
    }
}

void dfstrave(){
    for(int i=0; i<numperson; i++){
        if(vis[i] == false){    //没有被访问
            int head = i;
            int num = 0;
            int totalvalue = 0;
            dfs(i, head, num, totalvalue);  //递归
            if(num > 2 && totalvalue > k){  //符合条件,放进 res数组
                gang[intTostring[head]] = num;
            }
        }
    }
}

int change(string str){
    if(stringToint.find(str) != stringToint.end()){
        return stringToint[str];
    }
    else{
        stringToint[str] = numperson;
        intTostring[numperson] = str;
        return numperson++;
    }
}

int main(){
    int w;
    string str1, str2;
    cin >> n >> k;
    for(int i=0; i<n; i++){
        cin >> str1 >> str2 >> w;
        int id1 = change(str1);
        int id2 = change(str2);
        weight[id1] += w;
        weight[id2] += w;
        G[id1][id2] += w;
        G[id2][id1] += w;
    }
    dfstrave();
    cout << gang.size() << endl;
    for(auto it = gang.begin(); it != gang.end(); it++){
        cout << it->first << it->second << endl;
    }
    return 0;
}