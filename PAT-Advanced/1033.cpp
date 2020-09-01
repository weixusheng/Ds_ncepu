#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

const int inf = 99999999;  
struct station{
    double pris;
    double dis;
};

bool cmp(station a, station b){
    return a.dis < b.dis;
}

int main(int argc, char const *argv[])
{
    double cmax, d, avg;
    int n;
    scanf("%lf%lf%lf%d", &cmax, &d, &avg, &n);
    vector<station> sta(n+1);
    sta[0] = {0.0, d};
    for(int i=1; i<=n; i++){
        scanf("%lf%lf", &sta[i].pris, &sta[i].dis);
    }
    sort(sta.begin(), sta.end(), cmp);
    double nowdis = 0.0, maxdis = 0.0, nowpris = 0.0, totalpris = 0.0, leftdis = 0.0;
    //特判不存加原点加油站
    if(sta[0].dis != 0){
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    else{
        nowpris = sta[0].pris;
    }
    while(nowdis < d){
        maxdis = nowdis + cmax*avg; //最大行驶路程
        double minpris = inf;
        double minprisdis = 0;
        int flag = 0;
        //找到第一个符合条件的车站
        for(int i=1; i<=n && sta[i].dis <= maxdis; i++){
            if(sta[i].dis <= nowdis){
                continue;
            }
            if(sta[i].pris < nowpris){
                totalpris += (nowpris * (sta[i].dis - nowdis - leftdis)/avg);
                leftdis = 0.0;
                nowpris = sta[i].pris;
                nowdis = sta[i].dis;
                flag = 1;
                break;
            }
            if(sta[i].pris < minpris){
                minpris = sta[i].pris;
                minprisdis = sta[i].dis;
            }
        }
        if(flag == 0 && minpris != inf){
            totalpris += (nowpris * (cmax - leftdis/avg));
            leftdis = (cmax*avg)-(minprisdis - nowdis);
            nowdis = minprisdis;
            nowpris = minpris;
        }
        if(flag == 0 && minpris == inf){
            nowdis += cmax*avg;
            printf("The maximum travel distance = %.2f", nowdis);
            return 0;
        }
    }
    printf("%.2f", totalpris);
    return 0;
}
