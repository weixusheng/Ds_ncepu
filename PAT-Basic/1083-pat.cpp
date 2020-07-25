#include<iostream>
#include<vector>
#include<cmath>
#include<map>
#include<algorithm>

using namespace std;

struct node{
    int div,cnt;
};

bool cmp(node a, node b){
    return a.div > b.div;
}

int main(int argc, char const *argv[])
{
    int num,tmp,div,cnt=0;
    cin >> num;
    vector<node> ans;
    map<int,int> divid;
    for(int i=0; i<num; i++){
        cin >> tmp;
        div = abs(tmp-(i+1));
        if(divid.find(div) == divid.end()){
            ans.push_back(node{div,1});
            divid[div] = cnt++;
        }
        else{
            ans[divid[div]].cnt++;
        }
    }
    sort(ans.begin(), ans.end(), cmp);
    for(int j=0; j<cnt; j++){
        if(ans[j].cnt > 1){
            printf("%d %d\n",ans[j].div, ans[j].cnt);
        }
    }
    return 0;
}
