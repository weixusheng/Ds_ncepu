#include<stack>
#include<algorithm>
#include<string>
#include<iostream>

using namespace std;

const int maxn = 100010;
const int sqrn = 316;

stack<int> st;

int block[sqrn];
int table[maxn];

void peekm(int k){
    int sum = 0;
    int idx = 0;
    while(sum + block[idx] < k){
        sum += block[idx];
    }
    int num = idx * sqrn;
    while(sum + table[num] < k){
        sum += table[num++];
    }
    printf("%d\n", num);
}

void push(int x){
    st.push(x);
    block[x/sqrn]++;
    table[x]++;
}

void pop(){
    int x = st.top();
    st.pop();
    block[x/sqrn]--;
    table[x]--;
    printf("%d", x);
}

int main(){
    int x, query;
    fill(block, block+316, 0);
    fill(table, table+100010, 0);
    string cmd;
    for(int i=0; i<query; i++){
        cin >> cmd;
        if(cmd == "Push"){
            scanf("%d", x);
            push(x);
        }
        else if(cmd == "Pop"){
            if(st.empty() == true){
                printf("Invalid\n");
            }
            else{
                pop();
            }
        }
        else{
            if(st.empty() == true){
                printf("Invalid\n");
            }
            else{
                int k = st.size();
                if(k%2 == 1){
                    k = (k+1)/2;
                }
                else{
                    k = k/2;
                }
                peekm(k);
            }
        }
    }
    return 0;
}