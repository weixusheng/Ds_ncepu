#include<cstdlib>
#include<iostream>
#include<cmath>
#include<stack>

using namespace std;

int main(int argc, char const *argv[])
{
    long long a, b, c;
    cin >> a >> b;
    c = a+b;
    if(c < 0){
        cout << "-";
    }
    if(c == 0){
        cout << "0";
        return 0;
    }
    int carry;
    int cnt = 0;
    c = abs(c);
    stack<char> data;
    while(c != 0){
        carry = c%10;
        data.push(carry+'0');
        cnt++;
        if(cnt%3 == 0){
            data.push(',');
        }
        c = c/10;
    }
    if(data.top() == ','){
        data.pop();
    }
    int sizes = data.size();
    for(int i=0; i<sizes; i++){
        cout << data.top();
        data.pop();
    }
    return 0;
}
