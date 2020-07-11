#include<cstdio>
#include<map>
#include<set>

using namespace std;

int main(int argc, const char** argv) {
    int num;
    scanf("%d", &num);
    int s1,s2;
    map<int, int> data;
    for(int i=0; i<num; i++){
        scanf("%d %d", &s1, &s2);
        data[s1] = s2;
        data[s2] = s1;
    }
    int num2, count = 0;
    int temp;
    scanf("%d", &num2);
    set<int> data2;
    set<int> res;
    for(int k=0; k<num2; k++){
       scanf("%d", &temp);
       data2.insert(temp);
    }
    for(auto it = data2.begin(); it!=data2.end(); it++){
        if(data2.find(data[*it]) == data2.end()){
            count++;
            res.insert(*it);
        }
    }
    printf("%d\n", count);
    int flag = 0;
    for(auto it2 = res.begin(); it2!=res.end(); it2++){
        if(flag == 0){
            flag = 1;
        }
        else{
            printf(" ");
        }
        printf("%04d", *it2);
    }
    return 0;
}