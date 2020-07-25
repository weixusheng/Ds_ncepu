#include<cstdlib>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<iomanip>

using namespace std;

struct node{
    int id;
    int next;
};

int main(int argc, char const *argv[])
{
    int address, num, k;
    int tmpad,tmpid,tmpnext;
    cin >> address >> num >> k;
    vector<node> data(100000);
    map<int,int> mp;
    for(int i=0; i<num; i++){
        cin >> tmpad >> tmpid >> tmpnext;
        data[tmpad] = node{tmpid, tmpnext};
        mp[tmpid] = tmpad;
    }
    //int start = data[address].id;
    vector<int> res;
    while(address != -1){
        res.push_back(data[address].id);
        address = data[address].next;
    }
    // reverse
    for(int i=0; i<res.size()/k; i++){
        reverse(res.begin()+i*k,res.begin()+k*(i+1));
    }
    /*
    if(num%k != 0){
        reverse(res.begin()+num/k*k,res.begin()+num-1);
    }
    */
    for(int i=0; i<res.size(); i++){
        if(i == res.size()-1){
            //cout << setw(5) << setfill('0') <<mp[res[i]] << " " << res[i] << " -1" << endl;
            printf("%05d %d -1",mp[res[i]],res[i]);
        }
        else{
            printf("%05d %d %05d\n",mp[res[i]], res[i], mp[res[i+1]]);
            //cout << setw(5) << setfill('0') << mp[res[i]] << " " << res[i] << " " << setw(5) << setfill('0') << mp[res[i+1]] << endl;
        }
    }
    system("pause");
    return 0;
}