#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c1, c2;
int e[510][510], weight[510], dis[510], num[510], w[510];
bool visit[510];
const int inf = 99999999;   //初始化最大值

int main() {
    scanf("%d%d%d%d", &n, &m, &c1, &c2);
    for(int i = 0; i < n; i++)
        scanf("%d", &weight[i]);
    fill(e[0], e[0] + 510 * 510, inf);      //初始化 矩阵 为空值
    fill(dis, dis + 510, inf);      //初始化 距离数组 为空值
    int a, b, c;
    for(int i = 0; i < m; i++) {
        scanf("%d%d%d", &a, &b, &c);    //读入边值
        e[a][b] = e[b][a] = c;
    }
    /* 初始化 开始条件  begin*/
    dis[c1] = 0;
    w[c1] = weight[c1];
    num[c1] = 1;
    /* 初始化 开始条件  end*/
    for(int i = 0; i < n; i++) {
        /* 找到最小值边 begin*/
        int u = -1, minn = inf;
        for(int j = 0; j < n; j++) {
            if(visit[j] == false && dis[j] < minn) {
                u = j;
                minn = dis[j];
            }
        }
        /* 找到最小值边 end*/
        if(u == -1) break; //没有最小边-  结束当前
        visit[u] = true;   //标记访问
        /* 核心代码 begin*/
        for(int v = 0; v < n; v++) {
            if(visit[v] == false && e[u][v] != inf) {   //从当前边出发,判断是否有更近路径
                if(dis[u] + e[u][v] < dis[v]) {
                    dis[v] = dis[u] + e[u][v];  //更新距离
                    num[v] = num[u];            //更新路径数目
                    w[v] = w[u] + weight[v];    //更新权重和
                } 
                else if(dis[u] + e[u][v] == dis[v]) {
                    num[v] = num[v] + num[u];       //更新路径数目
                    if(w[u] + weight[v] > w[v])
                        w[v] = w[u] + weight[v];    //更新权重和
                }
            }
        }
        /* 核心代码 end*/
    }
    printf("%d %d", num[c2], w[c2]);
    return 0;
}