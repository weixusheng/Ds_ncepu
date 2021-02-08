#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cstring>

using namespace std;

struct node{
    string id;
    int score;
    int area;
    int rank;
    int localrank;
};

bool cmp(node a, node b){
    if(a.score == b.score){
        return a.id < b.id;
    }
    else{
        return a.score > b.score;
    }
}

int main(int argc, char const *argv[])
{
    int a, num;
    cin >> a;
    vector<vector<node> > data(a);
    vector<node> res;
    string id;
    int score;
    int pre;
    int rank;
    int tmprank;
    for(int i=0; i<a; i++){
        cin >> num;
        for(int j=0; j<num; j++){
            cin >> id >> score;
            data[i].push_back({id, score, i, 0, 0});
        }
        sort(data[i].begin(), data[i].end(),cmp);
        pre = 101;
        rank = 1;
        for(auto it = data[i].begin(); it!=data[i].end(); it++){
            if(it->score != pre){
                pre = it->score;
                it->localrank = rank; 
                tmprank = rank;
            }
            else{
                it->localrank = tmprank;
            }
            rank++;
        }
        for(int k=0; k<num; k++){
            res.push_back(data[i][k]);
        }
    }
    sort(res.begin(), res.end(), cmp);
    printf("%d\n", res.size());
    pre = 101;
    rank = 1;
    for(int i=0; i<res.size(); i++){
        //1234567890005 1 1 1
        if(res[i].score == pre){
            res[i].rank = tmprank;
        }
        else{
            res[i].rank = rank;
            tmprank = rank;
            pre = res[i].score;
        }
        rank++;
        node shit = res[i];
        printf("%s %d %d %d\n", shit.id.c_str(), shit.rank, shit.area+1, shit.localrank);
    }
    return 0;
}
