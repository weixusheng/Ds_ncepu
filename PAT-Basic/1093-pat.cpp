#include<cstdlib>
#include<set>
#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    string a, b;
    getline(cin, a);
    getchar();
    getline(cin, b);
    string c = a+b;
    set<char> data;
    for(int i=0; i<c.size(); i++){
        if(data.find(c[i]) == data.end()){
            printf("%c", c[i]);
            data.insert(c[i]);
        }
    }
    system("pause");
    return 0;
}
