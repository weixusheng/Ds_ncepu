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
        while(!s.empty())
    }
}

