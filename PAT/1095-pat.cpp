#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstdlib>

using namespace std;

struct lnode{
    string id;
    int score;
};

struct knode{
    int rnum,snum;
};

int main(int argc, char const *argv[])
{
    // B123180908127
    int m, n;
    cin >> m >> n;
    // id-score
    string id;
    int score;
    // level-date
    string level;
    string kaochang, date;
    //vector-levle
    map<string, vector<lnode> > lmap;
    map<string, knode> kmap;
    map<string, map<string, int> > dmap;
    for(int i=0; i<m; i++){
        cin >> id >> score;
        level = id[0];
        kaochang = id.substr(1,3);
        date = id.substr(4,6);
        // insert lmap
        lmap[level].push_back(lnode{id, score});
        // insert kmap
        //if(kmap.find(kaochang) == kmap.end()){
            //kmap[kaochang].snum = score;
            //kmap[kaochang].rnum = 1;
        //}
        //else{
            kmap[kaochang].snum += score;
            kmap[kaochang].rnum++;
        //}
        //insert dmap;
        //if(dmap[date].find(kaochang) == dmap[date].end()){
            //dmap[date][kaochang] = 1;
        //}
        //else{
            dmap[date][kaochang]++;
        //}
    }
    int mode;
    string shit;
    for(int j=0; j<n; j++){
        cin >> mode >> shit;
        cout << "Case " << j+1 << endl;
        switch (mode)
        {
        case 1:
            for(int k=0; k<lmap[shit].size(); k++){
                cout << lmap[shit][k].id << " " << lmap[shit][k].score << endl;
            }
            break;
        case 2:
            cout << kmap[shit].rnum <<" "<< kmap[shit].snum << endl;
            break;
        case 3:
            for(auto it = dmap[shit].begin(); it!=dmap[shit].end(); it++){
                cout << it->first << " " << it->second << endl;
            }
            break;
        }
    }
    system("pause");
    return 0;
}

