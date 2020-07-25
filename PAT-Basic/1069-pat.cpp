#include<cstdio>
#include<set>
#include<string>
#include<iostream>

using namespace std;

int main(int argc, const char** argv) {
    int M, N, start;
    scanf("%d %d %d", &N, &M ,&start);
    set<string> havegot;
    string temp;
    int num = 0;
    int move = 0;
    for(int i=0; i<N; i++){
        cin >> temp;
        if(i == start-1+num*M+move){
            if(havegot.find(temp) == havegot.end()){
                num++;
                havegot.insert(temp);
                cout << temp << endl;
            }
            else{
                move++;
            }
        }
    }
    if(havegot.size() == 0){
        printf("Keep going...");
    }
    return 0;
}