#include<map>
#include<set>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int m, n, s1, s2;
    cin >> m >> n;
    map<int,set<int> > data;
    for(int i=0; i<m; i++){
        cin >> s1 >> s2;
        data[s1].insert(s2);
        data[s2].insert(s1);
    }
    int cnt;
    for(int k=0; k<n; k++){
        cin >> cnt;
        int tmp;
        bool shit = false;
        set<int> res;
        for(int j=0; j<cnt; j++){
            cin >> tmp;
            res.insert(tmp);
        }
        for(auto it = res.begin(); it!=res.end(); it++){
            //int ss = data[*it];
            set<int> tmpshit = data[*it];
            for(auto it2 = tmpshit.begin(); it2!=tmpshit.end(); it2++){
                    if(res.find(*it2) != res.end()){
                        shit = true;
                        break;
                }
            }
        }
        if(shit){
            cout << "No" << endl;
        }
        else{
            cout << "Yes" << endl;
        }
    }
    system("pause");
    return 0;
}
