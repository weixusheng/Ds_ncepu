#include<cstdlib>
#include<map>
#include<iostream>
#include<string>
#include<vector>
#include<cstdio>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> month = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    int d, y,num;
    char m[20];
    cin >> num;
    for(int i=0; i<num; i++){
        scanf("%s %d, %d",&m,&d,&y);
        //find month
        int tmpm;
        string tmp;
        char data[100];
        for(int j=0; j<12; j++){
            if(month[j] == m){
                tmpm = j+1;
                break;
            }
        }
        sprintf(data,"%04d%02d%02d",y,tmpm,d);
        tmp = data;
        int k;
        for(k=0; k<4; k++){
            if(tmp[k] != tmp[7-k]){
                cout << "N ";
                break;
            }
        }
        if(k == 4){
            cout << "Y ";
        }
        cout << tmp << endl;
    }
    system("pause");
    return 0;
}
