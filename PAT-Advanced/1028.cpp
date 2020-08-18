#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

const int maxn = 100001;

struct Node{
    int no, score;
    string name;
}node[maxn];

int c;

bool cmp(Node a, Node b){
    if(c == 1){
        return a.no < b.no;
    }
    else if(c == 2){
        if(a.name == b.name){
            return a.no < b.no;
        }
        else{
            return a.name <= b.name;
        }
    }
    else {
        if(a.score == b.score){
            return a.no < b.no;
        }
        else{
            return a.score <= b.score;
        }
    }
}


int main(int argc, char const *argv[])
{
    int n;
    scanf("%d%d", &n, &c);
    for(int i=0; i<n; i++){
        cin >> node[i].no >> node[i].name >> node[i].score;
    }
    sort(node, node+n, cmp);
    for(int i=0; i<n; i++){
        printf("%06d %s %d\n", node[i].no, node[i].name.c_str(), node[i].score);
    }
    return 0;
}
