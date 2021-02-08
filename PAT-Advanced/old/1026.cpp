#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

struct person{
    int arrive, start, time;
    bool vip;
}tmpperson;

struct tablenode{
    int end = 8*3600, num;
    bool vip;
};

bool cmp1(person a, person b){
    return a.arrive < b.arrive;
}

bool cmp2(person a, person b){
    return a.start < b.start;
}

vector<person> player;
vector<tablenode>table;

void alloctable(int personid, int tableid){
    if(player[personid].arrive <= table[tableid].end){
        player[personid].start = table[tableid].end;
    }
    else{
        player[personid].start = player[personid].arrive;
    }
    table[tableid].end = player[personid].start + player[personid].time;
    table[tableid].num++;
}

int findnextvip(int vipid){
    vipid++;
    while(vipid < player.size() && player[vipid].vip == false){
        vipid++;
    }
    return vipid;
}

int main(int argc, char const *argv[])
{
    int n, k, m, viptable;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        int h,m,s,tmptime, flag;
        scanf("%d:%d:%d %d %d", &h, &m, &s, &tmptime, &flag);
        tmpperson.arrive = h*3600 + m*60 + s;
        tmpperson.start = 21 * 3600;
        if(tmpperson.arrive >= 21*3600){
            continue;
        }
        tmpperson.time = tmptime <= 120 ? tmptime*60 : 7200;
        tmpperson.vip = ((flag == 1) ? true : false);
        player.push_back(tmpperson);
    }
    scanf("%d%d", &k,&m);
    table.resize(k+1);
    for(int i=0; i<m; i++){
        scanf("%d", &viptable);
        table[viptable].vip = true;
    }
    sort(player.begin(), player.end(), cmp1);
    int i=0, vipid = -1;
    vipid = findnextvip(vipid);
    while(i < player.size()){
        int index = -1, minendtime = 999999999;
        for(int j=1; j<=k; j++){    //找到最先结束的table
            if(table[j].end < minendtime){
                minendtime = table[j].end;
                index = j;
            }
        }
        if(table[index].end >= 21*3600){
            break;
        }
        if(player[i].vip == true && i<vipid){
            i++;
            continue;
        }
        if(table[index].vip == true){   // vip table
            if(player[i].vip == true){  //vip table && vip man
                alloctable(i,  index);
                if(vipid == i){
                    vipid = findnextvip(vipid);
                }
                i++;
            }
            else{   // vip table !vip man
                if(vipid < player.size() && player[vipid].arrive <= table[index].end){
                    alloctable(vipid, index);
                    vipid = findnextvip(vipid); //先不跳过,留给非vip的下次循环
                }
                else{
                    alloctable(i, index);
                    i++;
                }
            }
        }
        else{   // !vip table
            if(player[i].vip == false){
                alloctable(i, index);
                i++;
            }
            else{   //vip man
                int vipindex = -1, minvipendtime = 999999999;
                for(int j=1; j<=k; j++){        //寻找符合要求的 vip table
                    if(table[j].vip == true && table[j].end < minvipendtime){
                        minvipendtime = table[j].end;
                        vipindex = j;
                    }
                }
                if(vipindex != -1 && player[i].arrive >= table[vipindex].end){
                    alloctable(i, vipindex);
                    if(vipid == i){
                        vipid = findnextvip(vipid);
                    }
                    i++;
                }
                else{   //没找到 vip table
                    alloctable(i, index);
                    if(vipid == i){
                        vipid = findnextvip(vipid);
                    }
                    i++;
                }
            }
        }
    }
    sort(player.begin(), player.end(), cmp2);
    // 注意最后 double四舍五入的方法，先 round 函数，再 .0f 输出
    for(int i=0; i<player.size() && player[i].start < 21*3600; i++){
        printf("%02d:%02d:%02d ", player[i].arrive/3600, player[i].arrive % 3600 / 60, player[i].arrive%60);
        printf("%02d:%02d:%02d ", player[i].start/3600, player[i].start% 3600 / 60, player[i].start%60);
        printf("%.0f\n", round((player[i].start-player[i].arrive) /60.0));
    }
    for(int i=1; i<=k; i++){
        if(i != 1){
            printf(" ");
        }
        printf("%d", table[i].num);
    }
    return 0;
}
