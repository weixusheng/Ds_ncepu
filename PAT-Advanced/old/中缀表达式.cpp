#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<queue>
#include<map>

using namespace std;

struct node
{
    double num;
    char op;
    bool flag; //true表示操作数,false表示操作符
};

string str;
stack<node> s;
queue<node> q;      // 操作符栈
map<char, int> op;  //后缀表达式序列

void change(){
    double num;
    node tmp;
    for(int i=0; i<str.length(); i++){
        if(str[i] >= '0' && str[i] <= '9'){
            tmp.flag = true;
            tmp.num = str[i++]-'0';
            while (i < str.length() && str[i] >= '0' && str[i] <= '9'){
                tmp.num = tmp.num*10 + (str[i]-'0');
                i++;
            }
            q.push(tmp);
        }
        else{
            tmp.flag = false;
            while(!s.empty() && op[str[i]] <= op[s.top().op]){
                q.push(s.top());
                s.pop();
            }
            tmp.op = str[i];
            s.push(tmp);
            i++;
        }
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

double cal(){
    double tmp1,tmp2;
    node cur, tmp;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.flag == true){
            s.push(cur);
        }
        else{
            tmp2 = s.top().num;
            s.pop();
            tmp1 = s.top().num;
            s.pop();
            tmp.flag = true;
            if(cur.op == '+'){
                tmp.num = tmp1+tmp2;
            }
            else if(cur.op == '-'){
                tmp.num = tmp1-tmp2;
            }
            else if(cur.op == '*'){
                tmp.num = tmp1*tmp2;
            }
            s.push(tmp);
        }
    }
    return s.top().num;
}

int main(){
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    while(getline(cin,str), str!="0"){
        for(auto it = str.end(); it!= str.begin(); it--){
            if(*it == ' '){
                str.erase(it);
            }
        }
        while(!s.empty()){
            s.pop();
        }
        change();
        printf(".2f\n", cal());
    }
    return 0;
}
