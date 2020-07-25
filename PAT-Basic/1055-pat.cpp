#include<cstdio>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

using namespace std;

struct node {
    string name;
    int height;
};
int cmp(struct node a, struct node b) {
    return a.height != b.height ? a.height > b.height : a.name < b.name;
}
int main() {
    int n, k, m;
    cin >> n >> k;
    vector<node> stu(n);
    for(int i = 0; i < n; i++) {
        cin >> stu[i].name >> stu[i].height;
    }
    sort(stu.begin(), stu.end(), cmp);
    int t = 0, row = k;
    while(row) {
        if(row == k)
            m = n - n / k * (k - 1);
        else
            m = n / k;
        vector<string> ans(m);
        ans[m / 2] = stu[t].name;
        // 左边一列
        int j = m / 2 - 1;
        for(int i = t + 1; i < t + m; i = i + 2)
            ans[j--] = stu[i].name;
        // 右边一列
        j = m / 2 + 1;
        for(int i = t + 2; i < t + m; i = i + 2)
            ans[j++] = stu[i].name;
        // 输出当前排
        cout << ans[0];
        for(int i = 1; i < m; i++)
            cout << " " << ans[i];
        cout << endl;
        t = t + m;
        row--;
    }
    return 0;
}

/*
typedef struct{
    int height;
    string name;
}person, *point_person;

int cmp(person a, person b){
    if(a.height == b.height){
        return a.name < b.name;
    }
    return a.height > b.height;
}

int main(int argc, const char** argv) {
    int N,K,n,m;
    scanf("%d %d\n", &N, &K);
    n = N/K;
    m = N%K;
    int last_row = m+n;
    vector<person> data(N);
    for(int i=0; i<N; i++){
        person new_person;
        cin >> new_person.name >> new_person.height;
        data[i] = new_person;
    }
    sort(data.begin(), data.end(),cmp);
    vector<string> shit(m+n,"0");
    int cur = 0, mid;
    int charge =  last_row-K;
    for(int k=0; k<K; k++){
        if(k==0){
            mid = last_row/2 +1;
            --mid;
            shit[mid] = data[cur++].name;
            for(int h=1,max = last_row; last_row>0; last_row-=2){
                if((mid-h)>=0){
                    shit[mid-h] = data[cur++].name;
                }
                if((mid+h)<max){
                    shit[mid+h] = data[cur++].name;
                }
                h++;
            }
            for(auto i = shit.begin(); i<shit.end(); i++){
                if(i == shit.end()-1){
                    printf("%s\n", (*i).c_str());
                }
                else{
                    printf("%s ", (*i).c_str());
                }
            }
        }
        else{
            mid = K/2 +1;
            --mid;
            shit[mid] = data[cur++].name;
            int temp;
            for(int h=1,max = K,temp = K; temp>0; temp-=2){
                if((mid-h)>=0){
                    shit[mid-h] = data[cur++].name;
                }
                if((mid+h)<max){
                    shit[mid+h] = data[cur++].name;
                }
                h++;
            }
            for(auto i = shit.begin(); i<shit.end()-charge; i++){
                if(i == shit.end()-1-charge){
                    printf("%s\n", (*i).c_str());
                }
                else{
                    printf("%s ", (*i).c_str());
                }
            }
        }
    }
    return 0;
}
*/