#include<set>
#include<iostream>
#include<cstdlib>

using namespace std;

int main(int argc, char const *argv[])
{
    int num;
    int cnt = 0;
    //double shit;
    cin >> num;
    set<int> res;
    int s;
    for(int i=1; i<=num; i++){
        s = i/2+i/3+i/5;
        if(res.find(s) == res.end()){
            res.insert(s);
            cnt++;
        }
    }
    printf("%d",cnt);
    system("pause");
    return 0;
}
