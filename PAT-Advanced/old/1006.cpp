#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    cin >> num;
    string tmpid, f_id, l_id, s1, s2, tmp1, tmp2;
    cin >> tmpid >> s1 >> s2;
    f_id = tmpid;
    l_id = tmpid;
    for(int i=1; i<num; i++){
        cin >> tmpid >> tmp1 >> tmp2;
        if(tmp1 < s1){
            s1 = tmp1;
            f_id = tmpid;
        }
        if(tmp2 > s2){
            s2 = tmp2;
            l_id = tmpid;
        }
    }
    cout << f_id << " " << l_id;
    return 0;
}