#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
    map<string, vector<int> > data;
    int n, k, no, num;
    string name;
    name.resize(30);
    //cin >> n >> k;
    scanf("%d %d", &n, &k);
    for(int i=0; i<k; i++){
        scanf("%d %d", &no, &num);
        for(int j=0; j<num; j++){
            //cin >> name;
            scanf("%s", &name[0]);
            data[name].push_back(no);
        }
    }
    for(int i=0; i<n; i++){
        //cin >> name;
        scanf("%s", &name[0]);
        sort(data[name].begin(), data[name].end());
        //cout << name << " " << data[name].size();
        printf("%s %d", name.c_str(), data[name].size());
        for(int k=0; k<data[name].size(); k++){
            printf(" %d", data[name][k]);
        }
        printf("\n");
    }
    return 0;
}
