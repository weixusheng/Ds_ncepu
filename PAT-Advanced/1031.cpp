#include<iostream>
#include<string>

using namespace std;

int main(int argc, char const *argv[])
{
    char data[30][30];
    string c;
    cin >> c;
    fill(data[0],data[0]+30*30,' ');
    int n = c.size();
    int n1 = n/3;
    int n2 = n/3 + n%3;
    int index = 0;
    for(int i=0; i<n1; i++){
        data[0][i] = c[index++];
    }
    for(int i=1; i<=n2-2; i++){
        data[n1-1][i] = c[index++];
    }
    for(int i=0; i<n1; i++){
        data[i][n2-1] = c[index++];
    }
    for(int i=0; i<n2; i++){
        for(int j=0; j<n1; j++){
            printf("%c", data[i][j]);
        }
        printf("\n");
    }
    return 0;
}
